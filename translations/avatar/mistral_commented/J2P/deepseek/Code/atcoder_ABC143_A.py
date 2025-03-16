# Importing necessary Python libraries
import sys

# Main method is the entry point of the Python application
def main():
    try:
        # Reading a line of input from the console and splitting it into a list of strings using space as delimiter
        x = sys.stdin.readline().strip().split()

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

# Call the main method to start the execution of the Python program
if __name__ == "__main__":
    main()
