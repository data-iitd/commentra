
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Main:
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
    queue = Main()

    while True:
        command = input("Enter commands (enqueue <value>, dequeue, peekFront, peekRear, size, isEmpty, print, exit):")
        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0].lower() == "enqueue":
                if len(parts) < 2:
                    print("Error: Missing value for enqueue")
                    continue
                value = int(parts[1])
                queue.enqueue(value)
                print("Enqueued: " + str(value))
            elif parts[0].lower() == "dequeue":
                print("Dequeued: " + str(queue.dequeue()))
            elif parts[0].lower() == "peekfront":
                print("Front element: " + str(queue.peekFront()))
            elif parts[0].lower() == "peekrear":
                print("Rear element: " + str(queue.peekRear()))
            elif parts[0].lower() == "size":
                print("Size: " + str(queue.size()))
            elif parts[0].lower() == "isempty":
                print("Is empty: " + str(queue.isEmpty()))
            elif parts[0].lower() == "print":
                print(queue)
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + str(e))

if __name__ == "__main__":
    main()

