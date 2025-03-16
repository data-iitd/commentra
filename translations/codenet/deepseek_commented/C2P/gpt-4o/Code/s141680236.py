# Function declarations for stack operations
def push(value):
    global top, stack
    top += 1
    stack[top] = value

def pop():
    global top, stack
    value = stack[top]
    top -= 1
    return value

# Global variables for stack and top index
top = -1
stack = [0] * 1000  # Initialize stack with a fixed size

# Read input until end of file
try:
    while True:
        null = input().strip()  # Read input
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
            push(int(null))
except EOFError:
    # Print the final result from the stack
    print(pop())

# <END-OF-CODE>
