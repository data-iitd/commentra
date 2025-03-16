import math

# Constants for error messages
POSITIVE_RADIUS = "Must be a positive radius"
POSITIVE_HEIGHT = "Must be a positive height"
POSITIVE_BASE = "Must be a positive base"

# Method to calculate the surface area of a cube
def surfaceMainCube(sideLength):
    # Validate that the side length is positive
    if sideLength <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the cube
    return 6 * sideLength * sideLength

# Method to calculate the surface area of a sphere
def surfaceMainSphere(radius):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the sphere
    return 4 * math.pi * radius * radius

# Method to calculate the surface area of a rectangle
def surfaceMainRectangle(length, width):
    # Validate that the length is positive
    if length <= 0:
        raise ValueError("Must be a positive length")
    # Validate that the width is positive
    if width <= 0:
        raise ValueError("Must be a positive width")
    # Calculate and return the surface area of the rectangle
    return length * width

# Method to calculate the surface area of a cylinder
def surfaceMainCylinder(radius, height):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the cylinder
    return 2 * (math.pi * radius * radius + math.pi * radius * height)

# Method to calculate the surface area of a square
def surfaceMainSquare(sideLength):
    # Validate that the side length is positive
    if sideLength <= 0:
        raise ValueError("Must be a positive sideLength")
    # Calculate and return the surface area of the square
    return sideLength * sideLength

# Method to calculate the surface area of a triangle
def surfaceMainTriangle(base, height):
    # Validate that the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the triangle
    return base * height / 2

# Method to calculate the surface area of a parallelogram
def surfaceMainParallelogram(base, height):
    # Validate that the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Validate that the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate and return the surface area of the parallelogram
    return base * height

# Method to calculate the surface area of a trapezium
def surfaceMainTrapezium(base1, base2, height):
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
def surfaceMainCircle(radius):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the circle
    return math.pi * radius * radius

# Method to calculate the surface area of a hemisphere
def surfaceMainHemisphere(radius):
    # Validate that the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate and return the surface area of the hemisphere
    return 3 * math.pi * radius * radius

# Method to calculate the surface area of a cone
def surfaceMainCone(radius, height):
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
    scanner = input()
    # Read the user's choice of shape
    choice = int(scanner)
    result = 0.0

    # Switch case to handle different shape calculations based on user choice
    if choice == 1:
        # Calculate surface area of a cube
        side = float(input())
        result = surfaceMainCube(side)
    elif choice == 2:
        # Calculate surface area of a sphere
        radiusSphere = float(input())
        result = surfaceMainSphere(radiusSphere)
    elif choice == 3:
        # Calculate surface area of a rectangle
        length = float(input())
        width = float(input())
        result = surfaceMainRectangle(length, width)
    elif choice == 4:
        # Calculate surface area of a cylinder
        radiusCylinder = float(input())
        heightCylinder = float(input())
        result = surfaceMainCylinder(radiusCylinder, heightCylinder)
    elif choice == 5:
        # Calculate surface area of a square
        sideSquare = float(input())
        result = surfaceMainSquare(sideSquare)
    elif choice == 6:
        # Calculate surface area of a triangle
        baseTriangle = float(input())
        heightTriangle = float(input())
        result = surfaceMainTriangle(baseTriangle, heightTriangle)
    elif choice == 7:
        # Calculate surface area of a parallelogram
        baseParallelogram = float(input())
        heightParallelogram = float(input())
        result = surfaceMainParallelogram(baseParallelogram, heightParallelogram)
    elif choice == 8:
        # Calculate surface area of a trapezium
        base1 = float(input())
        base2 = float(input())
        heightTrapezium = float(input())
        result = surfaceMainTrapezium(base1, base2, heightTrapezium)
    elif choice == 9:
        # Calculate surface area of a circle
        radiusCircle = float(input())
        result = surfaceMainCircle(radiusCircle)
    elif choice == 10:
        # Calculate surface area of a hemisphere
        radiusHemisphere = float(input())
        result = surfaceMainHemisphere(radiusHemisphere)
    elif choice == 11:
        # Calculate surface area of a cone
        radiusCone = float(input())
        heightCone = float(input())
        result = surfaceMainCone(radiusCone, heightCone)
    else:
        # Handle invalid choice
        print("Invalid choice")
        return

    # Print the calculated surface area result
    print("Calculated Main: %.2f" % result)

# Call the main method
if __name__ == "__main__":
    main()

