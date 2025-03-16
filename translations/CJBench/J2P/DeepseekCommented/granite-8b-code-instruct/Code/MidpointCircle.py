
import math

def generate_circle_points(center_x, center_y, radius):
    points = []
    # If the radius is 0, return the center point.
    if radius == 0:
        points.append((center_x, center_y))
        return points
    # Initialize variables for the algorithm.
    x = radius
    y = 0
    p = 1 - radius
    # Add the initial symmetric points.
    add_symmetric_points(points, center_x, center_y, x, y)
    # Loop to generate points in the first octant and mirror them.
    while x > y:
        y += 1
        if p <= 0:
            p = p + 2 * y + 1
        else:
            x -= 1
            p = p + 2 * y - 2 * x + 1
        add_symmetric_points(points, center_x, center_y, x, y)
    return points

# Adds symmetric points around the circle's circumference.
def add_symmetric_points(points, center_x, center_y, x, y):
    points.append((center_x + x, center_y + y))
    points.append((center_x - x, center_y + y))
    points.append((center_x + x, center_y - y))
    points.append((center_x - x, center_y - y))
    points.append((center_x + y, center_y + x))
    points.append((center_x - y, center_y + x))
    points.append((center_x + y, center_y - x))
    points.append((center_x - y, center_y - x))

# Entry point of the program. Reads input, generates circle points, and prints them.
def main():
    try:
        center_x = int(input("Enter the x-coordinate of the center of the circle: "))
        center_y = int(input("Enter the y-coordinate of the center of the circle: "))
        radius = int(input("Enter the radius of the circle: "))
        circle_points = generate_circle_points(center_x, center_y, radius)
        print("The points on the circumference of the circle are:")
        for point in circle_points:
            print(f"({point[0]}, {point[1]})")
    except ValueError:
        print("Invalid input! Please enter integers.")

if __name__ == "__main__":
    main()

