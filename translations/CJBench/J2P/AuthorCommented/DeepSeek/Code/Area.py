import math

def surface_main_cube(side_length):
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    return 6 * side_length * side_length

def surface_main_sphere(radius):
    if radius <= 0:
        raise ValueError("Must be a positive radius")
    return 4 * math.pi * radius * radius

def surface_main_rectangle(length, width):
    if length <= 0:
        raise ValueError("Must be a positive length")
    if width <= 0:
        raise ValueError("Must be a positive width")
    return length * width

def surface_main_cylinder(radius, height):
    if radius <= 0:
        raise ValueError("Must be a positive radius")
    if height <= 0:
        raise ValueError("Must be a positive height")
    return 2 * (math.pi * radius * radius + math.pi * radius * height)

def surface_main_square(side_length):
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    return side_length * side_length

def surface_main_triangle(base, height):
    if base <= 0:
        raise ValueError("Must be a positive base")
    if height <= 0:
        raise ValueError("Must be a positive height")
    return base * height / 2

def surface_main_parallelogram(base, height):
    if base <= 0:
        raise ValueError("Must be a positive base")
    if height <= 0:
        raise ValueError("Must be a positive height")
    return base * height

def surface_main_trapezium(base1, base2, height):
    if base1 <= 0:
        raise ValueError("Must be a positive base1")
    if base2 <= 0:
        raise ValueError("Must be a positive base2")
    if height <= 0:
        raise ValueError("Must be a positive height")
    return (base1 + base2) * height / 2

def surface_main_circle(radius):
    if radius <= 0:
        raise ValueError("Must be a positive radius")
    return math.pi * radius * radius

def surface_main_hemisphere(radius):
    if radius <= 0:
        raise ValueError("Must be a positive radius")
    return 3 * math.pi * radius * radius

def surface_main_cone(radius, height):
    if radius <= 0:
        raise ValueError("Must be a positive radius")
    if height <= 0:
        raise ValueError("Must be a positive height")
    return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))

def main():
    choice = int(input())

    result = 0.0
    if choice == 1:
        side = float(input("Enter side length: "))
        result = surface_main_cube(side)
    elif choice == 2:
        radius_sphere = float(input("Enter radius: "))
        result = surface_main_sphere(radius_sphere)
    elif choice == 3:
        length, width = map(float, input("Enter length and width: ").split())
        result = surface_main_rectangle(length, width)
    elif choice == 4:
        radius_cylinder, height_cylinder = map(float, input("Enter radius and height: ").split())
        result = surface_main_cylinder(radius_cylinder, height_cylinder)
    elif choice == 5:
        side_square = float(input("Enter side length: "))
        result = surface_main_square(side_square)
    elif choice == 6:
        base_triangle, height_triangle = map(float, input("Enter base and height: ").split())
        result = surface_main_triangle(base_triangle, height_triangle)
    elif choice == 7:
        base_parallelogram, height_parallelogram = map(float, input("Enter base and height: ").split())
        result = surface_main_parallelogram(base_parallelogram, height_parallelogram)
    elif choice == 8:
        base1, base2, height_trapezium = map(float, input("Enter base1, base2 and height: ").split())
        result = surface_main_trapezium(base1, base2, height_trapezium)
    elif choice == 9:
        radius_circle = float(input("Enter radius: "))
        result = surface_main_circle(radius_circle)
    elif choice == 10:
        radius_hemisphere = float(input("Enter radius: "))
        result = surface_main_hemisphere(radius_hemisphere)
    elif choice == 11:
        radius_cone, height_cone = map(float, input("Enter radius and height: ").split())
        result = surface_main_cone(radius_cone, height_cone)
    else:
        print("Invalid choice")
        return

    print(f"Calculated Main: {result:.2f}")

if __name__ == "__main__":
    main()
