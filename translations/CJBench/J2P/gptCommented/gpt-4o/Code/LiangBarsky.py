class Clipper:
    def __init__(self, x_min, y_min, x_max, y_max):
        # Define the boundaries of the clipping window
        self.x_min = x_min
        self.y_min = y_min
        self.x_max = x_max
        self.y_max = y_max

    def liang_barsky_clip(self, x1, y1, x2, y2):
        # Calculate the differences in x and y coordinates
        dx = x2 - x1
        dy = y2 - y1

        # Define the parameters for the Liang-Barsky algorithm
        p = [-dx, dx, -dy, dy]
        q = [x1 - self.x_min, self.x_max - x1, y1 - self.y_min, self.y_max - y1]

        # Call the clipping function to get the parameter values
        result_t = self.clip_line(p, q)

        # If the line is completely outside the clipping window, return None
        if result_t is None:
            return None

        # Calculate the coordinates of the clipped line segment
        return self.calculate_clipped_line(x1, y1, dx, dy, result_t[0], result_t[1])

    def clip_line(self, p, q):
        t0 = 0.0  # Start parameter
        t1 = 1.0  # End parameter

        # Iterate over each of the four edges of the clipping window
        for i in range(4):
            # Check for parallel lines outside the clipping window
            if p[i] == 0 and q[i] < 0:
                return None
            t = q[i] / p[i]  # Calculate the intersection parameter

            # Update t0 and t1 based on the direction of the line
            if p[i] < 0:
                t0 = max(t0, t)  # Update t0 for negative p
                if t0 > t1:
                    return None  # No intersection
            elif p[i] > 0:
                t1 = min(t1, t)  # Update t1 for positive p
                if t1 < t0:
                    return None  # No intersection

        # Return the final parameter values for the clipped line
        return [t0, t1]

    def calculate_clipped_line(self, x1, y1, dx, dy, t0, t1):
        # Calculate the start and end points of the clipped line
        clipped_x1 = x1 + t0 * dx
        clipped_y1 = y1 + t0 * dy
        clipped_x2 = x1 + t1 * dx
        clipped_y2 = y1 + t1 * dy

        # Return the coordinates of the clipped line segment
        return [clipped_x1, clipped_y1, clipped_x2, clipped_y2]


if __name__ == "__main__":
    # Read the clipping window boundaries from user input
    x_min = float(input())
    y_min = float(input())
    x_max = float(input())
    y_max = float(input())

    # Read the coordinates of the line segment to be clipped
    x1 = float(input())
    y1 = float(input())
    x2 = float(input())
    y2 = float(input())

    # Create an instance of the Clipper class with the clipping window
    clipper = Clipper(x_min, y_min, x_max, y_max)

    # Perform the clipping operation
    clipped_line = clipper.liang_barsky_clip(x1, y1, x2, y2)

    # Output the result of the clipping operation
    if clipped_line is not None:
        print(f"Clipped Line: ({clipped_line[0]:.2f}, {clipped_line[1]:.2f}) to ({clipped_line[2]:.2f}, {clipped_line[3]:.2f})")
    else:
        print("The line is completely outside the clipping window.")

# <END-OF-CODE>
