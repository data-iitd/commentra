

import sys

# Define the clipping window
x_min, y_min, x_max, y_max = map(float, input().split())

# Define the line
x1, y1, x2, y2 = map(float, input().split())

# Define the Liang-Barsky line clipping algorithm
def liang_barsky_clip(x1, y1, x2, y2):
    dx = x2 - x1
    dy = y2 - y1

    p = [-dx, dx, -dy, dy]
    q = [x1 - x_min, x_max - x1, y1 - y_min, y_max - y1]

    def clip_line(p, q):
        t0 = 0.0
        t1 = 1.0

        for i in range(4):
            if p[i] == 0 and q[i] < 0:
                return None  # Line is outside the boundary
            t = q[i] / p[i]
            if p[i] < 0:
                t0 = max(t0, t)
                if t0 > t1:
                    return None
            else:
                t1 = min(t1, t)
                if t1 < t0:
                    return None

        return [t0, t1]  # Return valid t0 and t1

    def calculate_clipped_line(x1, y1, dx, dy, t0, t1):
        clipped_x1 = x1 + t0 * dx
        clipped_y1 = y1 + t0 * dy
        clipped_x2 = x1 + t1 * dx
        clipped_y2 = y1 + t1 * dy

        return [clipped_x1, clipped_y1, clipped_x2, clipped_y2]

    result_t = clip_line(p, q)

    if result_t is None:
        return None  # Line is completely outside the clipping window

    return calculate_clipped_line(x1, y1, dx, dy, result_t[0], result_t[1])

# Run the Liang-Barsky line clipping algorithm
clipped_line = liang_barsky_clip(x1, y1, x2, y2)

if clipped_line is not None:
    print(f"Clipped Line: ({clipped_line[0]:.2f}, {clipped_line[1]:.2f}) to ({clipped_line[2]:.2f}, {clipped_line[3]:.2f})")
else:
    print("The line is completely outside the clipping window.")

