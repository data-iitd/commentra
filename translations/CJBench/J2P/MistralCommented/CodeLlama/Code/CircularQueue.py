
class Main:
    # Declare instance variables
    array = []
    topOfQueue = -1
    beginningOfQueue = -1
    size = 0
    currentSize = 0

    # Constructor initializes array, sets initial values for topOfQueue, beginningOfQueue, size, and currentSize
    def __init__(self, size):
        if size < 1:
            raise ValueError("Size must be greater than 0")
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
            raise IllegalStateException("Queue is full")
        if self.isEmpty():
            self.beginningOfQueue = 0
        self.topOfQueue = (self.topOfQueue + 1) % self.size
        self.array[self.topOfQueue] = value
        self.currentSize += 1

    # Dequeues a value from the queue
    def deQueue(self):
        if self.isEmpty():
            raise IllegalStateException("Queue is empty")
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
            raise IllegalStateException("Queue is empty")
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
        queueSize = int(input("Enter queue size: "))

        # Create a new queue of the given size
        queue = Main(queueSize)

        while True:
            command = input("Enter command (enQueue, deQueue, peek, isEmpty, isFull, size, exit): ").strip()

            if command.lower() == "exit":
                break

            try:
                parts = command.split(" ")

                # Process command based on its first word
                if parts[0].lower() == "enqueue":
                    if len(parts) < 2:
                        print("Error: Missing value for enQueue")
                        continue
                    value = int(parts[1])
                    queue.enQueue(value)
                    print("Enqueued: " + str(value))
                elif parts[0].lower() == "dequeue":
                    print("Dequeued: " + str(queue.deQueue()))
                elif parts[0].lower() == "peek":
                    print("Front of queue: " + str(queue.peek()))
                elif parts[0].lower() == "isempty":
                    print("Is empty: " + str(queue.isEmpty()))
                elif parts[0].lower() == "isfull":
                    print("Is full: " + str(queue.isFull()))
                elif parts[0].lower() == "size":
                    print("Current size: " + str(queue.size()))
                else:
                    print("Unknown command: " + parts[0])
            except Exception as e:
                print("Error: " + str(e))

        print("Exiting...")

    # Run the main method
    if __name__ == "__main__":
        main()

