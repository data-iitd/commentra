

import math

# Initializing the scanner for user input
def main():
    scanner = Scanner(System.in) # Creating a new Scanner object for reading user input

    # Reading user input for the initial conditions and equation choice
    x_start = scanner.nextDouble()
    x_end = scanner.nextDouble()
    step_size = scanner.nextDouble()
    y_start = scanner.nextDouble()
    equation_choice = scanner.nextInt()

    # Assigning the differential equation based on the user's choice
    def differential_equation(x, y):
        if equation_choice == 1:
            return x
        elif equation_choice == 2:
            return y
        elif equation_choice == 3:
            return x + y + x * y
        else:
            raise ValueError("Invalid choice of differential equation")

    # Calculating the points using the Euler method
    points = euler_full(x_start, x_end, step_size, y_start, differential_equation)

    # Printing the results
    print("Results:")
    for point in points:
        print(f"x: {point[0]}; y: {point[1]}")

    # Closing the scanner to release system resources
    scanner.close()

# Euler step method for calculating the next point
def euler_step(x_current, step_size, y_current, differential_equation):
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)

# Euler Full method for calculating all the points
def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    if x_start >= x_end:
        raise ValueError("x_end should be greater than x_start")
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")

    # Initializing an empty list to store the points
    points = []

    # Adding the initial point to the list
    points.append([x_start, y_start])

    y_current = y_start # Initializing the current y value
    x_current = x_start # Initializing the current x value

    # Calculating all the remaining points using the Euler method
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append([x_current, y_current])

    # Returning the list of points
    return points

if __name__ == "__main__":
    main()

