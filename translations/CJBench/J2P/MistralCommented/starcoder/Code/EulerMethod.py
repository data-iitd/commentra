
import math
import sys

# Initializing the scanner for user input
scanner = sys.stdin

# Starting point of the main method
def main():
    # Reading user input for the initial conditions and equation choice
    xStart = float(scanner.readline())
    xEnd = float(scanner.readline())
    stepSize = float(scanner.readline())
    yStart = float(scanner.readline())
    equationChoice = int(scanner.readline())

    # Assigning the differential equation based on the user's choice
    differentialEquation = None
    if equationChoice == 1:
        differentialEquation = lambda x, y: x
    elif equationChoice == 2:
        differentialEquation = lambda x, y: y
    elif equationChoice == 3:
        differentialEquation = lambda x, y: x + y + x * y
    else:
        raise Exception("Invalid choice of differential equation")

    # Calculating the points using the Euler method
    points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation)

    # Printing the results
    print("Results:")
    for point in points:
        print("x: " + str(point[0]) + "; y: " + str(point[1]))

# Euler step method for calculating the next point
def eulerStep(xCurrent, stepSize, yCurrent, differentialEquation):
    if stepSize <= 0: # Checking if the step size is valid
        raise Exception("stepSize should be greater than zero")
    return yCurrent + stepSize * differentialEquation(xCurrent, yCurrent) # Calculating the next y value using the Euler method

# Euler Full method for calculating all the points
def eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation):
    if xStart >= xEnd: # Checking if xEnd is greater than xStart
        raise Exception("xEnd should be greater than xStart")
    if stepSize <= 0: # Checking if the step size is valid
        raise Exception("stepSize should be greater than zero")

    # Initializing an empty list to store the points
    points = []

    # Adding the initial point to the list
    points.append([xStart, yStart])

    yCurrent = yStart # Initializing the current y value
    xCurrent = xStart # Initializing the current x value

    # Calculating all the remaining points using the Euler method
    while xCurrent < xEnd:
        yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation)
        xCurrent += stepSize
        points.append([xCurrent, yCurrent])

    # Returning the list of points
    return points

# Starting point of the program
if __name__ == "__main__":
    main()

# 