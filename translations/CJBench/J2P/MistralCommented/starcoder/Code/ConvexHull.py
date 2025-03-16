
import sys

class Main:
    def __init__(self):
        pass

    def main(self):
        input = sys.stdin.read().splitlines()
        n = int(input[0])
        points = []
        for i in range(1, n + 1):
            x, y = map(int, input[i].split())
            points.append(Point(x, y))
        bruteForceHull = convexHullBruteForce(points)
        print("Convex Hull (Brute Force):")
        for p in bruteForceHull:
            print(p.x, p.y)
        recursiveHull = convexHullRecursive(points)
        print("Convex Hull (Recursive):")
        for p in recursiveHull:
            print(p.x, p.y)

    def convexHullBruteForce(self, points):
        convexSet = set()
        for i in range(len(points) - 1):
            for j in range(i + 1, len(points)):
                allPointsOnOneSide = True
                leftSide = self.checkPointOrientation(points[i], points[j], points[(i + 1) % len(points)])
                for k in range(len(points)):
                    if k!= i and k!= j and self.checkPointOrientation(points[i], points[j], points[k])!= leftSide:
                        allPointsOnOneSide = False
                        break
                if allPointsOnOneSide:
                    convexSet.add(points[i])
                    convexSet.add(points[j])
        return list(convexSet)

    def convexHullRecursive(self, points):
        points.sort()
        convexSet = set()
        leftMostPoint = points[0]
        rightMostPoint = points[-1]
        convexSet.add(leftMostPoint)
        convexSet.add(rightMostPoint)
        upperHull = []
        lowerHull = []
        for i in range(1, len(points) - 1):
            det = self.checkPointOrientation(leftMostPoint, rightMostPoint, points[i])
            if det > 0:
                upperHull.append(points[i])
            elif det < 0:
                lowerHull.append(points[i])
        self.constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet)
        self.constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet)
        result = list(convexSet)
        result.sort()
        return result

    def constructHull(self, points, left, right, convexSet):
        if len(points) > 0:
            extremePoint = None
            extremePointDistance = -1
            for p in points:
                det = self.checkPointOrientation(left, right, p)
                if det > 0:
                    if det > extremePointDistance:
                        extremePointDistance = det
                        extremePoint = p
                elif det < 0:
                    if det < extremePointDistance:
                        extremePointDistance = det
                        extremePoint = p
            if extremePoint!= None:
                self.constructHull(points, left, extremePoint, convexSet)
                convexSet.add(extremePoint)
                self.constructHull(points, extremePoint, right, convexSet)

    def checkPointOrientation(self, i, j, k):
        return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return (self.x == other.x) and (self.y < other.y)

    def __gt__(self, other):
        return (self.x == other.x) and (self.y > other.y)

    def __eq__(self, other):
        return (self.x == other.x) and (self.y == other.y)

    def __le__(self, other):
        return (self.x == other.x) and (self.y <= other.y)

    def __ge__(self, other):
        return (self.x == other.x) and (self.y >= other.y)

    def __ne__(self, other):
        return (self.x == other.x) and (self.y!= other.y)

if __name__ == "__main__":
    main = Main()
    main.main()

