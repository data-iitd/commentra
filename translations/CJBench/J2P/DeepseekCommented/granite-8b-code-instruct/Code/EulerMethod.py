
import math
import sys

# Main entry point of the program
def main():
    # Initialize scanner to read input
    scanner = sys.stdin
    # Read initial and final values of x, step size, initial value of y, and equation choice
    x_start = float(scanner.readline())
    x_end = float(scanner.readline())
    step_size = float(scanner.readline())
    y_start = float(scanner.readline())
    equation_choice = int(scanner.readline())
    # Initialize the differential equation based on user choice
    differential_equation = None
    if equation_choice == 1:
        differential_equation = lambda x, y: x
    elif equation_choice == 2:
        differential_equation = lambda x, y: y
    elif equation_choice == 3:
        differential_equation = lambda x, y: x + y + x * y
    else:
        raise ValueError("Invalid choice of differential equation")
    # Compute the points using Euler's method
    points = euler_full(x_start, x_end, step_size, y_start, differential_equation)
    # Print the results
    print("Results:")
    for point in points:
        print(f"x: {point[0]}; y: {point[1]}")

# Computes the next y value using Euler's method
def euler_step(x_current, step_size, y_current, differential_equation):
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)

# Computes all points using Euler's method from x_start to x_end
def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    if x_start >= x_end:
        raise ValueError("x_end should be greater than x_start")
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    # Initialize the list to store points
    points = []
    # Add the initial point
    points.append([x_start, y_start])
    y_current = y_start
    x_current = x_start
    # Iterate through the range to compute points
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append([x_current, y_current])
    return points

if __name__ == "__main__":
    main()
