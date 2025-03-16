
import sys

class Main:
    def __init__(self, size):
        if size <= 0:
            raise ValueError("Buffer size must be positive")
        self.buffer = [None] * size
        self.putPointer = CircularPointer(0, size)
        self.getPointer = CircularPointer(0, size)
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def isFull(self):
        return self.size == len(self.buffer)

    def get(self):
        if self.isEmpty():
            return None
        item = self.buffer[self.getPointer.getAndIncrement()]
        self.size -= 1
        return item

    def put(self, item):
        if item is None:
            raise ValueError("Null items are not allowed")
        if self.isFull():
            self.getPointer.getAndIncrement() # Overwrite the oldest item
        else:
            self.size += 1
        self.buffer[self.putPointer.getAndIncrement()] = item
        return True

    class CircularPointer:
        def __init__(self, pointer, max):
            self.pointer = pointer
            self.max = max

        def getAndIncrement(self):
            tmp = self.pointer
            self.pointer = (self.pointer + 1) % self.max
            return tmp

if __name__ == "__main__":
    buffer = Main(int(sys.stdin.readline()))
    for line in sys.stdin:
        operation, *args = line.split()
        if operation == "PUT":
            buffer.put(args[0])
        elif operation == "GET":
            print(buffer.get())
        elif operation == "ISEMPTY":
            print(buffer.isEmpty())
        elif operation == "ISFULL":
            print(buffer.isFull())

