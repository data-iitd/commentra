# Import the sys module for standard input.
import sys

# Define the main function as the entry point of our program.
def main():
    # Read the values of variables "x" and "y" from the standard input.
    x, y = map(int, sys.stdin.readline().split())

    # Print the result of the expression "x + y/2" to the standard output.
    print(x + y // 2)

# Call the main function to execute the program.
if __name__ == "__main__":
    main()

# <END-OF-CODE>
