class Queue:
    def __init__(self, size):
        if size < 1:
            raise ValueError("Size must be greater than 0")
        self.array = [None] * size
        self.top_of_queue = -1
        self.beginning_of_queue = -1
        self.size = size
        self.current_size = 0

    def is_empty(self):
        return self.current_size == 0

    def is_full(self):
        return self.current_size == self.size

    def enqueue(self, value):
        if self.is_full():
            raise ValueError("Queue is full")
        if self.is_empty():
            self.beginning_of_queue = 0
        self.top_of_queue = (self.top_of_queue + 1) % self.size
        self.array[self.top_of_queue] = value
        self.current_size += 1

    def dequeue(self):
        if self.is_empty():
            raise ValueError("Queue is empty")
        removed_value = self.array[self.beginning_of_queue]
        self.array[self.beginning_of_queue] = None
        self.beginning_of_queue = (self.beginning_of_queue + 1) % self.size
        self.current_size -= 1
        if self.is_empty():
            self.beginning_of_queue = -1
            self.top_of_queue = -1
        return removed_value

    def peek(self):
        if self.is_empty():
            raise ValueError("Queue is empty")
        return self.array[self.beginning_of_queue]

    def delete_queue(self):
        self.array = [None] * self.size
        self.beginning_of_queue = -1
        self.top_of_queue = -1
        self.current_size = 0

    def get_size(self):
        return self.current_size

    def main(self):
        import sys
        for line in sys.stdin:
            command = line.strip().lower()
            if command == "exit":
                break
            parts = command.split()
            try:
                if parts[0] == "enQueue":
                    if len(parts) < 2:
                        print("Error: Missing value for enQueue")
                        continue
                    value = int(parts[1])
                    self.enqueue(value)
                    print(f"Enqueued: {value}")
                elif parts[0] == "deQueue":
                    print(f"Dequeued: {self.dequeue()}")
                elif parts[0] == "peek":
                    print(f"Front of queue: {self.peek()}")
                elif parts[0] == "isEmpty":
                    print(f"Is empty: {self.is_empty()}")
                elif parts[0] == "isFull":
                    print(f"Is full: {self.is_full()}")
                elif parts[0] == "size":
                    print(f"Current size: {self.get_size()}")
                else:
                    print(f"Unknown command: {parts[0]}")
            except Exception as e:
                print(f"Error: {e}")

queue = Queue(int(input().strip()))
queue.main()
