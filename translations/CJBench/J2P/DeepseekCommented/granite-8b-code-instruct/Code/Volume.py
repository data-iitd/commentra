
import math

def volume_cube(side_length):
    return side_length ** 3

def volume_cuboid(width, height, length):
    return width * height * length

def volume_sphere(radius):
    return (4 * math.pi * radius ** 3) / 3

def volume_cylinder(radius, height):
    return math.pi * radius ** 2 * height

def volume_hemisphere(radius):
    return (2 * math.pi * radius ** 3) / 3

def volume_cone(radius, height):
    return (math.pi * radius ** 2 * height) / 3

def volume_prism(base_area, height):
    return base_area * height

def volume_pyramid(base_area, height):
    return (base_area * height) / 3

def volume_frustum_of_cone(r1, r2, height):
    return (math.pi * height / 3) * (r1 ** 2 + r2 ** 2 + r1 * r2)

# Main program
while True:
    try:
        choice = int(input("Enter your choice: "))
        if choice == 1:
            side = float(input("Enter side length for cube: "))
            volume = volume_cube(side)
        elif choice == 2:
            width = float(input("Enter width for cuboid: "))
            height_cuboid = float(input("Enter height for cuboid: "))
            length = float(input("Enter length for cuboid: "))
            volume = volume_cuboid(width, height_cuboid, length)
        elif choice == 3:
            radius = float(input("Enter radius for sphere: "))
            volume = volume_sphere(radius)
        elif choice == 4:
            radius_cylinder = float(input("Enter radius for cylinder: "))
            height_cylinder = float(input("Enter height for cylinder: "))
            volume = volume_cylinder(radius_cylinder, height_cylinder)
        elif choice == 5:
            radius_hemisphere = float(input("Enter radius for hemisphere: "))
            volume = volume_hemisphere(radius_hemisphere)
        elif choice == 6:
            radius_cone = float(input("Enter radius for cone: "))
            height_cone = float(input("Enter height for cone: "))
            volume = volume_cone(radius_cone, height_cone)
        elif choice == 7:
            base_area_prism = float(input("Enter base area for prism: "))
            height_prism = float(input("Enter height for prism: "))
            volume = volume_prism(base_area_prism, height_prism)
        elif choice == 8:
            base_area_pyramid = float(input("Enter base area for pyramid: "))
            height_pyramid = float(input("Enter height for pyramid: "))
            volume = volume_pyramid(base_area_pyramid, height_pyramid)
        elif choice == 9:
            r1 = float(input("Enter radius of smaller base for frustum: "))
            r2 = float(input("Enter radius of larger base for frustum: "))
            height_frustum = float(input("Enter height for frustum: "))
            volume = volume_frustum_of_cone(r1, r2, height_frustum)
        else:
            break
        print(f"{volume:.2f}")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        print("