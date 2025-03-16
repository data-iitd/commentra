

import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def dominates(self, p1):
        return (self.x < p1.x and self.y <= p1.y) or (self.x <= p1.x and self.y < p1.y)
    
    def __str__(self):
        return f"{self.x} {self.y}"

def produce_sub_skylines(list):
    size = len(list)
    
    if size == 1:
        return list
    
    if size == 2:
        if list[0].dominates(list[1]):
            list.remove(list[1])
        elif list[1].dominates(list[0]):
            list.remove(list[0])
        return list
    
    left_half = list[:size // 2]
    right_half = list[size // 2:]
    
    left_skyline = produce_sub_skylines(left_half)
    right_skyline = produce_sub_skylines(right_half)
    
    return produce_final_skyline(left_skyline, right_skyline)

def produce_final_skyline(left, right):
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
            if left[i].y < right[j].y:
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
    n = int(input())
    points = []
    
    for _ in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))
    
    points.sort(key=lambda p: p.x)
    
    result = produce_sub_skylines(points)
    
    print("Final Skyline:")
    
    for point in result:
        print(point)

