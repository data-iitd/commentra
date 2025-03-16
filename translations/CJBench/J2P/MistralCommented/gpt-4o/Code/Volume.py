import math

def main():
    try:
        choice = int(input())  # Read an integer input from the user

        volume = 0  # Initialize the volume variable to 0

        # If-elif statement to determine the volume of different shapes based on user input
        if choice == 1:
            side = float(input())  # Read a float input for the side length of a cube
            volume = volume_cube(side)  # Calculate the volume of a cube
        elif choice == 2:
            width = float(input())  # Read float inputs for the width, height, and length of a cuboid
            height = float(input())
            length = float(input())
            volume = volume_cuboid(width, height, length)  # Calculate the volume of a cuboid
        elif choice == 3:
            radius = float(input())  # Read a float input for the radius of a sphere
            volume = volume_sphere(radius)  # Calculate the volume of a sphere
        elif choice == 4:
            radius_cyl = float(input())  # Read a float input for the radius of a cylinder
            height_cyl = float(input())
            volume = volume_cylinder(radius_cyl, height_cyl)  # Calculate the volume of a cylinder
        elif choice == 5:
            radius_hem = float(input())  # Read a float input for the radius of a hemisphere
            volume = volume_hemisphere(radius_hem)  # Calculate the volume of a hemisphere
        elif choice == 6:
            radius_cone = float(input())  # Read a float input for the radius of a cone
            height_cone = float(input())
            volume = volume_cone(radius_cone, height_cone)  # Calculate the volume of a cone
        elif choice == 7:
            base_area_prism = float(input())  # Read a float input for the base area of a prism
            height_prism = float(input())
            volume = volume_prism(base_area_prism, height_prism)  # Calculate the volume of a prism
        elif choice == 8:
            base_area_pyr = float(input())  # Read a float input for the base area of a pyramid
            height_pyr = float(input())
            volume = volume_pyramid(base_area_pyr, height_pyr)  # Calculate the volume of a pyramid
        elif choice == 9:
            r1 = float(input())  # Read float inputs for the radii and height of a frustum of a cone
            r2 = float(input())
            height_frustum = float(input())
            volume = volume_frustum_of_cone(r1, r2, height_frustum)  # Calculate the volume of a frustum of a cone
        else:
            return  # Exit the program if the user enters an invalid choice

        print(f"{volume:.2f}")  # Print the calculated volume with 2 decimal places

    except Exception as e:
        print(f"Error: {e}")  # Print an error message if an exception occurs

def volume_cube(side_length):
    return side_length ** 3  # Calculate the volume of a cube

def volume_cuboid(width, height, length):
    return width * height * length  # Calculate the volume of a cuboid

def volume_sphere(radius):
    return (4 * math.pi * radius ** 3) / 3  # Calculate the volume of a sphere

def volume_cylinder(radius, height):
    return math.pi * radius ** 2 * height  # Calculate the volume of a cylinder

def volume_hemisphere(radius):
    return (2 * math.pi * radius ** 3) / 3  # Calculate the volume of a hemisphere

def volume_cone(radius, height):
    return (math.pi * radius ** 2 * height) / 3  # Calculate the volume of a cone

def volume_prism(base_area, height):
    return base_area * height  # Calculate the volume of a prism

def volume_pyramid(base_area, height):
    return (base_area * height) / 3  # Calculate the volume of a pyramid

def volume_frustum_of_cone(r1, r2, height):
    return (math.pi * height / 3) * (r1 ** 2 + r2 ** 2 + r1 * r2)  # Calculate the volume of a frustum of a cone

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
