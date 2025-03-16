import sys

class Main:
    def __init__(self, capacity):
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.maxSize = capacity
        self.queueArray = [None] * capacity
        self.front = 0
        self.rear = -1
        self.nItems = 0

    def insert(self, element):
        if self.isFull():
            return False
        self.rear = (self.rear + 1) % self.maxSize
        self.queueArray[self.rear] = element
        self.nItems += 1
        return True

    def remove(self):
        if self.isEmpty():
            raise ValueError("Main is empty, cannot remove element")
        removedElement = self.queueArray[self.front]
        self.queueArray[self.front] = None
        self.front = (self.front + 1) % self.maxSize
        self.nItems -= 1
        return removedElement

    def peekFront(self):
        if self.isEmpty():
            raise ValueError("Main is empty, cannot peek front")
        return self.queueArray[self.front]

    def peekRear(self):
        if self.isEmpty():
            raise ValueError("Main is empty, cannot peek rear")
        return self.queueArray[self.rear]

    def isEmpty(self):
        return self.nItems == 0

    def isFull(self):
        return self.nItems == self.maxSize

    def getSize(self):
        return self.nItems

    def __str__(self):
        if self.isEmpty():
            return "[]"
        result = "["
        for i in range(self.nItems):
            index = (self.front + i) % self.maxSize
            result += str(self.queueArray[index]) + ", "
        result = result[:-2] + "]"
        return result

def main():
    scanner = sys.stdin
    print("Enter the size of the queue: ", end="")
    size = int(scanner.readline().strip())
    queue = Main(size)
    print("Enter commands (insert <value>, remove, peekFront, peekRear, getSize, isEmpty, print, exit):")
    while True:
        command = scanner.readline().strip()
        if command == "exit":
            break
        try:
            parts = command.split()
            if parts[0] == "insert":
                if len(parts) < 2:
                    raise ValueError("Missing value for insert")
                value = int(parts[1])
                if queue.insert(value):
                    print("Inserted:", value)
                else:
                    print("Main is full")
            elif parts[0] == "remove":
                print("Removed:", queue.remove())
            elif parts[0] == "peekFront":
                print("Front:", queue.peekFront())
            elif parts[0] == "peekRear":
                print("Rear:", queue.peekRear())
            elif parts[0] == "getSize":
                print("Size:", queue.getSize())
            elif parts[0] == "isEmpty":
                print("Is empty:", queue.isEmpty())
            elif parts[0] == "print":
                print("Main:", queue)
            else:
                raise ValueError("Unknown command: " + parts[0])
        except ValueError as e:
            print("Error:", e)

if __name__ == "__main__":
    main()

