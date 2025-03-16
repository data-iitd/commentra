class LiangBarskyClipper:
    def __init__(self, x_min, y_min, x_max, y_max):
        self.x_min = x_min
        self.y_min = y_min
        self.x_max = x_max
        self.y_max = y_max

    def liang_barsky_clip(self, x1, y1, x2, y2):
        dx = x2 - x1
        dy = y2 - y1

        p = [-dx, dx, -dy, dy]
        q = [x1 - self.x_min, self.x_max - x1, y1 - self.y_min, self.y_max - y1]

        result_t = self.clip_line(p, q)

        if result_t is None:
            return None  # Line is completely outside the clipping window

        return self.calculate_clipped_line(x1, y1, dx, dy, result_t[0], result_t[1])

    def clip_line(self, p, q):
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
            elif p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0:
                    return None

        return [t0, t1]  # Return valid t0 and t1

    def calculate_clipped_line(self, x1, y1, dx, dy, t0, t1):
        clipped_x1 = x1 + t0 * dx
        clipped_y1 = y1 + t0 * dy
        clipped_x2 = x1 + t1 * dx
        clipped_y2 = y1 + t1 * dy

        return [clipped_x1, clipped_y1, clipped_x2, clipped_y2]


def main():
    import sys
    input_data = sys.stdin.read().split()

    # Input clipping window
    x_min = float(input_data[0])
    y_min = float(input_data[1])
    x_max = float(input_data[2])
    y_max = float(input_data[3])

    # Input line coordinates
    x1 = float(input_data[4])
    y1 = float(input_data[5])
    x2 = float(input_data[6])
    y2 = float(input_data[7])

    clipper = LiangBarskyClipper(x_min, y_min, x_max, y_max)
    clipped_line = clipper.liang_barsky_clip(x1, y1, x2, y2)

    if clipped_line is not None:
        print(f"Clipped Line: ({clipped_line[0]:.2f}, {clipped_line[1]:.2f}) to ({clipped_line[2]:.2f}, {clipped_line[3]:.2f})")
    else:
        print("The line is completely outside the clipping window.")


if __name__ == "__main__":
    main()
