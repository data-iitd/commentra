class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def get_x(self):
        return self.x

    def get_y(self):
        return self.y

    def dominates(self, p1):
        return ((self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y))

    def __str__(self):
        return f"{self.x} {self.y}"


class Main:
    def __init__(self):
        self.points = []

    def produce_sub_sky_lines(self, points_list):
        size = len(points_list)
        if size == 1:
            return points_list
        elif size == 2:
            if points_list[0].dominates(points_list[1]):
                return [points_list[0]]
            elif points_list[1].dominates(points_list[0]):
                return [points_list[1]]
            else:
                return points_list
        left_half = points_list[:size // 2]
        right_half = points_list[size // 2:]
        left_skyline = self.produce_sub_sky_lines(left_half)
        right_skyline = self.produce_sub_sky_lines(right_half)
        return self.produce_final_sky_line(left_skyline, right_skyline)

    def produce_final_sky_line(self, left, right):
        final_skyline = []
        i, j = 0, 0
        while i < len(left) and j < len(right):
            if left[i].get_x() < right[j].get_x():
                final_skyline.append(left[i])
                i += 1
            elif left[i].get_x() > right[j].get_x():
                final_skyline.append(right[j])
                j += 1
            else:
                if left[i].get_y() < right[j].get_y():
                    final_skyline.append(left[i])
                else:
                    final_skyline.append(right[j])
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
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    points = []
    for i in range(1, n + 1):
        x = int(data[i * 2 - 1])
        y = int(data[i * 2])
        points.append(Point(x, y))
    points.sort(key=lambda point: point.get_x())
    skyline = Main()
    result = skyline.produce_sub_sky_lines(points)
    print("Final Skyline:")
    for point in result:
        print(point)
