
import queue

class Main:
    def __init__(self, size):
        # Validate that the size is positive
        if size <= 0:
            raise ValueError("Buffer size must be positive")
        # Initialize the buffer and pointers
        self.buffer = queue.Queue(size)
        self.size = 0 # Start with an empty buffer

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == self.buffer.maxsize

    def get(self):
        # Return None if the buffer is empty
        if self.is_empty():
            return None
        # Get the item at the current get pointer and decrement size
        item = self.buffer.get()
        self.size -= 1
        return item

    def put(self, item):
        # Validate that the item is not None
        if item is None:
            raise ValueError("Null items are not allowed")
        # If the buffer is full, remove an item from the buffer
        if self.is_full():
            self.buffer.get()
        # Place the item at the current put pointer
        self.buffer.put(item)
        self.size += 1
        return True # Indicate successful addition

# Main method to run the buffer operations
if __name__ == "__main__":
    import sys

    # Read buffer size and number of operations from input
    bufferSize = int(input())
    numberOfOperations = int(input())
    # Create a new buffer instance
    buffer = Main(bufferSize)

    # Process each operation
    for _ in range(numberOfOperations):
        operation = input()
        # Handle PUT operation
        if operation == "PUT":
            element = input()
            buffer.put(element) # Add element to buffer
            print(f"Added: {element}")
        # Handle GET operation
        elif operation == "GET":
            result = buffer.get() # Retrieve element from buffer
            print(f"Retrieved: {result if result is not None else 'null'}")
        # Check if the buffer is empty
        elif operation == "ISEMPTY":
            print(f"Is Empty: {buffer.is_empty()}")
        # Check if the buffer is full
        elif operation == "ISFULL":
            print(f"Is Full: {buffer.is_full()}")
        else:
            print(f"Invalid operation: {operation}")

# Close the input stream to prevent resource leaks
sys.stdin.close()
