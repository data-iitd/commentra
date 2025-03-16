class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.items:
            return None
        return self.items.pop()

# Initialize the stack
stack = Stack()

# Read input until EOF
while True:
    try:
        line = input()
    except EOFError:
        break

    # If the input is a '+' operator, perform addition
    if line == '+':
        chonda = stack.pop()
        yamagami = stack.pop()
        stack.push(chonda + yamagami)
    # If the input is a '-' operator, perform subtraction
    elif line == '-':
        yamagami = stack.pop()
        chonda = stack.pop()
        stack.push(chonda - yamagami)
    # If the input is a '*' operator, perform multiplication
    elif line == '*':
        chonda = stack.pop()
        yamagami = stack.pop()
        stack.push(chonda * yamagami)
    # If the input is a number, convert it to an integer and push onto the stack
    else:
        stack.push(int(line))

# Pop and print the final result from the stack
print(stack.pop())

