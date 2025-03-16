
import math

def euler_step(x_current, step_size, y_current, differential_equation):
    # Validate that the step size is positive
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    # Calculate the new y value using the differential equation
    return y_current + step_size * differential_equation(x_current, y_current)

def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    # Validate that the start and end x values are in the correct order
    if x_start >= x_end:
        raise ValueError("x_end should be greater than x_start")
    # Validate that the step size is positive
    if step_size <= 0:
        raise ValueError("step_size should be greater than zero")
    
    # Initialize a list to store the points (x, y)
    points = [(x_start, y_start)] # Add the starting point
    
    y_current = y_start # Initialize the current y value
    x_current = x_start # Initialize the current x value
    
    # Loop until the current x value reaches or exceeds the end x value
    while x_current < x_end:
        # Perform an Euler step to calculate the new y value
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size # Increment the current x value by the step size
        
        # Add the new point to the list
        points.append((x_current, y_current))
    
    # Return the list of calculated points
    return points

# Define the differential equations as lambda functions
def differential_equation_1(x, y):
    return x

def differential_equation_2(x, y):
    return y

def differential_equation_3(x, y):
    return x + y + x * y

# Read the starting x value, ending x value, step size, starting y value, and equation choice from user input
x_start = float(input("Enter the starting x value: "))
x_end = float(input("Enter the ending x value: "))
step_size = float(input("Enter the step size: "))
y_start = float(input("Enter the starting y value: "))
equation_choice = int(input("Enter the equation choice (1, 2, or 3): "))

# Select the appropriate differential equation based on user choice
if equation_choice == 1:
    differential_equation = differential_equation_1
elif equation_choice == 2:
    differential_equation = differential_equation_2
elif equation_choice == 3:
    differential_equation = differential_equation_3
else:
    raise ValueError("Invalid equation choice")

# Calculate the points using the Euler method
points = euler_full(x_start, x_end, step_size, y_start, differential_equation)

# Print the results
print("Results:")
for point in points:
    print(f"x: {point[0]:.6f}; y: {point[1]:.6f}")

