

import math

def draw_ellipse(center_x, center_y, a, b):
    points = [] # Create an empty list to store the ellipse points

    if a == 0 and b == 0: # Check if the ellipse has zero radius
        points.append((center_x, center_y)) # Add the center point to the list and return it
        return points

    if a == 0: # Check if the ellipse is a horizontal line
        for y in range(center_y - b, center_y + b + 1):
            points.append((center_x, y)) # Add each point on the horizontal line to the list
        return points

    if b == 0: # Check if the ellipse is a vertical line
        for x in range(center_x - a, center_x + a + 1):
            points.append((x, center_y)) # Add each point on the vertical line to the list
        return points

    compute_ellipse_points(points, center_x, center_y, a, b) # Call the compute_ellipse_points function to calculate the ellipse points
    return points

def compute_ellipse_points(points, center_x, center_y, a, b):
    x = 0
    y = b
    d1 = b * b - a * a * b + 0.25 * a * a
    dx = 2 * b * b * x
    dy = 2 * a * a * y

    while dx < dy:
        add_ellipse_points(points, center_x, center_y, x, y) # Add the current ellipse point to the list

        if d1 < 0:
            x += 1
            dx += 2 * b * b
            d1 += dx + b * b
        else:
            x += 1
            y -= 1
            dx += 2 * b * b
            dy -= 2 * a * a
            d1 += dx - dy + b * b

    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b

    while y >= 0:
        add_ellipse_points(points, center_x, center_y, x, y) # Add the current ellipse point to the list

        if d2 > 0:
            y -= 1
            dy -= 2 * a * a
            d2 += a * a - dy
        else:
            y -= 1
            x += 1
            dx += 2 * b * b
            dy -= 2 * a * a
            d2 += dx - dy + a * a

def add_ellipse_points(points, center_x, center_y, x, y):
    points.append((center_x + x, center_y + y)) # Add the point with positive x and y coordinates to the list
    points.append((center_x - x, center_y + y)) # Add the point with negative x and positive y coordinates to the list
    points.append((center_x + x, center_y - y)) # Add the point with positive x and negative y coordinates to the list
    points.append((center_x - x, center_y - y)) # Add the point with negative x and negative y coordinates to the list

# Call the draw_ellipse function with the given input values
center_x = 1
center_y = 2
a = 3
b = 4

ellipse_points = draw_ellipse(center_x, center_y, a, b) # Calculate the ellipse points

# Print the ellipse points
print("Ellipse Points:")
for point in ellipse_points:
    print(point)

# End of code
