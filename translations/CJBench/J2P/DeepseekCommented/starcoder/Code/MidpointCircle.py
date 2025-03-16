import sys

def generate_circle_points(center_x, center_y, radius):
    points = []
    if radius == 0:
        points.append((center_x, center_y))
        return points
    x = radius
    y = 0
    p = 1 - radius
    while x > y:
        y += 1
        if p <= 0:
            p = p + 2 * y + 1
        else:
            x -= 1
            p = p + 2 * y - 2 * x + 1
        points.append((center_x + x, center_y + y))
        points.append((center_x - x, center_y + y))
        points.append((center_x + x, center_y - y))
        points.append((center_x - x, center_y - y))
        points.append((center_x + y, center_y + x))
        points.append((center_x - y, center_y + x))
        points.append((center_x + y, center_y - x))
        points.append((center_x - y, center_y - x))
    return points

def main():
    try:
        center_x = int(sys.argv[1])
        center_y = int(sys.argv[2])
        radius = int(sys.argv[3])
        circle_points = generate_circle_points(center_x, center_y, radius)
        print("The points on the circumference of the circle are:")
        for point in circle_points:
            print("({}, {})".format(point[0], point[1]))
    except Exception:
        print("Invalid input! Please enter integers.")

if __name__ == "__main__":
    main()

# 