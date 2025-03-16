
import math

def main():
    # Create a Scanner object to read input from the user
    scanner = Scanner(System.in)

    try:
        # Read an integer input from the user
        choice = scanner.nextInt()

        volume = 0

        # Switch statement to determine the volume of different shapes based on user input
        if choice == 1:
            # Read a double input for the side length of a cube
            side = scanner.nextDouble()
            volume = volumeCube(side)
        elif choice == 2:
            # Read double inputs for the width, height, and length of a cuboid
            width = scanner.nextDouble()
            height = scanner.nextDouble()
            length = scanner.nextDouble()
            volume = volumeCuboid(width, height, length)
        elif choice == 3:
            # Read a double input for the radius of a sphere
            radius = scanner.nextDouble()
            volume = volumeSphere(radius)
        elif choice == 4:
            # Read a double input for the radius of a cylinder
            radiusCyl = scanner.nextDouble()
            # Read a double input for the height of a cylinder
            heightCyl = scanner.nextDouble()
            volume = volumeCylinder(radiusCyl, heightCyl)
        elif choice == 5:
            # Read a double input for the radius of a hemisphere
            radiusHem = scanner.nextDouble()
            volume = volumeHemisphere(radiusHem)
        elif choice == 6:
            # Read a double input for the radius of a cone
            radiusCone = scanner.nextDouble()
            # Read a double input for the height of a cone
            heightCone = scanner.nextDouble()
            volume = volumeCone(radiusCone, heightCone)
        elif choice == 7:
            # Read a double input for the base area of a prism
            baseAreaPrism = scanner.nextDouble()
            # Read a double input for the height of a prism
            heightPrism = scanner.nextDouble()
            volume = volumePrism(baseAreaPrism, heightPrism)
        elif choice == 8:
            # Read a double input for the base area of a pyramid
            baseAreaPyr = scanner.nextDouble()
            # Read a double input for the height of a pyramid
            heightPyr = scanner.nextDouble()
            volume = volumePyramid(baseAreaPyr, heightPyr)
        elif choice == 9:
            # Read double inputs for the radii and height of a frustum of a cone
            r1 = scanner.nextDouble()
            r2 = scanner.nextDouble()
            heightFrustum = scanner.nextDouble()
            volume = volumeFrustumOfCone(r1, r2, heightFrustum)
        else:
            return

        # Print the calculated volume with 2 decimal places
        print(f"{volume:.2f}")

    except Exception as e:
        # Print an error message if an exception occurs
        print(f"Error: {e.getMessage()}")

    finally:
        # Close the Scanner object to free up system resources
        scanner.close()

# Methods to calculate the volumes of different shapes
def volumeCube(sideLength):
    return sideLength * sideLength * sideLength

def volumeCuboid(width, height, length):
    return width * height * length

def volumeSphere(radius):
    return (4 * math.pi * radius * radius * radius) / 3

def volumeCylinder(radius, height):
    return math.pi * radius * radius * height

def volumeHemisphere(radius):
    return (2 * math.pi * radius * radius * radius) / 3

def volumeCone(radius, height):
    return (math.pi * radius * radius * height) / 3

def volumePrism(baseArea, height):
    return baseArea * height

def volumePyramid(baseArea, height):
    return (baseArea * height) / 3

def volumeFrustumOfCone(r1, r2, height):
    return (math.pi * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2)

if __name__ == "__main__":
    main()

