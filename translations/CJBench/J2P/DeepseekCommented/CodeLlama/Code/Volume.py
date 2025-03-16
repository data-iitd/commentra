import math

def main():
    try:
        choice = int(input("Enter the number of the shape you want to calculate the volume of: "))
        volume = 0

        # Switch case to determine the shape and calculate its volume
        if choice == 1:
            side = float(input("Enter the side length of the cube: "))
            volume = volumeCube(side)
        elif choice == 2:
            width = float(input("Enter the width of the cuboid: "))
            heightCuboid = float(input("Enter the height of the cuboid: "))
            length = float(input("Enter the length of the cuboid: "))
            volume = volumeCuboid(width, heightCuboid, length)
        elif choice == 3:
            radius = float(input("Enter the radius of the sphere: "))
            volume = volumeSphere(radius)
        elif choice == 4:
            radiusCyl = float(input("Enter the radius of the cylinder: "))
            heightCyl = float(input("Enter the height of the cylinder: "))
            volume = volumeCylinder(radiusCyl, heightCyl)
        elif choice == 5:
            radiusHem = float(input("Enter the radius of the hemisphere: "))
            volume = volumeHemisphere(radiusHem)
        elif choice == 6:
            radiusCone = float(input("Enter the radius of the cone: "))
            heightCone = float(input("Enter the height of the cone: "))
            volume = volumeCone(radiusCone, heightCone)
        elif choice == 7:
            baseAreaPrism = float(input("Enter the base area of the prism: "))
            heightPrism = float(input("Enter the height of the prism: "))
            volume = volumePrism(baseAreaPrism, heightPrism)
        elif choice == 8:
            baseAreaPyr = float(input("Enter the base area of the pyramid: "))
            heightPyr = float(input("Enter the height of the pyramid: "))
            volume = volumePyramid(baseAreaPyr, heightPyr)
        elif choice == 9:
            r1 = float(input("Enter the radius of the smaller base of the frustum: "))
            r2 = float(input("Enter the radius of the larger base of the frustum: "))
            heightFrustum = float(input("Enter the height of the frustum: "))
            volume = volumeFrustumOfCone(r1, r2, heightFrustum)
        else:
            return
        print(f"{volume:.2f}")
    except ValueError:
        print("Error: Please enter a valid number.")
    except ZeroDivisionError:
        print("Error: Please enter a valid number for the radius.")
    except:
        print("Error: Please enter a valid number for the radius.")

# Methods to calculate the volume of different shapes
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

