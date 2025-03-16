from typing import List, Set, Tuple, Optional

class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    @staticmethod
    def orientation(i: 'Point', j: 'Point', k: 'Point') -> int:
        return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

    def __lt__(self, other: 'Point') -> bool:
        return (self.x < other.x) or (self.x == other.x and self.y < other.y)

    def __eq__(self, other: 'Point') -> bool:
        return self.x == other.x and self.y == other.y

    def __hash__(self) -> int:
        return hash((self.x, self.y))

    def __str__(self) -> str:
        return f"({self.x}, {self.y})"

def check_point_orientation(i: Point, j: Point, k: Point) -> bool:
    det_k = Point.orientation(i, j, k)
    if det_k > 0:
        return True
    elif det_k < 0:
        return False
    else:
        return k.x >= i.x and k.x <= j.x if i.x != j.x else k.y >= i.y and k.y <= j.y

def convex_hull_brute_force(points: List[Point]) -> List[Point]:
    convex_set: Set[Point] = set()
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

def convex_hull_recursive(points: List[Point]) -> List[Point]:
    points.sort()
    convex_set: Set[Point] = set()
    left_most_point = points[0]
    right_most_point = points[-1]
    convex_set.add(left_most_point)
    convex_set.add(right_most_point)
    upper_hull: List[Point] = []
    lower_hull: List[Point] = []
    for i in range(1, len(points) - 1):
        det = Point.orientation(left_most_point, right_most_point, points[i])
        if det > 0:
            upper_hull.append(points[i])
        elif det < 0:
            lower_hull.append(points[i])
    construct_hull(upper_hull, left_most_point, right_most_point, convex_set)
    construct_hull(lower_hull, right_most_point, left_most_point, convex_set)
    result = list(convex_set)
    result.sort()
    return result

def construct_hull(points: List[Point], left: Point, right: Point, convex_set: Set[Point]):
    if points:
        extreme_point: Optional[Point] = None
        extreme_point_distance = float('-inf')
        candidate_points: List[Point] = []
        for p in points:
            det = Point.orientation(left, right, p)
            if det > 0:
                candidate_points.append(p)
                if det > extreme_point_distance:
                    extreme_point_distance = det
                    extreme_point = p
        if extreme_point:
            construct_hull(candidate_points, left, extreme_point, convex_set)
            convex_set.add(extreme_point)
            construct_hull(candidate_points, extreme_point, right, convex_set)

def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    points = []
    for i in range(1, n + 1):
        x = int(data[i * 2 - 1])
        y = int(data[i * 2])
        points.append(Point(x, y))
    brute_force_hull = convex_hull_brute_force(points)
    print("Convex Hull (Brute Force):")
    for p in brute_force_hull:
        print(p.x, p.y)
    recursive_hull = convex_hull_recursive(points)
    print("Convex Hull (Recursive):")
    for p in recursive_hull:
        print(p.x, p.y)

if __name__ == "__main__":
    main()
