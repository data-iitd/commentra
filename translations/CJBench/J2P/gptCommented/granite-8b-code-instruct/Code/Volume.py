
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

# Main function to read input from the user and calculate the volume
def main():
    try:
        # Read the user's choice of shape
        choice = int(input("Enter the choice of shape: "))
        volume = 0  # Variable to store the calculated volume

        # Switch statement to handle different shape volume calculations based on user choice
        if choice == 1:  # Calculate volume of a cube
            side = float(input("Enter the side length of the cube: "))
            volume = volume_cube(side)
        elif choice == 2:  # Calculate volume of a cuboid
            width = float(input("Enter the width of the cuboid: "))
            height = float(input("Enter the height of the cuboid: "))
            length = float(input("Enter the length of the cuboid: "))
            volume = volume_cuboid(width, height, length)
        elif choice == 3:  # Calculate volume of a sphere
            radius = float(input("Enter the radius of the sphere: "))
            volume = volume_sphere(radius)
        elif choice == 4:  # Calculate volume of a cylinder
            radius = float(input("Enter the radius of the cylinder: "))
            height = float(input("Enter the height of the cylinder: "))
            volume = volume_cylinder(radius, height)
        elif choice == 5:  # Calculate volume of a hemisphere
            radius = float(input("Enter the radius of the hemisphere: "))
            volume = volume_hemisphere(radius)
        elif choice == 6:  # Calculate volume of a cone
            radius = float(input("Enter the radius of the cone: "))
            height = float(input("Enter the height of the cone: "))
            volume = volume_cone(radius, height)
        elif choice == 7:  # Calculate volume of a prism
            base_area = float(input("Enter the base area of the prism: "))
            height = float(input("Enter the height of the prism: "))
            volume = volume_prism(base_area, height)
        elif choice == 8:  # Calculate volume of a pyramid
            base_area = float(input("Enter the base area of the pyramid: "))
            height = float(input("Enter the height of the pyramid: "))
            volume = volume_pyramid(base_area, height)
        elif choice == 9:  # Calculate volume of a frustum of a cone
            r1 = float(input("Enter the radius of the smaller base of the frustum: "))
            r2 = float(input("Enter the radius of the larger base of the frustum: "))
            height = float(input("Enter the height of the frustum: "))
            volume = volume_frustum_of_cone(r1, r2, height)
        else:  # Exit if the choice is not valid
            return

        # Print the calculated volume formatted to two decimal places
        print(f"{volume:.2f}")
    except Exception as e:
        # Handle any exceptions that occur during input or calculation
        print(f"Error: {e}")

if __name__ == "__main__":
    main()

