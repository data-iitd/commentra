
import math

# Class representing a point in 2D space
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# Class representing a bounding box defined by a center point and half width
class BoundingBox:
    def __init__(self, center, half_width):
        self.center = center
        self.half_width = half_width

    # Method to check if a point is contained within the bounding box
    def contains_point(self, point):
        return point.x >= self.center.x - self.half_width and point.x <= self.center.x + self.half_width and \
               point.y >= self.center.y - self.half_width and point.y <= self.center.y + self.half_width

    # Method to check if this bounding box intersects with another bounding box
    def intersects_bounding_box(self, other_bounding_box):
        return other_bounding_box.center.x - other_bounding_box.half_width <= self.center.x + self.half_width and \
               other_bounding_box.center.x + other_bounding_box.half_width >= self.center.x - self.half_width and \
               other_bounding_box.center.y - other_bounding_box.half_width <= self.center.y + self.half_width and \
               other_bounding_box.center.y + other_bounding_box.half_width >= self.center.y - self.half_width

# Main class representing a quadtree structure
class QuadTree:
    def __init__(self, boundary, capacity):
        self.boundary = boundary
        self.capacity = capacity
        self.point_list = []
        self.divided = False
        self.north_west = None
        self.north_east = None
        self.south_west = None
        self.south_east = None

    # Method to insert a point into the quadtree
    def insert(self, point):
        if point is None:
            return False  # Return False if the point is None
        if not self.boundary.contains_point(point):
            return False  # Return False if the point is outside the bounding box
        if len(self.point_list) < self.capacity:
            self.point_list.append(point)  # Add the point if there is capacity
            return True
        if not self.divided:
            self.subdivide()  # Subdivide the node if it is not already divided
        # Attempt to insert the point into one of the child nodes
        if self.north_west.insert(point) or self.north_east.insert(point) or self.south_west.insert(point) or self.south_east.insert(point):
            return True
        return False  # Return False if the point could not be inserted

    # Method to subdivide the current node into four child nodes
    def subdivide(self):
        quadrant_half_width = self.boundary.half_width / 2  # Calculate half width for the quadrants
        # Create child nodes for each quadrant
        self.north_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width, self.boundary.center.y + quadrant_half_width), quadrant_half_width), self.capacity)
        self.north_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width, self.boundary.center.y + quadrant_half_width), quadrant_half_width), self.capacity)
        self.south_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width, self.boundary.center.y - quadrant_half_width), quadrant_half_width), self.capacity)
        self.south_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width, self.boundary.center.y - quadrant_half_width), quadrant_half_width), self.capacity)
        self.divided = True  # Mark this node as divided

    # Method to query points within a given bounding box
    def query(self, other_bounding_box):
        points = []
        if not self.boundary.intersects_bounding_box(other_bounding_box):
            return points  # Return empty list if there is no intersection
        # Add points contained in this node's bounding box to the result
        points.extend(filter(lambda point: other_bounding_box.contains_point(point), self.point_list))
        # If this node is divided, query the child nodes
        if self.divided:
            points.extend(self.north_west.query(other_bounding_box))
            points.extend(self.north_east.query(other_bounding_box))
            points.extend(self.south_west.query(other_bounding_box))
            points.extend(self.south_east.query(other_bounding_box))
        return points  # Return the list of points found in the query

# Main method to run the program
if __name__ == "__main__":
    import sys
    # Read the center coordinates and half width for the bounding box
    center_x, center_y, half_width, capacity = map(float, sys.stdin.readline().split())
    # Create the bounding box and the quadtree
    boundary = BoundingBox(Point(center_x, center_y), half_width)
    quad_tree = QuadTree(boundary, capacity)
    # Read the number of points to insert into the quadtree
    num_points = int(sys.stdin.readline())
    for _ in range(num_points):
        x, y = map(float, sys.stdin.readline().split())
        quad_tree.insert(Point(x, y))  # Insert each point into the quadtree
    # Read the query bounding box parameters
    query_center_x, query_center_y, query_half_width = map(float, sys.stdin.readline().split())
    query_box = BoundingBox(Point(query_center_x, query_center_y), query_half_width)
    # Query the quadtree for points within the specified bounding box
    result = quad_tree.query(query_box)
    print("Points in range:")
    for point in result:
        print(point.x, point.y)  # Print the points found in the query

