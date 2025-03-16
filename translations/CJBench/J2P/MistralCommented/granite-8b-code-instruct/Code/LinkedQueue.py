

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def enqueue(self, data):
        if data is None:
            raise ValueError("Cannot enqueue null data")

        node = Node(data)

        if self.is_empty():
            self.front = node
        else:
            self.rear.next = node

        self.rear = node
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")

        data = self.front.data
        self.front = self.front.next
        self.size -= 1

        if self.is_empty():
            self.rear = None

        return data

    def peek_front(self):
        if self.is_empty():
            raise IndexError("Queue is empty")

        return self.front.data

    def peek_rear(self):
        if self.is_empty():
            raise IndexError("Queue is empty")

        return self.rear.data

    def __str__(self):
        if self.is_empty():
            return "[]"

        result = "["
        current = self.front

        while current is not None:
            result += str(current.data)
            if current.next is not None:
                result += ", "
            current = current.next

        result += "]"
        return result

# Main method for testing the queue implementation
if __name__ == "__main__":
    import sys

    queue = Queue()

    for line in sys.stdin:
        line = line.strip()

        if line.lower() == "exit":
            break

        parts = line.split()

        if len(parts) == 0:
            continue

        command = parts[0]

        if command == "enqueue":
            if len(parts) < 2:
                print("Error: Missing value for enqueue")
                continue

            value = int(parts[1])
            queue.enqueue(value)
            print(f"Enqueued: {value}")
        elif command == "dequeue":
            try:
                value = queue.dequeue()
                print(f"Dequeued: {value}")
            except IndexError as e:
                print(f"Error: {e}")
        elif command == "peekFront":
            try:
                value = queue.peek_front()
                print(f"Front element: {value}")
            except IndexError as e:
                print(f"Error: {e}")
        elif command == "peekRear":
            try:
                value = queue.peek_rear()
                print(f"Rear element: {value}")
            except IndexError as e:
                print(f"Error: {e}")
        elif command == "size":
            print(f"Size: {queue.size}")
        elif command == "isEmpty":
            print(f"Is empty: {queue.is_empty()}")
        elif command == "print":
            print(queue)
        else:
            print(f"Unknown command: {command}")

