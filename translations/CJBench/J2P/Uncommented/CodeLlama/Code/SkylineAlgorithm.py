
import sys
import math

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dominates(self, p1):
        return ((self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y))

    def __str__(self):
        return str(self.x) + " " + str(self.y)

def produce_sub_sky_lines(list):
    size = len(list)
    if size == 1:
        return list
    elif size == 2:
        if list[0].dominates(list[1]):
            list.remove(list[1])
        elif list[1].dominates(list[0]):
            list.remove(list[0])
        return list
    left_half = list[:size // 2]
    right_half = list[size // 2:]
    left_skyline = produce_sub_sky_lines(left_half)
    right_skyline = produce_sub_sky_lines(right_half)
    return produce_final_sky_line(left_skyline, right_skyline)

def produce_final_sky_line(left, right):
    final_skyline = []
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i].x < right[j].x:
            final_skyline.append(left[i])
            i += 1
        elif left[i].x > right[j].x:
            final_skyline.append(right[j])
            j += 1
        else:
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

def main():
    n = int(sys.stdin.readline())
    points = []
    for i in range(n):
        x, y = map(int, sys.stdin.readline().split())
        points.append(Point(x, y))
    points.sort(key=lambda p: p.x)
    skyline = produce_sub_sky_lines(points)
    print("Final Skyline:")
    for point in skyline:
        print(point)

if __name__ == "__main__":
    main()

