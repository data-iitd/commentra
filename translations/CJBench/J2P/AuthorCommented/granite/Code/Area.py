
import math

# Find the area of various geometric shapes

# String of IllegalArgumentException for radius
POSITIVE_RADIUS = "Must be a positive radius"

# String of IllegalArgumentException for height
POSITIVE_HEIGHT = "Must be a positive height"

# String of IllegalArgumentException for base
POSITIVE_BASE = "Must be a positive base"

# Calculate the surface area of a cube.
def surface_main_cube(side_length):
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    return 6 * side_length * side_length

# Calculate the surface area of a sphere.
def surface_main_sphere(radius):
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    return 4 * math.pi * radius * radius

# Calculate the area of a rectangle.
def surface_main_rectangle(length, width):
    if length <= 0:
        raise ValueError("Must be a positive length")
    if width <= 0:
        raise ValueError("Must be a positive width")
    return length * width

# Calculate surface area of a cylinder.
def surface_main_cylinder(radius, height):
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    return 2 * (math.pi * radius * radius + math.pi * radius * height)

# Calculate the area of a square.
def surface_main_square(side_length):
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    return side_length * side_length

# Calculate the area of a triangle.
def surface_main_triangle(base, height):
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    return base * height / 2

# Calculate the area of a parallelogram.
def surface_main_parallelogram(base, height):
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    return base * height

# Calculate the area of a trapezium.
def surface_main_trapezium(base1, base2, height):
    if base1 <= 0:
        raise ValueError(POSITIVE_BASE + 1)
    if base2 <= 0:
        raise ValueError(POSITIVE_BASE + 2)
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    return (base1 + base2) * height / 2

# Calculate the area of a circle.
def surface_main_circle(radius):
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    return math.pi * radius * radius

# Calculate the surface area of a hemisphere.
def surface_main_hemisphere(radius):
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    return 3 * math.pi * radius * radius

# Calculate the surface area of a cone.
def surface_main_cone(radius, height):
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))

if __name__ == "__main__":
    choice = int(input())

    result = 0.0
    if choice == 1:
        side = float(input("Enter side length: "))
        result = surface_main_cube(side)
    elif choice == 2:
        radius_sphere = float(input("Enter radius: "))
        result = surface_main_sphere(radius_sphere)
    elif choice == 3:
        length = float(input("Enter length and width: "))
        width = float(input())
        result = surface_main_rectangle(length, width)
    elif choice == 4:
        radius_cylinder = float(input("Enter radius and height: "))
        height_cylinder = float(input())
        result = surface_main_cylinder(radius_cylinder, height_cylinder)
    elif choice == 5:
        side_square = float(input("Enter side length: "))
        result = surface_main_square(side_square)
    elif choice == 6:
        base_triangle = float(input("Enter base and height: "))
        height_triangle = float(input())
        result = surface_main_triangle(base_triangle, height_triangle)
    elif choice == 7:
        base_parallelogram = float(input("Enter base and height: "))
        height_parallelogram = float(input())
        result = surface_main_parallelogram(base_parallelogram, height_parallelogram)
    elif choice == 8:
        base1 = float(input("Enter base1, base2 and height: "))
        base2 = float(input())
        height_trapezium = float(input())
        result = surface_main_trapezium(base1, base2, height_trapezium)
    elif choice == 9:
        radius_circle = float(input("Enter radius: "))
        result = surface_main_circle(radius_circle)
    elif choice == 10:
        radius_hemisphere = float(input("Enter radius: "))
        result = surface_main_hemisphere(radius_hemisphere)
    elif choice == 11:
        radius_cone = float(input("Enter radius and height: "))
        height_cone = float(input())
        result = surface_main_cone(radius_cone, height_cone)
    else:
        print("Invalid choice")
        exit(1)

    print(f"Calculated Main: {result:.2f}")

