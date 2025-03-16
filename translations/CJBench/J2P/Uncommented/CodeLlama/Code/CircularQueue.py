
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
    def main(self):
        scanner = Scanner(System.in)
        print("Enter the size of the Main:")
        queueSize = scanner.nextInt()
        scanner.nextLine()
        queue = Main(queueSize)
        print("Enter commands (enQueue <value>, deQueue, peek, isEmpty, isFull, size, exit):")
        while scanner.hasNextLine():
            command = scanner.nextLine().trim()
            if command.equalsIgnoreCase("exit"):
                break
            try:
                parts = command.split(" ")
                match parts[0]:
                    case "enQueue":
                        if len(parts) < 2:
                            print("Error: Missing value for enQueue")
                            break
                        value = int(parts[1])
                        queue.enQueue(value)
                        print("Enqueued: " + str(value))
                        break
                    case "deQueue":
                        print("Dequeued: " + str(queue.deQueue()))
                        break
                    case "peek":
                        print("Front of queue: " + str(queue.peek()))
                        break
                    case "isEmpty":
                        print("Is empty: " + str(queue.isEmpty()))
                        break
                    case "isFull":
                        print("Is full: " + str(queue.isFull()))
                        break
                    case "size":
                        print("Current size: " + str(queue.size()))
                        break
                    default:
                        print("Unknown command: " + parts[0])
            except Exception as e:
                print("Error: " + str(e.getMessage()))
        scanner.close()
    if __name__ == "__main__":
        Main().main()
        print("