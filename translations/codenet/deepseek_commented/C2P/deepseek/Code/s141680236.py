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

# Read input until end of file
while True:
    try:
        line = input()
    except EOFError:
        break

    # Check the operation based on the first character of the input
    if line[0] == '+':
        # Pop two values, add them, and push the result
        yamagami = stack.pop()
        chonda = stack.pop()
        stack.push(chonda + yamagami)
    elif line[0] == '-':
        # Pop two values, subtract the second from the first, and push the result
        yamagami = stack.pop()
        chonda = stack.pop()
        stack.push(chonda - yamagami)
    elif line[0] == '*':
        # Pop two values, multiply them, and push the result
        yamagami = stack.pop()
        chonda = stack.pop()
        stack.push(chonda * yamagami)
    else:
        # Convert input to integer and push it onto the stack
        stack.push(int(line))

# Print the final result from the stack
print(stack.pop())
