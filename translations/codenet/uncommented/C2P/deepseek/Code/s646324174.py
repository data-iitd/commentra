class Stack:
    def __init__(self):
        self.items = []

    def push(self, x):
        self.items.append(x)

    def pop(self):
        return self.items.pop()

stack = Stack()

while True:
    try:
        s = input().strip()
        if s == '+':
            b = stack.pop()
            a = stack.pop()
            stack.push(a + b)
        elif s == '-':
            b = stack.pop()
            a = stack.pop()
            stack.push(a - b)
        elif s == '*':
            b = stack.pop()
            a = stack.pop()
            stack.push(a * b)
        else:
            stack.push(int(s))
    except EOFError:
        break

print(stack.pop())
