class Location:
    def __init__(self, x, y):
        self.x = x
        self.y = y

def build_location(x, y):
    return Location(x, y)

def x_partition(a, first, last):
    pivot = a[last]
    i = first - 1
    for j in range(first, last):
        if a[j].x <= pivot.x:
            i += 1
            a[i], a[j] = a[j], a[i]
    a[i + 1], a[last] = a[last], a[i + 1]
    return i + 1

def x_quick_sort(a, first, last):
    if first < last:
        q = x_partition(a, first, last)
        x_quick_sort(a, first, q - 1)
        x_quick_sort(a, q + 1, last)

def brute_force(array_param):
    min_value = float('inf')
    for i in range(len(array_param) - 1):
        for j in range(i + 1, len(array_param)):
            x_gap = array_param[i].x - array_param[j].x
            y_gap = array_param[i].y - array_param[j].y
            length = (x_gap ** 2 + y_gap ** 2) ** 0.5
            if length < min_value:
                min_value = length
    return min_value

def closest_pair(a, index_num):
    divide_array = a[:index_num]
    divide_x = index_num // 2
    left_array = a[:divide_x]
    right_array = a[divide_x:]
    if index_num <= 3:
        return brute_force(divide_array)
    min_left_area = closest_pair(left_array, divide_x)
    min_right_area = closest_pair(right_array, index_num - divide_x)
    min_value = min(min_left_area, min_right_area)
    first_window = []
    for i in range(index_num):
        x_gap = abs(divide_array[divide_x].x - divide_array[i].x)
        if x_gap < min_value:
            first_window.append(divide_array[i])
    min_value = float('inf')
    for i in range(len(first_window) - 1):
        for j in range(i + 1, len(first_window)):
            x_gap = abs(first_window[i].x - first_window[j].x)
            y_gap = abs(first_window[i].y - first_window[j].y)
            if y_gap < min_value:
                length = (x_gap ** 2 + y_gap ** 2) ** 0.5
                if length < min_value:
                    min_value = length
    return min_value

class Main:
    def __init__(self, points):
        self.number_points = points
        self.array = [None] * points
        self.point1 = None
        self.point2 = None
        self.min_num = float('inf')

    @staticmethod
    def set_min_num(min_num):
        Main.min_num = min_num

    @staticmethod
    def set_second_count(second_count):
        Main.second_count = second_count

    second_count = 0

    def main(self):
        import sys
        input = sys.stdin.read
        data = input().split()
        n = int(data[0])
        points = []
        for i in range(1, n + 1):
            x = float(data[i * 2 - 1])
            y = float(data[i * 2])
            points.append(build_location(x, y))
        x_quick_sort(points, 0, len(points) - 1)
        result = closest_pair(points, len(points))
        print(f"({points[0].x}, {points[0].y})")
        print(f"({points[1].x}, {points[1].y})")
        print(f"Minimum Distance : {result}")

if __name__ == "__main__":
    main = Main(0)
    main.main()
