# Function prototypes for stack operations
def push(value):
    global top, stack
    top += 1
    stack[top] = value

def pop():
    global top, stack
    value = stack[top]
    top -= 1
    return value

# Global variables for stack management
top = -1  # Initialize the stack top index
stack = [0] * 1000  # 'stack' is the stack array

# Read input until EOF
try:
    while True:
        null = input()  # Read input
        # If the input is a '+' operator, perform addition
        if null == '+':
            chonda = pop()  # Pop the top two values from the stack
            yamagami = pop()
            push(chonda + yamagami)  # Push the result of addition back onto the stack
        # If the input is a '-' operator, perform subtraction
        elif null == '-':
            yamagami = pop()  # Pop the top two values from the stack
            chonda = pop()
            push(chonda - yamagami)  # Push the result of subtraction back onto the stack
        # If the input is a '*' operator, perform multiplication
        elif null == '*':
            chonda = pop()  # Pop the top two values from the stack
            yamagami = pop()
            push(chonda * yamagami)  # Push the result of multiplication back onto the stack
        # If the input is a number, convert it to an integer and push onto the stack
        else:
            push(int(null))
except EOFError:
    # Pop and print the final result from the stack
    print(pop())

# End of the program
# <END-OF-CODE>
