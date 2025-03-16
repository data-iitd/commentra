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
        if resultT is None:
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
                if t0 > t1:
                    return None
            elif p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0:
                    return None
        return [t0, t1]

    def calculateClippedLine(self, x1, y1, dx, dy, t0, t1):
        clippedX1 = x1 + t0 * dx
        clippedY1 = y1 + t0 * dy
        clippedX2 = x1 + t1 * dx
        clippedY2 = y1 + t1 * dy
        return [clippedX1, clippedY1, clippedX2, clippedY2]


def main():
    xMin = float(input())
    yMin = float(input())
    xMax = float(input())
    yMax = float(input())
    x1 = float(input())
    y1 = float(input())
    x2 = float(input())
    y2 = float(input())
    clipper = Main(xMin, yMin, xMax, yMax)
    clippedLine = clipper.liangBarskyClip(x1, y1, x2, y2)
    if clippedLine is not None:
        print(f"Clipped Line: ({clippedLine[0]:.2f}, {clippedLine[1]:.2f}) to ({clippedLine[2]:.2f}, {clippedLine[3]:.2f})")
    else:
        print("The line is completely outside the clipping window.")


main()
