#include<stdio.h>
#include<stdlib.h>

# Define the stack array and top variable
top, S = 0, [0] * 10000

# Function to push an element onto the stack
def push(x):
    global top
    S[top] = x
    top += 1

# Function to pop an element from the stack
def pop():
    global top
    top -= 1
    return S[top]

# Main function to read input, perform operations, and print the result
def main():
    a, b = 0, 0
    s = ""
    top = 0 # Initialize the top of the stack

    # Read input until end of file
    while s != "":
        s = input()
        if s[0] == '+':
            # Pop two elements, add them, and push the result
            b = pop()
            a = pop()
            push(a + b)
        elif s[0] == '-':
            # Pop two elements, subtract the top element from the bottom element, and push the result
            b = pop()
            a = pop()
            push(a - b)
        elif s[0] == '*':
            # Pop two elements, multiply them, and push the result
            b = pop()
            a = pop()
            push(a * b)
        else:
            # Convert the input string to an integer and push it onto the stack
            push(int(s))
    # Print the final result from the stack
    print(pop())

