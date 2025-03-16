
import sys

class Building:
    def __init__(self, left, height, right):
        self.left = left
        self.height = height
        self.right = right

class Skyline:
    def __init__(self, x, height):
        self.x = x
        self.height = height

    def __str__(self):
        return f"{self.x} {self.height}"

def merge_skyline(skyline1, skyline2):
    merged_skyline = []
    h1 = 0
    h2 = 0
    max_height = 0

    while skyline1 and skyline2:
        if skyline1[0].x < skyline2[0].x:
            x = skyline1[0].x
            h1 = skyline1[0].height
            skyline1.pop(0)
            max_height = max(h1, h2)
            add_skyline_point(merged_skyline, x, max_height)
        else:
            x = skyline2[0].x
            h2 = skyline2[0].height
            skyline2.pop(0)
            max_height = max(h1, h2)
            add_skyline_point(merged_skyline, x, max_height)

    while skyline1:
        merged_skyline.append(skyline1.pop(0))

    while skyline2:
        merged_skyline.append(skyline2.pop(0))

    return merged_skyline

def add_skyline_point(skyline, x, height):
    if not skyline or skyline[-1].height!= height:
        skyline.append(Skyline(x, height))

def find_skyline(buildings, start, end):
    if start == end:
        skyline = [Skyline(buildings[start].left, buildings[start].height), Skyline(buildings[start].right, 0)]
        return skyline

    mid = (start + end) // 2
    left_skyline = find_skyline(buildings, start, mid)
    right_skyline = find_skyline(buildings, mid + 1, end)
    return merge_skyline(left_skyline, right_skyline)

def main():
    num_buildings = int(input())
    buildings = [Building(0, 0, 0)] * num_buildings
    for i in range(num_buildings):
        left, height, right = map(int, input().split())
        buildings[i] = Building(left, height, right)

    skyline = find_skyline(buildings, 0, num_buildings - 1)
    for point in skyline:
        print(point)

if __name__ == "__main__":
    main()

