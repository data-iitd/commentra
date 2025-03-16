import math

def main():
    # Read the radius from user input
    r = float(input())
    
    # Calculate the area of the circle using the formula: area = π * r^2
    s = r * r * math.pi

    # Calculate the circumference of the circle using the formula: circumference = 2 * π * r
    l = 2 * math.pi * r
    
    # Print the calculated area and circumference
    print(f"{s} {l}")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
