class Clipper:
    def __init__(self, x_min, y_min, x_max, y_max):
        # Initialize the clipping window bounds
        self.x_min = x_min
        self.y_min = y_min
        self.x_max = x_max
        self.y_max = y_max

    def liang_barsky_clip(self, x1, y1, x2, y2):
        # Calculate the direction vector and the difference vector between the endpoints of the line
        dx = x2 - x1
        dy = y2 - y1
        p = [-dx, dx, -dy, dy]  # The direction vector
        q = [x1 - self.x_min, self.x_max - x1, y1 - self.y_min, self.y_max - y1]  # The vector from the origin to the line endpoints

        # Clip the line against the clipping window boundaries
        result_t = self.clip_line(p, q)

        # If the line is completely outside the clipping window, return None
        if result_t is None:
            return None

        # Calculate the clipped line endpoints
        return self.calculate_clipped_line(x1, y1, dx, dy, result_t[0], result_t[1])

    def clip_line(self, p, q):
        # Initialize the t0 and t1 variables to represent the clipped line endpoints
        t0 = 0.0
        t1 = 1.0

        # Iterate through each boundary plane and check for intersection
        for i in range(4):
            # If the direction vector is parallel to the boundary plane, return None
            if p[i] == 0:
                if q[i] < 0:
                    # The line starts inside the clipping window, so no clipping is needed
                    return [t0, t1]
                return None  # The line is completely outside the clipping window

            # Calculate the intersection point t of the line with the boundary plane
            t = q[i] / p[i]

            # If the line starts before the boundary plane, update t0
            if p[i] < 0:
                t0 = max(t0, t)
                if t0 > t1:
                    return None  # The line is completely clipped

            # If the line ends after the boundary plane, update t1
            elif p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0:
                    return None  # The line is completely clipped

        # If the line is completely clipped, return None
        if t1 < 0:
            return None

        # Otherwise, return the clipped line endpoints
        return [t0, t1]

    def calculate_clipped_line(self, x1, y1, dx, dy, t0, t1):
        # Calculate the clipped line endpoints
        clipped_x1 = x1 + t0 * dx
        clipped_y1 = y1 + t0 * dy
        clipped_x2 = x1 + t1 * dx
        clipped_y2 = y1 + t1 * dy

        # Return the clipped line endpoints as a list
        return [clipped_x1, clipped_y1, clipped_x2, clipped_y2]


if __name__ == "__main__":
    # Read the clipping window bounds from the standard input
    x_min = float(input())
    y_min = float(input())
    x_max = float(input())
    y_max = float(input())

    # Read the line endpoints from the standard input
    x1 = float(input())
    y1 = float(input())
    x2 = float(input())
    y2 = float(input())

    # Create a Clipper object with the clipping window bounds
    clipper = Clipper(x_min, y_min, x_max, y_max)

    # Clip the line using the Liang-Barsky algorithm and print the result
    clipped_line = clipper.liang_barsky_clip(x1, y1, x2, y2)
    if clipped_line is not None:
        print(f"Clipped Line: ({clipped_line[0]:.2f}, {clipped_line[1]:.2f}) to ({clipped_line[2]:.2f}, {clipped_line[3]:.2f})")
    else:
        print("The line is completely outside the clipping window.")

# <END-OF-CODE>
