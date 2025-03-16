import math

# Constants for validation messages
POSITIVE_RADIUS = "Must be a positive radius"
POSITIVE_HEIGHT = "Must be a positive height"
POSITIVE_BASE = "Must be a positive base"

# Methods to calculate the surface area of various shapes
def surfaceMainCube(sideLength):
    # Check if the side length is positive
    if sideLength <= 0:
        raise ValueError("Must be a positive sideLength")
    # Calculate the surface area of a cube
    return 6 * sideLength * sideLength

def surfaceMainSphere(radius):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a sphere
    return 4 * math.pi * radius * radius

def surfaceMainRectangle(length, width):
    # Check if the length is positive
    if length <= 0:
        raise ValueError("Must be a positive length")
    # Check if the width is positive
    if width <= 0:
        raise ValueError("Must be a positive width")
    # Calculate the surface area of a rectangle
    return length * width

def surfaceMainCylinder(radius, height):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a cylinder
    return 2 * (math.pi * radius * radius + math.pi * radius * height)

def surfaceMainSquare(sideLength):
    # Check if the side length is positive
    if sideLength <= 0:
        raise ValueError("Must be a positive sideLength")
    # Calculate the surface area of a square
    return sideLength * sideLength

def surfaceMainTriangle(base, height):
    # Check if the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a triangle
    return base * height / 2

def surfaceMainParallelogram(base, height):
    # Check if the base is positive
    if base <= 0:
        raise ValueError(POSITIVE_BASE)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a parallelogram
    return base * height

def surfaceMainTrapezium(base1, base2, height):
    # Check if the first base is positive
    if base1 <= 0:
        raise ValueError(POSITIVE_BASE + 1)
    # Check if the second base is positive
    if base2 <= 0:
        raise ValueError(POSITIVE_BASE + 2)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a trapezium
    return (base1 + base2) * height / 2

def surfaceMainCircle(radius):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a circle
    return math.pi * radius * radius

def surfaceMainHemisphere(radius):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Calculate the surface area of a hemisphere
    return 3 * math.pi * radius * radius

def surfaceMainCone(radius, height):
    # Check if the radius is positive
    if radius <= 0:
        raise ValueError(POSITIVE_RADIUS)
    # Check if the height is positive
    if height <= 0:
        raise ValueError(POSITIVE_HEIGHT)
    # Calculate the surface area of a cone
    return math.pi * radius * (radius + math.sqrt(height * height + radius * radius))

# Main method to read user input and calculate the surface area based on the choice
def main():
    choice = int(input())
    result = 0.0
    if choice == 1:
        side = float(input())
        result = surfaceMainCube(side)
    elif choice == 2:
        radiusSphere = float(input())
        result = surfaceMainSphere(radiusSphere)
    elif choice == 3:
        length = float(input())
        width = float(input())
        result = surfaceMainRectangle(length, width)
    elif choice == 4:
        radiusCylinder = float(input())
        heightCylinder = float(input())
        result = surfaceMainCylinder(radiusCylinder, heightCylinder)
    elif choice == 5:
        sideSquare = float(input())
        result = surfaceMainSquare(sideSquare)
    elif choice == 6:
        baseTriangle = float(input())
        heightTriangle = float(input())
        result = surfaceMainTriangle(baseTriangle, heightTriangle)
    elif choice == 7:
        baseParallelogram = float(input())
        heightParallelogram = float(input())
        result = surfaceMainParallelogram(baseParallelogram, heightParallelogram)
    elif choice == 8:
        base1 = float(input())
        base2 = float(input())
        heightTrapezium = float(input())
        result = surfaceMainTrapezium(base1, base2, heightTrapezium)
    elif choice == 9:
        radiusCircle = float(input())
        result = surfaceMainCircle(radiusCircle)
    elif choice == 10:
        radiusHemisphere = float(input())
        result = surfaceMainHemisphere(radiusHemisphere)
    elif choice == 11:
        radiusCone = float(input())
        heightCone = float(input())
        result = surfaceMainCone(radiusCone, heightCone)
    else:
        print("Invalid choice")
        return
    print("Calculated Main: %.2f" % result)

if __name__ == "__main__":
    main()
