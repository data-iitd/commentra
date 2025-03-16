import sys

class Queue:
    def __init__(self, size):
        self.size = size
        self.array = [None] * size
        self.topOfQueue = -1
        self.beginningOfQueue = -1
        self.currentSize = 0

    def isEmpty(self):
        return self.currentSize == 0

    def isFull(self):
        return self.currentSize == self.size

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

    def peek(self):
        if self.isEmpty():
            raise Exception("Queue is empty")
        return self.array[self.beginningOfQueue]

    def deleteQueue(self):
        self.array = None
        self.beginningOfQueue = -1
        self.topOfQueue = -1
        self.currentSize = 0

    def size(self):
        return self.currentSize

def main():
    queueSize = int(sys.stdin.readline())
    queue = Queue(queueSize)
    while True:
        command = sys.stdin.readline().strip()
        if command == "exit":
            break
        try:
            parts = command.split(" ")
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

if __name__ == "__main__":
    main()

