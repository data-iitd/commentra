
import math

# Private constructor to prevent instantiation of the class
class Main:
    pass

# Constants for error messages
POSITIVE_RADIUS = "Must be a positive radius"
POSITIVE_HEIGHT = "Must be a positive height"
POSITIVE_BASE = "Must be a positive base"

# Method to calculate the surface area of a cube
def surface_main_cube(side_length):
    # Validate that the side length is positive
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    # Calculate and return the surface area of the cube
    return 6 * side_length * side_length

# Method to calculate the surface area of a sphere
def surface_main_sphere(radius):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the sphere
    return 4 * math.pi * radius * radius

# Method to calculate the surface area of a rectangle
def surface_main_rectangle(length, width):
    # Validate that the length is positive
    if length <= 0:
        raise ValueError("Must be a positive length")
    # Validate that the width is positive
    if width <= 0:
        raise ValueError("Must be a positive width")
    # Calculate and return the surface area of the rectangle
    return length * width

# Method to calculate the surface area of a cylinder
def surface_main_cylinder(radius, height):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the cylinder
    return 2 * (math.pi * radius * radius + math.pi * radius * height)

# Method to calculate the surface area of a square
def surface_main_square(side_length):
    # Validate that the side length is positive
    if side_length <= 0:
        raise ValueError("Must be a positive sideLength")
    # Calculate and return the surface area of the square
    return side_length * side_length

# Method to calculate the surface area of a triangle
def surface_main_triangle(base, height):
    # Validate that the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the triangle
    return base * height / 2

# Method to calculate the surface area of a parallelogram
def surface_main_parallelogram(base, height):
    # Validate that the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the parallelogram
    return base * height

# Method to calculate the surface area of a trapezium
def surface_main_trapezium(base1, base2, height):
    # Validate that both bases are positive
    if base1 <= 0:
        raise ValueError(POSITIVE_BASE + 1)
    if base2 <= 0:
        raise ValueError(POSITIVE_BASE + 2)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the trapezium
    return (base1 + base2) * height / 2

# Method to calculate the surface area of a circle
def surface_main_circle(radius):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the circle
    return math.pi * radius * radius

# Method to calculate the surface area of a hemisphere
def surface_main_hemisphere(radius):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the hemisphere
    return 3 * math.pi * radius * radius

# Method to calculate the surface area of a cone
def surface_main_cone(radius, height):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the cone
    return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))

# Main method to execute the program
def main():
    # Create a Scanner object for user input
    scanner = Scanner(System.in)
    # Read the user's choice of shape
    choice = scanner.nextInt()
    result = 0.0

    # Switch case to handle different shape calculations based on user choice
    switch (choice) {
        case 1:
            // Calculate surface area of a cube
            double side = scanner.nextDouble();
            result = surface_main_cube(side);
            break;
        case 2:
            // Calculate surface area of a sphere
            double radiusSphere = scanner.nextDouble();
            result = surface_main_sphere(radiusSphere);
            break;
        case 3:
            // Calculate surface area of a rectangle
            double length = scanner.nextDouble();
            double width = scanner.nextDouble();
            result = surface_main_rectangle(length, width);
            break;
        case 4:
            // Calculate surface area of a cylinder
            double radiusCylinder = scanner.nextDouble();
            double heightCylinder = scanner.nextDouble();
            result = surface_main_cylinder(radiusCylinder, heightCylinder);
            break;
        case 5:
            // Calculate surface area of a square
            double sideSquare = scanner.nextDouble();
            result = surface_main_square(sideSquare);
            break;
        case 6:
            // Calculate surface area of a triangle
            double baseTriangle = scanner.nextDouble();
            double heightTriangle = scanner.nextDouble();
            result = surface_main_triangle(baseTriangle, heightTriangle);
            break;
        case 7:
            // Calculate surface area of a parallelogram
            double baseParallelogram = scanner.nextDouble();
            double heightParallelogram = scanner.nextDouble();
            result = surface_main_parallelogram(baseParallelogram, heightParallelogram);
            break;
        case 8:
            // Calculate surface area of a trapezium
            double base1 = scanner.nextDouble();
            double base2 = scanner.nextDouble();
            double heightTrapezium = scanner.nextDouble();
            result = surface_main_trapezium(base1, base2, heightTrapezium);
            break;
        case 9:
            // Calculate surface area of a circle
            double radiusCircle = scanner.nextDouble();
            result = surface_main_circle(radiusCircle);
            break;
        case 10:
            // Calculate surface area of a hemisphere
            double radiusHemisphere = scanner.nextDouble();
            result = surface_main_hemisphere(radiusHemisphere);
            break;
        case 11:
            // Calculate surface area of a cone
            double radiusCone = scanner.nextDouble();
            double heightCone = scanner.nextDouble();
            result = surface_main_cone(radiusCone, heightCone);
            break;
        default:
            // Handle invalid choice
            System.out.println("Invalid choice");
            return;
    }
    // Print the calculated surface area result
    System.out.printf("Calculated Main: %.2f%n", result);
}

# END-OF-CODE