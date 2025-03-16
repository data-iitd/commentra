
import math

# Initializing the scanner for user input
scanner = input()

# Reading user input for the initial conditions and equation choice
x_start = float(scanner[0])
x_end = float(scanner[1])
step_size = float(scanner[2])
y_start = float(scanner[3])
equation_choice = int(scanner[4])

# Assigning the differential equation based on the user's choice
differential_equation = None
if equation_choice == 1:
    differential_equation = lambda x, y: x
elif equation_choice == 2:
    differential_equation = lambda x, y: y
elif equation_choice == 3:
    differential_equation = lambda x, y: x + y + x * y
else:
    raise ValueError("Invalid choice of differential equation")

# Calculating the points using the Euler method
points = euler_full(x_start, x_end, step_size, y_start, differential_equation)

# Printing the results
print("Results:")
for point in points:
    print(f"x: {point[0]:.6f}; y: {point[1]:.6f}")

# Closing the scanner to release system resources
scanner.close()

# Euler step method for calculating the next point
def euler_step(x_current, step_size, y_current, differential_equation):
    if step_size <= 0:
        raise ValueError("stepSize should be greater than zero")
    return y_current + step_size * differential_equation(x_current, y_current)

# Euler Full method for calculating all the points
def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    if x_start >= x_end:
        raise ValueError("xEnd should be greater than xStart")
    if step_size <= 0:
        raise ValueError("stepSize should be greater than zero")

    # Initializing an empty ArrayList to store the points
    points = []

    # Adding the initial point to the ArrayList
    points.append([x_start, y_start])

    y_current = y_start
    x_current = x_start

    # Calculating all the remaining points using the Euler method
    while x_current < x_end:
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size
        points.append([x_current, y_current])

    # Returning the ArrayList of points
    return points

# 