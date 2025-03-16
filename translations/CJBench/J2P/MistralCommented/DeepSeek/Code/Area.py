import math

# Error message for invalid radius
POSITIVE_RADIUS = "Must be a positive radius"

# Error message for invalid height
POSITIVE_HEIGHT = "Must be a positive height"

# Error message for invalid base
POSITIVE_BASE = "Must be a positive base"

# Method to calculate the surface area of a cube
def surface_main_cube(side_length: float) -> float:
    if side_length <= 0:  # Check if sideLength is valid
        raise ValueError("Must be a positive sideLength")
    return 6 * side_length * side_length  # Calculate the surface area

# Method to calculate the surface area of a sphere
def surface_main_sphere(radius: float) -> float:
    if radius <= 0:  # Check if radius is valid
        raise ValueError(POSITIVE_RADIUS)
    return 4 * math.pi * radius * radius  # Calculate the surface area

# Method to calculate the surface area of a rectangle
def surface_main_rectangle(length: float, width: float) -> float:
    if length <= 0:  # Check if length is valid
        raise ValueError("Must be a positive length")
    if width <= 0:  # Check if width is valid
        raise ValueError("Must be a positive width")
    return length * width  # Calculate the surface area

# Method to calculate the surface area of a cylinder
def surface_main_cylinder(radius: float, height: float) -> float:
    if radius <= 0:  # Check if radius is valid
        raise ValueError(POSITIVE_RADIUS)
    if height <= 0:  # Check if height is valid
        raise ValueError(POSITIVE_HEIGHT)
    return 2 * (math.pi * radius * radius + math.pi * radius * height)  # Calculate the surface area

# Method to calculate the surface area of a square
def surface_main_square(side_length: float) -> float:
    if side_length <= 0:  # Check if sideLength is valid
        raise ValueError("Must be a positive sideLength")
    return side_length * side_length  # Calculate the surface area

# Method to calculate the surface area of a triangle
def surface_main_triangle(base: float, height: float) -> float:
    if base <= 0:  # Check if base is valid
        raise ValueError(POSITIVE_BASE)
    if height <= 0:  # Check if height is valid
        raise ValueError(POSITIVE_HEIGHT)
    return base * height / 2  # Calculate the surface area using the formula: 1/2 * base * height

# Method to calculate the surface area of a parallelogram
def surface_main_parallelogram(base: float, height: float) -> float:
    if base <= 0:  # Check if base is valid
        raise ValueError(POSITIVE_BASE)
    if height <= 0:  # Check if height is valid
        raise ValueError(POSITIVE_HEIGHT)
    return base * height  # Calculate the surface area

# Method to calculate the surface area of a trapezium
def surface_main_trapezium(base1: float, base2: float, height: float) -> float:
    if base1 <= 0:  # Check if base1 is valid
        raise ValueError(POSITIVE_BASE + " 1")
    if base2 <= 0:  # Check if base2 is valid
        raise ValueError(POSITIVE_BASE + " 2")
    if height <= 0:  # Check if height is valid
        raise ValueError(POSITIVE_HEIGHT)
    return (base1 + base2) * height / 2  # Calculate the surface area using the formula: 1/2 * (base1 + base2) * height

# Method to calculate the surface area of a circle
def surface_main_circle(radius: float) -> float:
    if radius <= 0:  # Check if radius is valid
        raise ValueError(POSITIVE_RADIUS)
    return math.pi * radius * radius  # Calculate the surface area

# Method to calculate the surface area of a hemisphere
def surface_main_hemisphere(radius: float) -> float:
    if radius <= 0:  # Check if radius is valid
        raise ValueError(POSITIVE_RADIUS)
    return 3 * math.pi * radius * radius  # Calculate the surface area

# Method to calculate the surface area of a cone
def surface_main_cone(radius: float, height: float) -> float:
    if radius <= 0:  # Check if radius is valid
        raise ValueError(POSITIVE_RADIUS)
    if height <= 0:  # Check if height is valid
        raise ValueError(POSITIVE_HEIGHT)
    return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))  # Calculate the surface area

# Main method to read user input and calculate the surface area based on the shape selected
def main():
    choice = int(input())  # Read the user's choice of shape

    result = 0.0  # Initialize the result variable to store the calculated surface area

    if choice == 1:
        side = float(input())  # Read the side length of the cube from the user
        result = surface_main_cube(side)  # Calculate the surface area of the cube
    elif choice == 2:
        radius_sphere = float(input())  # Read the radius of the sphere from the user
        result = surface_main_sphere(radius_sphere)  # Calculate the surface area of the sphere
    elif choice == 3:
        length = float(input())  # Read the length of the rectangle from the user
        width = float(input())  # Read the width of the rectangle from the user
        result = surface_main_rectangle(length, width)  # Calculate the surface area of the rectangle
    elif choice == 4:
        radius_cylinder = float(input())  # Read the radius of the cylinder from the user
        height_cylinder = float(input())  # Read the height of the cylinder from the user
        result = surface_main_cylinder(radius_cylinder, height_cylinder)  # Calculate the surface area of the cylinder
    elif choice == 5:
        side_square = float(input())  # Read the side length of the square from the user
        result = surface_main_square(side_square)  # Calculate the surface area of the square
    elif choice == 6:
        base_triangle = float(input())  # Read the base of the triangle from the user
        height_triangle = float(input())  # Read the height of the triangle from the user
        result = surface_main_triangle(base_triangle, height_triangle)  # Calculate the surface area of the triangle
    elif choice == 7:
        base_parallelogram = float(input())  # Read the base of the parallelogram from the user
        height_parallelogram = float(input())  # Read the height of the parallelogram from the user
        result = surface_main_parallelogram(base_parallelogram, height_parallelogram)  # Calculate the surface area of the parallelogram
    elif choice == 8:
        base1 = float(input())  # Read the base1 of the trapezium from the user
        base2 = float(input())  # Read the base2 of the trapezium from the user
        height_trapezium = float(input())  # Read the height of the trapezium from the user
        result = surface_main_trapezium(base1, base2, height_trapezium)  # Calculate the surface area of the trapezium
    elif choice == 9:
        radius_circle = float(input())  # Read the radius of the circle from the user
        result = surface_main_circle(radius_circle)  # Calculate the surface area of the circle
    elif choice == 10:
        radius_hemisphere = float(input())  # Read the radius of the hemisphere from the user
        result = surface_main_hemisphere(radius_hemisphere)  # Calculate the surface area of the hemisphere
    elif choice == 11:
        radius_cone = float(input())  # Read the radius of the cone from the user
        height_cone = float(input())  # Read the height of the cone from the user
        result = surface_main_cone(radius_cone, height_cone)  # Calculate the surface area of the cone
    else:
        print("Invalid choice")  # Print an error message if the user enters an invalid choice
        return  # Exit the program if the user enters an invalid choice

    print(f"Calculated Main: {result:.2f}")  # Print the calculated surface area

# Call the main method
main()
