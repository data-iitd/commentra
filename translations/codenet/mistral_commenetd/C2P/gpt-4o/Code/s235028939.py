# Import the sys module for standard input/output
import sys

def main():  # The entry point of the program
    # Read two integers from the standard input
    n, m = map(int, sys.stdin.readline().split())

    # Calculate the product of (n - 1) and (m - 1) and store the result in the variable result
    result = (n - 1) * (m - 1)

    # Print the result to the standard output
    print(result)

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
