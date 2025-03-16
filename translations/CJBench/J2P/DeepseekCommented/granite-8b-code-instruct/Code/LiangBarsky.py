
import sys

class Main:
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
        t0 = 0.0
        t1 = 1.0
        for i in range(4):
            if p[i] == 0 and q[i] < 0:
                return None
            t = q[i] / p[i]
            if p[i] < 0:
                t0 = max(t0, t)
                if t0 > t1:
                    return None
            elif p[i] > 0:
                t1 = min(t1, t)
                if t1 < t0:
                    return None
        clipped_x1 = x1 + t0 * dx
        clipped_y1 = y1 + t0 * dy
        clipped_x2 = x1 + t1 * dx
        clipped_y2 = y1 + t1 * dy
        return [clipped_x1, clipped_y1, clipped_x2, clipped_y2]

if __name__ == "__main__":
    x_min, y_min, x_max, y_max = map(float, input().split())
    x1, y1, x2, y2 = map(float, input().split())
    clipper = Main(x_min, y_min, x_max, y_max)
    clipped_line = clipper.liang_barsky_clip(x1, y1, x2, y2)
    if clipped_line is not None:
        print("Clipped Line: ({:.2f}, {:.2f}) to ({:.2f}, {:.2f})".format(clipped_line[0], clipped_line[1], clipped_line[2], clipped_line[3]))
    else:
        print("The line is completely outside the clipping window.")

