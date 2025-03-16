
import math

# Class representing a point in 2D space
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Class representing a bounding box defined by a center point and half width
class BoundingBox:
    def __init__(self, center, halfWidth):
        self.center = center
        self.halfWidth = halfWidth

    # Method to check if a point is contained within the bounding box
    def containsPoint(self, point):
        return point.x >= self.center.x - self.halfWidth and point.x <= self.center.x + self.halfWidth and \
               point.y >= self.center.y - self.halfWidth and point.y <= self.center.y + self.halfWidth

    # Method to check if this bounding box intersects with another bounding box
    def intersectsBoundingBox(self, otherBoundingBox):
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= self.center.x + self.halfWidth and \
               otherBoundingBox.center.x + otherBoundingBox.halfWidth >= self.center.x - self.halfWidth and \
               otherBoundingBox.center.y - otherBoundingBox.halfWidth <= self.center.y + self.halfWidth and \
               otherBoundingBox.center.y + otherBoundingBox.halfWidth >= self.center.y - self.halfWidth

# Main class representing a quadtree structure
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

    # Method to insert a point into the quadtree
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
        if self.northWest.insert(point) or self.northEast.insert(point) or self.southWest.insert(point) or self.southEast.insert(point):
            return True
        return False

    # Method to subdivide the current node into four child nodes
    def subDivide(self):
        quadrantHalfWidth = self.boundary.halfWidth / 2
        self.northWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.northEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.divided = True

    # Method to query points within a given bounding box
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

# Main method to run the program
def main():
    # Read the center coordinates and half width for the bounding box
    centerX = float(input())
    centerY = float(input())
    halfWidth = float(input())
    capacity = int(input())

    # Create the bounding box and the quadtree
    boundary = BoundingBox(Point(centerX, centerY), halfWidth)
    quadTree = Main(boundary, capacity)

    # Read the number of points to insert into the quadtree
    numPoints = int(input())
    for i in range(numPoints):
        x = float(input())
        y = float(input())
        quadTree.insert(Point(x, y))

    # Read the query bounding box parameters
    queryCenterX = float(input())
    queryCenterY = float(input())
    queryHalfWidth = float(input())
    queryBox = BoundingBox(Point(queryCenterX, queryCenterY), queryHalfWidth)

    # Query the quadtree for points within the specified bounding box
    result = quadTree.query(queryBox)
    print("Points in range:")
    for point in result:
        print(point.x, point.y)

if __name__ == "__main__":
    main()

