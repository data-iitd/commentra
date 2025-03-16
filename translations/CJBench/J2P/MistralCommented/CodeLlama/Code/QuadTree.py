
# Import the necessary libraries
import math

# Class representing a quadtree node
class Point:
    # x and y coordinates of the point
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Class representing a bounding box
class BoundingBox:
    # Center of the bounding box and its half width
    def __init__(self, center, halfWidth):
        self.center = center
        self.halfWidth = halfWidth

    # Checks if the given point is inside the bounding box
    def containsPoint(self, point):
        # Check if the given point is within the bounding box
        return point.x >= self.center.x - self.halfWidth and point.x <= self.center.x + self.halfWidth and point.y >= self.center.y - self.halfWidth and point.y <= self.center.y + self.halfWidth

    # Checks if the given bounding box intersects with this bounding box
    def intersectsBoundingBox(self, otherBoundingBox):
        # Check if the given bounding box intersects with this bounding box
        return otherBoundingBox.center.x - otherBoundingBox.halfWidth <= self.center.x + self.halfWidth and otherBoundingBox.center.x + otherBoundingBox.halfWidth >= self.center.x - self.halfWidth and otherBoundingBox.center.y - otherBoundingBox.halfWidth <= self.center.y + self.halfWidth and otherBoundingBox.center.y + otherBoundingBox.halfWidth >= self.center.y - self.halfWidth

# Main class for Main
class Main:
    # Bounding box and capacity of the current quadtree node
    def __init__(self, boundary, capacity):
        self.boundary = boundary
        self.capacity = capacity
        self.pointList = []
        self.divided = False
        self.northWest = None
        self.northEast = None
        self.southWest = None
        self.southEast = None

    # Inserts a point into the quadtree
    def insert(self, point):
        # Check if the point is null or not inside the bounding box
        if point is None:
            return False
        if not self.boundary.containsPoint(point):
            return False

        # If the list is not full, add the point to the list
        if len(self.pointList) < self.capacity:
            self.pointList.append(point)
            return True

        # If the quadtree is not divided, divide it into four quadrants
        if not self.divided:
            self.subDivide()

        # Recursively insert the point into the appropriate child node
        if self.northWest.insert(point):
            return True
        if self.northEast.insert(point):
            return True
        if self.southWest.insert(point):
            return True
        if self.southEast.insert(point):
            return True

        # If the point could not be inserted into any child node, return false
        return False

    # Divides the quadtree into four quadrants
    def subDivide(self):
        quadrantHalfWidth = self.boundary.halfWidth / 2

        # Initialize the child nodes of the quadtree
        self.northWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.northEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y + quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southWest = Main(BoundingBox(Point(self.boundary.center.x - quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)
        self.southEast = Main(BoundingBox(Point(self.boundary.center.x + quadrantHalfWidth, self.boundary.center.y - quadrantHalfWidth), quadrantHalfWidth), self.capacity)

        # Set the divided flag to true
        self.divided = True

    # Queries the quadtree for points within the given bounding box
    def query(self, otherBoundingBox):
        points = []

        # If the given bounding box does not intersect with this bounding box, return an empty list
        if not self.boundary.intersectsBoundingBox(otherBoundingBox):
            return points

        # Add all the points from the current list that are within the given bounding box
        points.extend([point for point in self.pointList if otherBoundingBox.containsPoint(point)])

        # Recursively query the child nodes and add their points to the result list
        if self.divided:
            points.extend(self.northWest.query(otherBoundingBox))
            points.extend(self.northEast.query(otherBoundingBox))
            points.extend(self.southWest.query(otherBoundingBox))
            points.extend(self.southEast.query(otherBoundingBox))

        # Return the final list of points
        return points

# Main method to run the program
def main():
    # Read the input parameters for the bounding box and capacity
    centerX = float(input())
    centerY = float(input())
    halfWidth = float(input())
    capacity = int(input())

    # Create a new bounding box and quadtree node
    boundary = BoundingBox(Point(centerX, centerY), halfWidth)
    quadTree = Main(boundary, capacity)

    # Read the number of points to be inserted and insert them into the quadtree
    numPoints = int(input())
    for i in range(numPoints):
        x = float(input())
        y = float(input())
        quadTree.insert(Point(x, y))

    # Read the query parameters and query the quadtree for points within the given bounding box
    queryCenterX = float(input())
    queryCenterY = float(input())
    queryHalfWidth = float(input())
    queryBox = BoundingBox(Point(queryCenterX, queryCenterY), queryHalfWidth)
    result = quadTree.query(queryBox)

    # Print the result
    print("Points in range:")
    for point in result:
        print(point.x, point.y)

# Call the main method
main()

