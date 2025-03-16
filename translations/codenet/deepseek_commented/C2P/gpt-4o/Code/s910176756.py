# Import the sys module for input handling
import sys

def main():  # Define the main function
    while True:  # Start an infinite loop
        # Read input from the user
        input_line = input()  # Read a line of input
        if not input_line:  # If the input is empty, break the loop
            break
        a, op, b = input_line.split()  # Split the input into operands and operator
        a = int(a)  # Convert the first operand to an integer
        b = int(b)  # Convert the second operand to an integer
        
        if op == '+':  # Check if the operator is addition
            c = a + b  # Perform the addition operation
            print(c)  # Print the result
        elif op == '-':  # Check if the operator is subtraction
            c = a - b  # Perform the subtraction operation
            print(c)  # Print the result
        elif op == '*':  # Check if the operator is multiplication
            c = a * b  # Perform the multiplication operation
            print(c)  # Print the result
        elif op == '/':  # Check if the operator is division
            c = a // b  # Perform the integer division operation
            print(c)  # Print the result
        else:  # If the operator is not recognized
            break  # Exit the loop

if __name__ == "__main__":  # Check if the script is being run directly
    main()  # Call the main function

# <END-OF-CODE>
