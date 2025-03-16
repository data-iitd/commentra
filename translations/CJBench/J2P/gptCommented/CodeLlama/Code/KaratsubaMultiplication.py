import math
import sys

# Private constructor to prevent instantiation of the class
class Main:
    def __init__(self):
        pass

# Method to perform Karatsuba multiplication
def karatsuba(x, y):
    # Base case: if either number is small (4 bits or less), use standard multiplication
    if x.bit_length() <= 4 or y.bit_length() <= 4:
        return x * y

    # Determine the maximum bit length of the two numbers
    n = max(x.bit_length(), y.bit_length())
    # Split the bit length in half
    m = n // 2

    # Split x into high and low parts
    high1 = x >> m
    low1 = x - (high1 << m)

    # Split y into high and low parts
    high2 = y >> m
    low2 = y - (high2 << m)

    # Recursively calculate the three products
    z0 = karatsuba(low1, low2)
    z1 = karatsuba(low1 + high1, low2 + high2)
    z2 = karatsuba(high1, high2)

    # Combine the three products to get the final result
    return (z2 << (2 * m)) + ((z1 - z2 - z0) << m) + z0

# Main method to execute the program
def main():
    try:
        # Read two large numbers from user input
        num1 = int(input("Enter the first large number: "))
        num2 = int(input("Enter the second large number: "))

        # Calculate the product using the Karatsuba method
        result = karatsuba(num1, num2)

        # Output the result
        print("The product of the two numbers is:")
        print(result)
    except ValueError:
        # Handle invalid input
        print("Invalid input. Please enter valid large numbers.")

if __name__ == "__main__":
    main()

