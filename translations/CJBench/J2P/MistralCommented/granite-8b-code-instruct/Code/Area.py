

import math

# Final class to prevent extension and ensure encapsulation
class Main:
    def __init__(self):
        pass

    # Error message for invalid radius
    POSITIVE_RADIUS = "Must be a positive radius"

    # Error message for invalid height
    POSITIVE_HEIGHT = "Must be a positive height"

    # Error message for invalid base
    POSITIVE_BASE = "Must be a positive base"

    # Method to calculate the surface area of a cube
    @staticmethod
    def surface_main_cube(side_length):
        if side_length <= 0: # Check if side_length is valid
            raise ValueError("Must be a positive side_length")
        return 6 * side_length * side_length # Calculate the surface area

    # Method to calculate the surface area of a sphere
    @staticmethod
    def surface_main_sphere(radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        return 4 * math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a rectangle
    @staticmethod
    def surface_main_rectangle(length, width):
        if length <= 0: # Check if length is valid
            raise ValueError("Must be a positive length")
        if width <= 0: # Check if width is valid
            raise ValueError("Must be a positive width")
        return length * width # Calculate the surface area

    # Method to calculate the surface area of a cylinder
    @staticmethod
    def surface_main_cylinder(radius, height):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return 2 * (math.pi * radius * radius + math.pi * radius * height) # Calculate the surface area

    # Method to calculate the surface area of a square
    @staticmethod
    def surface_main_square(side_length):
        if side_length <= 0: # Check if side_length is valid
            raise ValueError("Must be a positive side_length")
        return side_length * side_length # Calculate the surface area

    # Method to calculate the surface area of a triangle
    @staticmethod
    def surface_main_triangle(base, height):
        if base <= 0: # Check if base is valid
            raise ValueError(Main.POSITIVE_BASE)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return base * height / 2 # Calculate the surface area using the formula: 1/2 * base * height

    # Method to calculate the surface area of a parallelogram
    @staticmethod
    def surface_main_parallelogram(base, height):
        if base <= 0: # Check if base is valid
            raise ValueError(Main.POSITIVE_BASE)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return base * height # Calculate the surface area

    # Method to calculate the surface area of a trapezium
    @staticmethod
    def surface_main_trapezium(base1, base2, height):
        if base1 <= 0: # Check if base1 is valid
            raise ValueError(Main.POSITIVE_BASE + 1)
        if base2 <= 0: # Check if base2 is valid
            raise ValueError(Main.POSITIVE_BASE + 2)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return (base1 + base2) * height / 2 # Calculate the surface area using the formula: 1/2 * (base1 + base2) * height

    # Method to calculate the surface area of a circle
    @staticmethod
    def surface_main_circle(radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        return math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a hemisphere
    @staticmethod
    def surface_main_hemisphere(radius):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        return 3 * math.pi * radius * radius # Calculate the surface area

    # Method to calculate the surface area of a cone
    @staticmethod
    def surface_main_cone(radius, height):
        if radius <= 0: # Check if radius is valid
            raise ValueError(Main.POSITIVE_RADIUS)
        if height <= 0: # Check if height is valid
            raise ValueError(Main.POSITIVE_HEIGHT)
        return math.pi * radius * (radius + math.sqrt(height * height + radius * radius)) # Calculate the surface area

# Main method to read user input and calculate the surface area based on the shape selected
if __name__ == "__main__":
    import sys

    choice = int(input()) # Read the user's choice of shape

    result = 0.0 # Initialize the result variable to store the calculated surface area

    switcher = {
        1: lambda: Main.surface_main_cube(float(input())), # Calculate the surface area of the cube
        2: lambda: Main.surface_main_sphere(float(input())), # Calculate the surface area of the sphere
        3: lambda: Main.surface_main_rectangle(float(input()), float(input())), # Calculate the surface area of the rectangle
        4: lambda: Main.surface_main_cylinder(float(input()), float(input())), # Calculate the surface area of the cylinder
        5: lambda: Main.surface_main_square(float(input())), # Calculate the surface area of the square
        6: lambda: Main.surface_main_triangle(float(input()), float(input())), # Calculate the surface area of the triangle
        7: lambda: Main.surface_main_parallelogram(float(input()), float(input())), # Calculate the surface area of the parallelogram
        8: lambda: Main.surface_main_trapezium(float(input()), float(input()), float(input())), # Calculate the surface area of the trapezium
        9: lambda: Main.surface_main_circle(float(input())), # Calculate the surface area of the circle
        10: lambda: Main.surface_main_hemisphere(float(input())), # Calculate the surface area of the hemisphere
        11: lambda: Main.surface_main_cone(float(input()), float(input())), # Calculate the surface area of the cone
    }

    try:
        result = switcher.get(choice, lambda: "Invalid choice")() # Call the appropriate method based on the user's choice
    except ValueError as e:
        print(e) # Print an error message if the user enters an invalid input
    except Exception as e:
        print("An error occurred:", e) # Print an error message if an unexpected error occurs

    print(f"Calculated Main: {result:.2f}") # Print the calculated surface area