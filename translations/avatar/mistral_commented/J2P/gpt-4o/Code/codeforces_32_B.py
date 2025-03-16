# Importing the sys module for reading input
import sys

def main():  # Defining the main function
    n = sys.stdin.read().strip()  # Reading a string from the console and stripping any extra whitespace

    s = False  # Initializing a boolean variable 's' to False

    for char in n:  # Starting a for loop to iterate through each character in the string 'n'
        if char == '.':  # Checking if the current character is a '.'
            if s:  # If the boolean variable 's' is True
                print(1, end='')  # Printing '1' to the console
                s = False  # Setting the boolean variable 's' to False
            else:  # If the boolean variable 's' is False
                print(0, end='')  # Printing '0' to the console
        else:  # If the current character is not a '.'
            if s:  # If the boolean variable 's' is True
                print(2, end='')  # Printing '2' to the console
                s = False  # Setting the boolean variable 's' to False
            else:  # If the boolean variable 's' is False
                s = True  # Setting the boolean variable 's' to True

if __name__ == "__main__":  # Checking if the script is being run directly
    main()  # Calling the main function

# <END-OF-CODE>
