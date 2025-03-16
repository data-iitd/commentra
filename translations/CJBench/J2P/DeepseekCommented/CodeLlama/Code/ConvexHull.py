import sys
from collections import deque

def convex_hull_brute_force(points):
    convex_set = set()
    for i in range(len(points) - 1):
        for j in range(i + 1, len(points)):
            all_points_on_one_side = True
            left_side = check_point_orientation(points[i], points[j], points[(i + 1) % len(points)])
            for k in range(len(points)):
                if k != i and k != j and check_point_orientation(points[i], points[j], points[k]) != left_side:
                    all_points_on_one_side = False
                    break
            if all_points_on_one_side:
                convex_set.add(points[i])
                convex_set.add(points[j])
    return list(convex_set)

def check_point_orientation(i, j, k):
    det_k = orientation(i, j, k)
    if det_k > 0:
        return True
    elif det_k < 0:
        return False
    else:
        return k.compareTo(i) >= 0 and k.compareTo(j) <= 0

def orientation(i, j, k):
    return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

def convex_hull_recursive(points):
    points.sort()
    convex_set = set()
    left_most_point = points[0]
    right_most_point = points[len(points) - 1]
    convex_set.add(left_most_point)
    convex_set.add(right_most_point)
    upper_hull = deque()
    lower_hull = deque()
    for i in range(1, len(points) - 1):
        det = orientation(left_most_point, right_most_point, points[i])
        if det > 0:
            upper_hull.append(points[i])
        elif det < 0:
            lower_hull.append(points[i])
    construct_hull(upper_hull, left_most_point, right_most_point, convex_set)
    construct_hull(lower_hull, right_most_point, left_most_point, convex_set)
    result = list(convex_set)
    result.sort()
    return result

def construct_hull(points, left, right, convex_set):
    if len(points) > 0:
        extreme_point = None
        extreme_point_distance = sys.maxsize
        candidate_points = deque()
        for p in points:
            det = orientation(left, right, p)
            if det > 0:
                candidate_points.append(p)
                if det > extreme_point_distance:
                    extreme_point_distance = det
                    extreme_point = p
            elif det < 0:
                candidate_points.appendleft(p)
                if det < extreme_point_distance:
                    extreme_point_distance = det
                    extreme_point = p
        if extreme_point is not None:
            construct_hull(candidate_points, left, extreme_point, convex_set)
            convex_set.add(extreme_point)
            construct_hull(candidate_points, extreme_point, right, convex_set)

def main():
    n = int(input())
    points = []
    for i in range(n):
        x, y = map(int, input().split())
        points.append(Point(x, y))
    brute_force_hull = convex_hull_brute_force(points)
    print("Convex Hull (Brute Force):")
    for p in brute_force_hull:
        print(p.x, p.y)
    recursive_hull = convex_hull_recursive(points)
    print("Convex Hull (Recursive):")
    for p in recursive_hull:
        print(p.x, p.y)

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        if self.x == other.x:
            return self.y < other.y
        return self.x < other.x

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y

    def __hash__(self):
        return hash((self.x, self.y))

if __name__ == "__main__":
    main()
