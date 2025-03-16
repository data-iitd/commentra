
import sys

class Main:
    def __init__(self):
        self.stack = []

    def push(self, value):
        self.stack.append(value)

    def pop(self):
        if len(self.stack) == 0:
            raise Exception("Stack is empty, cannot pop element")
        return self.stack.pop()

    def peek(self):
        if len(self.stack) == 0:
            raise Exception("Stack is empty, cannot peek element")
        return self.stack[-1]

    def size(self):
        return len(self.stack)

    def isEmpty(self):
        return len(self.stack) == 0

    def makeEmpty(self):
        self.stack = []

    def __str__(self):
        return str(self.stack)

if __name__ == "__main__":
    stack = Main()
    while True:
        command = input("Enter commands (push <value>, pop, peek, size, isEmpty, exit):")
        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0].lower() == "push":
                if len(parts) < 2:
                    raise Exception("Missing value for push")
                value = int(parts[1])
                stack.push(value)
                print("Pushed:", value)
            elif parts[0].lower() == "pop":
                print("Popped:", stack.pop())
            elif parts[0].lower() == "peek":
                print("Top:", stack.peek())
            elif parts[0].lower() == "size":
                print("Size:", stack.size())
            elif parts[0].lower() == "isempty":
                print("Is empty:", stack.isEmpty())
            else:
                raise Exception("Unknown command: " + parts[0])
        except Exception as e:
            print("Error:", e)

