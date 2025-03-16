
import sys

class Main:
    # Declare instance variables
    buffer = []
    putPointer = 0
    getPointer = 0
    size = 0

    # Constructor
    def __init__(self, size):
        # Check if size is positive
        if size <= 0:
            raise Exception("Buffer size must be positive")

        # Initialize buffer with given size
        self.buffer = [None] * size

        # Initialize putPointer and getPointer with given size
        self.putPointer = 0
        self.getPointer = 0

        # Initialize size to 0
        self.size = 0

    # Check if buffer is empty
    def isEmpty(self):
        return self.size == 0

    # Check if buffer is full
    def isFull(self):
        return self.size == len(self.buffer)

    # Get an item from buffer
    def get(self):
        if self.isEmpty():
            # Return null if buffer is empty
            return None

        # Get the item at the current getPointer position
        item = self.buffer[self.getPointer]

        # Decrement size
        self.size -= 1

        # Return the item
        return item

    # Put an item into buffer
    def put(self, item):
        if item == None:
            # Throw an exception if item is null
            raise Exception("Null items are not allowed")

        if self.isFull():
            # Increment getPointer to make room for new item
            self.getPointer += 1
        else:
            # Increment size and put the item at the current putPointer position
            self.size += 1
            self.buffer[self.putPointer] = item

        # Return true to indicate successful put
        return True

# Main method
if __name__ == "__main__":
    # Read buffer size from standard input
    bufferSize = int(sys.stdin.readline())

    # Read number of operations from standard input
    numberOfOperations = int(sys.stdin.readline())

    # Create a new Main instance with given buffer size
    buffer = Main(bufferSize)

    # Perform given number of operations
    for i in range(numberOfOperations):
        operation = sys.stdin.readline().strip()

        if operation == "PUT":
            # Read the element to be put from standard input
            element = sys.stdin.readline().strip()

            # Put the element into the buffer
            buffer.put(element)

            # Print a message indicating successful put
            print("Added: " + element)
        elif operation == "GET":
            # Get an item from the buffer and print its value
            result = buffer.get()
            print("Retrieved: " + (result!= None and result or "null"))
        elif operation == "ISEMPTY":
            # Print a message indicating if the buffer is empty
            print("Is Empty: " + buffer.isEmpty())
        elif operation == "ISFULL":
            # Print a message indicating if the buffer is full
            print("Is Full: " + buffer.isFull())

