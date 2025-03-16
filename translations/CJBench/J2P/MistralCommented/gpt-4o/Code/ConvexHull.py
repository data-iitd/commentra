import sys

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    @staticmethod
    def orientation(i, j, k):
        return (j.y - i.y) * (k.x - j.x) - (j.x - i.x) * (k.y - j.y)

    def __lt__(self, other):
        if self.x == other.x:
            return self.y < other.y
        return self.x < other.x

def convex_hull_brute_force(points):
    convex_set = set()  # Create an empty set to store the convex points

    for i in range(len(points) - 1):  # Iterate through all pairs of points
        for j in range(i + 1, len(points)):
            all_points_on_one_side = True  # Assume all points are on the same side initially
            left_side = Point.orientation(points[i], points[j], points[(i + 1) % len(points)]) > 0

            for k in range(len(points)):  # Check if all points are on the same side
                if k != i and k != j and Point.orientation(points[i], points[j], points[k]) > 0 != left_side:
                    all_points_on_one_side = False  # If a point is not on the same side, break the loop
                    break

            if all_points_on_one_side:  # If all points are on the same side, add points i and j to the convex set
                convex_set.add(points[i])
                convex_set.add(points[j])

    return list(convex_set)  # Return the convex hull as a list

def convex_hull_recursive(points):
    points.sort()  # Sort the points based on their x-coordinates

    convex_set = set()  # Create an empty set to store the convex points

    left_most_point = points[0]  # Set the leftmost point as the first point in the list
    right_most_point = points[-1]  # Set the rightmost point as the last point in the list

    convex_set.add(left_most_point)  # Add the leftmost point to the convex set
    convex_set.add(right_most_point)  # Add the rightmost point to the convex set

    upper_hull = []  # Create an empty list to store the upper hull points
    lower_hull = []  # Create an empty list to store the lower hull points

    for i in range(1, len(points) - 1):  # Iterate through all points except the first and last points
        det = Point.orientation(left_most_point, right_most_point, points[i])  # Calculate the orientation

        if det > 0:  # If the orientation is positive, add the point to the upper hull
            upper_hull.append(points[i])
        elif det < 0:  # If the orientation is negative, add the point to the lower hull
            lower_hull.append(points[i])

    construct_hull(upper_hull, left_most_point, right_most_point, convex_set)  # Recursively construct the upper hull
    construct_hull(lower_hull, right_most_point, left_most_point, convex_set)  # Recursively construct the lower hull

    result = list(convex_set)  # Create a copy of the convex set as the result
    result.sort()  # Sort the result based on their x-coordinates

    return result  # Return the convex hull as a sorted list

def construct_hull(points, left, right, convex_set):
    if points:  # If there are still points to process
        extreme_point = None  # Initialize the extreme point as None
        extreme_point_distance = float('-inf')  # Initialize the extreme point distance as the minimum value

        for p in points:  # Iterate through all points in the collection
            det = Point.orientation(left, right, p)  # Calculate the orientation

            if det > 0:  # If the orientation is positive, check if this point is the extreme point
                if det > extreme_point_distance:
                    extreme_point_distance = det  # Update the extreme point distance
                    extreme_point = p  # Update the extreme point

        if extreme_point:  # If an extreme point is found
            construct_hull(points, left, extreme_point, convex_set)  # Recursively construct the hull
            convex_set.add(extreme_point)  # Add the extreme point to the convex set
            construct_hull(points, extreme_point, right, convex_set)  # Recursively construct the hull

def main():
    n = int(sys.stdin.readline().strip())  # Read the number of points from the input

    points = []  # Create an empty list to store the points

    for _ in range(n):  # Iterate through the input and add each point to the list
        x, y = map(int, sys.stdin.readline().strip().split())
        points.append(Point(x, y))

    brute_force_hull = convex_hull_brute_force(points)  # Calculate the convex hull using the brute force method
    print("Convex Hull (Brute Force):")  # Print the header for the output of the brute force method
    for p in brute_force_hull:  # Iterate through the points in the brute force hull and print their coordinates
        print(p.x, p.y)

    recursive_hull = convex_hull_recursive(points)  # Calculate the convex hull using the recursive method
    print("Convex Hull (Recursive):")  # Print the header for the output of the recursive method
    for p in recursive_hull:  # Iterate through the points in the recursive hull and print their coordinates
        print(p.x, p.y)

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
