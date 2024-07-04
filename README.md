[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-v6.svg#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/chamabdoul-cell/Signaloid_Learning.git#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-v6.svg#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/chamabdoul-cell/Signaloid_Learning.git#gh-light-mode-only)


Uncertainty Tracing in Projectile Range Calculation
Problem Description
This project aims to determine how uncertainties in the initial velocity and launch angle affect the range of a projectile.

Problem Formulation
Given:
	Initial velocity (v_0) has an uncertainty.
	Launch angle (θ) has an uncertainty.
	The acceleration due to gravity (g) is constant.
 
Goal: Determine the uncertainty in the range (R) of the projectile.

 Input Uncertainties
	Initial velocity (v_0) is normally distributed with a mean of 50 m/s and a standard deviation of 2 m/s.
	Launch angle (θ) is normally distributed with a mean of 45 degrees and a standard deviation of 1 degree.
 
Quantify Input Uncertainties
	v_0: N(50,2^2) in m/s
	θ:   N(45,1^2) in degrees
Model Output
The range (R) of a projectile is given by:
R=(v_0^2 sin⁡(2θ))/g

 
The output will provide:
	The range of the projectile.

