
import sys

class Main:
    # Declare instance variables
    array = None
    topOfQueue = None
    beginningOfQueue = None
    size = None
    currentSize = None

    # Constructor initializes array, sets initial values for topOfQueue, beginningOfQueue, size, and currentSize
    def __init__(self, size):
        if size < 1:
            raise Exception("Size must be greater than 0")
        self.array = [None] * size
        self.topOfQueue = -1
        self.beginningOfQueue = -1
        self.size = size
        self.currentSize = 0

    # Checks if queue is empty
    def isEmpty(self):
        return self.currentSize == 0

    # Checks if queue is full
    def isFull(self):
        return self.currentSize == self.size

    # Enqueues a value into the queue
    def enQueue(self, value):
        if self.isFull():
            raise Exception("Queue is full")
        if self.isEmpty():
            self.beginningOfQueue = 0
        self.topOfQueue = (self.topOfQueue + 1) % self.size
        self.array[self.topOfQueue] = value
        self.currentSize += 1

    # Dequeues a value from the queue
    def deQueue(self):
        if self.isEmpty():
            raise Exception("Queue is empty")
        removedValue = self.array[self.beginningOfQueue]
        self.array[self.beginningOfQueue] = None
        self.beginningOfQueue = (self.beginningOfQueue + 1) % self.size
        self.currentSize -= 1
        if self.isEmpty():
            self.beginningOfQueue = -1
            self.topOfQueue = -1
        return removedValue

    # Returns the value at the front of the queue
    def peek(self):
        if self.isEmpty():
            raise Exception("Queue is empty")
        return self.array[self.beginningOfQueue]

    # Frees up memory used by the queue
    def deleteQueue(self):
        self.array = None
        self.beginningOfQueue = -1
        self.topOfQueue = -1
        self.currentSize = 0

    # Returns the current size of the queue
    def size(self):
        return self.currentSize

    # Main method reads user input and processes commands
    def main(self):
        queueSize = int(sys.stdin.readline().strip())

        # Create a new queue of the given size
        queue = Main(queueSize)

        while True:
            command = sys.stdin.readline().strip()

            if command.lower() == "exit":
                break

            parts = command.split(" ")

            # Process command based on its first word
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

        return

# 