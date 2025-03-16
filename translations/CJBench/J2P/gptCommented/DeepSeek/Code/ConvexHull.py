import sys
from typing import List, Set, Tuple, Optional

class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def __lt__(self, other: 'Point') -> bool:
        return self.x < other.x or (self.x == other.x and self.y < other.y)

    def __eq__(self, other: 'Point') -> bool:
        return self.x == other.x and self.y == other.y

    def __hash__(self) -> int:
        return hash((self.x, self.y))

    def __repr__(self) -> str:
        return f"({self.x}, {self.y})"

def orientation(i: Point, j: Point, k: Point) -> int:
    val = (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)
    if val == 0:
        return 0
    elif val > 0:
        return 1
    else:
        return -1

def convex_hull_brute_force(points: List[Point]) -> List[Point]:
    convex_set = set()
    n = len(points)
    for i in range(n):
        for j in range(i + 1, n):
            left_side = True
            right_side = True
            for k in range(n):
                if k != i and k != j:
                    if orientation(points[i], points[j], points[k]) > 0:
                        left_side = False
                    elif orientation(points[i], points[j], points[k]) < 0:
                        right_side = False
            if left_side:
                convex_set.add(points[i])
                convex_set.add(points[j])
            if right_side:
                convex_set.add(points[i])
                convex_set.add(points[j])
    return list(convex_set)

def convex_hull_recursive(points: List[Point]) -> List[Point]:
    points.sort()
    convex_set = set()
    n = len(points)
    if n < 3:
        return points
    left_most = points[0]
    right_most = points[n - 1]
    convex_set.add(left_most)
    convex_set.add(right_most)
    upper_hull = []
    lower_hull = []
    for i in range(1, n - 1):
        det = orientation(left_most, right_most, points[i])
        if det > 0:
            upper_hull.append(points[i])
        elif det < 0:
            lower_hull.append(points[i])
    construct_hull(upper_hull, left_most, right_most, convex_set)
    construct_hull(lower_hull, right_most, left_most, convex_set)
    return sorted(list(convex_set))

def construct_hull(points: List[Point], left: Point, right: Point, convex_set: Set[Point]):
    if len(points) > 0:
        extreme_point = None
        extreme_distance = -sys.maxsize
        candidate_points = []
        for p in points:
            det = orientation(left, right, p)
            if det > 0:
                candidate_points.append(p)
                if det > extreme_distance:
                    extreme_distance = det
                    extreme_point = p
        if extreme_point is not None:
            construct_hull(candidate_points, left, extreme_point, convex_set)
            convex_set.add(extreme_point)
            construct_hull(candidate_points, extreme_point, right, convex_set)

def main():
    n = int(input().strip())
    points = []
    for _ in range(n):
        x, y = map(int, input().strip().split())
        points.append(Point(x, y))
    
    brute_force_hull = convex_hull_brute_force(points)
    print("Convex Hull (Brute Force):")
    for p in brute_force_hull:
        print(f"{p.x} {p.y}")
    
    recursive_hull = convex_hull_recursive(points)
    print("Convex Hull (Recursive):")
    for p in recursive_hull:
        print(f"{p.x} {p.y}")

if __name__ == "__main__":
    main()
