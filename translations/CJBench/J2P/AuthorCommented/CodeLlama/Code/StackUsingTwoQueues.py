
import sys

class Main:
    def __init__(self):
        self.mainQueue = []
        self.tempQueue = []

    def push(self, item):
        self.tempQueue.append(item)
        while self.mainQueue:
            self.tempQueue.append(self.mainQueue.pop(0))
        self.mainQueue, self.tempQueue = self.tempQueue, self.mainQueue

    def pop(self):
        if not self.mainQueue:
            raise IndexError("Stack is empty")
        return self.mainQueue.pop(0)

    def peek(self):
        if not self.mainQueue:
            return None
        return self.mainQueue[0]

    def isEmpty(self):
        return not self.mainQueue

    def size(self):
        return len(self.mainQueue)


if __name__ == "__main__":
    stack = Main()
    n = int(sys.stdin.readline())
    for _ in range(n):
        operation = sys.stdin.readline().strip()
        if operation == "push":
            value = int(sys.stdin.readline().strip())
            stack.push(value)
            print("Pushed:", value)
        elif operation == "pop":
            try:
                print("Popped:", stack.pop())
            except IndexError as e:
                print("Error:", e)
        elif operation == "peek":
            top = stack.peek()
            if top is not None:
                print("Top element:", top)
            else:
                print("Stack is empty")
        elif operation == "isEmpty":
            print("Is stack empty?", stack.isEmpty())
        elif operation == "size":
            print("Stack size:", stack.size())
        else:
            print("Invalid operation")

