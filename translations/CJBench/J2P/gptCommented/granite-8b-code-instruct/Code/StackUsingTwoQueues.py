
import queue

class Stack:
    def __init__(self):
        self.main_queue = queue.Queue()
        self.temp_queue = queue.Queue()

    def push(self, item):
        self.temp_queue.put(item)
        while not self.main_queue.empty():
            self.temp_queue.put(self.main_queue.get())
        self.main_queue, self.temp_queue = self.temp_queue, self.main_queue

    def pop(self):
        if self.main_queue.empty():
            raise queue.Empty("Stack is empty")
        return self.main_queue.get()

    def peek(self):
        if self.main_queue.empty():
            return None
        return self.main_queue.queue[0]

    def is_empty(self):
        return self.main_queue.empty()

    def size(self):
        return self.main_queue.qsize()

if __name__ == "__main__":
    stack = Stack()
    n = int(input("Enter the number of operations: "))
    for _ in range(n):
        operation = input("Enter the operation type (push/pop/peek/isEmpty/size): ")
        if operation == "push":
            value = int(input("Enter the value to push: "))
            stack.push(value)
            print(f"Pushed: {value}")
        elif operation == "pop":
            try:
                print(f"Popped: {stack.pop()}")
            except queue.Empty as e:
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

