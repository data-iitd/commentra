
import math
import sys

def karatsuba(x, y):
    # Base case: if the bit length of either x or y is less than or equal to 4,
    # return the product of x and y using the built-in multiplication method
    if x.bit_length() <= 4 or y.bit_length() <= 4:
        return x * y

    # Calculate the maximum bit length of x and y and divide it by 2 to get m
    n = max(x.bit_length(), y.bit_length())
    m = n // 2

    # Shift right x by m bits to get the high part (the left half)
    high1 = x >> m

    # Subtract the shifted high part from x and shift left m bits to get the low part (the right half)
    low1 = x - (high1 << m)

    # Perform the same operations on y
    high2 = y >> m
    low2 = y - (high2 << m)

    # Recursively calculate the product of the low parts using the karatsuba method
    z0 = karatsuba(low1, low2)

    # Calculate the product of the high parts and shift left 2m bits to get z2
    z2 = karatsuba(high1, high2) << (2 * m)

    # Calculate z1 as the sum of the products of the low parts and high parts,
    # then subtract z2 and shift left m bits to get the final result
    z1 = karatsuba(low1 + high1, low2 + high2) - z2
    result = z2 + z1 - z0 + z0

    return result

if __name__ == "__main__":
    try:
        # Read two large numbers as strings from the console and convert them to BigInteger objects
        num1 = int(input("Enter the first large number: ").strip())
        num2 = int(input("Enter the second large number: ").strip())

        # Call the karatsuba method to calculate the product of num1 and num2
        result = karatsuba(num1, num2)

        # Print the result to the console
        print("The product of the two numbers is:")
        print(result)
    except ValueError:
        # Handle the ValueError by printing an error message to the console
        print("Invalid input. Please enter valid large numbers.")
    finally:
        # Close the input stream to free up system resources
        sys.stdin.close()

