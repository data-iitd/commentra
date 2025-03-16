class CircularBuffer:
    def __init__(self, size):
        if size <= 0:
            raise ValueError("Buffer size must be positive")
        self.buffer = [None] * size
        self.put_pointer = 0
        self.get_pointer = 0
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def is_full(self):
        return self.size == len(self.buffer)

    def get(self):
        if self.is_empty():
            return None
        item = self.buffer[self.get_pointer]
        self.get_pointer = (self.get_pointer + 1) % len(self.buffer)
        self.size -= 1
        return item

    def put(self, item):
        if item is None:
            raise ValueError("None items are not allowed")
        if self.is_full():
            self.get_pointer = (self.get_pointer + 1) % len(self.buffer)
        else:
            self.size += 1
        self.buffer[self.put_pointer] = item
        self.put_pointer = (self.put_pointer + 1) % len(self.buffer)
        return True


def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    buffer_size = int(data[0])
    number_of_operations = int(data[1])

    buffer = CircularBuffer(buffer_size)

    for i in range(2, len(data), 2):
        operation = data[i]
        if operation == "PUT":
            element = data[i + 1]
            buffer.put(element)
            print(f"Added: {element}")
        elif operation == "GET":
            result = buffer.get()
            print(f"Retrieved: {result if result is not None else 'null'}")
        elif operation == "ISEMPTY":
            print(f"Is Empty: {buffer.is_empty()}")
        elif operation == "ISFULL":
            print(f"Is Full: {buffer.is_full()}")


if __name__ == "__main__":
    main()
