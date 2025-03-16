import math

class SurfaceAreaCalculator:
    # Constants for error messages
    POSITIVE_RADIUS = "Must be a positive radius"
    POSITIVE_HEIGHT = "Must be a positive height"
    POSITIVE_BASE = "Must be a positive base"

    @staticmethod
    def surface_main_cube(side_length):
        # Validate that the side length is positive
        if side_length <= 0:
            raise ValueError("Must be a positive sideLength")
        # Calculate and return the surface area of the cube
        return 6 * side_length * side_length

    @staticmethod
    def surface_main_sphere(radius):
        # Validate that the radius is positive
        if radius <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_RADIUS)
        # Calculate and return the surface area of the sphere
        return 4 * math.pi * radius * radius

    @staticmethod
    def surface_main_rectangle(length, width):
        # Validate that the length is positive
        if length <= 0:
            raise ValueError("Must be a positive length")
        # Validate that the width is positive
        if width <= 0:
            raise ValueError("Must be a positive width")
        # Calculate and return the surface area of the rectangle
        return length * width

    @staticmethod
    def surface_main_cylinder(radius, height):
        # Validate that the radius is positive
        if radius <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_RADIUS)
        # Validate that the height is positive
        if height <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_HEIGHT)
        # Calculate and return the surface area of the cylinder
        return 2 * (math.pi * radius * radius + math.pi * radius * height)

    @staticmethod
    def surface_main_square(side_length):
        # Validate that the side length is positive
        if side_length <= 0:
            raise ValueError("Must be a positive sideLength")
        # Calculate and return the surface area of the square
        return side_length * side_length

    @staticmethod
    def surface_main_triangle(base, height):
        # Validate that the base is positive
        if base <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_BASE)
        # Validate that the height is positive
        if height <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_HEIGHT)
        # Calculate and return the surface area of the triangle
        return base * height / 2

    @staticmethod
    def surface_main_parallelogram(base, height):
        # Validate that the base is positive
        if base <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_BASE)
        # Validate that the height is positive
        if height <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_HEIGHT)
        # Calculate and return the surface area of the parallelogram
        return base * height

    @staticmethod
    def surface_main_trapezium(base1, base2, height):
        # Validate that both bases are positive
        if base1 <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_BASE + " 1")
        if base2 <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_BASE + " 2")
        # Validate that the height is positive
        if height <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_HEIGHT)
        # Calculate and return the surface area of the trapezium
        return (base1 + base2) * height / 2

    @staticmethod
    def surface_main_circle(radius):
        # Validate that the radius is positive
        if radius <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_RADIUS)
        # Calculate and return the surface area of the circle
        return math.pi * radius * radius

    @staticmethod
    def surface_main_hemisphere(radius):
        # Validate that the radius is positive
        if radius <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_RADIUS)
        # Calculate and return the surface area of the hemisphere
        return 3 * math.pi * radius * radius

    @staticmethod
    def surface_main_cone(radius, height):
        # Validate that the radius is positive
        if radius <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_RADIUS)
        # Validate that the height is positive
        if height <= 0:
            raise ValueError(SurfaceAreaCalculator.POSITIVE_HEIGHT)
        # Calculate and return the surface area of the cone
        return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))

def main():
    # Read the user's choice of shape
    choice = int(input("Enter the shape choice (1-11): "))
    result = 0.0

    # Switch case to handle different shape calculations based on user choice
    if choice == 1:
        # Calculate surface area of a cube
        side = float(input("Enter the side length of the cube: "))
        result = SurfaceAreaCalculator.surface_main_cube(side)
    elif choice == 2:
        # Calculate surface area of a sphere
        radius_sphere = float(input("Enter the radius of the sphere: "))
        result = SurfaceAreaCalculator.surface_main_sphere(radius_sphere)
    elif choice == 3:
        # Calculate surface area of a rectangle
        length = float(input("Enter the length of the rectangle: "))
        width = float(input("Enter the width of the rectangle: "))
        result = SurfaceAreaCalculator.surface_main_rectangle(length, width)
    elif choice == 4:
        # Calculate surface area of a cylinder
        radius_cylinder = float(input("Enter the radius of the cylinder: "))
        height_cylinder = float(input("Enter the height of the cylinder: "))
        result = SurfaceAreaCalculator.surface_main_cylinder(radius_cylinder, height_cylinder)
    elif choice == 5:
        # Calculate surface area of a square
        side_square = float(input("Enter the side length of the square: "))
        result = SurfaceAreaCalculator.surface_main_square(side_square)
    elif choice == 6:
        # Calculate surface area of a triangle
        base_triangle = float(input("Enter the base of the triangle: "))
        height_triangle = float(input("Enter the height of the triangle: "))
        result = SurfaceAreaCalculator.surface_main_triangle(base_triangle, height_triangle)
    elif choice == 7:
        # Calculate surface area of a parallelogram
        base_parallelogram = float(input("Enter the base of the parallelogram: "))
        height_parallelogram = float(input("Enter the height of the parallelogram: "))
        result = SurfaceAreaCalculator.surface_main_parallelogram(base_parallelogram, height_parallelogram)
    elif choice == 8:
        # Calculate surface area of a trapezium
        base1 = float(input("Enter the first base of the trapezium: "))
        base2 = float(input("Enter the second base of the trapezium: "))
        height_trapezium = float(input("Enter the height of the trapezium: "))
        result = SurfaceAreaCalculator.surface_main_trapezium(base1, base2, height_trapezium)
    elif choice == 9:
        # Calculate surface area of a circle
        radius_circle = float(input("Enter the radius of the circle: "))
        result = SurfaceAreaCalculator.surface_main_circle(radius_circle)
    elif choice == 10:
        # Calculate surface area of a hemisphere
        radius_hemisphere = float(input("Enter the radius of the hemisphere: "))
        result = SurfaceAreaCalculator.surface_main_hemisphere(radius_hemisphere)
    elif choice == 11:
        # Calculate surface area of a cone
        radius_cone = float(input("Enter the radius of the cone: "))
        height_cone = float(input("Enter the height of the cone: "))
        result = SurfaceAreaCalculator.surface_main_cone(radius_cone, height_cone)
    else:
        # Handle invalid choice
        print("Invalid choice")
        return

    # Print the calculated surface area result
    print(f"Calculated Main: {result:.2f}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
