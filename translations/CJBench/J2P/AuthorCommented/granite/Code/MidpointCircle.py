

import math

def generate_circle_points(center_x, center_y, radius):
    points = []

    # Special case for radius 0, only the center point should be added.
    if radius == 0:
        points.append((center_x, center_y))
        return points

    # Start at (radius, 0)
    x = radius
    y = 0

    # Decision parameter
    p = 1 - radius

    # Add the initial points in all octants
    add_symmetric_points(points, center_x, center_y, x, y)

    # Iterate while x > y
    while x > y:
        y += 1

        if p <= 0:
            # Midpoint is inside or on the circle
            p = p + 2 * y + 1
        else:
            # Midpoint is outside the circle
            x -= 1
            p = p + 2 * y - 2 * x + 1

        # Add points for this (x, y)
        add_symmetric_points(points, center_x, center_y, x, y)

    return points

def add_symmetric_points(points, center_x, center_y, x, y):
    # Octant symmetry points
    points.append((center_x + x, center_y + y))
    points.append((center_x - x, center_y + y))
    points.append((center_x + x, center_y - y))
    points.append((center_x - x, center_y - y))
    points.append((center_x + y, center_y + x))
    points.append((center_x - y, center_y + x))
    points.append((center_x + y, center_y - x))
    points.append((center_x - y, center_y - x))

if __name__ == "__main__":
    center_x = int(input("Enter the x-coordinate of the circle's center: "))
    center_y = int(input("Enter the y-coordinate of the circle's center: "))
    radius = int(input("Enter the radius of the circle: "))

    circle_points = generate_circle_points(center_x, center_y, radius)

    print("The points on the circumference of the circle are:")
    for point in circle_points:
        print(f"({point[0]}, {point[1]})")

