
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
        self.stackArray[self.top + 1] = value
        self.top += 1

    def pop(self):
        if self.isEmpty():
            raise ValueError("Stack is empty, cannot pop element")
        value = self.stackArray[self.top]
        self.stackArray[self.top] = None
        self.top -= 1
        if self.top + 1 < self.maxSize // 4 and self.maxSize > 10:
            self.resize(self.maxSize // 2)
        return value

    def peek(self):
        if self.isEmpty():
            raise ValueError("Stack is empty, cannot peek element")
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
        result = "Main ["
        for i in range(self.top + 1):
            result += str(self.stackArray[i])
            if i < self.top:
                result += ", "
        result += "]"
        return result

if __name__ == "__main__":
    import sys
    stack = Main()
    print("Enter commands (push <value>, pop, peek, size, isEmpty, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split(" ")
            if parts[0].lower() == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
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
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", e)
    sys.exit(0)

