
import sys

# A class providing algorithms to compute the convex hull of a set of points
# using brute-force and recursive methods.
#
# Convex hull: The smallest convex polygon that contains all the given points.
#
# Algorithms provided:
# 1. Brute-Force Method
# 2. Recursive (Divide-and-Conquer) Method
#
# @author Hardvan

class Main:
    def __init__(self):
        pass

    def check_point_orientation(self, i, j, k):
        det_k = self.orientation(i, j, k)
        if det_k > 0:
            return True  # pointsLeftOfIJ
        elif det_k < 0:
            return False  # pointsRightOfIJ
        else:
            return k.compareTo(i) >= 0 and k.compareTo(j) <= 0

    def convex_hull_brute_force(self, points):
        convex_set = set()

        for i in range(len(points) - 1):
            for j in range(i + 1, len(points)):
                all_points_on_one_side = True
                left_side = self.check_point_orientation(points[i], points[j], points[(i + 1) % len(points)])

                for k in range(len(points)):
                    if k != i and k != j and self.check_point_orientation(points[i], points[j], points[k]) != left_side:
                        all_points_on_one_side = False
                        break

                if all_points_on_one_side:
                    convex_set.add(points[i])
                    convex_set.add(points[j])

        return list(convex_set)

    def convex_hull_recursive(self, points):
        points.sort()
        convex_set = set()
        left_most_point = points[0]
        right_most_point = points[len(points) - 1]

        convex_set.add(left_most_point)
        convex_set.add(right_most_point)

        upper_hull = []
        lower_hull = []

        for i in range(1, len(points) - 1):
            det = self.orientation(left_most_point, right_most_point, points[i])
            if det > 0:
                upper_hull.append(points[i])
            elif det < 0:
                lower_hull.append(points[i])

        self.construct_hull(upper_hull, left_most_point, right_most_point, convex_set)
        self.construct_hull(lower_hull, right_most_point, left_most_point, convex_set)

        result = list(convex_set)
        result.sort()
        return result

    def construct_hull(self, points, left, right, convex_set):
        if len(points) > 0:
            extreme_point = None
            extreme_point_distance = sys.maxsize
            candidate_points = []

            for p in points:
                det = self.orientation(left, right, p)
                if det > 0:
                    candidate_points.append(p)
                    if det > extreme_point_distance:
                        extreme_point_distance = det
                        extreme_point = p

            if extreme_point is not None:
                self.construct_hull(candidate_points, left, extreme_point, convex_set)
                convex_set.add(extreme_point)
                self.construct_hull(candidate_points, extreme_point, right, convex_set)

    def orientation(self, i, j, k):
        return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

    def compare_to(self, other):
        return (self.x == other.x) - (self.y == other.y)

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def __init__(self):
        pass

    def