class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

# Initialize the stack and top index
stack = Stack()

# Read input until EOF
import sys
for line in sys.stdin:
    s = line.strip()
    # Check for addition operation
    if s == '+':
        b = stack.pop()
        a = stack.pop()
        stack.push(a + b)
    # Check for subtraction operation
    elif s == '-':
        b = stack.pop()
        a = stack.pop()
        stack.push(a - b)
    # Check for multiplication operation
    elif s == '*':
        b = stack.pop()
        a = stack.pop()
        stack.push(a * b)
    # If the input is a number, convert it and push onto the stack
    else:
        stack.push(int(s))

# Print the final result which is the last remaining value in the stack
print(stack.pop())
