
import sys

# Main method is the entry point of the program
def main():
    try:
        choice = int(input()) # Read an integer input from the user

        volume = 0 # Initialize the volume variable to 0

        # Switch statement to determine the volume of different shapes based on user input
        if choice == 1:
            side = float(input()) # Read a double input for the side length of a cube
            volume = volumeCube(side) # Calculate the volume of a cube using the volumeCube method
        elif choice == 2:
            width = float(input()) # Read double inputs for the width, height, and length of a cuboid
            height = float(input())
            length = float(input())
            volume = volumeCuboid(width, height, length) # Calculate the volume of a cuboid using the volumeCuboid method
        elif choice == 3:
            radius = float(input()) # Read a double input for the radius of a sphere
            volume = volumeSphere(radius) # Calculate the volume of a sphere using the volumeSphere method
        elif choice == 4:
            radiusCyl = float(input()) # Read a double input for the radius of a cylinder
            heightCyl = float(input())
            volume = volumeCylinder(radiusCyl, heightCyl) # Calculate the volume of a cylinder using the volumeCylinder method
        elif choice == 5:
            radiusHem = float(input()) # Read a double input for the radius of a hemisphere
            volume = volumeHemisphere(radiusHem) # Calculate the volume of a hemisphere using the volumeHemisphere method
        elif choice == 6:
            radiusCone = float(input()) # Read a double input for the radius of a cone
            heightCone = float(input())
            volume = volumeCone(radiusCone, heightCone) # Calculate the volume of a cone using the volumeCone method
        elif choice == 7:
            baseAreaPrism = float(input()) # Read a double input for the base area of a prism
            heightPrism = float(input())
            volume = volumePrism(baseAreaPrism, heightPrism) # Calculate the volume of a prism using the volumePrism method
        elif choice == 8:
            baseAreaPyr = float(input()) # Read a double input for the base area of a pyramid
            heightPyr = float(input())
            volume = volumePyramid(baseAreaPyr, heightPyr) # Calculate the volume of a pyramid using the volumePyramid method
        elif choice == 9:
            r1 = float(input()) # Read double inputs for the radii and height of a frustum of a cone
            r2 = float(input())
            heightFrustum = float(input())
            volume = volumeFrustumOfCone(r1, r2, heightFrustum) # Calculate the volume of a frustum of a cone using the volumeFrustumOfCone method
        else:
            return # Exit the program if the user enters an invalid choice

        print(format(volume, '.2f')) # Print the calculated volume with 2 decimal places

    except Exception as e:
        print("Error: " + str(e)) # Print an error message if an exception occurs

# Methods to calculate the volumes of different shapes
def volumeCube(sideLength):
    return sideLength * sideLength * sideLength # Calculate the volume of a cube by cubing the side length

def volumeCuboid(width, height, length):
    return width * height * length # Calculate the volume of a cuboid by multiplying the width, height, and length

def volumeSphere(radius):
    return (4 * math.pi * radius * radius * radius) / 3 # Calculate the volume of a sphere using the given formula

def volumeCylinder(radius, height):
    return math.pi * radius * radius * height # Calculate the volume of a cylinder by multiplying the area of the base and height

def volumeHemisphere(radius):
    return (2 * math.pi * radius * radius * radius) / 3 # Calculate the volume of a hemisphere using the given formula

def volumeCone(radius, height):
    return (math.pi * radius * radius * height) / 3 # Calculate the volume of a cone using the given formula

def volumePrism(baseArea, height):
    return baseArea * height # Calculate the volume of a prism by multiplying the base area and height

def volumePyramid(baseArea, height):
    return (baseArea * height) / 3 # Calculate the volume of a pyramid by dividing the product of the base area and height by 3

def volumeFrustumOfCone(r1, r2, height):
    return (math.pi * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2) # Calculate the volume of a frustum of a cone using the given formula

if __name__ == "__main__":
    main()

