import sys

def karatsuba(x, y):
    # Base case: if the numbers are small enough, use simple multiplication
    if x.bit_length() <= 4 or y.bit_length() <= 4:
        return x * y

    # Determine the size of the numbers
    n = max(x.bit_length(), y.bit_length())
    m = n // 2

    # Split the numbers into high and low parts
    high1 = x >> m
    low1 = x - (high1 << m)
    high2 = y >> m
    low2 = y - (high2 << m)

    # Recursively compute the three multiplications
    z0 = karatsuba(low1, low2)
    z1 = karatsuba(low1 + high1, low2 + high2)
    z2 = karatsuba(high1, high2)

    # Combine the results using the Karatsuba formula
    return (z2 << (2 * m)) + (z1 - z2 - z0 << m) + z0

# Main function to read input and compute the product using Karatsuba algorithm
def main():
    try:
        # Read two large integers from the user
        num1 = int(input().strip())
        num2 = int(input().strip())

        # Compute the product using the Karatsuba algorithm
        result = karatsuba(num1, num2)

        # Print the result
        print("The product of the two numbers is:")
        print(result)
    except ValueError:
        # Handle invalid input
        print("Invalid input. Please enter valid large numbers.", file=sys.stderr)

if __name__ == "__main__":
    main()

