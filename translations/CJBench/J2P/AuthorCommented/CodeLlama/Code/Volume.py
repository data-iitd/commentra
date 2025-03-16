
import math

def volume_cube(side_length):
    return side_length * side_length * side_length

def volume_cuboid(width, height, length):
    return width * height * length

def volume_sphere(radius):
    return (4 * math.pi * radius * radius * radius) / 3

def volume_cylinder(radius, height):
    return math.pi * radius * radius * height

def volume_hemisphere(radius):
    return (2 * math.pi * radius * radius * radius) / 3

def volume_cone(radius, height):
    return (math.pi * radius * radius * height) / 3

def volume_prism(base_area, height):
    return base_area * height

def volume_pyramid(base_area, height):
    return (base_area * height) / 3

def volume_frustum_of_cone(r1, r2, height):
    return (math.pi * height / 3) * (r1 * r1 + r2 * r2 + r1 * r2)

# 