# Import necessary libraries (not used in this code)
import sys

# Define a shorthand for long long type (not necessary in Python)
# Define a constant for infinity (not used in this code)
INF = 1 << 60  # Not used in this code
MOD = 1000000007  # Not used in this code

def main():
    # Read values for a and b from standard input
    a, b = map(int, sys.stdin.readline().split())

    # Calculate the maximum of the sum, difference, and product of a and b
    print(max(a + b, a - b, a * b))  # Output the maximum value

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
