

import math

# Calculate definite integrals by using Composite simpson's rule.
# Wiki: https://en.wikipedia.org/wiki/Simpson%27s_rule#Composite_Simpson's_rule
# Given f a function and an even number N of intervals that divide the integration interval
# e.g. [a, b], we calculate the step h = (b-a)/N and create a table that contains all the x
# points of the real axis xi = x0 + i*h and the value f(xi) that corresponds to these xi.
#
# To evaluate the integral i use the formula below:
# I = h/3 * {f(x0) + 4*f(x1) + 2*f(x2) + 4*f(x3) +... + 2*f(xN-2) + 4*f(xN-1) + f(xN)}
#

def main():
    n = int(input("Enter the number of intervals (must be even number N=2*k): "))

    # Ensure n is even
    if n % 2!= 0:
        print("n must be an even number for Simpson's method. Exiting.")
        return

    a = float(input("Enter the starting point of the interval: "))

    b = float(input("Enter the ending point of the interval: "))

    # Calculate step h and evaluate the integral
    h = (b - a) / n
    integral_evaluation = simpsons_method(n, h, a)
    print("The integral is equal to: ", integral_evaluation)

# @param N: Number of intervals (must be even number N=2*k)
# @param h: Step h = (b-a)/N
# @param a: Starting point of the interval
# @param b: Ending point of the interval
#
# The interpolation points xi = x0 + i*h are stored the treeMap data
#
# @return result of the integral evaluation
def simpsons_method(n, h, a):
    data = {} # Key: i, Value: f(xi)
    xi = a # Initialize xi = x0

    # Create the table of xi and yi points
    for i in range(n + 1):
        xi = a + i * h
        temp = f(xi) # Get the value of the function at xi
        data[i] = temp

    # Apply Simpson's rule formula
    integral_evaluation = 0
    for i in data:
        if i == 0 or i == n:
            integral_evaluation += data[i]
        elif i % 2!= 0:
            integral_evaluation += 4 * data[i]
        else:
            integral_evaluation += 2 * data[i]

    # Multiply by h/3
    integral_evaluation = h / 3 * integral_evaluation

    # Return the result
    return integral_evaluation

# Sample function f
# Function f(x) = e^(-x) * (4 - x^2)
def f(x):
    return math.exp(-x) * (4 - x**2)

if __name__ == "__main__":
    main()

