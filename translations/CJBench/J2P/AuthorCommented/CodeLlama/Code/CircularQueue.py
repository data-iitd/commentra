
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
            raise IllegalStateException("Queue is full")
        if self.isEmpty():
            self.beginningOfQueue = 0
        self.topOfQueue = (self.topOfQueue + 1) % self.size
        self.array[self.topOfQueue] = value
        self.currentSize += 1

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

    def peek(self):
        if self.isEmpty():
            raise IllegalStateException("Queue is empty")
        return self.array[self.beginningOfQueue]

    def deleteQueue(self):
        self.array = None
        self.beginningOfQueue = -1
        self.topOfQueue = -1
        self.currentSize = 0

    def size(self):
        return self.currentSize


if __name__ == "__main__":
    scanner = Scanner(System.in)
    print("Enter the size of the Main:")
    queueSize = scanner.nextInt()
    scanner.nextLine()  # Consume the newline

    queue = Main(queueSize)
    print("Enter commands (enQueue <value>, deQueue, peek, isEmpty, isFull, size, exit):")

    while scanner.hasNextLine():
        command = scanner.nextLine().strip()

        if command.lower() == "exit":
            break

        try:
            parts = command.split(" ")
            if len(parts) < 2:
                raise ValueError("Missing value for enQueue")
            if parts[0].lower() == "enqueue":
                value = int(parts[1])
                queue.enQueue(value)
                print("Enqueued:", value)
            elif parts[0].lower() == "dequeue":
                print("Dequeued:", queue.deQueue())
            elif parts[0].lower() == "peek":
                print("Front of queue:", queue.peek())
            elif parts[0].lower() == "isempty":
                print("Is empty:", queue.isEmpty())
            elif parts[0].lower() == "isfull":
                print("Is full:", queue.isFull())
            elif parts[0].lower() == "size":
                print("Current size:", queue.size())
            else:
                raise ValueError("Unknown command: " + parts[0])
        except Exception as e:
            print("Error:", e)

    scanner.close()

