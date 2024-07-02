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

We use Monte Carlo simulation to propagate the uncertainties through the model:
	Generate N samples of v_0 and θ from their respective distributions.
	Compute the range (R) for each sample.
	Analyze the distribution of the resulting R values.
 
The output will provide:
	The mean range of the projectile.
	The standard deviation of the range.
	The 95% confidence interval for the range.
This project illustrates how uncertainty tracing can be applied to a simple physics problem to understand the impact of input uncertainties on the output.

