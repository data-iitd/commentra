
import math

# Calculate the volume of various shapes.

def volume_cube(side_length):
    return side_length ** 3

def volume_cuboid(width, height, length):
    return width * height * length

def volume_sphere(radius):
    return (4 * math.pi * radius ** 3) / 3

def volume_cylinder(radius, height):
    return math.pi * radius ** 2 * height

def volume_hemisphere(radius):
    return (2 * math.pi * radius ** 3) / 3

def volume_cone(radius, height):
    return (math.pi * radius ** 2 * height) / 3

def volume_prism(base_area, height):
    return base_area * height

def volume_pyramid(base_area, height):
    return (base_area * height) / 3

def volume_frustum_of_cone(r1, r2, height):
    return (math.pi * height / 3) * (r1 ** 2 + r2 ** 2 + r1 * r2)

# Main function
def main():
    choice = int(input())
    volume = 0

    switcher = {
        1: volume_cube,
        2: volume_cuboid,
        3: volume_sphere,
        4: volume_cylinder,
        5: volume_hemisphere,
        6: volume_cone,
        7: volume_prism,
        8: volume_pyramid,
        9: volume_frustum_of_cone
    }

    func = switcher.get(choice, lambda: "Invalid choice")
    volume = func()

    print(f"{volume:.2f}")

if __name__ == "__main__":
    main()

