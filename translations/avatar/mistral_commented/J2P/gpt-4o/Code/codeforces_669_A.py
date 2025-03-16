# Importing the necessary module for reading input
import sys

def main():
    # Read the input number from the console
    n = int(input("Enter a number: "))

    # Call the 'solve' function to calculate and print the result
    solve(n)

def solve(n):
    # Calculate the result and print it to the console
    print((n // 3) * 2 + (0 if n % 3 == 0 else 1))

# Entry point of the Python application
if __name__ == "__main__":
    main()

# <END-OF-CODE>
