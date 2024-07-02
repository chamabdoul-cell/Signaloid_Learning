#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


#define N 10000  // Number of simulations
#define G 9.81   // Acceleration due to gravity (m/s^2)

// Function to generate a random number from a normal distribution using Box-Muller transform
double randn(double mean, double std) {
    double u1 = ((double) rand() / RAND_MAX);
    double u2 = ((double) rand() / RAND_MAX);
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return z0 * std + mean;
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    double diff = *(double *)a - *(double *)b;
    return (diff > 0) - (diff < 0);
}

int main() {
    double v0_mean = 50.0;  // Mean initial velocity (m/s)
    double v0_std = 2.0;    // Standard deviation of initial velocity (m/s)
    double theta_mean_deg = 45.0;  // Mean launch angle (degrees)
    double theta_std_deg = 1.0;    // Standard deviation of launch angle (degrees)

    // Convert mean and std of angle to radians
    double theta_mean = theta_mean_deg * M_PI / 180.0;
    double theta_std = theta_std_deg * M_PI / 180.0;

    // Seed the random number generator
    srand(time(NULL));

    // Arrays to store results
    double *R_samples = (double *)malloc(N * sizeof(double));

    // Monte Carlo simulation
    for (int i = 0; i < N; i++) {
        double v0 = randn(v0_mean, v0_std);
        double theta = randn(theta_mean, theta_std);
        R_samples[i] = (v0 * v0 * sin(2 * theta)) / G;
    }

    // Calculate mean, standard deviation, and 95% confidence interval
    double R_sum = 0.0;
    for (int i = 0; i < N; i++) {
        R_sum += R_samples[i];
    }
    double R_mean = R_sum / N;

    double R_var_sum = 0.0;
    for (int i = 0; i < N; i++) {
        R_var_sum += (R_samples[i] - R_mean) * (R_samples[i] - R_mean);
    }
    double R_std = sqrt(R_var_sum / N);

    // Sort the results to calculate the confidence interval
    qsort(R_samples, N, sizeof(double), compare);
    double R_95_lower = R_samples[(int)(N * 0.025)];
    double R_95_upper = R_samples[(int)(N * 0.975)];

    // Print the results
    printf("Mean range: %.2f m\n", R_mean);
    printf("Standard deviation of range: %.2f m\n", R_std);
    printf("95%% confidence interval of range: %.2f m to %.2f m\n", R_95_lower, R_95_upper);

    // Free allocated memory
    free(R_samples);

    return 0;
}
