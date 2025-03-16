
import sys

class Main:

    def __init__(self):
        # Private Constructor to prevent instantiation.
        pass

    @staticmethod
    def generate_circle_points(center_x, center_y, radius):
        points = []

        # Special case for radius 0, only the center point should be added.
        if radius == 0:
            points.append([center_x, center_y])
            return points

        # Start at (radius, 0)
        x = radius
        y = 0

        # Decision parameter
        p = 1 - radius

        # Add the initial points in all octants
        Main.add_symmetric_points(points, center_x, center_y, x, y)

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
            Main.add_symmetric_points(points, center_x, center_y, x, y)

        return points

    @staticmethod
    def add_symmetric_points(points, center_x, center_y, x, y):
        # Octant symmetry points
        points.append([center_x + x, center_y + y])
        points.append([center_x - x, center_y + y])
        points.append([center_x + x, center_y - y])
        points.append([center_x - x, center_y - y])
        points.append([center_x + y, center_y + x])
        points.append([center_x - y, center_y + x])
        points.append([center_x + y, center_y - x])
        points.append([center_x - y, center_y - x])

    def main(self):
        try:
            center_x = int(input())
            center_y = int(input())

            radius = int(input())

            circle_points = Main.generate_circle_points(center_x, center_y, radius)

            print("The points on the circumference of the circle are:")
            for point in circle_points:
                print("({}, {})".format(point[0], point[1]))
        except Exception as e:
            print("Invalid input! Please enter integers.")

if __name__ == "__main__":
    Main().main()

