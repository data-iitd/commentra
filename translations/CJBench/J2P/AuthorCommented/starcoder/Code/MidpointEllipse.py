
import sys

# The Main class implements the Midpoint Ellipse Drawing Algorithm.
# This algorithm efficiently computes the points on an ellipse by dividing it into two regions
# and using decision parameters to determine the next point to plot.
class Main:

    def __init__(self):
        # Prevent instantiation
        pass

    # Main method to take input and display the ellipse points.
    def main(self):
        # Input center coordinates, semi-major axis (a), and semi-minor axis (b)
        centerX = int(sys.stdin.readline())
        centerY = int(sys.stdin.readline())
        a = int(sys.stdin.readline())
        b = int(sys.stdin.readline())

        # Calculate and output ellipse points
        points = drawEllipse(centerX, centerY, a, b)
        print("Ellipse Points:")
        for point in points:
            print(point[0], point[1])

    # Draws an ellipse using the Midpoint Ellipse Algorithm.
    #
    # @param centerX the x-coordinate of the center of the ellipse
    # @param centerY the y-coordinate of the center of the ellipse
    # @param a the length of the semi-major axis (horizontal radius)
    # @param b the length of the semi-minor axis (vertical radius)
    # @return a list of points (represented as int arrays) that form the ellipse
    def drawEllipse(self, centerX, centerY, a, b):
        points = []

        # Handle degenerate cases
        if a == 0 and b == 0:
            points.append([centerX, centerY])
            return points
        if a == 0:
            for y in range(centerY - b, centerY + b + 1):
                points.append([centerX, y])
            return points
        if b == 0:
            for x in range(centerX - a, centerX + a + 1):
                points.append([x, centerY])
            return points

        computeEllipsePoints(points, centerX, centerY, a, b)
        return points

    # Computes points of a non-degenerate ellipse using the Midpoint Ellipse Algorithm.
    #
    # @param points    the list to which points will be added
    # @param centerX  the x-coordinate of the center of the ellipse
    # @param centerY  the y-coordinate of the center of the ellipse
    # @param a        the length of the semi-major axis (horizontal radius)
    # @param b        the length of the semi-minor axis (vertical radius)
    def computeEllipsePoints(self, points, centerX, centerY, a, b):
        x = 0
        y = b

        # Region 1: Initial decision parameter
        d1 = b * b - a * a * b + 0.25 * a * a
        dx = 2 * b * b * x
        dy = 2 * a * a * y

        # Region 1
        while dx < dy:
            self.addEllipsePoints(points, centerX, centerY, x, y)
            if d1 < 0:
                x += 1
                dx += 2 * b * b
                d1 += dx + b * b
            else:
                x += 1
                y -= 1
                dx += 2 * b * b
                dy -= 2 * a * a
                d1 += dx - dy + b * b

        # Region 2
        d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b
        while y >= 0:
            self.addEllipsePoints(points, centerX, centerY, x, y)
            if d2 > 0:
                y -= 1
                dy -= 2 * a * a
                d2 += a * a - dy
            else:
                y -= 1
                x += 1
                dx += 2 * b * b
                dy -= 2 * a * a
                d2 += dx - dy + a * a

    # Adds points for all four quadrants of the ellipse based on symmetry.
    #
    # @param points    the list to which points will be added
    # @param centerX  the x-coordinate of the center of the ellipse
    # @param centerY  the y-coordinate of the center of the ellipse
    # @param x        the x-coordinate relative to the center
    # @param y        the y-coordinate relative to the center
    def addEllipsePoints(self, points, centerX, centerY, x, y):
        points.append([centerX + x, centerY + y])
        points.append([centerX - x, centerY + y])
        points.append([centerX + x, centerY - y])
        points.append([centerX - x, centerY - y])

# 