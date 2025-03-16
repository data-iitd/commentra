class Main:
    DEFAULT_CAPACITY = 10
    def __init__(self, size=DEFAULT_CAPACITY):
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")
        self.maxSize = size
        self.stackArray = [None] * size
        self.top = -1
    def push(self, value):
        if self.isFull():
            self.resize(self.maxSize * 2)
        self.stackArray[self.top + 1] = value
        self.top += 1
    def pop(self):
        if self.isEmpty():
            raise IndexError("Stack is empty, cannot pop element")
        value = self.stackArray[self.top]
        self.top -= 1
        if self.top + 1 < self.maxSize / 4 and self.maxSize > self.DEFAULT_CAPACITY:
            self.resize(self.maxSize / 2)
        return value
    def peek(self):
        if self.isEmpty():
            raise IndexError("Stack is empty, cannot peek element")
        return self.stackArray[self.top]
    def resize(self, newSize):
        newArray = [None] * newSize
        for i in range(self.top + 1):
            newArray[i] = self.stackArray[i]
        self.stackArray = newArray
        self.maxSize = newSize
    def isFull(self):
        return self.top + 1 == self.maxSize
    def isEmpty(self):
        return self.top == -1
    def makeEmpty(self):
        self.top = -1
    def size(self):
        return self.top + 1
    def __str__(self):
        sb = []
        sb.append("Main [")
        for i in range(self.top + 1):
            sb.append(str(self.stackArray[i]))
            if i < self.top:
                sb.append(", ")
        sb.append("]")
        return "".join(sb)

if __name__ == "__main__":
    import sys
    stack = Main()
    while True:
        command = sys.stdin.readline().strip()
        if command.lower() == "exit":
            break
        parts = command.split(" ")
        try:
            if parts[0] == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])
                stack.push(value)
                print("Pushed: " + str(value))
            elif parts[0] == "pop":
                print("Popped: " + str(stack.pop()))
            elif parts[0] == "peek":
                print("Top: " + str(stack.peek()))
            elif parts[0] == "size":
                print("Size: " + str(stack.size()))
            elif parts[0] == "isEmpty":
                print("Is empty: " + str(stack.isEmpty()))
            else:
                print("Error: Invalid command")
        except Exception as e:
            print("Error: " + str(e))

