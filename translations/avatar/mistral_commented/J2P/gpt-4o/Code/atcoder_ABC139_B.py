# Importing necessary classes for input and output
import sys

# Main function is the entry point of the Python application
def main():
    # Read first integer input A from user
    A = int(input().strip())

    # Read second integer input B from user
    B = int(input().strip())

    # Initialize variables for storing remainders and result
    amari = 0
    result = 0

    # Calculate the result by dividing B by A - 1 and storing the quotient
    result = (B - 1) // (A - 1)

    # Calculate the remainder of B divided by A - 1 and store it in amari
    amari = (B - 1) % (A - 1)

    # Check if the remainder is not zero
    if amari != 0:
        # If the remainder is not zero, increment the result by 1
        result += 1

    # Write the result to the standard output
    print(result)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
