import math
import sys

# Main entry point of the program
def main():
    # Initialize scanner to read input
    scanner = sys.stdin
    # Read initial and final values of x, step size, initial value of y, and equation choice
    xStart = float(scanner.readline())
    xEnd = float(scanner.readline())
    stepSize = float(scanner.readline())
    yStart = float(scanner.readline())
    equationChoice = int(scanner.readline())
    # Initialize the differential equation based on user choice
    differentialEquation = None
    if equationChoice == 1:
        differentialEquation = lambda x, y: x
    elif equationChoice == 2:
        differentialEquation = lambda x, y: y
    elif equationChoice == 3:
        differentialEquation = lambda x, y: x + y + x * y
    else:
        raise ValueError("Invalid choice of differential equation")
    # Compute the points using Euler's method
    points = eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation)
    # Print the results
    print("Results:")
    for point in points:
        print("x: {0}; y: {1}".format(point[0], point[1]))

# Computes the next y value using Euler's method
def eulerStep(xCurrent, stepSize, yCurrent, differentialEquation):
    if stepSize <= 0:
        raise ValueError("stepSize should be greater than zero")
    return yCurrent + stepSize * differentialEquation(xCurrent, yCurrent)

# Computes all points using Euler's method from xStart to xEnd
def eulerFull(xStart, xEnd, stepSize, yStart, differentialEquation):
    if xStart >= xEnd:
        raise ValueError("xEnd should be greater than xStart")
    if stepSize <= 0:
        raise ValueError("stepSize should be greater than zero")
    # Initialize the list to store points
    points = []
    # Add the initial point
    points.append([xStart, yStart])
    yCurrent = yStart
    xCurrent = xStart
    # Iterate through the range to compute points
    while xCurrent < xEnd:
        yCurrent = eulerStep(xCurrent, stepSize, yCurrent, differentialEquation)
        xCurrent += stepSize
        points.append([xCurrent, yCurrent])
    return points

# Main entry point of the program
if __name__ == "__main__":
    main()

# 