#include<stdio.h>
#include<stdlib.h>
#include<string.h>

# Function declarations for stack operations
def push(chonda):
    global top, kinbo
    kinbo[top + 1] = chonda
    top += 1

def pop():
    global top, kinbo
    top -= 1
    return kinbo[top + 1]

# Global variables for stack and top index
top = 0
kinbo = [0] * 1000

# Array to store input characters temporarily
null = [0] * 100

# Read input until end of file
while scanf("%s", null) != EOF:
    # Check the operation based on the first character of the input
    if null[0] == '+':
        # Pop two values, add them, and push the result
        chonda = pop()
        yamagami = pop()
        push(chonda + yamagami)
    elif null[0] == '-':
        # Pop two values, subtract the second from the first, and push the result
        yamagami = pop()
        chonda = pop()
        push(chonda - yamagami)
    elif null[0] == '*':
        # Pop two values, multiply them, and push the result
        chonda = pop()
        yamagami = pop()
        push(chonda * yamagami)
    else:
        # Convert input to integer and push it onto the stack
        push(atoi(null))

# Print the final result from the stack
printf("%d\n", pop())

# 