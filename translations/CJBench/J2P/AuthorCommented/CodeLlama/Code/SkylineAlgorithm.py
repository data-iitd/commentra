

import sys


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dominates(self, p1):
        return (self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y)


def produce_sub_sky_lines(list):
    # part where function exits flashback
    size = len(list)
    if size == 1:
        return list
    elif size == 2:
        if list[0].dominates(list[1]):
            list.remove(list[1])
        elif list[1].dominates(list[0]):
            list.remove(list[0])
        return list

    # recursive part of the function
    left_half = list[0:size // 2]
    right_half = list[size // 2:size]

    left_skyline = produce_sub_sky_lines(left_half)
    right_skyline = produce_sub_sky_lines(right_half)

    # skyline is produced
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
    n = int(sys.stdin.readline())
    points = []

    # Input points
    for i in range(n):
        x, y = map(int, sys.stdin.readline().split())
        points.append(Point(x, y))

    # Sort points by x-coordinate
    points.sort(key=lambda point: point.x)

    result = produce_sub_sky_lines(points)

    # Output final skyline
    print("Final Skyline:")
    for point in result:
        print(point)

# 