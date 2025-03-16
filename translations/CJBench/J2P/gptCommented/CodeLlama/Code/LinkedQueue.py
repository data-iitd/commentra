
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def isEmpty(self):
        return self.size == 0

    def enqueue(self, data):
        if data is None:
            raise ValueError("Cannot enqueue null data")
        newNode = Node(data)
        if self.isEmpty():
            self.front = newNode
        else:
            self.rear.next = newNode
        self.rear = newNode
        self.size += 1

    def dequeue(self):
        if self.isEmpty():
            raise ValueError("Queue is empty")
        retValue = self.front.data
        self.front = self.front.next
        self.size -= 1
        if self.isEmpty():
            self.rear = None
        return retValue

    def peekFront(self):
        if self.isEmpty():
            raise ValueError("Queue is empty")
        return self.front.data

    def peekRear(self):
        if self.isEmpty():
            raise ValueError("Queue is empty")
        return self.rear.data

    def size(self):
        return self.size

    def clear(self):
        self.front = None
        self.rear = None
        self.size = 0

    def __str__(self):
        if self.isEmpty():
            return "[]"
        sb = "["
        current = self.front
        while current is not None:
            sb += str(current.data)
            if current.next is not None:
                sb += ", "
            current = current.next
        sb += "]"
        return sb

def main():
    queue = Queue()
    while True:
        command = input("Enter command: ").strip()
        if command == "exit":
            break
        parts = command.split(" ")
        try:
            if parts[0] == "enqueue":
                if len(parts) < 2:
                    raise ValueError("Missing value for enqueue")
                value = int(parts[1])
                queue.enqueue(value)
                print("Enqueued:", value)
            elif parts[0] == "dequeue":
                print("Dequeued:", queue.dequeue())
            elif parts[0] == "peekFront":
                print("Front element:", queue.peekFront())
            elif parts[0] == "peekRear":
                print("Rear element:", queue.peekRear())
            elif parts[0] == "size":
                print("Size:", queue.size())
            elif parts[0] == "isEmpty":
                print("Is empty:", queue.isEmpty())
            elif parts[0] == "print":
                print(queue)
            else:
                raise ValueError("Unknown command: " + parts[0])
        except ValueError as e:
            print("Error:", e)

if __name__ == "__main__":
    main()

