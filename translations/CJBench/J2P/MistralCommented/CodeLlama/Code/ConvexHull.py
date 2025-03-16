
import sys

def main():
    # Read the number of points from the input
    n = int(sys.stdin.readline())

    # Create an empty list to store the points
    points = []

    # Iterate through the input and add each point to the list
    for i in range(n):
        x, y = map(int, sys.stdin.readline().split())
        points.append((x, y))

    # Calculate the convex hull using the brute force method
    brute_force_hull = convex_hull_brute_force(points)
    print("Convex Hull (Brute Force):")
    for p in brute_force_hull:
        print(p[0], p[1])

    # Calculate the convex hull using the recursive method
    recursive_hull = convex_hull_recursive(points)
    print("Convex Hull (Recursive):")
    for p in recursive_hull:
        print(p[0], p[1])

def convex_hull_brute_force(points):
    # Create an empty set to store the convex points
    convex_set = set()

    # Iterate through all pairs of points
    for i in range(len(points) - 1):
        for j in range(i + 1, len(points)):
            # Check if all points are on the same side
            all_points_on_one_side = True
            left_side = check_point_orientation(points[i], points[j], points[(i + 1) % len(points)])
            for k in range(len(points)):
                if k != i and k != j and check_point_orientation(points[i], points[j], points[k]) != left_side:
                    all_points_on_one_side = False
                    break

            if all_points_on_one_side:
                # If all points are on the same side, add points i and j to the convex set
                convex_set.add(points[i])
                convex_set.add(points[j])

    return list(convex_set)

def convex_hull_recursive(points):
    # Sort the points based on their x-coordinates
    points.sort(key=lambda p: p[0])

    # Create an empty set to store the convex points
    convex_set = set()

    # Set the leftmost point as the first point in the list
    left_most_point = points[0]
    # Set the rightmost point as the last point in the list
    right_most_point = points[-1]

    # Add the leftmost point to the convex set
    convex_set.add(left_most_point)
    # Add the rightmost point to the convex set
    convex_set.add(right_most_point)

    # Create an empty list to store the upper hull points
    upper_hull = []
    # Create an empty list to store the lower hull points
    lower_hull = []

    # Iterate through all points except the first and last points
    for i in range(1, len(points) - 1):
        # Calculate the orientation of points i, leftmost, and rightmost
        det = orientation(left_most_point, right_most_point, points[i])

        if det > 0:
            # If the orientation is positive, add the point to the upper hull
            upper_hull.append(points[i])
        elif det < 0:
            # If the orientation is negative, add the point to the lower hull
            lower_hull.append(points[i])

    # Recursively construct the upper hull
    construct_hull(upper_hull, left_most_point, right_most_point, convex_set)
    # Recursively construct the lower hull
    construct_hull(lower_hull, right_most_point, left_most_point, convex_set)

    # Create a copy of the convex set as the result
    result = list(convex_set)
    # Sort the result based on their x-coordinates
    result.sort(key=lambda p: p[0])

    return result

def construct_hull(points, left, right, convex_set):
    if points:
        # If there are still points to process
        # Initialize the extreme point as null
        extreme_point = None
        # Initialize the extreme point distance as the minimum value
        extreme_point_distance = -sys.maxsize

        for p in points:
            # Calculate the orientation of points left, right, and p
            det = orientation(left, right, p)

            if det > 0:
                # If the orientation is positive, check if this point is the extreme point
                if det > extreme_point_distance:
                    # Update the extreme point distance if a new extreme point is found
                    extreme_point_distance = det
                    # Update the extreme point
                    extreme_point = p

        if extreme_point is not None:
            # If an extreme point is found
            # Recursively construct the hull with the new extreme point
            construct_hull(points, left, extreme_point, convex_set)
            # Add the extreme point to the convex set
            convex_set.add(extreme_point)
            # Recursively construct the hull with the new extreme point
            construct_hull(points, extreme_point, right, convex_set)

def check_point_orientation(i, j, k):
    # Calculate the orientation of points i, j, and k
    det = orientation(i, j, k)

    if det > 0:
        # If the orientation is positive, return true
        return True
    elif det < 0:
        # If the orientation is negative, return false
        return False
    else:
        # If the orientation is zero, return true
        return True

def orientation(i, j, k):
    # Calculate the orientation of points i, j, and k
    return (j[1] - i[1]) * (k[0] - j[0]) - (j[0] - i[0]) * (k[1] - j[1])

if __name__ == "__main__":
    main()

