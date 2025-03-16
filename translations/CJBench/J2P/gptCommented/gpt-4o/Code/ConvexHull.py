import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    @staticmethod
    def orientation(i, j, k):
        return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

    def __lt__(self, other):
        return (self.x, self.y) < (other.x, other.y)

def check_point_orientation(i, j, k):
    det_k = Point.orientation(i, j, k)
    if det_k > 0:
        return True
    elif det_k < 0:
        return False
    else:
        return (k >= i) and (k <= j)

def convex_hull_brute_force(points):
    convex_set = set()
    n = len(points)

    for i in range(n - 1):
        for j in range(i + 1, n):
            all_points_on_one_side = True
            left_side = check_point_orientation(points[i], points[j], points[(i + 1) % n])

            for k in range(n):
                if k != i and k != j and check_point_orientation(points[i], points[j], points[k]) != left_side:
                    all_points_on_one_side = False
                    break

            if all_points_on_one_side:
                convex_set.add(points[i])
                convex_set.add(points[j])

    return sorted(convex_set)

def construct_hull(points, left, right, convex_set):
    if points:
        extreme_point = None
        extreme_point_distance = float('-inf')
        candidate_points = []

        for p in points:
            det = Point.orientation(left, right, p)
            if det > 0:
                candidate_points.append(p)
                if det > extreme_point_distance:
                    extreme_point_distance = det
                    extreme_point = p

        if extreme_point is not None:
            construct_hull(candidate_points, left, extreme_point, convex_set)
            convex_set.add(extreme_point)
            construct_hull(candidate_points, extreme_point, right, convex_set)

def convex_hull_recursive(points):
    points.sort()
    convex_set = set()

    left_most_point = points[0]
    right_most_point = points[-1]

    convex_set.add(left_most_point)
    convex_set.add(right_most_point)

    upper_hull = []
    lower_hull = []

    for i in range(1, len(points) - 1):
        det = Point.orientation(left_most_point, right_most_point, points[i])
        if det > 0:
            upper_hull.append(points[i])
        elif det < 0:
            lower_hull.append(points[i])

    construct_hull(upper_hull, left_most_point, right_most_point, convex_set)
    construct_hull(lower_hull, right_most_point, left_most_point, convex_set)

    return sorted(convex_set)

def main():
    n = int(input())
    points = []

    for _ in range(n):
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

if __name__ == "__main__":
    main()

# <END-OF-CODE>
