# Importing the sys module for standard input/output
import sys

def main():  # Declaring the main function
    a, b = map(int, sys.stdin.readline().split())  # Reading two integers from the standard input and storing them in variables a and b

    # Logical block to check if 500 times the value of variable 'a' is greater than or equal to the value of variable 'b'
    if 500 * a >= b:
        print("Yes")  # If the condition is true, print 'Yes' to the standard output
    else:
        print("No")  # If the condition is false, print 'No' to the standard output

if __name__ == "__main__":  # Ensuring the main function runs only when the script is executed directly
    main()

# <END-OF-CODE>
