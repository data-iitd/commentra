import sys

class Main:
    # Define the boundaries of the clipping window
    xMin = 0.0
    yMin = 0.0
    xMax = 0.0
    yMax = 0.0

    # Constructor to initialize the clipping window boundaries
    def __init__(self, xMin, yMin, xMax, yMax):
        self.xMin = xMin
        self.yMin = yMin
        self.xMax = xMax
        self.yMax = yMax

    # Method to perform Liang-Barsky line clipping algorithm
    def liangBarskyClip(self, x1, y1, x2, y2):
        # Calculate the differences in x and y coordinates
        dx = x2 - x1
        dy = y2 - y1

        # Define the parameters for the Liang-Barsky algorithm
        p = [-dx, dx, -dy, dy]
        q = [x1 - self.xMin, self.xMax - x1, y1 - self.yMin, self.yMax - y1]

        # Call the clipping function to get the parameter values
        resultT = self.clipLine(p, q)
        
        # If the line is completely outside the clipping window, return null
        if resultT == None:
            return None
        
        # Calculate the coordinates of the clipped line segment
        return self.calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1])

    # Method to clip the line using the Liang-Barsky algorithm
    def clipLine(self, p, q):
        t0 = 0.0 # Start parameter
        t1 = 1.0 # End parameter

        # Iterate over each of the four edges of the clipping window
        for i in range(0, 4):
            # Check for parallel lines outside the clipping window
            if p[i] == 0 and q[i] < 0:
                return None
            t = q[i] / p[i] # Calculate the intersection parameter

            # Update t0 and t1 based on the direction of the line
            if p[i] < 0:
                t0 = max(t0, t) # Update t0 for negative p
                if t0 > t1: return None # No intersection
            elif p[i] > 0:
                t1 = min(t1, t) # Update t1 for positive p
                if t1 < t0: return None # No intersection

        # Return the final parameter values for the clipped line
        return [t0, t1] 

    # Method to calculate the coordinates of the clipped line segment
    def calculateClippedLine(self, x1, y1, dx, dy, t0, t1):
        # Calculate the start and end points of the clipped line
        clippedX1 = x1 + t0 * dx
        clippedY1 = y1 + t0 * dy
        clippedX2 = x1 + t1 * dx
        clippedY2 = y1 + t1 * dy

        # Return the coordinates of the clipped line segment
        return [clippedX1, clippedY1, clippedX2, clippedY2]

# Main method to execute the program
if __name__ == "__main__":
    # Read the clipping window boundaries from user input
    xMin = float(sys.stdin.readline().strip())
    yMin = float(sys.stdin.readline().strip())
    xMax = float(sys.stdin.readline().strip())
    yMax = float(sys.stdin.readline().strip())
    
    # Read the coordinates of the line segment to be clipped
    x1 = float(sys.stdin.readline().strip())
    y1 = float(sys.stdin.readline().strip())
    x2 = float(sys.stdin.readline().strip())
    y2 = float(sys.stdin.readline().strip())
    
    # Create an instance of the Main class with the clipping window
    clipper = Main(xMin, yMin, xMax, yMax)
    
    # Perform the clipping operation
    clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2)
    
    # Output the result of the clipping operation
    if clippedLine!= None:
        print("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)" % (clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]))
    else:
        print("The line is completely outside the clipping window.")

