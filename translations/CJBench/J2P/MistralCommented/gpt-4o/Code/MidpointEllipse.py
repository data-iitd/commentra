import math

class Main:
    @staticmethod
    def draw_ellipse(center_x, center_y, a, b):
        points = []  # Create an empty list to store the ellipse points

        if a == 0 and b == 0:  # Check if the ellipse has zero radius
            points.append((center_x, center_y))  # Add the center point to the list and return it
            return points

        if a == 0:  # Check if the ellipse is a horizontal line
            for y in range(center_y - b, center_y + b + 1):
                points.append((center_x, y))  # Add each point on the horizontal line to the list
            return points

        if b == 0:  # Check if the ellipse is a vertical line
            for x in range(center_x - a, center_x + a + 1):
                points.append((x, center_y))  # Add each point on the vertical line to the list
            return points

        Main.compute_ellipse_points(points, center_x, center_y, a, b)  # Call the compute_ellipse_points method to calculate the ellipse points
        return points

    @staticmethod
    def compute_ellipse_points(points, center_x, center_y, a, b):
        x = 0
        y = b  # Initialize the x and y variables for the ellipse points calculation

        d1 = b * b - a * a * b + 0.25 * a * a  # Calculate the discriminant d1 for the ellipse points calculation

        dx = 2 * b * b * x
        dy = 2 * a * a * y  # Calculate the temporary variables dx and dy for the while loop condition

        while dx < dy:  # Iterate through the major half of the ellipse
            Main.add_ellipse_points(points, center_x, center_y, x, y)  # Add the current ellipse point to the list

            if d1 < 0:  # Check if the next point is on the left side of the ellipse
                x += 1  # Increment x and update dx
                dx += 2 * b * b
                d1 += dx + b * b
            else:  # Check if the next point is on the right side of the ellipse
                x += 1  # Increment x
                y -= 1  # Decrement y and update dy
                dx += 2 * b * b
                dy -= 2 * a * a
                d1 += dx - dy + b * b

        d2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b  # Calculate the discriminant d2 for the second half of the ellipse

        while y >= 0:  # Iterate through the minor half of the ellipse
            Main.add_ellipse_points(points, center_x, center_y, x, y)  # Add the current ellipse point to the list

            if d2 > 0:  # Check if the next point is below the ellipse
                y -= 1  # Decrement y and update dy
                dy -= 2 * a * a
                d2 += a * a - dy
            else:  # Check if the next point is above the ellipse
                y -= 1  # Decrement y
                x += 1  # Increment x and update dx
                dx += 2 * b * b
                dy -= 2 * a * a
                d2 += dx - dy + a * a

    @staticmethod
    def add_ellipse_points(points, center_x, center_y, x, y):
        points.append((center_x + x, center_y + y))  # Add the point with positive x and y coordinates to the list
        points.append((center_x - x, center_y + y))  # Add the point with negative x and positive y coordinates to the list
        points.append((center_x + x, center_y - y))  # Add the point with positive x and negative y coordinates to the list
        points.append((center_x - x, center_y - y))  # Add the point with negative x and negative y coordinates to the list

if __name__ == "__main__":
    center_x = int(input())  # Read the center X coordinate from the input
    center_y = int(input())  # Read the center Y coordinate from the input
    a = int(input())  # Read the major axis length from the input
    b = int(input())  # Read the minor axis length from the input

    points = Main.draw_ellipse(center_x, center_y, a, b)  # Call the draw_ellipse method to get the list of ellipse points

    print("Ellipse Points:")  # Print the header message for the list of ellipse points
    for point in points:  # Iterate through the list of points and print each point
        print(point[0], point[1])

