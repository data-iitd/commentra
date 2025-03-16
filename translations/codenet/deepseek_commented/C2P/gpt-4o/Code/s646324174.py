# Define the stack list and top variable
top = -1
S = []

# Function to push an element onto the stack
def push(x):
    global top
    top += 1
    S.append(x)

# Function to pop an element from the stack
def pop():
    global top
    value = S[top]
    top -= 1
    return value

# Main function to read input, perform operations, and print the result
def main():
    global top
    top = -1  # Initialize the top of the stack

    # Read input until end of file
    try:
        while True:
            s = input()
            if s == '+':
                # Pop two elements, add them, and push the result
                b = pop()
                a = pop()
                push(a + b)
            elif s == '-':
                # Pop two elements, subtract the top element from the bottom element, and push the result
                b = pop()
                a = pop()
                push(a - b)
            elif s == '*':
                # Pop two elements, multiply them, and push the result
                b = pop()
                a = pop()
                push(a * b)
            else:
                # Convert the input string to an integer and push it onto the stack
                push(int(s))
    except EOFError:
        # Print the final result from the stack
        print(pop())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
