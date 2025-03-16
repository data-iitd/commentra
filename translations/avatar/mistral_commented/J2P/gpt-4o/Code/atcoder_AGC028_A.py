# Import necessary libraries
from math import gcd  # For calculating the greatest common divisor
from sys import stdin  # For reading input
from functools import reduce  # For reducing functions

# Main function to start the program
def main():
    # Read input values for n and m
    n, m = map(int, stdin.readline().split())

    # Calculate the greatest common divisor (GCD) of n and m
    gcd_value = gcd(n, m)

    # Read input strings s and t
    s = stdin.readline().strip()
    t = stdin.readline().strip()

    # Perform the required calculation and print the result
    result = next((-1 for k in range(gcd_value) if s[k * n // gcd_value] != t[k * m // gcd_value]), 
                  (n * m) // gcd_value)

    # Print the result
    print(result)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
