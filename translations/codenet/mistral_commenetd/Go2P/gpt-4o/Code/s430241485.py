# Import the sys module for reading input
import sys

# Define the main function
def main():
    # Read input from standard input (keyboard) and split it into two variables
    s, t = sys.stdin.read().split()

    # Print the concatenated string of t and s
    print(t + s)

# Call the main function
if __name__ == "__main__":
    main()

# <END-OF-CODE>
