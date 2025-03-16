
import math
def draw_ellipse(center_x, center_y, a, b):
    points = [] # Initialize a list to store the ellipse points
    if a == 0 and b == 0:
        points.append((center_x, center_y)) # If both axes are zero, add the center point
        return points
    if a == 0:
        for y in range(center_y - b, center_y + b + 1): # If a is zero, draw a vertical line
            points.append((center_x, y))
        return points
    if b == 0:
        for x in range(center_x - a, center_x + a + 1): # If b is zero, draw a horizontal line
            points.append((x, center_y))
        return points
    compute_ellipse_points(points, center_x, center_y, a, b) # Compute the ellipse points using the midpoint algorithm
    return points

def compute_ellipse_points(points, center_x, center_y, a, b):
    x = 0
    y = b
    d1 = b * b - a * a * b + 0.25 * a * a
    dx = 2 * b * b * x
    dy = 2 * a * a * y
    while dx < dy:
        add_ellipse_points(points, center_x, center_y, x, y) # Add the symmetric points to the list
        if d1 < 0:
            x += 1 # Move along the x-axis
            dx += 2 * b * b # Update dx
            d1 += dx + b * b # Update d1
        else:
            x += 1 # Move along the x-axis
            y -= 1 # Move along the y-axis
            dx += 2 * b * b # Update dx
            dy -= 2 * a * a # Update dy
            d1 += dx - dy + b * b # Update d1
    d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b
    while y >= 0:
        add_ellipse_points(points, center_x, center_y, x, y) # Add the symmetric points to the list
        if d2 > 0:
            y -= 1 # Move along the y-axis
            dy -= 2 * a * a # Update dy
            d2 += a * a - dy # Update d2
        else:
            y -= 1 # Move along the y-axis
            x += 1 # Move along the x-axis
            dx += 2 * b * b # Update dx
            dy -= 2 * a * a # Update dy
            d2 += dx - dy + a * a # Update d2

def add_ellipse_points(points, center_x, center_y, x, y):
    points.append((center_x + x, center_y + y)) # Add the point (center_x + x, center_y + y)
    points.append((center_x - x, center_y + y)) # Add the point (center_x - x, center_y + y)
    points.append((center_x + x, center_y - y)) # Add the point (center_x + x, center_y - y)
    points.append((center_x - x, center_y - y)) # Add the point (center_x - x, center_y - y)

# Test the function
center_x = 0
center_y = 0
a = 3
b = 2
points = draw_ellipse(center_x, center_y, a, b)
print("Ellipse Points:")
for point in points:
    print(point)

