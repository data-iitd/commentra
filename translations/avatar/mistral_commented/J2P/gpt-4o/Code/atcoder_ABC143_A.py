# Importing necessary libraries
import sys

# Main function to start the execution of the Python program
def main():
    try:
        # Reading a line of input from the console and splitting it into a list of strings using space as delimiter
        x = input().strip().split()

        # Parsing the first and second elements of the input list into integers 'a' and 'b' respectively
        a = int(x[0])
        b = int(x[1])

        # Calculate the value of 'c' by subtracting 'b' multiplied by 2 from 'a'
        c = a - b * 2

        # If the value of 'c' is negative, set it to zero
        if c < 0:
            c = 0

        # Print the value of 'c' to the console
        print(c)
    except Exception as e:
        # Handling any exceptions that might occur during the execution of the program
        pass

# Calling the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
