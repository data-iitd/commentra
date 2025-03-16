
import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def dominates(self, p1):
        return (self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y)

    def __str__(self):
        return str(self.x) + " " + str(self.y)

def produce_sub_sky_lines(list):
    size = len(list)

    # Base case: if the list has only one element, return it
    if size == 1:
        return list

    # Base case: if the list has only two elements, check dominance and return the non-dominated point
    elif size == 2:
        if list[0].dominates(list[1]):
            list.remove(list[1]) # remove the dominated point
        elif list[1].dominates(list[0]):
            list.remove(list[0]) # remove the dominating point
        return list

    # Recursive case: divide the list into left and right halves and call produce_sub_sky_lines recursively
    left_half = list[:size // 2]
    right_half = list[size // 2:]
    left_skyline = produce_sub_sky_lines(left_half) # produce sub skyline for left half
    right_skyline = produce_sub_sky_lines(right_half) # produce sub skyline for right half
    return produce_final_sky_line(left_skyline, right_skyline) # merge left and right sub sky lines to get the final skyline

def produce_final_sky_line(left, right):
    final_skyline = []

    i = 0
    j = 0

    # Merge the smaller x-coordinate sub skyline into the final skyline
    while i < len(left) and j < len(right):
        if left[i].x < right[j].x:
            final_skyline.append(left[i]) # add point from left sub skyline
            i += 1
        elif left[i].x > right[j].x:
            final_skyline.append(right[j]) # add point from right sub skyline
            j += 1
        else: # if x-coordinates are equal, compare y-coordinates and add the dominating point
            final_skyline.append(left[i] if left[i].y < right[j].y else right[j])
            i += 1
            j += 1

    # Add remaining points from left and right sub sky lines to the final skyline
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

    for i in range(n):
        x, y = map(int, sys.stdin.readline().split())
        points.append(Point(x, y))

    points.sort(key=lambda point: point.x)

    result = produce_sub_sky_lines(points)

    print("Final Skyline:")

    for point in result:
        print(point)

# 