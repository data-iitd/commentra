class Point:
    def __init__(self, x, y):
        self.x = x  # X coordinate of the point
        self.y = y  # Y coordinate of the point


class BoundingBox:
    def __init__(self, center, half_width):
        self.center = center  # Center point of the bounding box
        self.half_width = half_width  # Half the width (and height) of the bounding box

    def contains_point(self, point):
        return (self.center.x - self.half_width <= point.x <= self.center.x + self.half_width and
                self.center.y - self.half_width <= point.y <= self.center.y + self.half_width)

    def intersects_bounding_box(self, other):
        return (other.center.x - other.half_width <= self.center.x + self.half_width and
                other.center.x + other.half_width >= self.center.x - self.half_width and
                other.center.y - other.half_width <= self.center.y + self.half_width and
                other.center.y + other.half_width >= self.center.y - self.half_width)


class QuadTree:
    def __init__(self, boundary, capacity):
        self.boundary = boundary  # The bounding box for this node
        self.capacity = capacity  # Maximum number of points allowed in this node before subdivision
        self.point_list = []  # List of points contained in this node
        self.divided = False  # Flag indicating whether this node has been subdivided
        self.north_west = None  # Northwest child node
        self.north_east = None  # Northeast child node
        self.south_west = None  # Southwest child node
        self.south_east = None  # Southeast child node

    def insert(self, point):
        if point is None:
            return False  # Return false if the point is null
        if not self.boundary.contains_point(point):
            return False  # Return false if the point is outside the bounding box
        if len(self.point_list) < self.capacity:
            self.point_list.append(point)  # Add the point if there is capacity
            return True
        if not self.divided:
            self.subdivide()  # Subdivide the node if it is not already divided
        # Attempt to insert the point into one of the child nodes
        if (self.north_west.insert(point) or
                self.north_east.insert(point) or
                self.south_west.insert(point) or
                self.south_east.insert(point)):
            return True
        return False  # Return false if the point could not be inserted

    def subdivide(self):
        quadrant_half_width = self.boundary.half_width / 2  # Calculate half width for the quadrants
        # Create child nodes for each quadrant
        self.north_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width,
                                                       self.boundary.center.y + quadrant_half_width),
                                                quadrant_half_width), self.capacity)
        self.north_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width,
                                                       self.boundary.center.y + quadrant_half_width),
                                                quadrant_half_width), self.capacity)
        self.south_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width,
                                                       self.boundary.center.y - quadrant_half_width),
                                                quadrant_half_width), self.capacity)
        self.south_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width,
                                                       self.boundary.center.y - quadrant_half_width),
                                                quadrant_half_width), self.capacity)
        self.divided = True  # Mark this node as divided

    def query(self, other_bounding_box):
        points = []
        if not self.boundary.intersects_bounding_box(other_bounding_box):
            return points  # Return empty list if there is no intersection
        # Add points contained in this node's bounding box to the result
        points.extend([point for point in self.point_list if other_bounding_box.contains_point(point)])
        # If this node is divided, query the child nodes
        if self.divided:
            points.extend(self.north_west.query(other_bounding_box))
            points.extend(self.north_east.query(other_bounding_box))
            points.extend(self.south_west.query(other_bounding_box))
            points.extend(self.south_east.query(other_bounding_box))
        return points  # Return the list of points found in the query


def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    # Read the center coordinates and half width for the bounding box
    center_x, center_y, half_width, capacity = map(float, data[0].split())
    capacity = int(capacity)  # Convert capacity to int

    # Create the bounding box and the quadtree
    boundary = BoundingBox(Point(center_x, center_y), half_width)
    quad_tree = QuadTree(boundary, capacity)

    # Read the number of points to insert into the quadtree
    num_points = int(data[1])
    for i in range(num_points):
        x, y = map(float, data[i + 2].split())
        quad_tree.insert(Point(x, y))  # Insert each point into the quadtree

    # Read the query bounding box parameters
    query_center_x, query_center_y, query_half_width = map(float, data[num_points + 2].split())
    query_box = BoundingBox(Point(query_center_x, query_center_y), query_half_width)

    # Query the quadtree for points within the specified bounding box
    result = quad_tree.query(query_box)
    print("Points in range:")
    for point in result:
        print(f"{point.x} {point.y}")  # Print the points found in the query


if __name__ == "__main__":
    main()

# <END-OF-CODE>
