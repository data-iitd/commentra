
import sys

class Main:
    def __init__(self, capacity=10):
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.maxSize = capacity
        self.queueArray = [None] * capacity
        self.front = 0
        self.rear = -1
        self.nItems = 0

    def insert(self, value):
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.maxSize
        self.queueArray[self.rear] = value
        self.nItems += 1
        return True

    def remove(self):
        if self.isEmpty():
            return None
        value = self.queueArray[self.front]
        self.front = (self.front + 1) % self.maxSize
        self.nItems -= 1
        return value

    def peekFront(self):
        if self.isEmpty():
            return None
        return self.queueArray[self.front]

    def peekRear(self):
        if self.isEmpty():
            return None
        return self.queueArray[self.rear]

    def isEmpty(self):
        return self.nItems == 0

    def isFull(self):
        return self.nItems == self.maxSize

    def getSize(self):
        return self.nItems

    def print(self):
        if self.isEmpty():
            print("Main is empty")
            return
        print("Main:", end=" ")
        for i in range(self.front, self.rear + 1):
            print(self.queueArray[i], end=" ")
        print()



if __name__ == "__main__":
    size = int(input("Enter the size of the queue: "))
    queue = Main(size)

    while True:
        command = input("Enter a command (insert, remove, peekFront, peekRear, getSize, isEmpty, isFull, print, or exit): ")
        if command.lower() == "exit":
            break

        parts = command.split()

        if parts[0].lower() == "insert":
            if len(parts) < 2:
                print("Error: Missing value for insert")
                continue
            value = int(parts[1])
            if queue.insert(value):
                print("Inserted:", value)
            else:
                print("Main is full")
        # ... (other cases for "remove", "peekFront", "peekRear", "getSize", "isEmpty", and "print")

    print("