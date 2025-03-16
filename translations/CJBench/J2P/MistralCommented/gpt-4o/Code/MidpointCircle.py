import math

def generate_circle_points(center_x, center_y, radius):
    points = []  # Initialize an empty list to store the circle points

    if radius == 0:  # Check if the radius is zero
        points.append((center_x, center_y))  # Add the center point to the list if the radius is zero
        return points  # Return the list with the center point

    x = radius  # Initialize x and y variables for calculating the circle points
    y = 0
    p = 1 - radius  # Initialize the decision variable p

    add_symmetric_points(points, center_x, center_y, x, y)  # Add the first four symmetric points to the list

    while x > y:  # Iterate while x is greater than y
        y += 1  # Increment y

        if p <= 0:  # Check the condition for the decision variable p
            p = p + 2 * y + 1  # Update the value of p
        else:  # If the condition is not met, update x and p
            x -= 1
            p = p + 2 * y - 2 * x + 1

        add_symmetric_points(points, center_x, center_y, x, y)  # Add the next four symmetric points to the list

    return points  # Return the list of circle points

def add_symmetric_points(points, center_x, center_y, x, y):
    # Add the eight symmetric points to the list
    points.append((center_x + x, center_y + y))
    points.append((center_x - x, center_y + y))
    points.append((center_x + x, center_y - y))
    points.append((center_x - x, center_y - y))
    points.append((center_x + y, center_y + x))
    points.append((center_x - y, center_y + x))
    points.append((center_x + y, center_y - x))
    points.append((center_x - y, center_y - x))

def main():
    try:
        center_x = int(input("Enter the center x-coordinate: "))  # Read the center x-coordinate from the user
        center_y = int(input("Enter the center y-coordinate: "))  # Read the center y-coordinate from the user
        radius = int(input("Enter the radius: "))  # Read the radius from the user

        circle_points = generate_circle_points(center_x, center_y, radius)  # Generate the circle points

        print("The points on the circumference of the circle are:")  # Print a message to the console
        for point in circle_points:  # Iterate through the list of circle points
            print(f"({point[0]}, {point[1]})")  # Print each point to the console
    except ValueError:
        print("Invalid input! Please enter integers.")  # Print an error message if the user enters invalid input

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
