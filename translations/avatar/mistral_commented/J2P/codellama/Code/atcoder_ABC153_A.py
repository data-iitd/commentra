# Importing necessary Python libraries for reading input from the console and handling exceptions
import sys

# Main method is the entry point of the Python application
def main():

    # Reading a single line of input from the console and storing it as a String array
    str = sys.stdin.readline().split()

    # Parsing the first two elements of the String array as integers 'h' and 'a' respectively
    h = int(str[0])
    a = int(str[1])

    # Initializing a variable 'num' to keep track of the number of steps
    num = 0

    # Using a for loop to simulate the given condition
    for i in range(1, h + 1):

        # Subtracting 'a' from 'h' in each iteration
        h = h - a

        # Incrementing the 'num' variable after each successful subtraction
        num += 1

    # Printing the final result 'num' to the console
    print(num)

# Calling the main method to begin the execution of the program
main()


