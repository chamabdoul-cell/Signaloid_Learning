#include <stdio.h>
#include <uxhw.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define G 9.81   // Acceleration due to gravity (m/s^2)

int main() {
    double v0_mean = 50.0;  // Mean initial velocity (m/s)
    double v0_std = 2.0;    // Standard deviation of initial velocity (m/s)

    double theta_mean = M_PI / 4.0;
    double theta_std =  M_PI / 180.0;

    double v0, theta, R;

    v0 = UxHwDoubleNormalDist(v0_mean, v0_std);
    theta = UxHwDoubleNormalDist(theta_mean, theta_std);
    R = (v0 * v0 * sin(2 * theta)) / G; // The range (R) of the projectile.

    // Print the results
    printf("Mean initial velocity v0: %.2f (m/s)\n", v0);
    printf("Launch angle theta: %.2f (m/s)\n", theta);
    printf("The range R: %.2f m\n", R);

    return 0;
}
