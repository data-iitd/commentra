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
    i += 1
    a[i], a[last] = a[last], a[i]
    return i

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

    first_window = []
    for i in range(index_num):
        x_gap = abs(a[divide_x].x - a[i].x)
        if x_gap < min_value:
            first_window.append(a[i])

    length = 0
    for i in range(len(first_window) - 1):
        for j in range(i + 1, len(first_window)):
            x_gap = abs(first_window[i].x - first_window[j].x)
            y_gap = abs(first_window[i].y - first_window[j].y)
            if y_gap < min_value:
                length = math.sqrt(x_gap * x_gap + y_gap * y_gap)
                if length < min_value:
                    min_value = length
    return min_value

def main():
    n = int(sys.stdin.readline().strip())
    array = []
    for _ in range(n):
        x, y = map(float, sys.stdin.readline().strip().split())
        array.append(build_location(x, y))

    x_quick_sort(array, 0, len(array) - 1)
    result = closest_pair(array, len(array))

    min_num = float('inf')
    point1 = None
    point2 = None
    for i in range(len(array) - 1):
        for j in range(i + 1, len(array)):
            x_gap = array[i].x - array[j].x
            y_gap = array[i].y - array[j].y
            length = math.sqrt(x_gap * x_gap + y_gap * y_gap)
            if length < min_num:
                min_num = length
                point1 = array[i]
                point2 = array[j]

    print(f"({point1.x}, {point1.y})")
    print(f"({point2.x}, {point2.y})")
    print("Minimum Distance :", result)

if __name__ == "__main__":
    main()
