import math

class Main:
    min_num = float('inf')
    second_count = 0

    def __init__(self, points):
        self.number_points = points
        self.array = [None] * self.number_points
        self.point1 = None
        self.point2 = None

    class Location:
        def __init__(self, xpar, ypar):
            self.x = xpar
            self.y = ypar

    def build_location(self, x, y):
        return self.Location(x, y)

    def x_partition(self, a, first, last):
        pivot = a[last]
        i = first - 1
        for j in range(first, last):
            if a[j].x <= pivot.x:
                i += 1
                a[i], a[j] = a[j], a[i]
        i += 1
        a[i], a[last] = a[last], a[i]
        return i

    def x_quick_sort(self, a, first, last):
        if first < last:
            q = self.x_partition(a, first, last)
            self.x_quick_sort(a, first, q - 1)
            self.x_quick_sort(a, q + 1, last)

    def closest_pair(self, a, index_num):
        divide_array = a[:index_num]
        divide_x = index_num // 2
        left_array = divide_array[:divide_x]
        right_array = divide_array[divide_x:]

        if index_num <= 3:
            return self.brute_force(divide_array)

        min_left_area = self.closest_pair(left_array, divide_x)
        min_right_area = self.closest_pair(right_array, index_num - divide_x)
        min_value = min(min_left_area, min_right_area)

        for i in range(index_num):
            x_gap = abs(divide_array[divide_x].x - divide_array[i].x)
            if x_gap < min_value:
                Main.second_count += 1

        first_window = [None] * Main.second_count
        k = 0
        for i in range(index_num):
            x_gap = abs(divide_array[divide_x].x - divide_array[i].x)
            if x_gap < min_value:
                first_window[k] = divide_array[i]
                k += 1

        for i in range(Main.second_count - 1):
            for j in range(i + 1, Main.second_count):
                x_gap = abs(first_window[i].x - first_window[j].x)
                y_gap = abs(first_window[i].y - first_window[j].y)
                if y_gap < min_value:
                    length = math.sqrt(x_gap ** 2 + y_gap ** 2)
                    if length < min_value:
                        min_value = length
                        if length < Main.min_num:
                            Main.min_num = length
                            self.point1 = first_window[i]
                            self.point2 = first_window[j]

        Main.second_count = 0
        return min_value

    def brute_force(self, array_param):
        min_value = float('inf')
        for i in range(len(array_param) - 1):
            for j in range(i + 1, len(array_param)):
                x_gap = array_param[i].x - array_param[j].x
                y_gap = array_param[i].y - array_param[j].y
                length = math.sqrt(x_gap ** 2 + y_gap ** 2)
                if length < min_value:
                    min_value = length
                    if length < Main.min_num:
                        Main.min_num = length
                        self.point1 = array_param[i]
                        self.point2 = array_param[j]
        return min_value

if __name__ == "__main__":
    n = int(input())
    cp = Main(n)
    for i in range(n):
        x, y = map(float, input().split())
        cp.array[i] = cp.build_location(x, y)
    cp.x_quick_sort(cp.array, 0, len(cp.array) - 1)
    result = cp.closest_pair(cp.array, len(cp.array))
    print(f"({cp.point1.x}, {cp.point1.y})")
    print(f"({cp.point2.x}, {cp.point2.y})")
    print(f"Minimum Distance : {result}")

# <END-OF-CODE>
