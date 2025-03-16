import sys

# Private function to prevent instantiation of the class
def __init__(self):
    pass

def main():
    # Create a Scanner object to read input from the user
    scanner = sys.stdin
    try:
        # Read the user's choice of shape
        choice = int(input())
        volume = 0 # Variable to store the calculated volume

        # Switch statement to handle different shape volume calculations based on user choice
        if choice == 1: # Calculate volume of a cube
            side = float(input())
            volume = volumeCube(side)
        elif choice == 2: # Calculate volume of a cuboid
            width = float(input())
            height = float(input())
            length = float(input())
            volume = volumeCuboid(width, height, length)
        elif choice == 3: # Calculate volume of a sphere
            radius = float(input())
            volume = volumeSphere(radius)
        elif choice == 4: # Calculate volume of a cylinder
            radiusCyl = float(input())
            heightCyl = float(input())
            volume = volumeCylinder(radiusCyl, heightCyl)
        elif choice == 5: # Calculate volume of a hemisphere
            radiusHem = float(input())
            volume = volumeHemisphere(radiusHem)
        elif choice == 6: # Calculate volume of a cone
            radiusCone = float(input())
            heightCone = float(input())
            volume = volumeCone(radiusCone, heightCone)
        elif choice == 7: # Calculate volume of a prism
            baseAreaPrism = float(input())
            heightPrism = float(input())
            volume = volumePrism(baseAreaPrism, heightPrism)
        elif choice == 8: # Calculate volume of a pyramid
            baseAreaPyr = float(input())
            heightPyr = float(input())
            volume = volumePyramid(baseAreaPyr, heightPyr)
        elif choice == 9: # Calculate volume of a frustum of a cone
            r1 = float(input())
            r2 = float(input())
            heightFrustum = float(input())
            volume = volumeFrustumOfCone(r1, r2, heightFrustum)
        else: # Exit if the choice is not valid
            return

        # Print the calculated volume formatted to two decimal places
        print(format(volume, '.2f'))
    except Exception as e:
        # Handle any exceptions that occur during input or calculation
        print("Error: " + str(e))
    finally:
        # Close the scanner to free up resources
        scanner.close()

# Method to calculate the volume of a cube
def volumeCube(sideLength):
    return sideLength * sideLength * sideLength

# Method to calculate the volume of a cuboid
def volumeCuboid(width, height, length):
    return width * height * length

# Method to calculate the volume of a sphere
def volumeSphere(radius):
    return (4 * Math.PI * radius * radius * radius) / 3

# Method to calculate the volume of a cylinder
def volumeCylinder(radius, height):
    return Math.PI * radius * radius * height

# Method to calculate the volume of a hemisphere
def volumeHemisphere(radius):
    return (2 * Math.PI * radius * radius * radius) / 3

# Method to calculate the volume of a cone
def volumeCone(radius, height):
    return (Math.PI * radius * radius * height) / 3

# Method to calculate the volume of a prism
def volumePrism(baseArea, height):
    return baseArea * height

# Method to calculate the volume of a pyramid
def volumePyramid(baseArea, height):
    return (baseArea * height) / 3

# Method to calculate the volume of a frustum of a cone
def volumeFrustumOfCone(r1, r2, height):
    return (Math.PI * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2)

if __name__ == "__main__":
    main()

# 