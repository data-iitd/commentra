class PriorityQueue:
    def __init__(self, size):
        self.maxSize = size + 1
        self.queueArray = [0] * (size + 1)
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
            raise Exception("Queue is full")
        else:
            self.nItems += 1
            self.queueArray[self.nItems] = value
            self.swim(self.nItems)

    def remove(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        else:
            max_val = self.queueArray[1]
            self.queueArray[1], self.queueArray[self.nItems] = self.queueArray[self.nItems], self.queueArray[1]
            self.queueArray[self.nItems] = 0
            self.nItems -= 1
            self.sink(1)
            return max_val

    def peek(self):
        if self.isEmpty():
            raise Exception("Queue is Empty")
        return self.queueArray[1]

    def isEmpty(self):
        return self.nItems == 0

    def isFull(self):
        return self.nItems == self.maxSize - 1

    def getSize(self):
        return self.nItems


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    size = int(data[0])
    pq = PriorityQueue(size)

    i = 1
    while i < len(data):
        command = data[i]
        i += 1
        if command == "exit":
            break

        try:
            if command == "insert":
                value = int(data[i])
                i += 1
                pq.insert(value)
                print(f"Inserted: {value}")
            elif command == "remove":
                print(f"Removed: {pq.remove()}")
            elif command == "peek":
                print(f"Peek: {pq.peek()}")
            elif command == "getSize":
                print(f"Size: {pq.getSize()}")
            elif command == "isEmpty":
                print(f"Is empty: {pq.isEmpty()}")
            else:
                print(f"Unknown command: {command}")
        except Exception as e:
            print(f"Error: {e}")


if __name__ == "__main__":
    main()
