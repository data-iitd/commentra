
import math  # Import the math module for mathematical constants and functions

def main():
    r = float(input("Enter the radius: "))  # Prompt the user to input the radius and convert it to a float

    # Calculate and print the area and circumference of the circle
    # Area = π * r^2
    # Circumference = 2 * π * r
    print(r * r * math.pi, 2 * math.pi * r)

if __name__ == "__main__":
    main()

