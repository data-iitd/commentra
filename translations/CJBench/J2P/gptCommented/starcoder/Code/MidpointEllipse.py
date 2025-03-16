import sys

# Private constructor to prevent instantiation
class Main:
    def __init__(self):
        pass

    def main(self):
        # Create a Scanner object to read input from the user
        scanner = sys.stdin

        # Read the center coordinates and the semi-major and semi-minor axes of the ellipse
        centerX = int(scanner.readline())
        centerY = int(scanner.readline())
        a = int(scanner.readline())
        b = int(scanner.readline())

        # Generate the points of the ellipse based on the input parameters
        points = drawEllipse(centerX, centerY, a, b)

        # Output the generated points of the ellipse
        print("Ellipse Points:")
        for point in points:
            print(point[0], point[1])

        # Close the scanner to prevent resource leaks
        scanner.close()

    def drawEllipse(self, centerX, centerY, a, b):
        # Initialize a list to hold the points of the ellipse
        points = []

        # Handle the case where both axes are zero (point case)
        if a == 0 and b == 0:
            points.append([centerX, centerY])
            return points

        # Handle the case where the semi-major axis is zero (vertical line)
        if a == 0:
            for y in range(centerY - b, centerY + b + 1):
                points.append([centerX, y])
            return points

        # Handle the case where the semi-minor axis is zero (horizontal line)
        if b == 0:
            for x in range(centerX - a, centerX + a + 1):
                points.append([x, centerY])
            return points

        # Compute the points of the ellipse using the midpoint ellipse algorithm
        computeEllipsePoints(points, centerX, centerY, a, b)
        return points

    def computeEllipsePoints(self, points, centerX, centerY, a, b):
        # Initialize variables for the ellipse drawing algorithm
        x = 0
        y = b
        d1 = b * b - a * a * b + 0.25 * a * a
        dx = 2 * b * b * x
        dy = 2 * a * a * y

        # First region of the ellipse (x < y)
        while dx < dy:
            # Add the calculated points to the collection
            addEllipsePoints(points, centerX, centerY, x, y)
            if d1 < 0:
                # Move to the next point in the x direction
                x += 1
                dx += 2 * b * b
                d1 += dx + b * b
            else:
                # Move to the next point in both x and y directions
                x += 1
                y -= 1
                dx += 2 * b * b
                dy -= 2 * a * a
                d1 += dx - dy + b * b

        # Second region of the ellipse (y < x)
        d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b
        while y >= 0:
            # Add the calculated points to the collection
            addEllipsePoints(points, centerX, centerY, x, y)
            if d2 > 0:
                # Move to the next point in the y direction
                y -= 1
                dy -= 2 * a * a
                d2 += a * a - dy
            else:
                # Move to the next point in both x and y directions
                y -= 1
                x += 1
                dx += 2 * b * b
                dy -= 2 * a * a
                d2 += dx - dy + a * a

    def addEllipsePoints(self, points, centerX, centerY, x, y):
        # Add symmetrical points of the ellipse to the collection
        points.append([centerX + x, centerY + y])
        points.append([centerX - x, centerY + y])
        points.append([centerX + x, centerY - y])
        points.append([centerX - x, centerY - y])

# Main execution
if __name__ == "__main__":
    Main().main()

# 