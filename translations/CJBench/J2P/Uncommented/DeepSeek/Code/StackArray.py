class Main:
    DEFAULT_CAPACITY = 10

    def __init__(self, size=DEFAULT_CAPACITY):
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")
        self.max_size = size
        self.stack_array = [None] * size
        self.top = -1

    def push(self, value):
        if self.is_full():
            self.resize(self.max_size * 2)
        self.stack_array[self.top + 1] = value
        self.top += 1

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is empty, cannot pop element")
        value = self.stack_array[self.top]
        self.stack_array[self.top] = None
        self.top -= 1
        if self.top + 1 < self.max_size / 4 and self.max_size > Main.DEFAULT_CAPACITY:
            self.resize(self.max_size // 2)
        return value

    def peek(self):
        if self.is_empty():
            raise IndexError("Stack is empty, cannot peek element")
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
        values = [str(self.stack_array[i]) for i in range(self.top + 1)]
        return f"Main [{', '.join(values)}]"

    @staticmethod
    def main():
        stack = Main()
        print("Enter commands (push <value>, pop, peek, size, isEmpty, exit):")
        while True:
            command = input().strip()
            if command.lower() == "exit":
                break
            try:
                parts = command.split()
                if parts[0].lower() == "push":
                    if len(parts) < 2:
                        print("Error: Missing value for push")
                        continue
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
                    print(f"Is empty: {stack.is_empty()}")
                else:
                    print(f"Unknown command: {parts[0]}")
            except Exception as e:
                print(f"Error: {e}")

Main.main()
