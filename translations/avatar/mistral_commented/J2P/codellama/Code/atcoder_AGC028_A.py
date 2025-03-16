#######
# Import necessary libraries
#######
import math
import sys

# Main method to start the program
def main():
    # Read input values for n and m
    n, m = map(int, sys.stdin.readline().split())

    # Calculate the greatest common divisor (GCD) of n and m
    gcd = math.gcd(n, m)

    # Read input strings s and t
    s = sys.stdin.readline().strip()
    t = sys.stdin.readline().strip()

    # Perform the required calculation and print the result
    result = sum(1 for i in range(gcd) if s[i * n // gcd] != t[i * m // gcd])
    if result == 0:
        result = n * m // gcd
    print(result)

# Call the main method
main()


