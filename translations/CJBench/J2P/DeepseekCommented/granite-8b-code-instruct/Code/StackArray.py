
class Main:
    def __init__(self, size=10):
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")
        self.max_size = size
        self.stack_array = [None] * size
        self.top = -1

    def push(self, value):
        if self.is_full():
            self.resize(self.max_size * 2)
        self.top += 1
        self.stack_array[self.top] = value

    def pop(self):
        if self.is_empty():
            raise ValueError("Stack is empty, cannot pop element")
        value = self.stack_array[self.top]
        self.top -= 1
        if self.top + 1 < self.max_size // 4 and self.max_size > 10:
            self.resize(self.max_size // 2)
        return value

    def peek(self):
        if self.is_empty():
            raise ValueError("Stack is empty, cannot peek element")
        return self.stack_array[self.top]

    def resize(self, new_size):
        new_array = [None] * new_size
        for i in range(self.top + 1):
            new_array[i] = self.stack_array[i]
        self.stack_array = new_array
        self.max_size = new_size

    def is_full(self):
        return self.top + 1 == self.max_size

    def is_empty(self):
        return self.top == -1

    def make_empty(self):
        self.top = -1

    def size(self):
        return self.top + 1

    def __str__(self):
        result = "Main ["
        for i in range(self.top + 1):
            result += str(self.stack_array[i])
            if i < self.top:
                result += ", "
        result += "]"
        return result

if __name__ == "__main__":
    import sys
    stack = Main()
    while True:
        line = input().strip()
        if line.lower() == "exit":
            break
        try:
            parts = line.split()
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
                print("Is empty:", stack.is_empty())
            else:
                print("Error: Invalid command")
        except Exception as e:
            print("Error:", e)

