import math

class VolumeCalculator:
    @staticmethod
    def volume_cube(side_length):
        return side_length ** 3

    @staticmethod
    def volume_cuboid(width, height, length):
        return width * height * length

    @staticmethod
    def volume_sphere(radius):
        return (4 * math.pi * radius ** 3) / 3

    @staticmethod
    def volume_cylinder(radius, height):
        return math.pi * radius ** 2 * height

    @staticmethod
    def volume_hemisphere(radius):
        return (2 * math.pi * radius ** 3) / 3

    @staticmethod
    def volume_cone(radius, height):
        return (math.pi * radius ** 2 * height) / 3

    @staticmethod
    def volume_prism(base_area, height):
        return base_area * height

    @staticmethod
    def volume_pyramid(base_area, height):
        return (base_area * height) / 3

    @staticmethod
    def volume_frustum_of_cone(r1, r2, height):
        return (math.pi * height / 3) * (r1 ** 2 + r2 ** 2 + r1 * r2)

def main():
    try:
        choice = int(input("Enter the shape choice (1-9): "))
        volume = 0  # Variable to store the calculated volume

        if choice == 1:  # Calculate volume of a cube
            side = float(input("Enter the side length of the cube: "))
            volume = VolumeCalculator.volume_cube(side)
        elif choice == 2:  # Calculate volume of a cuboid
            width = float(input("Enter the width of the cuboid: "))
            height = float(input("Enter the height of the cuboid: "))
            length = float(input("Enter the length of the cuboid: "))
            volume = VolumeCalculator.volume_cuboid(width, height, length)
        elif choice == 3:  # Calculate volume of a sphere
            radius = float(input("Enter the radius of the sphere: "))
            volume = VolumeCalculator.volume_sphere(radius)
        elif choice == 4:  # Calculate volume of a cylinder
            radius_cyl = float(input("Enter the radius of the cylinder: "))
            height_cyl = float(input("Enter the height of the cylinder: "))
            volume = VolumeCalculator.volume_cylinder(radius_cyl, height_cyl)
        elif choice == 5:  # Calculate volume of a hemisphere
            radius_hem = float(input("Enter the radius of the hemisphere: "))
            volume = VolumeCalculator.volume_hemisphere(radius_hem)
        elif choice == 6:  # Calculate volume of a cone
            radius_cone = float(input("Enter the radius of the cone: "))
            height_cone = float(input("Enter the height of the cone: "))
            volume = VolumeCalculator.volume_cone(radius_cone, height_cone)
        elif choice == 7:  # Calculate volume of a prism
            base_area_prism = float(input("Enter the base area of the prism: "))
            height_prism = float(input("Enter the height of the prism: "))
            volume = VolumeCalculator.volume_prism(base_area_prism, height_prism)
        elif choice == 8:  # Calculate volume of a pyramid
            base_area_pyr = float(input("Enter the base area of the pyramid: "))
            height_pyr = float(input("Enter the height of the pyramid: "))
            volume = VolumeCalculator.volume_pyramid(base_area_pyr, height_pyr)
        elif choice == 9:  # Calculate volume of a frustum of a cone
            r1 = float(input("Enter the radius of the first base of the frustum: "))
            r2 = float(input("Enter the radius of the second base of the frustum: "))
            height_frustum = float(input("Enter the height of the frustum: "))
            volume = VolumeCalculator.volume_frustum_of_cone(r1, r2, height_frustum)
        else:  # Exit if the choice is not valid
            return

        # Print the calculated volume formatted to two decimal places
        print(f"{volume:.2f}")
    except Exception as e:
        # Handle any exceptions that occur during input or calculation
        print(f"Error: {e}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
