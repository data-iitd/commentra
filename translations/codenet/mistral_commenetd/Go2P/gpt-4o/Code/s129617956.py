import math
import sys

def next_int():
    return int(sys.stdin.readline().strip())

def min_digits_in_divisor(n):
    rt = int(math.sqrt(n))  # Calculate the square root of n
    minf = float('inf')  # Initialize minimum factor with a large value

    # Check divisibility for numbers from 1 to the square root of n
    for i in range(1, rt + 1):
        if n % i == 0:
            # Calculate the number of digits in the divisor
            b = n // i
            ndigit = len(str(b))  # Count the number of digits in b
            # Update minimum factor if a divisor with fewer digits is found
            minf = min(minf, ndigit)

    return minf

if __name__ == "__main__":
    n = next_int()  # Read an integer from standard input
    result = min_digits_in_divisor(n)  # Find the minimum number of digits in a divisor of n
    print(result)  # Print the result

# <END-OF-CODE>
