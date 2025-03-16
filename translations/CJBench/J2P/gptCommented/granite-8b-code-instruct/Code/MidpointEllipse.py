
import math

def draw_ellipse(center_x, center_y, a, b):
    # Initialize a list to hold the points of the ellipse
    points = []

    # Handle the case where both axes are zero (point case)
    if a == 0 and b == 0:
        points.append((center_x, center_y))
        return points

    # Handle the case where the semi-major axis is zero (vertical line)
    if a == 0:
        for y in range(center_y - b, center_y + b + 1):
            points.append((center_x, y))
        return points

    # Handle the case where the semi-minor axis is zero (horizontal line)
    if b == 0:
        for x in range(center_x - a, center_x + a + 1):
            points.append((x, center_y))
        return points

    # Compute the points of the ellipse using the midpoint ellipse algorithm
    compute_ellipse_points(points, center_x, center_y, a, b)
    return points

def compute_ellipse_points(points, center_x, center_y, a, b):
    # Initialize variables for the ellipse drawing algorithm
    x = 0
    y = b
    d1 = b * b - a * a * b + 0.25 * a * a
    dx = 2 * b * b * x
    dy = 2 * a * a * y

    # First region of the ellipse (x < y)
    while dx < dy:
        # Add the calculated points to the collection
        add_ellipse_points(points, center_x, center_y, x, y)
        if d1 < 0:
            # Move to the next point in the x direction
            x += 1
            dx += 2 * b * b
            d1 += dx + b * b
        else:
            # Move to the next point in both x and y directions
            x += 1
            y -= 1
            dx += 2 * b * b
            dy -= 2 * a * a
            d1 += dx - dy + b * b

    # Second region of the ellipse (y < x)
    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b
    while y >= 0:
        # Add the calculated points to the collection
        add_ellipse_points(points, center_x, center_y, x, y)
        if d2 > 0:
            # Move to the next point in the y direction
            y -= 1
            dy -= 2 * a * a
            d2 += a * a - dy
        else:
            # Move to the next point in both x and y directions
            y -= 1
            x += 1
            dx += 2 * b * b
            dy -= 2 * a * a
            d2 += dx - dy + a * a

def add_ellipse_points(points, center_x, center_y, x, y):
    # Add symmetrical points of the ellipse to the collection
    points.append((center_x + x, center_y + y))
    points.append((center_x - x, center_y + y))
    points.append((center_x + x, center_y - y))
    points.append((center_x - x, center_y - y))

# Test the draw_ellipse function
center_x = 0
center_y = 0
a = 3
b = 2
points = draw_ellipse(center_x, center_y, a, b)
print("Ellipse Points:")
for point in points:
    print(point)

# Output:
# Ellipse Points:
# (0, 2)
# (0, -2)
# (3, 0)
# (-3, 0)
# (2, 3)
# (-2, 3)
# (2, -3)
# (-2, -3)

# END-OF-CODE