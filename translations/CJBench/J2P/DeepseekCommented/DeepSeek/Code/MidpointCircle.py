def generate_circle_points(centerX, centerY, radius):
    points = []
    if radius == 0:
        points.append([centerX, centerY])
        return points
    x = radius
    y = 0
    p = 1 - radius
    add_symmetric_points(points, centerX, centerY, x, y)
    while x > y:
        y += 1
        if p <= 0:
            p = p + 2 * y + 1
        else:
            x -= 1
            p = p + 2 * y - 2 * x + 1
        add_symmetric_points(points, centerX, centerY, x, y)
    return points


def add_symmetric_points(points, centerX, centerY, x, y):
    points.append([centerX + x, centerY + y])
    points.append([centerX - x, centerY + y])
    points.append([centerX + x, centerY - y])
    points.append([centerX - x, centerY - y])
    points.append([centerX + y, centerY + x])
    points.append([centerX - y, centerY + x])
    points.append([centerX + y, centerY - x])
    points.append([centerX - y, centerY - x])


def main():
    try:
        centerX = int(input())
        centerY = int(input())
        radius = int(input())
        circle_points = generate_circle_points(centerX, centerY, radius)
        print("The points on the circumference of the circle are:")
        for point in circle_points:
            print(f"({point[0]}, {point[1]})")
    except ValueError:
        print("Invalid input! Please enter integers.")


main()
