class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

class BoundingBox:
    def __init__(self, center, half_width):
        self.center = center
        self.half_width = half_width

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
        self.boundary = boundary
        self.capacity = capacity
        self.point_list = []
        self.divided = False
        self.north_west = None
        self.north_east = None
        self.south_west = None
        self.south_east = None

    def insert(self, point):
        if point is None:
            return False
        if not self.boundary.contains_point(point):
            return False
        if len(self.point_list) < self.capacity:
            self.point_list.append(point)
            return True
        if not self.divided:
            self.subdivide()
        if self.north_west.insert(point):
            return True
        if self.north_east.insert(point):
            return True
        if self.south_west.insert(point):
            return True
        if self.south_east.insert(point):
            return True
        return False

    def subdivide(self):
        quadrant_half_width = self.boundary.half_width / 2
        self.north_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width, self.boundary.center.y + quadrant_half_width), quadrant_half_width), self.capacity)
        self.north_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width, self.boundary.center.y + quadrant_half_width), quadrant_half_width), self.capacity)
        self.south_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width, self.boundary.center.y - quadrant_half_width), quadrant_half_width), self.capacity)
        self.south_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width, self.boundary.center.y - quadrant_half_width), quadrant_half_width), self.capacity)
        self.divided = True

    def query(self, other):
        points = []
        if not self.boundary.intersects_bounding_box(other):
            return points
        points.extend([p for p in self.point_list if other.contains_point(p)])
        if self.divided:
            points.extend(self.north_west.query(other))
            points.extend(self.north_east.query(other))
            points.extend(self.south_west.query(other))
            points.extend(self.south_east.query(other))
        return points

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().splitlines()
    
    center_x, center_y, half_width, capacity = map(float, data[0].split())
    capacity = int(capacity)
    boundary = BoundingBox(Point(center_x, center_y), half_width)
    quad_tree = QuadTree(boundary, capacity)
    
    num_points = int(data[1])
    for i in range(num_points):
        x, y = map(float, data[i + 2].split())
        quad_tree.insert(Point(x, y))
    
    query_center_x, query_center_y, query_half_width = map(float, data[num_points + 2].split())
    query_box = BoundingBox(Point(query_center_x, query_center_y), query_half_width)
    result = quad_tree.query(query_box)
    
    print("Points in range:")
    for point in result:
        print(f"{point.x} {point.y}")

# <END-OF-CODE>
