class Stack:
    def __init__(self):
        self.top = -1
        self.S = []

    def push(self, x):
        self.S.append(x)
        self.top += 1

    def pop(self):
        if self.top == -1:
            raise IndexError("pop from empty stack")
        self.top -= 1
        return self.S.pop()

def main():
    stack = Stack()
    while True:
        try:
            s = input()
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
        except IndexError:
            print("Error: Stack is empty")
            return

    print(stack.pop())

if __name__ == "__main__":
    main()

# <END-OF-CODE>
