import sys  # Importing sys for handling input and output
from decimal import Decimal  # Importing Decimal for handling large numbers

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
    z0 = karatsuba(low1, low2)  # z0 = low1 * low2
    z1 = karatsuba(low1 + high1, low2 + high2)  # z1 = (low1 + high1) * (low2 + high2)
    z2 = karatsuba(high1, high2)  # z2 = high1 * high2

    # Combine the three products to get the final result
    return (z2 << (2 * m)) + ((z1 - z2 - z0) << m) + z0  # Combine results

def main():
    try:
        # Read two large numbers from user input
        num1 = Decimal(input().strip())
        num2 = Decimal(input().strip())

        # Calculate the product using the Karatsuba method
        result = karatsuba(int(num1), int(num2))

        # Output the result
        print("The product of the two numbers is:")
        print(result)
    except ValueError:
        # Handle invalid input
        print("Invalid input. Please enter valid large numbers.", file=sys.stderr)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
