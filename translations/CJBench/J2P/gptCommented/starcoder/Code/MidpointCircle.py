import sys

# Class to represent a point on the circumference of a circle
class Point:
    # Constructor to initialize the point
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Method to generate points on the circumference of a circle
def generateCirclePoints(centerX, centerY, radius):
    # List to hold the points on the circle
    points = []
    
    # If the radius is zero, return the center point
    if radius == 0:
        points.append(Point(centerX, centerY))
        return points
    
    # Initialize variables for the circle drawing algorithm
    x = radius # Start with the radius on the x-axis
    y = 0      # Start with y at 0
    p = 1 - radius # Decision parameter for the circle drawing algorithm
    
    # Add initial symmetric points for the circle
    addSymmetricPoints(points, centerX, centerY, x, y)
    
    # Loop to calculate points using Bresenham's circle algorithm
    while x > y:
        y += 1 # Increment y coordinate
        
        # Update the decision parameter based on its value
        if p <= 0:
            p = p + 2 * y + 1 # Inside the circle
        else:
            x -= 1 # Move left in the x direction
            p = p + 2 * y - 2 * x + 1 # Outside the circle
        
        # Add symmetric points for the current (x, y)
        addSymmetricPoints(points, centerX, centerY, x, y)
    
    # Return the list of points on the circle
    return points

# Method to add symmetric points for the circle based on the current (x, y)
def addSymmetricPoints(points, centerX, centerY, x, y):
    # Add all eight symmetric points of the circle
    points.append(Point(centerX + x, centerY + y))
    points.append(Point(centerX - x, centerY + y))
    points.append(Point(centerX + x, centerY - y))
    points.append(Point(centerX - x, centerY - y))
    points.append(Point(centerX + y, centerY + x))
    points.append(Point(centerX - y, centerY + x))
    points.append(Point(centerX + y, centerY - x))
    points.append(Point(centerX - y, centerY - x))

# Main method to execute the program
def main():
    # Read the center coordinates and radius from user input
    centerX = int(input("Enter the center x-coordinate: "))
    centerY = int(input("Enter the center y-coordinate: "))
    radius = int(input("Enter the radius: "))
    
    # Generate the points on the circle
    circlePoints = generateCirclePoints(centerX, centerY, radius)
    print("The points on the circumference of the circle are:")
    
    # Print each point on the circle
    for point in circlePoints:
        print("({0}, {1})".format(point.x, point.y))

# Entry point of the program
if __name__ == "__main__":
    main()

# 