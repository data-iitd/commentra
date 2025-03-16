import math

# Final class to prevent extension and ensure encapsulation
class Main:
    @staticmethod
    def surface_main_cube(side_length):
        if side_length <= 0:  # Check if side_length is valid
            raise ValueError("Must be a positive sideLength")
        return 6 * side_length * side_length  # Calculate the surface area

    @staticmethod
    def surface_main_sphere(radius):
        if radius <= 0:  # Check if radius is valid
            raise ValueError("Must be a positive radius")
        return 4 * math.pi * radius * radius  # Calculate the surface area

    @staticmethod
    def surface_main_rectangle(length, width):
        if length <= 0:  # Check if length is valid
            raise ValueError("Must be a positive length")
        if width <= 0:  # Check if width is valid
            raise ValueError("Must be a positive width")
        return length * width  # Calculate the surface area

    @staticmethod
    def surface_main_cylinder(radius, height):
        if radius <= 0:  # Check if radius is valid
            raise ValueError("Must be a positive radius")
        if height <= 0:  # Check if height is valid
            raise ValueError("Must be a positive height")
        return 2 * (math.pi * radius * radius + math.pi * radius * height)  # Calculate the surface area

    @staticmethod
    def surface_main_square(side_length):
        if side_length <= 0:  # Check if side_length is valid
            raise ValueError("Must be a positive sideLength")
        return side_length * side_length  # Calculate the surface area

    @staticmethod
    def surface_main_triangle(base, height):
        if base <= 0:  # Check if base is valid
            raise ValueError("Must be a positive base")
        if height <= 0:  # Check if height is valid
            raise ValueError("Must be a positive height")
        return base * height / 2  # Calculate the surface area using the formula: 1/2 * base * height

    @staticmethod
    def surface_main_parallelogram(base, height):
        if base <= 0:  # Check if base is valid
            raise ValueError("Must be a positive base")
        if height <= 0:  # Check if height is valid
            raise ValueError("Must be a positive height")
        return base * height  # Calculate the surface area

    @staticmethod
    def surface_main_trapezium(base1, base2, height):
        if base1 <= 0:  # Check if base1 is valid
            raise ValueError("Must be a positive base")
        if base2 <= 0:  # Check if base2 is valid
            raise ValueError("Must be a positive base")
        if height <= 0:  # Check if height is valid
            raise ValueError("Must be a positive height")
        return (base1 + base2) * height / 2  # Calculate the surface area using the formula: 1/2 * (base1 + base2) * height

    @staticmethod
    def surface_main_circle(radius):
        if radius <= 0:  # Check if radius is valid
            raise ValueError("Must be a positive radius")
        return math.pi * radius * radius  # Calculate the surface area

    @staticmethod
    def surface_main_hemisphere(radius):
        if radius <= 0:  # Check if radius is valid
            raise ValueError("Must be a positive radius")
        return 3 * math.pi * radius * radius  # Calculate the surface area

    @staticmethod
    def surface_main_cone(radius, height):
        if radius <= 0:  # Check if radius is valid
            raise ValueError("Must be a positive radius")
        if height <= 0:  # Check if height is valid
            raise ValueError("Must be a positive height")
        return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))  # Calculate the surface area

# Main method to read user input and calculate the surface area based on the shape selected
def main():
    choice = int(input("Enter the shape choice (1-11): "))  # Read the user's choice of shape

    result = 0.0  # Initialize the result variable to store the calculated surface area

    if choice == 1:
        side = float(input("Enter the side length of the cube: "))  # Read the side length of the cube from the user
        result = Main.surface_main_cube(side)  # Calculate the surface area of the cube
    elif choice == 2:
        radius_sphere = float(input("Enter the radius of the sphere: "))  # Read the radius of the sphere from the user
        result = Main.surface_main_sphere(radius_sphere)  # Calculate the surface area of the sphere
    elif choice == 3:
        length = float(input("Enter the length of the rectangle: "))  # Read the length of the rectangle from the user
        width = float(input("Enter the width of the rectangle: "))  # Read the width of the rectangle from the user
        result = Main.surface_main_rectangle(length, width)  # Calculate the surface area of the rectangle
    elif choice == 4:
        radius_cylinder = float(input("Enter the radius of the cylinder: "))  # Read the radius of the cylinder from the user
        height_cylinder = float(input("Enter the height of the cylinder: "))  # Read the height of the cylinder from the user
        result = Main.surface_main_cylinder(radius_cylinder, height_cylinder)  # Calculate the surface area of the cylinder
    elif choice == 5:
        side_square = float(input("Enter the side length of the square: "))  # Read the side length of the square from the user
        result = Main.surface_main_square(side_square)  # Calculate the surface area of the square
    elif choice == 6:
        base_triangle = float(input("Enter the base of the triangle: "))  # Read the base of the triangle from the user
        height_triangle = float(input("Enter the height of the triangle: "))  # Read the height of the triangle from the user
        result = Main.surface_main_triangle(base_triangle, height_triangle)  # Calculate the surface area of the triangle
    elif choice == 7:
        base_parallelogram = float(input("Enter the base of the parallelogram: "))  # Read the base of the parallelogram from the user
        height_parallelogram = float(input("Enter the height of the parallelogram: "))  # Read the height of the parallelogram from the user
        result = Main.surface_main_parallelogram(base_parallelogram, height_parallelogram)  # Calculate the surface area of the parallelogram
    elif choice == 8:
        base1 = float(input("Enter the base1 of the trapezium: "))  # Read the base1 of the trapezium from the user
        base2 = float(input("Enter the base2 of the trapezium: "))  # Read the base2 of the trapezium from the user
        height_trapezium = float(input("Enter the height of the trapezium: "))  # Read the height of the trapezium from the user
        result = Main.surface_main_trapezium(base1, base2, height_trapezium)  # Calculate the surface area of the trapezium
    elif choice == 9:
        radius_circle = float(input("Enter the radius of the circle: "))  # Read the radius of the circle from the user
        result = Main.surface_main_circle(radius_circle)  # Calculate the surface area of the circle
    elif choice == 10:
        radius_hemisphere = float(input("Enter the radius of the hemisphere: "))  # Read the radius of the hemisphere from the user
        result = Main.surface_main_hemisphere(radius_hemisphere)  # Calculate the surface area of the hemisphere
    elif choice == 11:
        radius_cone = float(input("Enter the radius of the cone: "))  # Read the radius of the cone from the user
        height_cone = float(input("Enter the height of the cone: "))  # Read the height of the cone from the user
        result = Main.surface_main_cone(radius_cone, height_cone)  # Calculate the surface area of the cone
    else:
        print("Invalid choice")  # Print an error message if the user enters an invalid choice
        return  # Exit the program if the user enters an invalid choice

    print(f"Calculated Main: {result:.2f}")  # Print the calculated surface area

if __name__ == "__main__":
    main()  # Call the main function to execute the program

# <END-OF-CODE>
