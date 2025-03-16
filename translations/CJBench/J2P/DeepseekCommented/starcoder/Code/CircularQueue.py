import sys

class Main:
    # Array to hold the queue elements
    array = []
    # Index of the top of the queue
    topOfQueue = -1
    # Index of the beginning of the queue
    beginningOfQueue = -1
    # Size of the queue
    size = 0
    # Current number of elements in the queue
    currentSize = 0
    
    # Constructor to initialize the queue with a given size
    def __init__(self, size):
        # Check if the size is valid
        if size < 1:
            raise Exception("Size must be greater than 0")
        # Initialize the array with the given size
        self.array = [None] * size
        # Initialize indices and sizes
        self.topOfQueue = -1
        self.beginningOfQueue = -1
        self.size = size
        self.currentSize = 0
    
    # Check if the queue is empty
    def isEmpty(self):
        return self.currentSize == 0
    
    # Check if the queue is full
    def isFull(self):
        return self.currentSize == self.size
    
    # Add an element to the queue
    def enQueue(self, value):
        if self.isFull():
            raise Exception("Queue is full")
        # Set beginning of queue if it's the first element
        if self.isEmpty():
            self.beginningOfQueue = 0
        # Update the top of the queue and add the value
        self.topOfQueue = (self.topOfQueue + 1) % self.size
        self.array[self.topOfQueue] = value
        self.currentSize += 1
    
    # Remove and return the front element from the queue
    def deQueue(self):
        if self.isEmpty():
            raise Exception("Queue is empty")
        # Get the value to be removed
        removedValue = self.array[self.beginningOfQueue]
        # Clear the position and update the beginning of the queue
        self.array[self.beginningOfQueue] = None
        self.beginningOfQueue = (self.beginningOfQueue + 1) % self.size
        self.currentSize -= 1
        # If the queue is empty, reset the beginning and top indices
        if self.isEmpty():
            self.beginningOfQueue = -1
            self.topOfQueue = -1
        return removedValue
    
    # Return the front element without removing it
    def peek(self):
        if self.isEmpty():
            raise Exception("Queue is empty")
        return self.array[self.beginningOfQueue]
    
    # Delete the queue
    def deleteQueue(self):
        self.array = None
        self.beginningOfQueue = -1
        self.topOfQueue = -1
        self.currentSize = 0
    
    # Return the current size of the queue
    def size(self):
        return self.currentSize
    
    # Main method to interact with the queue via command line
    def main(self):
        queueSize = int(sys.stdin.readline().strip())
        queue = Main(queueSize)
        while True:
            command = sys.stdin.readline().strip()
            if command.lower() == "exit":
                break
            parts = command.split(" ")
            try:
                if parts[0] == "enQueue":
                    if len(parts) < 2:
                        print("Error: Missing value for enQueue")
                        continue
                    value = int(parts[1])
                    queue.enQueue(value)
                    print("Enqueued: " + str(value))
                elif parts[0] == "deQueue":
                    print("Dequeued: " + str(queue.deQueue()))
                elif parts[0] == "peek":
                    print("Front of queue: " + str(queue.peek()))
                elif parts[0] == "isEmpty":
                    print("Is empty: " + str(queue.isEmpty()))
                elif parts[0] == "isFull":
                    print("Is full: " + str(queue.isFull()))
                elif parts[0] == "size":
                    print("Current size: " + str(queue.size()))
                else:
                    print("Unknown command: " + parts[0])
            except Exception as e:
                print("Error: " + str(e))
        return

# Start the program
if __name__ == "__main__":
    Main().main()
