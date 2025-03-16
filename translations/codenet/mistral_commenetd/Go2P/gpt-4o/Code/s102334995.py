# Importing the 'sys' module for input operations
import sys

def main():
    # Reading input values for variables 'a' and 'b' from the standard input
    a, b = map(int, sys.stdin.readline().split())

    # Multiplying the variables 'a' and 'b' and printing the result
    print(a * b)

    # Multiplying the sum of 'a' and 'b' with 2 and printing the result
    print((a + b) * 2)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
