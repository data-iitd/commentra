# Import necessary libraries
import sys

# Constants definition
INF = 1 << 60  # Infinite value for long long int
MOD = 1000000007  # Modulus value for modular arithmetic

# Input output functions
def main():
    # Read input values from standard input
    a, b = map(int, sys.stdin.readline().split())

    # Calculate the maximum value among a+b, a-b, and a*b
    result = max(a + b, a - b, a * b)

    # Output the result to standard output
    print(result)

# End of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
