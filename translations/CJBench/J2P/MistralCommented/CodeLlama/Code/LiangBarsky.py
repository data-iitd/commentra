
import math

class Main:
    # Declare private instance variables for the clipping window bounds
    xMin = 0.0
    yMin = 0.0
    xMax = 0.0
    yMax = 0.0

    # Constructor initializes the clipping window bounds
    def __init__(self, xMin, yMin, xMax, yMax):
        self.xMin = xMin
        self.yMin = yMin
        self.xMax = xMax
        self.yMax = yMax

    # Method to clip a line using the Liang-Barsky algorithm
    def liangBarskyClip(self, x1, y1, x2, y2):
        # Calculate the direction vector and the difference vector between the endpoints of the line
        dx = x2 - x1
        dy = y2 - y1
        p = [-dx, dx, -dy, dy] # The direction vector
        q = [x1 - self.xMin, self.xMax - x1, y1 - self.yMin, self.yMax - y1] # The vector from the origin to the line endpoints

        # Clip the line against the clipping window boundaries
        resultT = self.clipLine(p, q)

        # If the line is completely outside the clipping window, return null
        if resultT is None:
            return None

        # Calculate the clipped line endpoints
        return self.calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1])

    # Method to clip a line against the clipping window boundaries
    def clipLine(self, p, q):
        # Initialize the t0 and t1 variables to represent the clipped line endpoints
        t0 = 0.0
        t1 = 1.0

        # Iterate through each boundary plane and check for intersection
        for i in range(4):
            # If the direction vector is parallel to the boundary plane, return null
            if p[i] == 0:
                if q[i] < 0:
                    # The line starts inside the clipping window, so no clipping is needed
                    return [t0, t1]
                return None # The line is completely outside the clipping window

            # Calculate the intersection point t of the line with the boundary plane
            t = q[i] / p[i]

            # If the line starts before the boundary plane, update t0
            if p[i] < 0:
                t0 = max(t0, t)
                if t0 > t1: return None # The line is completely clipped

            # If the line ends after the boundary plane, update t1
            else if p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0: return None # The line is completely clipped

        # If the line is completely clipped, return null
        if t1 < 0:
            return None

        # Otherwise, return the clipped line endpoints
        return [t0, t1]

    # Method to calculate the clipped line endpoints
    def calculateClippedLine(self, x1, y1, dx, dy, t0, t1):
        # Calculate the clipped line endpoints
        clippedX1 = x1 + t0 * dx
        clippedY1 = y1 + t0 * dy
        clippedX2 = x1 + t1 * dx
        clippedY2 = y1 + t1 * dy

        # Return the clipped line endpoints as an array
        return [clippedX1, clippedY1, clippedX2, clippedY2]

# Main method to read input and test the clipping algorithm
def main():
    # Initialize a Scanner to read input from the standard input
    scanner = input()

    # Read the clipping window bounds from the standard input
    xMin = scanner.nextDouble()
    yMin = scanner.nextDouble()
    xMax = scanner.nextDouble()
    yMax = scanner.nextDouble()

    # Read the line endpoints from the standard input
    x1 = scanner.nextDouble()
    y1 = scanner.nextDouble()
    x2 = scanner.nextDouble()
    y2 = scanner.nextDouble()

    # Create a Main object with the clipping window bounds
    clipper = Main(xMin, yMin, xMax, yMax)

    # Clip the line using the Liang-Barsky algorithm and print the result
    clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2)
    if clippedLine is not None:
        print("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)" % (clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]))
    else:
        print("The line is completely outside the clipping window.")

    # Close the Scanner to free system resources
    scanner.close()

if __name__ == "__main__":
    main()

