
import sys

class Main:
    # Default capacity for the queue
    DEFAULT_CAPACITY = 10
    # Maximum size of the queue
    maxSize = 0
    # Array to hold the queue elements
    queueArray = []
    # Index of the front of the queue
    front = 0
    # Index of the rear of the queue
    rear = -1
    # Current number of items in the queue
    nItems = 0

    # Default constructor initializing with default capacity
    def __init__(self):
        self.maxSize = Main.DEFAULT_CAPACITY
        self.queueArray = [None] * self.maxSize
        self.front = 0
        self.rear = -1
        self.nItems = 0

    # Constructor that initializes the queue with a specified capacity
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.maxSize = capacity
        self.queueArray = [None] * self.maxSize
        self.front = 0
        self.rear = -1
        self.nItems = 0

    # Method to insert an element into the queue
    def insert(self, element):
        # Check if the queue is full
        if self.isFull():
            return False
        # Update rear index in a circular manner and add the element
        self.rear = (self.rear + 1) % self.maxSize
        self.queueArray[self.rear] = element
        self.nItems += 1
        return True

    # Method to remove and return the front element of the queue
    def remove(self):
        # Check if the queue is empty
        if self.isEmpty():
            raise IllegalStateException("Main is empty, cannot remove element")
        # Retrieve the front element and update the front index
        removedElement = self.queueArray[self.front]
        self.queueArray[self.front] = None # Clear the reference
        self.front = (self.front + 1) % self.maxSize
        self.nItems -= 1
        return removedElement

    # Method to peek at the front element without removing it
    def peekFront(self):
        # Check if the queue is empty
        if self.isEmpty():
            raise IllegalStateException("Main is empty, cannot peek front")
        return self.queueArray[self.front]

    # Method to peek at the rear element without removing it
    def peekRear(self):
        # Check if the queue is empty
        if self.isEmpty():
            raise IllegalStateException("Main is empty, cannot peek rear")
        return self.queueArray[self.rear]

    # Method to check if the queue is empty
    def isEmpty(self):
        return self.nItems == 0

    # Method to check if the queue is full
    def isFull(self):
        return self.nItems == self.maxSize

    # Method to get the current size of the queue
    def getSize(self):
        return self.nItems

    # Method to return a string representation of the queue
    def __str__(self):
        if self.isEmpty():
            return "[]" # Return empty representation if queue is empty
        sb = ""
        sb += "["
        # Iterate through the queue elements in order
        for i in range(self.nItems):
            index = (self.front + i) % self.maxSize # Calculate index in a circular manner
            sb += str(self.queueArray[index]) + ", "
        sb = sb[:-2] # Remove the last comma and space
        sb += "]"
        return sb

    # Main method to execute the queue operations based on user input
    def main(self):
        scanner = sys.stdin
        # Read the size of the queue from user input
        size = int(scanner.readline().strip())
        queue = Main(size) # Create a queue with specified size

        # Process user commands until "exit" is entered
        while True:
            command = scanner.readline().strip()
            if command == "exit":
                break # Exit the loop if the command is "exit"
            try:
                parts = command.split(" ")
                # Handle different commands for queue operations
                if parts[0] == "insert":
                    if len(parts) < 2:
                        raise ValueError("Missing value for insert")
                    value = int(parts[1])
                    if queue.insert(value):
                        print("Inserted: " + str(value))
                    else:
                        print("Main is full")
                elif parts[0] == "remove":
                    print("Removed: " + str(queue.remove()))
                elif parts[0] == "peekFront":
                    print("Front: " + str(queue.peekFront()))
                elif parts[0] == "peekRear":
                    print("Rear: " + str(queue.peekRear()))
                elif parts[0] == "getSize":
                    print("Size: " + str(queue.getSize()))
                elif parts[0] == "isEmpty":
                    print("Is empty: " + str(queue.isEmpty()))
                elif parts[0] == "print":
                    print("Main: " + str(queue))
                else:
                    raise ValueError("Unknown command: " + parts[0])
            except Exception as e:
                print("Error: " + str(e))
        scanner.close() # Close the scanner resource

if __name__ == "__main__":
    Main().main()

