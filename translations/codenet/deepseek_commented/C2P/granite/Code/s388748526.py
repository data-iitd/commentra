
import math

def calculate_circle_properties(radius):
    # Calculate the area of the circle (πr^2) and the circumference (2πr)
    area = math.pi * radius ** 2
    circumference = 2 * math.pi * radius
    return area, circumference

# Read the input value for the radius of the circle
radius = float(input("Enter the radius of the circle: "))

# Call the function to calculate the circle properties
area, circumference = calculate_circle_properties(radius)

# Print the results
print(f"The area of the circle is {area} and the circumference is {circumference}.")

