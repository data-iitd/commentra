
# Buffer to hold items
buffer = []
# Pointers to manage the circular buffer
putPointer = 0
getPointer = 0
# Current size of the buffer
size = 0

# Constructor to initialize the buffer with a given size
def __init__(self, size):
    # Validate that the size is positive
    if size <= 0:
        raise ValueError("Buffer size must be positive")
    # Initialize the buffer and pointers
    self.buffer = [None] * size
    self.putPointer = 0
    self.getPointer = 0
    self.size = 0 # Start with an empty buffer

# Check if the buffer is empty
def isEmpty(self):
    return self.size == 0

# Check if the buffer is full
def isFull(self):
    return self.size == len(self.buffer)

# Retrieve an item from the buffer
def get(self):
    # Return null if the buffer is empty
    if self.isEmpty():
        return None
    # Get the item at the current get pointer and decrement size
    item = self.buffer[self.getPointer]
    self.size -= 1
    return item

# Add an item to the buffer
def put(self, item):
    # Validate that the item is not null
    if item is None:
        raise ValueError("Null items are not allowed")
    # If the buffer is full, increment the get pointer to overwrite
    if self.isFull():
        self.getPointer += 1
    else:
        self.size += 1 # Increment size if not full
    # Place the item at the current put pointer
    self.buffer[self.putPointer] = item
    return True # Indicate successful addition

# Inner class to manage circular indexing
class CircularPointer:
    # Constructor to initialize the pointer and its maximum
    def __init__(self, pointer, max):
        self.pointer = pointer
        self.max = max

    # Get the current pointer value and increment it circularly
    def getAndIncrement(self):
        tmp = self.pointer # Store current pointer
        self.pointer = (self.pointer + 1) % self.max # Increment circularly
        return tmp # Return the old pointer value

# Main method to run the buffer operations
def main(args):
    # Read buffer size and number of operations from input
    bufferSize = int(input())
    numberOfOperations = int(input())
    # Create a new buffer instance
    buffer = Main(bufferSize)
    
    # Process each operation
    for i in range(numberOfOperations):
        operation = input()
        # Handle PUT operation
        if operation == "PUT":
            element = input()
            buffer.put(element) # Add element to buffer
            print("Added: " + element)
        # Handle GET operation
        elif operation == "GET":
            result = buffer.get() # Retrieve element from buffer
            print("Retrieved: " + (result if result else "null"))
        # Check if the buffer is empty
        elif operation == "ISEMPTY":
            print("Is Empty: " + str(buffer.isEmpty()))
        # Check if the buffer is full
        elif operation == "ISFULL":
            print("Is Full: " + str(buffer.isFull()))

# Close the scanner to prevent resource leaks
scanner.close()

