

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

# Main method is the entry point of the program
def main():
    try:
        choice = int(input("Enter the shape number: "))

        volume = 0

        # Switch statement to determine the volume of different shapes based on user input
        if choice == 1:
            side = float(input("Enter the side length of the cube: "))
            volume = volume_cube(side)
        elif choice == 2:
            width = float(input("Enter the width of the cuboid: "))
            height = float(input("Enter the height of the cuboid: "))
            length = float(input("Enter the length of the cuboid: "))
            volume = volume_cuboid(width, height, length)
        elif choice == 3:
            radius = float(input("Enter the radius of the sphere: "))
            volume = volume_sphere(radius)
        elif choice == 4:
            radius_cyl = float(input("Enter the radius of the cylinder: "))
            height_cyl = float(input("Enter the height of the cylinder: "))
            volume = volume_cylinder(radius_cyl, height_cyl)
        elif choice == 5:
            radius_hemi = float(input("Enter the radius of the hemisphere: "))
            volume = volume_hemisphere(radius_hemi)
        elif choice == 6:
            radius_cone = float(input("Enter the radius of the cone: "))
            height_cone = float(input("Enter the height of the cone: "))
            volume = volume_cone(radius_cone, height_cone)
        elif choice == 7:
            base_area_prism = float(input("Enter the base area of the prism: "))
            height_prism = float(input("Enter the height of the prism: "))
            volume = volume_prism(base_area_prism, height_prism)
        elif choice == 8:
            base_area_pyr = float(input("Enter the base area of the pyramid: "))
            height_pyr = float(input("Enter the height of the pyramid: "))
            volume = volume_pyramid(base_area_pyr, height_pyr)
        elif choice == 9:
            r1 = float(input("Enter the radius of the frustum of the cone: "))
            r2 = float(input("Enter the radius of the frustum of the cone: "))
            height_frustum = float(input("Enter the height of the frustum of the cone: "))
            volume = volume_frustum_of_cone(r1, r2, height_frustum)
        else:
            return

        print(f"{volume:.2f}")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()

