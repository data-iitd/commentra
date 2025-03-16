# Global variables
top = -1  # Stack to hold integers and a variable to track the top index
S = []    # Stack to hold integers

# Function to push an integer onto the stack
def push(x):
    global top
    top += 1
    if top < len(S):
        S[top] = x
    else:
        S.append(x)  # Append if the stack is not large enough

# Function to pop an integer from the stack
def pop():
    global top
    value = S[top]
    top -= 1
    return value

if __name__ == "__main__":
    import sys

    # Initialize the stack top index
    top = -1

    # Read input until EOF
    for line in sys.stdin:
        s = line.strip()  # Read and strip the input line

        # Check for addition operation
        if s == '+':
            b = pop()  # Pop the top two values from the stack
            a = pop()
            push(a + b)  # Push the result of addition back onto the stack
        # Check for subtraction operation
        elif s == '-':
            b = pop()  # Pop the top two values from the stack
            a = pop()
            push(a - b)  # Push the result of subtraction back onto the stack
        # Check for multiplication operation
        elif s == '*':
            b = pop()  # Pop the top two values from the stack
            a = pop()
            push(a * b)  # Push the result of multiplication back onto the stack
        # If the input is a number, convert it and push onto the stack
        else:
            push(int(s))  # Convert string to integer and push onto the stack

    # Print the final result which is the last remaining value in the stack
    print(pop())  # Output the final result
# <END-OF-CODE>
