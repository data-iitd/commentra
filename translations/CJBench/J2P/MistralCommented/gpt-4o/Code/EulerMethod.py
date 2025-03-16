import numpy as np

# Function to perform the Euler step
def euler_step(x_current, step_size, y_current, differential_equation):
    if step_size <= 0:  # Checking if the step size is valid
        raise ValueError("stepSize should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)  # Calculating the next y value using the Euler method

# Function to calculate all points using the Euler method
def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    if x_start >= x_end:  # Checking if x_end is greater than x_start
        raise ValueError("xEnd should be greater than xStart")
    if step_size <= 0:  # Checking if the step size is valid
        raise ValueError("stepSize should be greater than zero")

    points = []  # Initializing an empty list to store the points
    points.append((x_start, y_start))  # Adding the initial point to the list

    y_current = y_start  # Initializing the current y value
    x_current = x_start  # Initializing the current x value

    # Calculating all the remaining points using the Euler method
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append((x_current, y_current))

    return points  # Returning the list of points

# Main function to execute the program
def main():
    # Reading user input for the initial conditions and equation choice
    x_start = float(input())
    x_end = float(input())
    step_size = float(input())
    y_start = float(input())
    equation_choice = int(input())

    # Assigning the differential equation based on the user's choice
    if equation_choice == 1:
        differential_equation = lambda x, y: x  # Assigning the first differential equation
    elif equation_choice == 2:
        differential_equation = lambda x, y: y  # Assigning the second differential equation
    elif equation_choice == 3:
        differential_equation = lambda x, y: x + y + x * y  # Assigning the third differential equation
    else:
        raise ValueError("Invalid choice of differential equation")  # Throwing an exception for invalid equation choice

    # Calculating the points using the Euler method
    points = euler_full(x_start, x_end, step_size, y_start, differential_equation)

    # Printing the results
    print("Results:")
    for point in points:
        print(f"x: {point[0]:.6f}; y: {point[1]:.6f}")

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
