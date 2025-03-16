# Initialize stack
stack = []

# Function to push an element onto the stack
def push(x):
    stack.append(x)

# Function to pop an element from the stack
def pop():
    return stack.pop()

# Main function
if __name__ == "__main__":
    import sys

    # Read input until end of file
    for line in sys.stdin:
        s = line.strip()
        # Check if the input is an operator or a number
        if s in ('+', '-', '*'):
            # Pop the top two elements from the stack
            b = pop()
            a = pop()

            # Perform the operation and push the result back onto the stack
            if s == '+':
                push(a + b)
            elif s == '-':
                push(a - b)
            elif s == '*':
                push(a * b)
        else:  # Input is a number
            # Push the number directly onto the stack
            push(int(s))

    # Print the final result
    print(pop())

# <END-OF-CODE>
