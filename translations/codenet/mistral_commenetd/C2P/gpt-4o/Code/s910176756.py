# Import the sys module for standard input/output
import sys

def main():  # Start of the main function
    a, op, b = map(str, input().split())  # Read an integer, an operator, and another integer from the standard input
    a = int(a)  # Convert the first input to an integer
    b = int(b)  # Convert the second input to an integer

    while True:  # Start of an infinite loop
        if op == '+':  # Check if the operator is '+'
            c = a + b  # If so, add the two numbers and store the result in variable c
            print(c)  # Print the result to the standard output

        elif op == '-':  # Check if the operator is '-'
            c = a - b  # If so, subtract the second number from the first and store the result in variable c
            print(c)  # Print the result to the standard output

        elif op == '*':  # Check if the operator is '*'
            c = a * b  # If so, multiply the two numbers and store the result in variable c
            print(c)  # Print the result to the standard output

        elif op == '/':  # Check if the operator is '/'
            c = a // b  # If so, divide the first number by the second and store the result in variable c
            print(c)  # Print the result to the standard output

        else:  # If the operator is not one of the above, break the loop
            break

        a, op, b = map(str, input().split())  # Read the next set of numbers and operator from the standard input
        a = int(a)  # Convert the first input to an integer
        b = int(b)  # Convert the second input to an integer

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
