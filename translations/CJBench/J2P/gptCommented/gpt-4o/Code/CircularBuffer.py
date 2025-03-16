class CircularPointer:
    def __init__(self, pointer, max_size):
        self.pointer = pointer  # Current position of the pointer
        self.max = max_size  # Maximum size of the buffer

    def get_and_increment(self):
        tmp = self.pointer  # Store current pointer
        self.pointer = (self.pointer + 1) % self.max  # Increment circularly
        return tmp  # Return the old pointer value


class Main:
    def __init__(self, size):
        # Validate that the size is positive
        if size <= 0:
            raise ValueError("Buffer size must be positive")
        # Initialize the buffer and pointers
        self.buffer = [None] * size
        self.put_pointer = CircularPointer(0, size)
        self.get_pointer = CircularPointer(0, size)
        self.size = 0  # Start with an empty buffer

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == len(self.buffer)

    def get(self):
        # Return None if the buffer is empty
        if self.is_empty():
            return None
        # Get the item at the current get pointer and decrement size
        item = self.buffer[self.get_pointer.get_and_increment()]
        self.size -= 1
        return item

    def put(self, item):
        # Validate that the item is not None
        if item is None:
            raise ValueError("Null items are not allowed")
        # If the buffer is full, increment the get pointer to overwrite
        if self.is_full():
            self.get_pointer.get_and_increment()
        else:
            self.size += 1  # Increment size if not full
        # Place the item at the current put pointer
        self.buffer[self.put_pointer.get_and_increment()] = item
        return True  # Indicate successful addition


if __name__ == "__main__":
    import sys

    # Read buffer size and number of operations from input
    buffer_size = int(sys.stdin.readline().strip())
    number_of_operations = int(sys.stdin.readline().strip())
    # Create a new buffer instance
    buffer = Main(buffer_size)

    # Process each operation
    for _ in range(number_of_operations):
        operation = sys.stdin.readline().strip()
        # Handle PUT operation
        if operation.startswith("PUT"):
            _, element = operation.split()
            buffer.put(element)  # Add element to buffer
            print(f"Added: {element}")
        # Handle GET operation
        elif operation == "GET":
            result = buffer.get()  # Retrieve element from buffer
            print(f"Retrieved: {result if result is not None else 'null'}")
        # Check if the buffer is empty
        elif operation == "ISEMPTY":
            print(f"Is Empty: {buffer.is_empty()}")
        # Check if the buffer is full
        elif operation == "ISFULL":
            print(f"Is Full: {buffer.is_full()}")

# <END-OF-CODE>
