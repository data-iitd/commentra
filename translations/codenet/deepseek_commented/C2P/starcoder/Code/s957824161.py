# Include the standard input/output library
import sys

# Declare two integer variables to store user input
x = 0
y = 0

# Define the main function, the entry point of the program
def main():
    # Read two integers from the standard input and store them in x and y
    x, y = map(int, sys.stdin.readline().split())
    # Print the product of x and y and the perimeter of the rectangle
    print(x * y, 2 * x + 2 * y)

# Call the main function
if __name__ == "__main__":
    main()

