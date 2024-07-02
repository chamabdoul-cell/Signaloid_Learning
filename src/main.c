#include <stdio.h>
#include <math.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

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
  - The function computeRange below Compute the range of a projectile given the initial velocity and angle.

  - v0 Initial velocity (in m/s)
  - theta Initial angle (in radians)
  - return the range of the projectile (in m)
 */
double computeRange(double v0, double theta) {
    return (v0 * v0 * sin(2 * theta)) / g;
}

int main() {
    // convert to radians
    const double theta_mean_rad = M_PI / 180 * theta_mean;
    const double theta_std_rad = M_PI / 180 * theta_std;

    // random samples for v0 and theta
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> v0_dist(v0_mean, v0_std);
    normal_distribution<double> theta_dist(theta_mean_rad, theta_std_rad);

    vector<double> v0_samples(N);
    vector<double> theta_samples(N);

    for (int i = 0; i < N; i++) {
        v0_samples[i] = v0_dist(gen);
        theta_samples[i] = theta_dist(gen);
    }

    // compute the range R
    vector<double> R_samples(N);
    for (int i = 0; i < N; i++) {
        R_samples[i] = computeRange(v0_samples[i], theta_samples[i]);
    }

    // Analyze the output uncertainties
    double R_mean = 0.0;
    for (double r : R_samples) {
        R_mean += r;
    }
    R_mean /= N;

    double R_std = 0.0;
    for (double r : R_samples) {
        R_std += (r - R_mean) * (r - R_mean);
    }
    R_std = sqrt(R_std / (N - 1));

    sort(R_samples.begin(), R_samples.end());
    double R_95_conf_interval[2] = {
        R_samples[static_cast<int>(N * 0.025)],
        R_samples[static_cast<int>(N * 0.975)]
    };

    // Print the results
    printf("Mean range: %.2f m\n", R_mean);
    printf("Standard deviation of range: %.2f m\n", R_std);
    printf("95%% confidence interval of range: %.2f m to %.2f m\n", R_95_conf_interval[0], R_95_conf_interval[1]);

    return 0;
}
