def push(x):
    global top
    top += 1
    S[top] = x


def pop():
    global top
    top -= 1
    return S[top + 1]


# Define the stack array and top variable
S = [0] * 10000
top = 0

# Main function to read input, perform operations, and print the result
if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().split()

    for s in data:
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

    # Print the final result from the stack
    print(pop())
