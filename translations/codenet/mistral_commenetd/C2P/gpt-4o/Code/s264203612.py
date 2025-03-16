import math  # Import the math library for mathematical constants and functions

def main():  # Define the main function
    r = float(input())  # Read a value from the standard input and convert it to float
    s = r * r * math.pi  # Calculate the area of a circle with radius 'r'
    l = 2 * math.pi * r  # Calculate the circumference of a circle with radius 'r'

    print(f"{s} {l}")  # Print the values of 's' and 'l'

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
