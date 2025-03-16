import math

# Constants for validation messages
POSITIVE_RADIUS = "Must be a positive radius"
POSITIVE_HEIGHT = "Must be a positive height"
POSITIVE_BASE = "Must be a positive base"

# Methods to calculate the surface area of various shapes
def surface_main_cube(side_length):
    # Check if the side length is positive
    if side_length <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a cube
    return 6 * side_length * side_length

def surface_main_sphere(radius):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a sphere
    return 4 * math.pi * radius * radius

def surface_main_rectangle(length, width):
    # Check if the length is positive
    if length <= 0:
        raise ValueError("Must be a positive length")
    # Check if the width is positive
    if width <= 0:
        raise ValueError("Must be a positive width")
    # Calculate the surface area of a rectangle
    return length * width

def surface_main_cylinder(radius, height):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a cylinder
    return 2 * (math.pi * radius * radius + math.pi * radius * height)

def surface_main_square(side_length):
    # Check if the side length is positive
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    # Calculate the surface area of a square
    return side_length * side_length

def surface_main_triangle(base, height):
    # Check if the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a triangle
    return base * height / 2

def surface_main_parallelogram(base, height):
    # Check if the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a parallelogram
    return base * height

def surface_main_trapezium(base1, base2, height):
    # Check if the first base is positive
    if base1 <= 0:
        raise ValueError(POSITIVE_BASE + 1)
    # Check if the second base is positive
    if base2 <= 0:
        raise ValueError(POSITIVE_BASE + 2)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a trapezium
    return (base1 + base2) * height / 2

def surface_main_circle(radius):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a circle
    return math.pi * radius * radius

def surface_main_hemisphere(radius):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a hemisphere
    return 3 * math.pi * radius * radius

def surface_main_cone(radius, height):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a cone
    return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))

# Main method to read user input and calculate the surface area based on the choice
def main():
    choice = int(input())
    result = 0.0
    if choice == 1:
        side = float(input())
        result = surface_main_cube(side)
    elif choice == 2:
        radius_sphere = float(input())
        result = surface_main_sphere(radius_sphere)
    elif choice == 3:
        length = float(input())
        width = float(input())
        result = surface_main_rectangle(length, width)
    elif choice == 4:
        radius_cylinder = float(input())
        height_cylinder = float(input())
        result = surface_main_cylinder(radius_cylinder, height_cylinder)
    elif choice == 5:
        side_square = float(input())
        result = surface_main_square(side_square)
    elif choice == 6:
        base_triangle = float(input())
        height_triangle = float(input())
        result = surface_main_triangle(base_triangle, height_triangle)
    elif choice == 7:
        base_parallelogram = float(input())
        height_parallelogram = float(input())
        result = surface_main_parallelogram(base_parallelogram, height_parallelogram)
    elif choice == 8:
        base1 = float(input())
        base2 = float(input())
        height_trapezium = float(input())
        result = surface_main_trapezium(base1, base2, height_trapezium)
    elif choice == 9:
        radius_circle = float(input())
        result = surface_main_circle(radius_circle)
    elif choice == 10:
        radius_hemisphere = float(input())
        result = surface_main_hemisphere(radius_hemisphere)
    elif choice == 11:
        radius_cone = float(input())
        height_cone = float(input())
        result = surface_main_cone(radius_cone, height_cone)
    else:
        print("Invalid choice")
        return
    print("Calculated Main: %.2f" % result)

if __name__ == "__main__":
    main()

