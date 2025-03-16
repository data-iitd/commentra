
import sys

def generateCirclePoints(centerX, centerY, radius):
    points = [] # Initialize an empty list to store the circle points

    if radius == 0: # Check if the radius is zero
        points.append([centerX, centerY]) # Add the center point to the list if the radius is zero
        return points # Return the list with the center point

    x = radius # Initialize x and y variables for calculating the circle points
    y = 0
    p = 1 - radius # Initialize the decision variable p

    addSymmetricPoints(points, centerX, centerY, x, y) # Add the first four symmetric points to the list

    while x > y: # Iterate while x is greater than y
        y += 1 # Increment y

        if p <= 0: # Check the condition for the decision variable p
            p = p + 2 * y + 1 # Update the value of p
        else: # If the condition is not met, update x and p
            x -= 1
            p = p + 2 * y - 2 * x + 1

        addSymmetricPoints(points, centerX, centerY, x, y) # Add the next four symmetric points to the list

    return points # Return the list of circle points

def addSymmetricPoints(points, centerX, centerY, x, y):
    # Add the eight symmetric points to the list
    points.append([centerX + x, centerY + y])
    points.append([centerX - x, centerY + y])
    points.append([centerX + x, centerY - y])
    points.append([centerX - x, centerY - y])
    points.append([centerX + y, centerY + x])
    points.append([centerX - y, centerY + x])
    points.append([centerX + y, centerY - x])
    points.append([centerX - y, centerY - x])

if __name__ == '__main__':
    try:
        centerX = int(input()) # Read the center x-coordinate from the user
        centerY = int(input()) # Read the center y-coordinate from the user
        radius = int(input()) # Read the radius from the user

        circlePoints = generateCirclePoints(centerX, centerY, radius) # Generate the circle points

        print("The points on the circumference of the circle are:") # Print a message to the console
        for point in circlePoints: # Iterate through the list of circle points
            print("({}, {})".format(point[0], point[1])) # Print each point to the console
    except Exception as e:
        print("Invalid input! Please enter integers.", file=sys.stderr) # Print an error message if the user enters invalid input

