# Import the sys module for standard input/output
import sys

def main():  # Start of the main function
    # Read two integers from the user and store them in variables a and b
    a, b = map(int, input().split())

    # Multiply the two integers and store the result in variable c
    c = a * b

    # Multiply each integer with 2 and add them to get the value of d
    d = 2 * a + 2 * b

    # Print the values of c and d on the console
    print(c, d)

# Call the main function to execute the program
if __name__ == "__main__":
    main()

# <END-OF-CODE>
