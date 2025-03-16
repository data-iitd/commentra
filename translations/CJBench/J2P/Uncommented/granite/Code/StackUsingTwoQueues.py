
class Main:
    def __init__(self):
        self.mainQueue = []
        self.tempQueue = []

    def push(self, item):
        self.tempQueue.append(item)
        while self.mainQueue:
            self.tempQueue.append(self.mainQueue.pop())
        self.mainQueue, self.tempQueue = self.tempQueue, self.mainQueue

    def pop(self):
        if not self.mainQueue:
            raise IndexError("Stack is empty")
        return self.mainQueue.pop()

    def peek(self):
        if not self.mainQueue:
            return None
        return self.mainQueue[-1]

    def isEmpty(self):
        return not self.mainQueue

    def size(self):
        return len(self.mainQueue)

if __name__ == "__main__":
    stack = Main()
    n = int(input())
    for _ in range(n):
        operation = input().split()
        if operation[0] == "push":
            value = int(operation[1])
            stack.push(value)
            print("Pushed:", value)
        elif operation[0] == "pop":
            try:
                print("Popped:", stack.pop())
            except IndexError as e:
                print("Error:", e)
        elif operation[0] == "peek":
            top = stack.peek()
            if top is not None:
                print("Top element:", top)
            else:
                print("Stack is empty")
        elif operation[0] == "isEmpty":
            print("Is stack empty?", stack.isEmpty())
        elif operation[0] == "size":
            print("Stack size:", stack.size())
        else:
            print("Invalid operation")
