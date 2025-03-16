import sys

# Calculate the volume of various shapes.
def main():
    try:
        choice = int(input())
        volume = 0

        if choice == 1:
            side = float(input())
            volume = volumeCube(side)
        elif choice == 2:
            width = float(input())
            height = float(input())
            length = float(input())
            volume = volumeCuboid(width, height, length)
        elif choice == 3:
            radius = float(input())
            volume = volumeSphere(radius)
        elif choice == 4:
            radiusCyl = float(input())
            heightCyl = float(input())
            volume = volumeCylinder(radiusCyl, heightCyl)
        elif choice == 5:
            radiusHem = float(input())
            volume = volumeHemisphere(radiusHem)
        elif choice == 6:
            radiusCone = float(input())
            heightCone = float(input())
            volume = volumeCone(radiusCone, heightCone)
        elif choice == 7:
            baseAreaPrism = float(input())
            heightPrism = float(input())
            volume = volumePrism(baseAreaPrism, heightPrism)
        elif choice == 8:
            baseAreaPyr = float(input())
            heightPyr = float(input())
            volume = volumePyramid(baseAreaPyr, heightPyr)
        elif choice == 9:
            r1 = float(input())
            r2 = float(input())
            heightFrustum = float(input())
            volume = volumeFrustumOfCone(r1, r2, heightFrustum)
        else:
            return  # Exit on invalid choice

        print(volume)
    except Exception as e:
        print("Error: " + str(e))

# Calculate the volume of a cube.
def volumeCube(sideLength):
    return sideLength * sideLength * sideLength

# Calculate the volume of a cuboid.
def volumeCuboid(width, height, length):
    return width * height * length

# Calculate the volume of a sphere.
def volumeSphere(radius):
    return (4 * math.pi * radius * radius * radius) / 3

# Calculate volume of a cylinder
def volumeCylinder(radius, height):
    return math.pi * radius * radius * height

# Calculate the volume of a hemisphere.
def volumeHemisphere(radius):
    return (2 * math.pi * radius * radius * radius) / 3

# Calculate the volume of a cone.
def volumeCone(radius, height):
    return (math.pi * radius * radius * height) / 3

def volumePrism(baseArea, height):
    return baseArea * height

# Calculate the volume of a pyramid.
def volumePyramid(baseArea, height):
    return (baseArea * height) / 3

# Calculate the volume of a frustum of a cone.
def volumeFrustumOfCone(r1, r2, height):
    return (math.pi * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2)

if __name__ == "__main__":
    main()

