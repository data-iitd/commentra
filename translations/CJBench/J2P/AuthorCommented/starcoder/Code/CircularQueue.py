
import sys

class Main:
    def __init__(self, size):
        if size < 1:
            raise ValueError("Size must be greater than 0")
        self.array = [None] * size
        self.topOfQueue = -1
        self.beginningOfQueue = -1
        self.size = size
        self.currentSize = 0

    def isEmpty(self):
        return self.currentSize == 0

    def isFull(self):
        return self.currentSize == self.size

    def enQueue(self, value):
        if self.isFull():
            raise ValueError("Queue is full")
        if self.isEmpty():
            self.beginningOfQueue = 0
        self.topOfQueue = (self.topOfQueue + 1) % self.size
        self.array[self.topOfQueue] = value
        self.currentSize += 1

    def deQueue(self):
        if self.isEmpty():
            raise ValueError("Queue is empty")
        removedValue = self.array[self.beginningOfQueue]
        self.array[self.beginningOfQueue] = None
        self.beginningOfQueue = (self.beginningOfQueue + 1) % self.size
        self.currentSize -= 1
        if self.isEmpty():
            self.beginningOfQueue = -1
            self.topOfQueue = -1
        return removedValue

    def peek(self):
        if self.isEmpty():
            raise ValueError("Queue is empty")
        return self.array[self.beginningOfQueue]

    def deleteQueue(self):
        self.array = None
        self.beginningOfQueue = -1
        self.topOfQueue = -1
        self.currentSize = 0

    def size(self):
        return self.currentSize

if __name__ == "__main__":
    queue = Main(int(sys.stdin.readline().strip()))
    while True:
        command = sys.stdin.readline().strip()
        if command.lower() == "exit":
            break
        parts = command.split(" ")
        if parts[0].lower() == "enQueue":
            if len(parts) < 2:
                print("Error: Missing value for enQueue")
                continue
            queue.enQueue(int(parts[1]))
        elif parts[0].lower() == "deQueue":
            print("Dequeued: " + str(queue.deQueue()))
        elif parts[0].lower() == "peek":
            print("Front of queue: " + str(queue.peek()))
        elif parts[0].lower() == "isEmpty":
            print("Is empty: " + str(queue.isEmpty()))
        elif parts[0].lower() == "isFull":
            print("Is full: " + str(queue.isFull()))
        elif parts[0].lower() == "size":
            print("Current size: " + str(queue.size()))
        else:
            print("Unknown command: " + parts[0])

