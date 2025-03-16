# Importing necessary libraries for reading input
import sys

# Main function is the entry point of the Python application
def main():
    # Reading a single line of input from the console and splitting it into a list
    str_input = sys.stdin.read().strip().split()

    # Parsing the first two elements of the list as integers 'h' and 'a' respectively
    h = int(str_input[0])
    a = int(str_input[1])

    # Initializing a variable 'num' to keep track of the number of steps
    num = 0

    # Using a while loop to simulate the given condition
    while h > 0:
        # Subtracting 'a' from 'h' in each iteration
        h -= a

        # Incrementing the 'num' variable after each successful subtraction
        num += 1

    # Printing the final result 'num' to the console
    print(num)

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
