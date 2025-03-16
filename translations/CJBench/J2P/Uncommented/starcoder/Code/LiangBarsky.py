
import sys
import math

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
            return None
        return self.calculateClippedLine(x1, y1, dx, dy, resultT[0], resultT[1])

    def clipLine(self, p, q):
        t0 = 0.0
        t1 = 1.0
        for i in range(4):
            if p[i] == 0 and q[i] < 0:
                return None
            t = q[i] / p[i]
            if p[i] < 0:
                t0 = max(t0, t)
                if t0 > t1: return None
            elif p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0: return None
        return [t0, t1]

    def calculateClippedLine(self, x1, y1, dx, dy, t0, t1):
        clippedX1 = x1 + t0 * dx
        clippedY1 = y1 + t0 * dy
        clippedX2 = x1 + t1 * dx
        clippedY2 = y1 + t1 * dy
        return [clippedX1, clippedY1, clippedX2, clippedY2]

if __name__ == "__main__":
    xMin = float(sys.stdin.readline())
    yMin = float(sys.stdin.readline())
    xMax = float(sys.stdin.readline())
    yMax = float(sys.stdin.readline())
    x1 = float(sys.stdin.readline())
    y1 = float(sys.stdin.readline())
    x2 = float(sys.stdin.readline())
    y2 = float(sys.stdin.readline())
    clipper = Main(xMin, yMin, xMax, yMax)
    clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2)
    if clippedLine!= None:
        print("Clipped Line: (%.2f, %.2f) to (%.2f, %.2f)" % (clippedLine[0], clippedLine[1], clippedLine[2], clippedLine[3]))
    else:
        print("The line is completely outside the clipping window.")

