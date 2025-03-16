
import sys

def generate_circle_points(center_x, center_y, radius):
    # List to hold the points on the circle
    points = []
    
    # If the radius is zero, return the center point
    if radius == 0:
        points.append((center_x, center_y))
        return points
    
    # Initialize variables for the circle drawing algorithm
    x = radius
    y = 0
    p = 1 - radius
    
    # Add initial symmetric points for the circle
    add_symmetric_points(points, center_x, center_y, x, y)
    
    # Loop to calculate points using Bresenham's circle algorithm
    while x > y:
        y += 1  # Increment y coordinate
        
        # Update the decision parameter based on its value
        if p <= 0:
            p += 2 * y + 1  # Inside the circle
        else:
            x -= 1  # Move left in the x direction
            p += 2 * y - 2 * x + 1  # Outside the circle
        
        # Add symmetric points for the current (x, y)
        add_symmetric_points(points, center_x, center_y, x, y)
    
    # Return the list of points on the circle
    return points

def add_symmetric_points(points, center_x, center_y, x, y):
    # Add all eight symmetric points of the circle
    points.append((center_x + x, center_y + y))
    points.append((center_x - x, center_y + y))
    points.append((center_x + x, center_y - y))
    points.append((center_x - x, center_y - y))
    points.append((center_x + y, center_y + x))
    points.append((center_x - y, center_y + x))
    points.append((center_x + y, center_y - x))
    points.append((center_x - y, center_y - x))

# Main method to execute the program
def main():
    # Read the center coordinates and radius from user input
    try:
        center_x = int(input("Enter the x-coordinate of the center: "))
        center_y = int(input("Enter the y-coordinate of the center: "))
        radius = int(input("Enter the radius of the circle: "))
        
        # Generate the points on the circle
        circle_points = generate_circle_points(center_x, center_y, radius)
        print("The points on the circumference of the circle are:")
        
        # Print each point on the circle
        for point in circle_points:
            print(f"({point[0]}, {point[1]})")
    except ValueError:
        # Handle invalid input
        print("Invalid input! Please enter integers.")

if __name__ == "__main__":
    main()

