# Importing necessary Python libraries
import sys

# Main method is the entry point of the Python application
def main():
    # Reading a line of input from the console and splitting it into an array of strings using space as delimiter
    x = sys.stdin.readline().strip().split(" ")

    # Parsing the first and second elements of the input array into integers 'a' and 'b' respectively
    a = int(x[0])
    b = int(x[1])

    # Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
    c = a - b * 2

    # If the value of 'c' is negative, set it to zero
    if c < 0:
        c = 0

    # Print the value of 'c' to the console
    print(c)

# Calling the main method
if __name__ == "__main__":
    main()

