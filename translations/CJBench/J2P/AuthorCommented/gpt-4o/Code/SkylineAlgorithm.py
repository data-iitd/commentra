class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dominates(self, other):
        return (self.x < other.x and self.y <= other.y) or (self.x <= other.x and self.y < other.y)

    def __str__(self):
        return f"{self.x} {self.y}"


class Main:
    def __init__(self):
        self.points = []

    def produce_sub_sky_lines(self, points):
        size = len(points)
        if size == 1:
            return points
        elif size == 2:
            if points[0].dominates(points[1]):
                points.pop(1)
            elif points[1].dominates(points[0]):
                points.pop(0)
            return points

        left_half = points[:size // 2]
        right_half = points[size // 2:]

        left_skyline = self.produce_sub_sky_lines(left_half)
        right_skyline = self.produce_sub_sky_lines(right_half)

        return self.produce_final_sky_line(left_skyline, right_skyline)

    def produce_final_sky_line(self, left, right):
        final_skyline = []
        i, j = 0, 0

        while i < len(left) and j < len(right):
            if left[i].x < right[j].x:
                final_skyline.append(left[i])
                i += 1
            elif left[i].x > right[j].x:
                final_skyline.append(right[j])
                j += 1
            else:  # Same x coordinate, choose the smaller y value
                final_skyline.append(left[i] if left[i].y < right[j].y else right[j])
                i += 1
                j += 1

        while i < len(left):
            final_skyline.append(left[i])
            i += 1

        while j < len(right):
            final_skyline.append(right[j])
            j += 1

        return final_skyline


if __name__ == "__main__":
    import sys

    # Input number of points
    n = int(sys.stdin.readline().strip())
    points = []

    # Input points
    for _ in range(n):
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append(Point(x, y))

    # Sort points by x-coordinate
    points.sort(key=lambda p: p.x)

    skyline = Main()
    result = skyline.produce_sub_sky_lines(points)

    # Output final skyline
    print("Final Skyline:")
    for point in result:
        print(point)

# <END-OF-CODE>
