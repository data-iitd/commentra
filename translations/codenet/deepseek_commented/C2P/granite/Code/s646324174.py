
# Python code to translate the given C code

# Define the stack list and top variable
stack = []
top = -1

# Function to push an element onto the stack
def push(x):
    global top
    stack.append(x)
    top += 1

# Function to pop an element from the stack
def pop():
    global top
    x = stack[top]
    top -= 1
    return x

# Main function to read input, perform operations, and print the result
def main():
    input_str = input()
    while input_str!= "