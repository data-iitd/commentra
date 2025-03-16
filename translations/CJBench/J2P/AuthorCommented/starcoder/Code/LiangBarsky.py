
import sys

# Define the clipping window
xMin = float(sys.argv[1])
yMin = float(sys.argv[2])
xMax = float(sys.argv[3])
yMax = float(sys.argv[4])

# Input line coordinates
x1 = float(sys.argv[5])
y1 = float(sys.argv[6])
x2 = float(sys.argv[7])
y2 = float(sys.argv[8])

# Define the clipping window
class Main:
    def __init__(self, xMin, yMin, xMax, yMax):
        self.xMin = xMin
        self.yMin = yMin
        self.xMax = xMax
        self.yMax = yMax

    def liangBarskyClip(self, x1, y1, x2, y2):
        dx = x2 - x1
        dy = y2 - y1

        p = [-dx, dx, -dy, dy]
        q = [x1 - self.xMin, self.xMax - x1, y1 - self.yMin, self.yMax - y1]

        resultT = self.clipLine(p, q)

        if resultT == None:
            return None # Line is completely outside the clipping window

        return self.calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1])

    # clip the line by adjusting t0 and t1 for each edge
    def clipLine(self, p, q):
        t0 = 0.0
        t1 = 1.0

        for i in range(4):
            if p[i] == 0 and q[i] < 0:
                return None # Line is outside the boundary

            t = q[i] / p[i]
            if p[i] < 0:
                t0 = max(t0, t)
                if t0 > t1: return None
            elif p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0: return None

        return [t0, t1] # Return valid t0 and t1

    # calculate the clipped line based on t0 and t1
    def calculateClippedLine(self, x1, y1, dx, dy, t0, t1):
        clippedX1 = x1 + t0 * dx
        clippedY1 = y1 + t0 * dy
        clippedX2 = x1 + t1 * dx
        clippedY2 = y1 + t1 * dy

        return [clippedX1, clippedY1, clippedX2, clippedY2]

clipper = Main(xMin, yMin, xMax, yMax)
clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2)

if clippedLine!= None:
    print("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)" % (clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]))
else:
    print("The line is completely outside the clipping window.")

# 