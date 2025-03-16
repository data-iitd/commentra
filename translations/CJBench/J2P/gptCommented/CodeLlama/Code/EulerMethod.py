import math

def euler_step(x_current, step_size, y_current, differential_equation):
    # Validate that the step size is positive
    if step_size <= 0:
        raise ValueError("stepSize should be greater than zero")
    # Calculate the new y value using the differential equation
    return y_current + step_size * differential_equation(x_current, y_current)

def euler_full(x_start, x_end, step_size, y_start, differential_equation):
    # Validate that the start and end x values are in the correct order
    if x_start >= x_end:
        raise ValueError("xEnd should be greater than xStart")
    # Validate that the step size is positive
    if step_size <= 0:
        raise ValueError("stepSize should be greater than zero")
    
    # Initialize a list to store the points (x, y)
    points = []
    points.append([x_start, y_start]) # Add the starting point
    
    y_current = y_start # Initialize the current y value
    x_current = x_start # Initialize the current x value
    
    # Loop until the current x value reaches or exceeds the end x value
    while x_current < x_end:
        # Perform an Euler step to calculate the new y value
        y_current = euler_step(x_current, step_size, y_current, differential_equation)
        x_current += step_size # Increment the current x value by the step size
        
        # Add the new point to the list
        points.append([x_current, y_current])
    
    # Return the list of calculated points
    return points

# Main function
def main():
    # Create a scanner object for user input
    scanner = input("Enter the starting x value, ending x value, step size, starting y value, and equation choice separated by spaces: ")
    # Read the starting x value, ending x value, step size, starting y value, and equation choice from user input
    x_start, x_end, step_size, y_start, equation_choice = scanner.split()
    x_start = float(x_start)
    x_end = float(x_end)
    step_size = float(step_size)
    y_start = float(y_start)
    equation_choice = int(equation_choice)
    
    # Declare a function to represent the differential equation
    differential_equation = None
    
    # Select the appropriate differential equation based on user choice
    if equation_choice == 1:
        differential_equation = lambda x, y: x # dy/dx = x
    elif equation_choice == 2:
        differential_equation = lambda x, y: y # dy/dx = y
    elif equation_choice == 3:
        differential_equation = lambda x, y: x + y + x * y # dy/dx = x + y + xy
    else:
        # Throw an exception if the user provides an invalid choice
        raise ValueError("Invalid choice of differential equation")
    
    # Calculate the points using the Euler method
    points = euler_full(x_start, x_end, step_size, y_start, differential_equation)
    
    # Print the results
    print("Results:")
    for point in points:
        print("x: {:.6f}; y: {:.6f}".format(point[0], point[1]))

if __name__ == "__main__":
    main()

