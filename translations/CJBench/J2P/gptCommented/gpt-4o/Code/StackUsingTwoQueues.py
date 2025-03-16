from collections import deque

class Stack:
    def __init__(self):
        # Initialize two queues to simulate stack behavior
        self.main_queue = deque()
        self.temp_queue = deque()

    def push(self, item):
        # Add the new item to the temporary queue
        self.temp_queue.append(item)
        
        # Move all elements from the main queue to the temporary queue
        while self.main_queue:
            self.temp_queue.append(self.main_queue.popleft())
        
        # Swap the references of the main queue and the temporary queue
        self.main_queue, self.temp_queue = self.temp_queue, self.main_queue

    def pop(self):
        # Check if the main queue is empty and raise an exception if it is
        if not self.main_queue:
            raise IndexError("Stack is empty")
        # Remove and return the top item from the main queue
        return self.main_queue.popleft()

    def peek(self):
        # If the main queue is empty, return None
        if not self.main_queue:
            return None
        # Return the top item of the main queue
        return self.main_queue[0]

    def is_empty(self):
        # Return True if the main queue is empty, False otherwise
        return not self.main_queue

    def size(self):
        # Return the size of the main queue
        return len(self.main_queue)

# Main function to run the program
if __name__ == "__main__":
    # Create an instance of the Stack class
    stack = Stack()
    
    # Read the number of operations to perform
    n = int(input())
    
    # Loop through the number of operations
    for _ in range(n):
        # Read the operation type
        operation = input().strip()
        if operation == "push":
            # Read the value to push onto the stack
            value = int(input())
            stack.push(value)
            print(f"Pushed: {value}")
        elif operation == "pop":
            # Attempt to pop an item from the stack and handle exceptions
            try:
                print(f"Popped: {stack.pop()}")
            except IndexError as e:
                print(f"Error: {e}")
        elif operation == "peek":
            # Peek at the top item of the stack
            top = stack.peek()
            if top is not None:
                print(f"Top element: {top}")
            else:
                print("Stack is empty")
        elif operation == "isEmpty":
            # Check if the stack is empty
            print(f"Is stack empty? {stack.is_empty()}")
        elif operation == "size":
            # Get the size of the stack
            print(f"Stack size: {stack.size()}")
        else:
            # Handle invalid operations
            print("Invalid operation")

# <END-OF-CODE>
