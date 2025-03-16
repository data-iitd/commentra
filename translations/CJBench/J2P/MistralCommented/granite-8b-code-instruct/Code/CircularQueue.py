

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

    def en_queue(self, value):
        if self.is_full():
            raise RuntimeError("Queue is full")
        if self.is_empty():
            self.beginning_of_queue = 0
        self.top_of_queue = (self.top_of_queue + 1) % self.size
        self.array[self.top_of_queue] = value
        self.current_size += 1

    def de_queue(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        removed_value = self.array[self.beginning_of_queue]
        self.array[self.beginning_of_queue] = None
        self.beginning_of_queue = (self.beginning_of_queue + 1) % self.size
        self.current_size -= 1
        if self.is_empty():
            self.beginning_of_queue = -1
            self.top_of_queue = -1

    def peek(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        return self.array[self.beginning_of_queue]

    def delete_queue(self):
        self.array = None
        self.beginning_of_queue = -1
        self.top_of_queue = -1
        self.current_size = 0

    def size(self):
        return self.current_size

if __name__ == "__main__":
    import sys

    queue_size = int(input())

    # Create a new queue of the given size
    queue = Queue(queue_size)

    for line in sys.stdin:
        command = line.strip()

        if command.lower() == "exit":
            break

        parts = command.split()

        # Process command based on its first word
        if len(parts) == 0:
            continue

        if parts[0].lower() == "enqueue":
            if len(parts) < 2:
                print("Error: Missing value for enQueue")
                continue
            value = int(parts[1])
            queue.en_queue(value)
            print("Enqueued:", value)
        elif parts[0].lower() == "dequeue":
            try:
                removed_value = queue.de_queue()
                print("Dequeued:", removed_value)
            except RuntimeError as e:
                print("Error:", e)
        elif parts[0].lower() == "peek":
            try:
                print("Front of queue:", queue.peek())
            except RuntimeError as e:
                print("Error:", e)
        elif parts[0].lower() == "isempty":
            print("Is empty:", queue.is_empty())
        elif parts[0].lower() == "isfull":
            print("Is full:", queue.is_full())
        elif parts[0].lower() == "size":
            print("Current size:", queue.size())
        else:
            print("Unknown command:", parts[0])

