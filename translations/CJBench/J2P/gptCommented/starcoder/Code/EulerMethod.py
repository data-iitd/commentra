import math

# Private function to prevent instantiation
def __init__():
    pass

# Function to perform a single Euler step
def eulerStep(xCurrent, stepSize, yCurrent, differentialEquation):
    # Validate that the step size is positive
    if stepSize <= 0:
        raise Exception("stepSize should be greater than zero")
    # Calculate the new y value using the differential equation
    return yCurrent + stepSize * differentialEquation(xCurrent, yCurrent)

# Function to perform the full Euler method over the specified range
def eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation):
    # Validate that the start and end x values are in the correct order
    if xStart >= xEnd:
        raise Exception("xEnd should be greater than xStart")
    # Validate that the step size is positive
    if stepSize <= 0:
        raise Exception("stepSize should be greater than zero")
    
    # Initialize a list to store the points (x, y)
    points = []
    points.append([xStart, yStart]) # Add the starting point
    
    yCurrent = yStart # Initialize the current y value
    xCurrent = xStart # Initialize the current x value
    
    # Loop until the current x value reaches or exceeds the end x value
    while xCurrent < xEnd:
        # Perform an Euler step to calculate the new y value
        yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation)
        xCurrent += stepSize # Increment the current x value by the step size
        
        # Add the new point to the list
        points.append([xCurrent, yCurrent])
    
    # Return the list of calculated points
    return points

# Main function
def main():
    # Create a scanner object for user input
    scanner = input()
    
    # Read the starting x value, ending x value, step size, starting y value, and equation choice from user input
    xStart = float(scanner.nextDouble())
    xEnd = float(scanner.nextDouble())
    stepSize = float(scanner.nextDouble())
    yStart = float(scanner.nextDouble())
    equationChoice = int(scanner.nextInt())
    
    # Declare a function to represent the differential equation
    differentialEquation = None
    
    # Select the appropriate differential equation based on user choice
    if equationChoice == 1:
        differentialEquation = lambda x, y: x # dy/dx = x
    elif equationChoice == 2:
        differentialEquation = lambda x, y: y # dy/dx = y
    elif equationChoice == 3:
        differentialEquation = lambda x, y: x + y + x * y # dy/dx = x + y + xy
    else:
        # Throw an exception if the user provides an invalid choice
        raise Exception("Invalid choice of differential equation")
    
    # Calculate the points using the Euler method
    points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation)
    
    # Print the results
    print("Results:")
    for point in points:
        print("x: %.6f; y: %.6f" % (point[0], point[1]))

# Call the main function
if __name__ == "__main__":
    main()

# 