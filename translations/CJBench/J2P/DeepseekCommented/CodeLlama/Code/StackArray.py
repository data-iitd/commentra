
class Main:
    def __init__(self, size=10):
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")
        self.maxSize = size
        self.stackArray = [None] * size
        self.top = -1

    def push(self, value):
        if self.isFull():
            self.resize(self.maxSize * 2)
        self.top += 1
        self.stackArray[self.top] = value

    def pop(self):
        if self.isEmpty():
            raise ValueError("Stack is empty, cannot pop element")
        value = self.stackArray[self.top]
        self.stackArray[self.top] = None
        self.top -= 1
        if self.top + 1 < self.maxSize / 4 and self.maxSize > 10:
            self.resize(self.maxSize // 2)
        return value

    def peek(self):
        if self.isEmpty():
            raise ValueError("Stack is empty, cannot peek element")
        return self.stackArray[self.top]

    def isFull(self):
        return self.top + 1 == self.maxSize

    def isEmpty(self):
        return self.top == -1

    def makeEmpty(self):
        self.top = -1

    def size(self):
        return self.top + 1

    def resize(self, newSize):
        newArray = [None] * newSize
        for i in range(self.top + 1):
            newArray[i] = self.stackArray[i]
        self.stackArray = newArray
        self.maxSize = newSize

    def __str__(self):
        return "Main [ " + ", ".join(map(str, self.stackArray[:self.top + 1])) + " ]"


if __name__ == "__main__":
    stack = Main()
    while True:
        command = input("Enter command (push <value>, pop, peek, size, isEmpty, exit): ").strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split()
            if parts[0].lower() == "push":
                if len(parts) < 2:
                    raise ValueError("Missing value for push")
                value = int(parts[1])
                stack.push(value)
                print(f"Pushed: {value}")
            elif parts[0].lower() == "pop":
                print(f"Popped: {stack.pop()}")
            elif parts[0].lower() == "peek":
                print(f"Top: {stack.peek()}")
            elif parts[0].lower() == "size":
                print(f"Size: {stack.size()}")
            elif parts[0].lower() == "isempty":
                print(f"Is empty: {stack.isEmpty()}")
            else:
                raise ValueError("Invalid command")
        except ValueError as e:
            print(f"Error: {e}")

    print("