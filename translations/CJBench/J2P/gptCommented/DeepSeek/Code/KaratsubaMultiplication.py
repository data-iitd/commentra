import math
from typing import Final

class Main:
    # Private constructor to prevent instantiation of the class
    def __init__(self):
        pass

    @staticmethod
    def karatsuba(x, y):
        # Base case: if either number is small (4 bits or less), use standard multiplication
        if x.bit_length() <= 4 or y.bit_length() <= 4:
            return x * y

        # Determine the maximum bit length of the two numbers
        n = max(x.bit_length(), y.bit_length())
        # Split the bit length in half
        m = n // 2

        # Split x into high and low parts
        high1 = x >> m  # High part of x
        low1 = x - (high1 << m)  # Low part of x

        # Split y into high and low parts
        high2 = y >> m  # High part of y
        low2 = y - (high2 << m)  # Low part of y

        # Recursively calculate the three products
        z0 = Main.karatsuba(low1, low2)  # z0 = low1 * low2
        z1 = Main.karatsuba(low1 + high1, low2 + high2)  # z1 = (low1 + high1) * (low2 + high2)
        z2 = Main.karatsuba(high1, high2)  # z2 = high1 * high2

        # Combine the three products to get the final result
        return (z2 << (2 * m)) + ((z1 - z2 - z0) << m) + z0

# Main method to execute the program
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    # Read two large numbers from user input
    num1 = int(data[0])
    num2 = int(data[1])

    # Calculate the product using the Karatsuba method
    result = Main.karatsuba(num1, num2)

    # Output the result
    print("The product of the two numbers is:")
    print(result)
