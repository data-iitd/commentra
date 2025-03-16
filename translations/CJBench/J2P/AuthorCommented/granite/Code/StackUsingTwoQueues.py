
class Stack:
    def __init__(self):
        self.main_queue = []
        self.temp_queue = []

    def push(self, item):
        self.temp_queue.append(item)
        while self.main_queue:
            self.temp_queue.append(self.main_queue.pop())
        self.main_queue, self.temp_queue = self.temp_queue, self.main_queue

    def pop(self):
        if not self.main_queue:
            raise IndexError("Stack is empty")
        return self.main_queue.pop()

    def peek(self):
        if not self.main_queue:
            return None
        return self.main_queue[-1]

    def is_empty(self):
        return not self.main_queue

    def size(self):
        return len(self.main_queue)

if __name__ == "__main__":
    stack = Stack()
    n = int(input("Number of operations: "))

    for _ in range(n):
        operation = input("Operation: ")

        if operation == "push":
            value = int(input("Value: "))
            stack.push(value)
            print(f"Pushed: {value}")
        elif operation == "pop":
            try:
                print(f"Popped: {stack.pop()}")
            except IndexError as e:
                print(f"Error: {e}")
        elif operation == "peek":
            top = stack.peek()
            if top is not None:
                print(f"Top element: {top}")
            else:
                print("Stack is empty")
        elif operation == "isEmpty":
            print(f"Is stack empty? {stack.is_empty()}")
        elif operation == "size":
            print(f"Stack size: {stack.size()}")
        else:
            print("Invalid operation")

