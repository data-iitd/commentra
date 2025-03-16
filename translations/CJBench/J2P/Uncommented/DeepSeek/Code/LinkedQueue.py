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
            raise ValueError("Cannot enqueue None data")
        new_node = Node(data)
        if self.is_empty():
            self.front = new_node
        else:
            self.rear.next = new_node
        self.rear = new_node
        self.size += 1

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        ret_value = self.front.data
        self.front = self.front.next
        self.size -= 1
        if self.is_empty():
            self.rear = None
        return ret_value

    def peek_front(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        return self.front.data

    def peek_rear(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        return self.rear.data

    def get_size(self):
        return self.size

    def clear(self):
        self.front = None
        self.rear = None
        self.size = 0

    def __str__(self):
        if self.is_empty():
            return "[]"
        result = "["
        current = self.front
        while current:
            result += str(current.data)
            if current.next:
                result += ", "
            current = current.next
        result += "]"
        return result

def main():
    queue = Queue()
    print("Enter commands (enqueue <value>, dequeue, peekFront, peekRear, size, isEmpty, print, exit):")
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break
        parts = command.split()
        try:
            if parts[0].lower() == "enqueue":
                if len(parts) < 2:
                    print("Error: Missing value for enqueue")
                    continue
                value = int(parts[1])
                queue.enqueue(value)
                print(f"Enqueued: {value}")
            elif parts[0].lower() == "dequeue":
                print(f"Dequeued: {queue.dequeue()}")
            elif parts[0].lower() == "peekfront":
                print(f"Front element: {queue.peek_front()}")
            elif parts[0].lower() == "peekrear":
                print(f"Rear element: {queue.peek_rear()}")
            elif parts[0].lower() == "size":
                print(f"Size: {queue.get_size()}")
            elif parts[0].lower() == "isempty":
                print(f"Is empty: {queue.is_empty()}")
            elif parts[0].lower() == "print":
                print(queue)
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

if __name__ == "__main__":
    main()
