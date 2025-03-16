# Initialize stack as a list
stack = []

def push(value):
    # Push element onto the stack
    stack.append(value)

def pop():
    # Pop the top element from the stack and return it
    return stack.pop()

if __name__ == "__main__":
    import sys

    # Read input strings from standard input until EOF is reached
    for line in sys.stdin:
        null = line.strip()  # Read and strip the input line

        # Check if the first character of the input string is '+'
        if null[0] == '+':
            # Pop two elements from the stack
            chonda = pop()
            yamagami = pop()

            # Add the popped elements and push the result onto the stack
            push(chonda + yamagami)
        # Check if the first character of the input string is '-'
        elif null[0] == '-':
            # Pop two elements from the stack
            yamagami = pop()
            chonda = pop()

            # Subtract the second popped element from the first popped element and push the result onto the stack
            push(chonda - yamagami)
        # Check if the first character of the input string is '*'
        elif null[0] == '*':
            # Pop two elements from the stack
            chonda = pop()
            yamagami = pop()

            # Multiply the popped elements and push the result onto the stack
            push(chonda * yamagami)
        # If the first character of the input string is not an operator, convert it to an integer and push it onto the stack
        else:
            push(int(null))

    # Print the top element of the stack, which is the final result
    print(pop())

# <END-OF-CODE>
