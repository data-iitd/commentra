import sys

class Main:
    # Array to hold the elements of the queue
    array = None
    # Index of the top element in the queue
    topOfQueue = -1
    # Index of the beginning element in the queue
    beginningOfQueue = -1
    # Maximum size of the queue
    size = 0
    # Current number of elements in the queue
    currentSize = 0

    # Constructor to initialize the queue with a specified size
    def __init__(self, size):
        # Validate that the size is greater than 0
        if size < 1:
            raise Exception("Size must be greater than 0")
        # Initialize the array and other variables
        self.array = [None] * size
        self.topOfQueue = -1
        self.beginningOfQueue = -1
        self.size = size
        self.currentSize = 0

    # Method to check if the queue is empty
    def isEmpty(self):
        return self.currentSize == 0

    # Method to check if the queue is full
    def isFull(self):
        return self.currentSize == self.size

    # Method to add an element to the queue
    def enQueue(self, value):
        # Check if the queue is full before adding an element
        if self.isFull():
            raise Exception("Queue is full")
        # If the queue is empty, set the beginning index
        if self.isEmpty():
            self.beginningOfQueue = 0
        # Update the top index in a circular manner and add the new value
        self.topOfQueue = (self.topOfQueue + 1) % self.size
        self.array[self.topOfQueue] = value
        self.currentSize += 1

    # Method to remove and return the front element of the queue
    def deQueue(self):
        # Check if the queue is empty before removing an element
        if self.isEmpty():
            raise Exception("Queue is empty")
        # Store the value to be removed
        removedValue = self.array[self.beginningOfQueue]
        # Clear the position in the array
        self.array[self.beginningOfQueue] = None
        # Update the beginning index in a circular manner
        self.beginningOfQueue = (self.beginningOfQueue + 1) % self.size
        self.currentSize -= 1
        # Reset indices if the queue is empty after removal
        if self.isEmpty():
            self.beginningOfQueue = -1
            self.topOfQueue = -1
        return removedValue

    # Method to view the front element of the queue without removing it
    def peek(self):
        # Check if the queue is empty before peeking
        if self.isEmpty():
            raise Exception("Queue is empty")
        return self.array[self.beginningOfQueue]

    # Method to delete the queue and free resources
    def deleteQueue(self):
        self.array = None # Clear the array reference
        self.beginningOfQueue = -1 # Reset beginning index
        self.topOfQueue = -1 # Reset top index
        self.currentSize = 0 # Reset current size

    # Method to get the current size of the queue
    def size(self):
        return self.currentSize

    # Main method to execute the program
    def main(self):
        # Read the size of the queue from user input
        queueSize = int(input())
        # Create a new queue instance
        queue = Main(queueSize)
        
        # Loop to process user commands until "exit" is entered
        while True:
            command = input().strip()
            if command.lower() == "exit":
                break # Exit the loop if the command is "exit"
            try:
                # Split the command into parts for processing
                parts = command.split(" ")
                if parts[0].lower() == "enQueue":
                    # Check for missing value in the command
                    if len(parts) < 2:
                        print("Error: Missing value for enQueue")
                        break
                    # Parse the value and enqueue it
                    value = int(parts[1])
                    queue.enQueue(value)
                    print("Enqueued: " + str(value))
                elif parts[0].lower() == "deQueue":
                    # Dequeue an element and print it
                    print("Dequeued: " + str(queue.deQueue()))
                elif parts[0].lower() == "peek":
                    # Peek at the front element of the queue
                    print("Front of queue: " + str(queue.peek()))
                elif parts[0].lower() == "isEmpty":
                    # Check if the queue is empty and print the result
                    print("Is empty: " + str(queue.isEmpty()))
                elif parts[0].lower() == "isFull":
                    # Check if the queue is full and print the result
                    print("Is full: " + str(queue.isFull()))
                elif parts[0].lower() == "size":
                    # Print the current size of the queue
                    print("Current size: " + str(queue.size()))
                else:
                    # Handle unknown commands
                    print("Unknown command: " + parts[0])
            except Exception as e:
                # Handle any exceptions that occur during command processing
                print("Error: " + str(e))

# Create a new instance of the Main class
main = Main()
# Start executing the program
main.main()
