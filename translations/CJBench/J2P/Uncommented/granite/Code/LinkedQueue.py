

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

if __name__ == "__main__":
    queue = Queue()
    print("Enter commands (enqueue <value>, dequeue, peekFront, peekRear, size, isEmpty, print, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        try:
            parts = command.split(" ")
            if parts[0].lower() == "enqueue":
                if len(parts) < 2:
                    print("Error: Missing value for enqueue")
                    continue
                value = int(parts[1])
                queue.enqueue(value)
                print("Enqueued:", value)
            elif parts[0].lower() == "dequeue":
                print("Dequeued:", queue.dequeue())
            elif parts[0].lower() == "peekfront":
                print("Front element:", queue.peek_front())
            elif parts[0].lower() == "peekrear":
                print("Rear element:", queue.peek_rear())
            elif parts[0].lower() == "size":
                print("Size:", queue.size)
            elif parts[0].lower() == "isempty":
                print("Is empty:", queue.is_empty())
            elif parts[0].lower() == "print":
                print(queue)
            else:
                print("Unknown command:", parts[0])
        except Exception as e:
            print("Error:", e)

