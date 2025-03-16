class Stack:
    DEFAULT_CAPACITY = 10

    def __init__(self, size=None):
        if size is None:
            size = self.DEFAULT_CAPACITY
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
            raise IndexError("Stack is empty, cannot pop element")
        value = self.stack_array[self.top]
        self.top -= 1
        if self.top + 1 < self.max_size / 4 and self.max_size > self.DEFAULT_CAPACITY:
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
        return "Stack [" + ", ".join(str(self.stack_array[i]) for i in range(self.top + 1)) + "]"


def main():
    import sys
    stack = Stack()  # Create an instance of the Stack class

    for line in sys.stdin:
        command = line.strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split()
            if parts[0] == "push":
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])
                stack.push(value)
                print(f"Pushed: {value}")
            elif parts[0] == "pop":
                print(f"Popped: {stack.pop()}")
            elif parts[0] == "peek":
                print(f"Top: {stack.peek()}")
            elif parts[0] == "size":
                print(f"Size: {stack.size()}")
            elif parts[0] == "isEmpty":
                print(f"Is empty: {stack.is_empty()}")
            else:
                print("Error: Unknown command")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()

# <END-OF-CODE>
