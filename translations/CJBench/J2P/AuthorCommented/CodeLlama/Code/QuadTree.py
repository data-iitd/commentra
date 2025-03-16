

import math


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class BoundingBox:
    def __init__(self, center, halfWidth):
        self.center = center
        self.halfWidth = halfWidth

    def containsPoint(self, point):
        return point.x >= self.center.x - self.halfWidth and point.x <= self.center.x + self.halfWidth and point.y >= self.center.y - self.halfWidth and point.y <= self.center.y + self.halfWidth

    def intersectsBoundingBox(self, otherBoundingBox):
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= self.center.x + self.halfWidth and otherBoundingBox.center.x + otherBoundingBox.halfWidth >= self.center.x - self.halfWidth and otherBoundingBox.center.y - otherBoundingBox.halfWidth <= self.center.y + self.halfWidth and otherBoundingBox.center.y + otherBoundingBox.halfWidth >= self.center.y - self.halfWidth


class Main:
    def __init__(self, boundary, capacity):
        self.boundary = boundary
        self.capacity = capacity

        self.pointList = []
        self.divided = False
        self.northWest = None
        self.northEast = None
        self.southWest = None
        self.southEast = None

    def insert(self, point):
        if point is None:
            return False

        # Ignore points that don't belong to this quad tree
        if not self.boundary.containsPoint(point):
            return False

        # if the space is not already occupied, add it to the list
        if len(self.pointList) < self.capacity:
            self.pointList.append(point)
            return True

        # if subdivision hasn't happened, divide the tree
        if not self.divided:
            self.subDivide()

        # try to add the point in one of the four quadrants
        if self.northWest.insert(point):
            return True

        if self.northEast.insert(point):
            return True

        if self.southWest.insert(point):
            return True

        if self.southEast.insert(point):
            return True

        return False

    def subDivide(self):
        quadrantHalfWidth = self.boundary.halfWidth / 2

        self.northWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.northEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.divided = True

    def query(self, otherBoundingBox):
        points = []

        if not self.boundary.intersectsBoundingBox(otherBoundingBox):
            return points

        points.extend(list(filter(otherBoundingBox.containsPoint, self.pointList)))

        if self.divided:
            points.extend(self.northWest.query(otherBoundingBox))
            points.extend(self.northEast.query(otherBoundingBox))
            points.extend(self.southWest.query(otherBoundingBox))
            points.extend(self.southEast.query(otherBoundingBox))

        return points


if __name__ == "__main__":
    # Input: Boundary and capacity
    centerX = float(input())
    centerY = float(input())
    halfWidth = float(input())
    capacity = int(input())

    boundary = BoundingBox(Point(centerX, centerY), halfWidth)
    quadTree = Main(boundary, capacity)

    # Input: Number of points
    numPoints = int(input())
    for i in range(numPoints):
        x = float(input())
        y = float(input())
        quadTree.insert(Point(x, y))

    # Input: Query bounding box
    queryCenterX = float(input())
    queryCenterY = float(input())
    queryHalfWidth = float(input())

    queryBox = BoundingBox(Point(queryCenterX, queryCenterY), queryHalfWidth)
    result = quadTree.query(queryBox)

    # Output: Points in query range
    print("Points in range:")
    for point in result:
        print(point.x, point.y)

    # 