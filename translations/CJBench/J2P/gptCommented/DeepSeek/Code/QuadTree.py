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

    def intersects_bounding_box(self, other_bounding_box):
        return (other_bounding_box.center.x - other_bounding_box.half_width <= self.center.x + self.half_width and
                other_bounding_box.center.x + other_bounding_box.half_width >= self.center.x - self.half_width and
                other_bounding_box.center.y - other_bounding_box.half_width <= self.center.y + self.half_width and
                other_bounding_box.center.y + other_bounding_box.half_width >= self.center.y - self.half_width)


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
            self._subdivide()
        if self.north_west.insert(point) or self.north_east.insert(point) or self.south_west.insert(point) or self.south_east.insert(point):
            return True
        return False

    def _subdivide(self):
        quadrant_half_width = self.boundary.half_width / 2
        self.north_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width, self.boundary.center.y + quadrant_half_width), quadrant_half_width), self.capacity)
        self.north_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width, self.boundary.center.y + quadrant_half_width), quadrant_half_width), self.capacity)
        self.south_west = QuadTree(BoundingBox(Point(self.boundary.center.x - quadrant_half_width, self.boundary.center.y - quadrant_half_width), quadrant_half_width), self.capacity)
        self.south_east = QuadTree(BoundingBox(Point(self.boundary.center.x + quadrant_half_width, self.boundary.center.y - quadrant_half_width), quadrant_half_width), self.capacity)
        self.divided = True

    def query(self, other_bounding_box):
        points_in_range = []
        if not self.boundary.intersects_bounding_box(other_bounding_box):
            return points_in_range
        points_in_range.extend([point for point in self.point_list if other_bounding_box.contains_point(point)])
        if self.divided:
            points_in_range.extend(self.north_west.query(other_bounding_box))
            points_in_range.extend(self.north_east.query(other_bounding_box))
            points_in_range.extend(self.south_west.query(other_bounding_box))
            points_in_range.extend(self.south_east.query(other_bounding_box))
        return points_in_range


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    center_x = float(data[0])
    center_y = float(data[1])
    half_width = float(data[2])
    capacity = int(data[3])
    num_points = int(data[4])

    boundary = BoundingBox(Point(center_x, center_y), half_width)
    quad_tree = QuadTree(boundary, capacity)

    point_index = 5
    for _ in range(num_points):
        x = float(data[point_index])
        y = float(data[point_index + 1])
        quad_tree.insert(Point(x, y))
        point_index += 2

    query_center_x = float(data[point_index])
    query_center_y = float(data[point_index + 1])
    query_half_width = float(data[point_index + 2])
    query_box = BoundingBox(Point(query_center_x, query_center_y), query_half_width)

    result = quad_tree.query(query_box)
    print("Points in range:")
    for point in result:
        print(f"{point.x} {point.y}")


if __name__ == "__main__":
    main()
