import sys

class Main:
    def __init__(self, size):
        self.maxSize = size + 1
        self.queueArray = [0] * self.maxSize
        self.nItems = 0

    def swim(self, pos):
        while pos > 1 and self.queueArray[pos // 2] < self.queueArray[pos]:
            self.queueArray[pos], self.queueArray[pos // 2] = self.queueArray[pos // 2], self.queueArray[pos]
            pos = pos // 2

    def sink(self, pos):
        while 2 * pos <= self.nItems:
            current = 2 * pos
            if current < self.nItems and self.queueArray[current] < self.queueArray[current + 1]:
                current += 1
            if self.queueArray[pos] >= self.queueArray[current]:
                break
            self.queueArray[pos], self.queueArray[current] = self.queueArray[current], self.queueArray[pos]
            pos = current

    def insert(self, value):
        if self.isFull():
            raise RuntimeError("Queue is full")
        else:
            self.queueArray[self.nItems + 1] = value
            self.nItems += 1
            self.swim(self.nItems)

    def remove(self):
        if self.isEmpty():
            raise RuntimeError("Queue is Empty")
        else:
            max = self.queueArray[1]
            self.queueArray[1], self.queueArray[self.nItems] = self.queueArray[self.nItems], self.queueArray[1]
            self.queueArray[self.nItems] = 0
            self.nItems -= 1
            self.sink(1)
            return max

    def peek(self):
        if self.isEmpty():
            raise RuntimeError("Queue is Empty")
        return self.queueArray[1]

    def isEmpty(self):
        return self.nItems == 0

    def isFull(self):
        return self.nItems == self.maxSize - 1

    def getSize(self):
        return self.nItems


if __name__ == "__main__":
    size = int(input())
    pq = Main(size)
    while True:
        command = input().strip()
        if command == "exit":
            break
        try:
            parts = command.split()
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                pq.insert(value)
                print("Inserted:", value)
            elif parts[0] == "remove":
                print("Removed:", pq.remove())
            elif parts[0] == "peek":
                print("Peek:", pq.peek())
            elif parts[0] == "getSize":
                print("Size:", pq.getSize())
            elif parts[0] == "isEmpty":
                print("Is empty:", pq.isEmpty())
            else:
                print("Error: Invalid command")
        except Exception as e:
            print("Error:", e)


