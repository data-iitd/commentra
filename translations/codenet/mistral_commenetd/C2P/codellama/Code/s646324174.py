#include<stdio.h>
#include<stdlib.h>

# Initialize stack top to 0
top = 0
S = [0] * 10000

# Function to push an element onto the stack
def push(x):
 # Increment the top index and push the element
 S[top] = x
 top += 1

# Function to pop an element from the stack
def pop():
 # Return the top element and decrement the top index
 top -= 1
 return S[top]

# Main function
def main():
 # Initialize variables
 a, b = 0, 0
 s = ""

 # Initialize stack top to 0
 top = 0

 # Read input until end of file
 while True:
 # Check if the input is an operator or a number
 if s[0] == '+' or s[0] == '-' or s[0] == '*':
 # Pop the top two elements from the stack
 b = pop()
 a = pop()

 # Perform the operation and push the result back onto the stack
 if s[0] == '+':
 push(a + b)
 elif s[0] == '-':
 push(a - b)
 else: # s[0] == '*'
 push(a * b)
 else: # Input is a number
 # Push the number directly onto the stack
 push(int(s))

 # Print the final result
 print(pop())

 # Return 0 to indicate successful execution
 return 0

