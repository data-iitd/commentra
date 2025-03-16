class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.items:
            return None
        return self.items.pop()

def main():
    stack = Stack()
    while True:
        try:
            line = input()
        except EOFError:
            break
        if line.startswith('+'):
            b = stack.pop()
            a = stack.pop()
            stack.push(a + b)
        elif line.startswith('-'):
            b = stack.pop()
            a = stack.pop()
            stack.push(a - b)
        elif line.startswith('*'):
            b = stack.pop()
            a = stack.pop()
            stack.push(a * b)
        else:
            stack.push(int(line))
    print(stack.pop())

main()
