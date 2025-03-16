
class CircularPointer:
    def __init__(self, pointer, max):
        self.pointer = pointer
        self.max = max

    def getAndIncrement(self):
        tmp = self.pointer
        self.pointer = (self.pointer + 1) % self.max
        return tmp

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
            self.getPointer.getAndIncrement()
        else:
            self.size += 1
        self.buffer[self.putPointer.getAndIncrement()] = item
        return True

if __name__ == "__main__":
    import sys
    scanner = iter(sys.stdin.read().splitlines())
    bufferSize = int(next(scanner))
    numberOfOperations = int(next(scanner))
    buffer = Main(bufferSize)
    for i in range(numberOfOperations):
        operation = next(scanner)
        if operation == "PUT":
            element = next(scanner)
            buffer.put(element)
            print("Added: " + element)
        elif operation == "GET":
            result = buffer.get()
            print("Retrieved: " + (result if result is not None else "null"))
        elif operation == "ISEMPTY":
            print("Is Empty: " + str(buffer.isEmpty()))
        elif operation == "ISFULL":
            print("Is Full: " + str(buffer.isFull()))
    