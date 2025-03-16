import sys
import math

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
            length = math.sqrt(x_gap * x_gap + y_gap * y_gap)
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

    strip = []
    for i in range(index_num):
        x_gap = abs(divide_array[divide_x].x - divide_array[i].x)
        if x_gap < min_value:
            strip.append(divide_array[i])

    strip.sort(key=lambda point: point.y)

    for i in range(len(strip) - 1):
        for j in range(i + 1, len(strip)):
            y_gap = abs(strip[i].y - strip[j].y)
            if y_gap < min_value:
                x_gap = abs(strip[i].x - strip[j].x)
                length = math.sqrt(x_gap * x_gap + y_gap * y_gap)
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

    def build_location(self, x, y):
        return build_location(x, y)

    def x_partition(self, a, first, last):
        return x_partition(a, first, last)

    def x_quick_sort(self, a, first, last):
        return x_quick_sort(a, first, last)

    def closest_pair(self, a, index_num):
        return closest_pair(a, index_num)

    def brute_force(self, array_param):
        return brute_force(array_param)

if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())
    cp = Main(n)

    for i in range(n):
        x, y = map(float, sys.stdin.readline().strip().split())
        cp.array[i] = cp.build_location(x, y)

    cp.x_quick_sort(cp.array, 0, cp.array.