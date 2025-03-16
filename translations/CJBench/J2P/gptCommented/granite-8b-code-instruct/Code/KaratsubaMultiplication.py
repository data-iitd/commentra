
import sys
from math import log2
from decimal import Decimal, getcontext

def karatsuba(x, y):
    # Base case: if either number is small (4 bits or less), use standard multiplication
    if len(str(x)) <= 4 or len(str(y)) <= 4:
        return x * y

    # Determine the maximum bit length of the two numbers
    n = max(len(str(x)), len(str(y)))
    # Split the bit length in half
    m = n // 2

    # Split x into high and low parts
    high1 = int(x / (10 ** m))
    low1 = x % (10 ** m)

    # Split y into high and low parts
    high2 = int(y / (10 ** m))
    low2 = y % (10 ** m)

    # Recursively calculate the three products
    z0 = karatsuba(low1, low2) # z0 = low1 * low2
    z1 = karatsuba(low1 + high1, low2 + high2) # z1 = (low1 + high1) * (low2 + high2)
    z2 = karatsuba(high1, high2) # z2 = high1 * high2

    # Combine the three products to get the final result
    return z2 * (10 ** (2 * m)) + (z1 - z2 - z0) * (10 ** m) + z0

def main():
    # Set the precision of the decimal module to a large value
    getcontext().prec = 10000

    # Read two large numbers from user input
    num1 = Decimal(input("Enter the first large number: "))
    num2 = Decimal(input("Enter the second large number: "))

    # Calculate the product using the Karatsuba method
    result = karatsuba(num1, num2)

    # Output the result
    print("The product of the two numbers is:")
    print(result)

if __name__ == "__main__":
    main()

