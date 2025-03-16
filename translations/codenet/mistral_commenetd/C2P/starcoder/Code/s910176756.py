#include<stdio.h> // Include the standard input/output library

def main(): # Start of the main function
    a, b, c = 0, 0, 0 # Declare three integer variables: a, b, and c
    op ='' # Declare a character variable: op

    a, op, b = map(int, input().split()) # Read an integer, an operator, and another integer from the standard input

    while(1): # Start of an infinite loop
        if ( op == '+' ): # Check if the operator is '+'
            c = a + b # If so, add the two numbers and store the result in variable c
            print(c) # Print the result to the standard output
        elif ( op == '-' ): # Check if the operator is '-'
            c = a - b # If so, subtract the second number from the first and store the result in variable c
            print(c) # Print the result to the standard output
        elif ( op == '*' ): # Check if the operator is '*'
            c = a * b # If so, multiply the two numbers and store the result in variable c
            print(c) # Print the result to the standard output
        elif ( op == '/' ): # Check if the operator is '/'
            c = a / b # If so, divide the first number by the second and store the result in variable c
            print(c) # Print the result to the standard output
        else: # If the operator is not one of the above, break the loop
            break
        a, op, b = map(int, input().split()) # Read the next set of numbers and operator from the standard input

if __name__ == "__main__":
    main() # Execute the main function

#