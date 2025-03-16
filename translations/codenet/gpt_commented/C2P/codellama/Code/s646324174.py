#include<stdio.h>
#include<stdlib.h>

# Global variables
top = 0
S = [0] * 10000

# Function to push an integer onto the stack
def push(x):
    global top
    S[top] = x
    top += 1

# Function to pop an integer from the stack
def pop():
    global top
    top -= 1
    return S[top]

# Main function
def main():
    a, b = 0, 0
    s = ""
    top = 0

    # Read input until EOF
    while True:
        s = input()
        if s == "":
            break
        # Check for addition operation
        if s[0] == '+':
            b = pop() # Pop the top two values from the stack
            a = pop()
            push(a + b) # Push the result of addition back onto the stack
        # Check for subtraction operation
        elif s[0] == '-':
            b = pop() # Pop the top two values from the stack
            a = pop()
            push(a - b) # Push the result of subtraction back onto the stack
        # Check for multiplication operation
        elif s[0] == '*':
            b = pop() # Pop the top two values from the stack
            a = pop()
            push(a * b) # Push the result of multiplication back onto the stack
        # If the input is a number, convert it and push onto the stack
        else:
            push(int(s)) # Convert string to integer and push onto the stack

    # Print the final result which is the last remaining value in the stack
    print(pop())

# End of code
