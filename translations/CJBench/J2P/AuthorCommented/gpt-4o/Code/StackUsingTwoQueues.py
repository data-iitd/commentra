from collections import deque

class StackUsingQueues:
    def __init__(self):
        # Initialize two queues
        self.main_queue = deque()
        self.temp_queue = deque()

    def push(self, item):
        # Push an item onto the stack
        self.temp_queue.append(item)
        while self.main_queue:
            self.temp_queue.append(self.main_queue.popleft())
        # Swap the queues
        self.main_queue, self.temp_queue = self.temp_queue, self.main_queue

    def pop(self):
        # Remove and return the top element of the stack
        if not self.main_queue:
            raise IndexError("Stack is empty")
        return self.main_queue.popleft()

    def peek(self):
        # Return the top element without removing it
        if not self.main_queue:
            return None
        return self.main_queue[0]

    def is_empty(self):
        # Check if the stack is empty
        return len(self.main_queue) == 0

    def size(self):
        # Return the size of the stack
        return len(self.main_queue)

if __name__ == "__main__":
    stack = StackUsingQueues()
    n = int(input("Enter number of operations: "))  # Number of operations

    for _ in range(n):
        operation = input().strip()

        if operation == "push":
            value = int(input())
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

# <END-OF-CODE>
