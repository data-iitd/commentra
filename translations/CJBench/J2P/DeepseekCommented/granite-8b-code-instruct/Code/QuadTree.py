
import math

# Represents a point in a 2D space with x and y coordinates.
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Represents a bounding box with a center point and a half-width.
class BoundingBox:
    def __init__(self, center, halfWidth):
        self.center = center
        self.halfWidth = halfWidth

    # Checks if a point is contained within the bounding box.
    def containsPoint(self, point):
        return point.x >= self.center.x - self.halfWidth and point.x <= self.center.x + self.halfWidth and point.y >= self.center.y - self.halfWidth and point.y <= self.center.y + self.halfWidth

    # Checks if the bounding box intersects with another bounding box.
    def intersectsBoundingBox(self, otherBoundingBox):
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= self.center.x + self.halfWidth and otherBoundingBox.center.x + otherBoundingBox.halfWidth >= self.center.x - self.halfWidth and otherBoundingBox.center.y - otherBoundingBox.halfWidth <= self.center.y + self.halfWidth and otherBoundingBox.center.y + otherBoundingBox.halfWidth >= self.center.y - self.halfWidth

# Represents the quadtree data structure.
class Main:
    def __init__(self, boundary, capacity):
        self.boundary = boundary
        self.capacity = capacity
        self.pointList = [] # List to store points in the current node.
        self.divided = False # Flag to check if the quadtree is divided.
        self.northWest = None # Reference to the north-west child quadtree.
        self.northEast = None # Reference to the north-east child quadtree.
        self.southWest = None # Reference to the south-west child quadtree.
        self.southEast = None # Reference to the south-east child quadtree.

    # Inserts a point into the quadtree.
    def insert(self, point):
        if point is None:
            return False
        if not self.boundary.containsPoint(point):
            return False
        if len(self.pointList) < self.capacity:
            self.pointList.append(point)
            return True
        if not self.divided:
            self.subDivide()
        if self.northWest.insert(point):
            return True
        if self.northEast.insert(point):
            return True
        if self.southWest.insert(point):
            return True
        if self.southEast.insert(point):
            return True
        return False

    # Subdivides the quadtree into four child quadtrees.
    def subDivide(self):
        quadrantHalfWidth = self.boundary.halfWidth / 2
        self.northWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.northEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.divided = True

    # Returns a list of points within a given bounding box.
    def query(self, otherBoundingBox):
        points = []
        if not self.boundary.intersectsBoundingBox(otherBoundingBox):
            return points
        points.extend(filter(lambda point: otherBoundingBox.containsPoint(point), self.pointList))
        if self.divided:
            points.extend(self.northWest.query(otherBoundingBox))
            points.extend(self.northEast.query(otherBoundingBox))
            points.extend(self.southWest.query(otherBoundingBox))
            points.extend(self.southEast.query(otherBoundingBox))
        return points

    # Main method to read input, insert points, and query for points within a bounding box.
    def main():
        centerX, centerY, halfWidth, capacity = map(float, input().split())
        boundary = BoundingBox(Point(centerX, centerY), halfWidth)
        quadTree = Main(boundary, capacity)
        numPoints = int(input())
        for _ in range(numPoints):
            x, y = map(float, input().split())
            quadTree.insert(Point(x, y))
        queryCenterX, queryCenterY, queryHalfWidth = map(float, input().split())
        queryBox = BoundingBox(Point(queryCenterX, queryCenterY), queryHalfWidth)
        result = quadTree.query(queryBox)
        print("Points in range:")
        for point in result:
            print(point.x, point.y)

if __name__ == "__main__":
    Main.main()

