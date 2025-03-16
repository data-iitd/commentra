import math

def surface_main_cube(side_length):
    if side_length <= 0:
        raise ValueError("Must be a positive side_length")
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
        raise ValueError("Must be a positive side_length")
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
    choice = int(input("Enter choice: "))
    if choice == 1:
        side_length = float(input("Enter side length: "))
        result = surface_main_cube(side_length)
    elif choice == 2:
        radius = float(input("Enter radius: "))
        result = surface_main_sphere(radius)
    elif choice == 3:
        length = float(input("Enter length: "))
        width = float(input("Enter width: "))
        result = surface_main_rectangle(length, width)
    elif choice == 4:
        radius = float(input("Enter radius: "))
        height = float(input("Enter height: "))
        result = surface_main_cylinder(radius, height)
    elif choice == 5:
        side_length = float(input("Enter side length: "))
        result = surface_main_square(side_length)
    elif choice == 6:
        base = float(input("Enter base: "))
        height = float(input("Enter height: "))
        result = surface_main_triangle(base, height)
    elif choice == 7:
        base = float(input("Enter base: "))
        height = float(input("Enter height: "))
        result = surface_main_parallelogram(base, height)
    elif choice == 8:
        base1 = float(input("Enter base1: "))
        base2 = float(input("Enter base2: "))
        height = float(input("Enter height: "))
        result = surface_main_trapezium(base1, base2, height)
    elif choice == 9:
        radius = float(input("Enter radius: "))
        result = surface_main_circle(radius)
    elif choice == 10:
        radius = float(input("Enter radius: "))
        result = surface_main_hemisphere(radius)
    elif choice == 11:
        radius = float(input("Enter radius: "))
        height = float(input("Enter height: "))
        result = surface_main_cone(radius, height)
    else:
        print("Invalid choice")
        return
    print("Calculated Main: %.2f" % result)

if __name__ == "__main__":
    main()

