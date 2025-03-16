
import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.x < other.x or (self.x == other.x and self.y < other.y)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))

    def __str__(self):
        return "(%d, %d)" % (self.x, self.y)

def orientation(i, j, k):
    return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

def convexHullBruteForce(points):
    convexSet = set()

    for i in range(len(points) - 1):
        for j in range(i + 1, len(points)):
            allPointsOnOneSide = True
            leftSide = orientation(points[i], points[j], points[(i + 1) % len(points)])

            for k in range(len(points)):
                if k!= i and k!= j and orientation(points[i], points[j], points[k])!= leftSide:
                    allPointsOnOneSide = False
                    break

            if allPointsOnOneSide:
                convexSet.add(points[i])
                convexSet.add(points[j])

    return sorted(convexSet)

def convexHullRecursive(points):
    points.sort()
    convexSet = set()
    leftMostPoint = points[0]
    rightMostPoint = points[-1]

    convexSet.add(leftMostPoint)
    convexSet.add(rightMostPoint)

    upperHull = []
    lowerHull = []

    for i in range(1, len(points) - 1):
        det = orientation(leftMostPoint, rightMostPoint, points[i])
        if det > 0:
            upperHull.append(points[i])
        elif det < 0:
            lowerHull.append(points[i])

    constructHull(upperHull, leftMostPoint, rightMostPoint, convexSet)
    constructHull(lowerHull, rightMostPoint, leftMostPoint, convexSet)

    return sorted(convexSet)

def constructHull(points, left, right, convexSet):
    if points:
        extremePoint = None
        extremePointDistance = -sys.maxsize
        candidatePoints = []

        for p in points:
            det = orientation(left, right, p)
            if det > 0:
                candidatePoints.append(p)
                if det > extremePointDistance:
                    extremePointDistance = det
                    extremePoint = p

        if extremePoint:
            constructHull(candidatePoints, left, extremePoint, convexSet)
            convexSet.add(extremePoint)
            constructHull(candidatePoints, extremePoint, right, convexSet)

if __name__ == "__main__":
    n = int(input())
    points = []
    for i in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))

    convexHullBruteForce = convexHullBruteForce(points)
    print("Convex Hull (Brute Force):")
    for p in convexHullBruteForce:
        print(p)

    convexHullRecursive = convexHullRecursive(points)
    print("Convex Hull (Recursive):")
    for p in convexHullRecursive:
        print(p)

