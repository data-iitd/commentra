# Import necessary modules (not needed in this simple case, but included for completeness)
import sys

# Main function
def main():
    # Read two integer values from standard input
    a, b = map(int, input().split())

    # Calculate and output the result of the expression (6 - a - b)
    # This assumes that a and b are part of a game or problem where their sum should not exceed 6
    print(6 - a - b)

# Entry point of the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
