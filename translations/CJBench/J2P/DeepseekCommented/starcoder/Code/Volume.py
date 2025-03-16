import sys

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
            radius = float(input())
            height = float(input())
            volume = volumeCylinder(radius, height)
        elif choice == 5:
            radius = float(input())
            volume = volumeHemisphere(radius)
        elif choice == 6:
            radius = float(input())
            height = float(input())
            volume = volumeCone(radius, height)
        elif choice == 7:
            baseArea = float(input())
            height = float(input())
            volume = volumePrism(baseArea, height)
        elif choice == 8:
            baseArea = float(input())
            height = float(input())
            volume = volumePyramid(baseArea, height)
        elif choice == 9:
            r1 = float(input())
            r2 = float(input())
            height = float(input())
            volume = volumeFrustumOfCone(r1, r2, height)
        else:
            return
        print(volume)
    except Exception as e:
        print("Error: " + str(e))

def volumeCube(side):
    return side * side * side

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

