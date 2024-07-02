#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <signaloid.h>  // Include Signaloid's library

// Constants
const double g = 9.81;  // acceleration due to gravity (m/s^2)

// Input uncertainties
const double v0_mean = 50;  // m/s
const double v0_std = 2;  // m/s
const double theta_mean = 45;  // degrees
const double theta_std = 1;  // degrees

// Number of simulations
const int N = 10000;

/*
  - The function computeRange below computes the range of a projectile given the initial velocity and angle.

  - v0 Initial velocity (in m/s)
  - theta Initial angle (in radians)
  - return the range of the projectile (in m)
 */
double computeRange(double v0, double theta) {
    return (v0 * v0 * sin(2 * theta)) / g;
}

int main() {
    // Convert to radians
    const double theta_mean_rad = M_PI / 180 * theta_mean;
    const double theta_std_rad = M_PI / 180 * theta_std;

    // Initialize Signaloid's random number generator
    signaloid_init_random(time(NULL));

    // Random samples for v0 and theta using Signaloid's functions
    double v0_samples[N];
    double theta_samples[N];

    for (int i = 0; i < N; i++) {
        v0_samples[i] = signaloid_random_normal(v0_mean, v0_std);
        theta_samples[i] = signaloid_random_normal(theta_mean_rad, theta_std_rad);
    }

    // Compute the range R
    double R_samples[N];
    for (int i = 0; i < N; i++) {
        R_samples[i] = computeRange(v0_samples[i], theta_samples[i]);
    }

    // Analyze the output uncertainties
    double R_mean = signaloid_mean(R_samples, N);
    double R_std = signaloid_stddev(R_samples, N);

    // Sort the range samples
    signaloid_sort(R_samples, N);

    double R_95_conf_interval[2] = {
        R_samples[(int)(N * 0.025)],
        R_samples[(int)(N * 0.975)]
    };

    // Print the results
    printf("Mean range: %.2f m\n", R_mean);
    printf("Standard deviation of range: %.2f m\n", R_std);
    printf("95%% confidence interval of range: %.2f m to %.2f m\n", R_95_conf_interval[0], R_95_conf_interval[1]);

    return 0;
}
