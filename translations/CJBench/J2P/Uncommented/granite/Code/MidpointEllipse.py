

import math
def draw_ellipse(center_x, center_y, a, b):
    points = []
    if a == 0 and b == 0:
        points.append((center_x, center_y))
        return points
    if a == 0:
        for y in range(center_y - b, center_y + b + 1):
            points.append((center_x, y))
        return points
    if b == 0:
        for x in range(center_x - a, center_x + a + 1):
            points.append((x, center_y))
        return points
    compute_ellipse_points(points, center_x, center_y, a, b)
    return points

def compute_ellipse_points(points, center_x, center_y, a, b):
    x = 0
    y = b
    d1 = b * b - a * a * b + 0.25 * a * a
    dx = 2 * b * b * x
    dy = 2 * a * a * y
    while dx < dy:
        add_ellipse_points(points, center_x, center_y, x, y)
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
        add_ellipse_points(points, center_x, center_y, x, y)
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
    points.append((center_x + x, center_y + y))
    points.append((center_x - x, center_y + y))
    points.append((center_x + x, center_y - y))
    points.append((center_x - x, center_y - y))

# 