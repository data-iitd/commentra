import math
import sys

def volume_cube(side_length):
    return side_length * side_length * side_length

def volume_cuboid(width, height, length):
    return width * height * length

def volume_sphere(radius):
    return (4 * math.pi * radius * radius * radius) / 3

def volume_cylinder(radius, height):
    return math.pi * radius * radius * height

def volume_hemisphere(radius):
    return (2 * math.pi * radius * radius * radius) / 3

def volume_cone(radius, height):
    return (math.pi * radius * radius * height) / 3

def volume_prism(base_area, height):
    return base_area * height

def volume_pyramid(base_area, height):
    return (base_area * height) / 3

def volume_frustum_of_cone(r1, r2, height):
    return (math.pi * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2)

if __name__ == "__main__":
    try:
        choice = int(input())
        volume = 0
        if choice == 1:
            side = float(input())
            volume = volume_cube(side)
        elif choice == 2:
            width = float(input())
            height = float(input())
            length = float(input())
            volume = volume_cuboid(width, height, length)
        elif choice == 3:
            radius = float(input())
            volume = volume_sphere(radius)
        elif choice == 4:
            radius_cyl = float(input())
            height_cyl = float(input())
            volume = volume_cylinder(radius_cyl, height_cyl)
        elif choice == 5:
            radius_hem = float(input())
            volume = volume_hemisphere(radius_hem)
        elif choice == 6:
            radius_cone = float(input())
            height_cone = float(input())
            volume = volume_cone(radius_cone, height_cone)
        elif choice == 7:
            base_area_prism = float(input())
            height_prism = float(input())
            volume = volume_prism(base_area_prism, height_prism)
        elif choice == 8:
            base_area_pyr = float(input())
            height_pyr = float(input())
            volume = volume_pyramid(base_area_pyr, height_pyr)
        elif choice == 9:
            r1 = float(input())
            r2 = float(input())
            height_frustum = float(input())
            volume = volume_frustum_of_cone(r1, r2, height_frustum)
        else:
            return
        print(f"{volume:.2f}")
    except ValueError as e:
        print(f"Error: {e}")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        sys.exit()

