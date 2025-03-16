class CircularQueue:
    """
    The CircularQueue class represents a generic circular queue data structure that uses an array to
    store elements. This queue allows efficient utilization of space by wrapping around the array,
    thus avoiding the need to shift elements during enqueue and dequeue operations.

    When the queue reaches its maximum capacity, further enqueues will raise an exception.
    Similarly, attempts to dequeue or peek from an empty queue will also result in an exception.

    Usage Example:
    queue = CircularQueue(3)
    queue.enQueue(1)
    queue.enQueue(2)
    queue.enQueue(3)
    queue.deQueue()  # Removes 1
    queue.enQueue(4)  # Wraps around and places 4 at the position of removed 1
    """

    def __init__(self, size):
        if size < 1:
            raise ValueError("Size must be greater than 0")
        self.array = [None] * size
        self.top_of_queue = -1
        self.beginning_of_queue = -1
        self.size = size
        self.current_size = 0

    def is_empty(self):
        """Checks if the queue is empty."""
        return self.current_size == 0

    def is_full(self):
        """Checks if the queue is full."""
        return self.current_size == self.size

    def enQueue(self, value):
        """Adds a new element to the queue. If the queue is full, an exception is raised."""
        if self.is_full():
            raise Exception("Queue is full")
        if self.is_empty():
            self.beginning_of_queue = 0
        self.top_of_queue = (self.top_of_queue + 1) % self.size
        self.array[self.top_of_queue] = value
        self.current_size += 1

    def deQueue(self):
        """Removes and returns the element at the front of the queue."""
        if self.is_empty():
            raise Exception("Queue is empty")
        removed_value = self.array[self.beginning_of_queue]
        self.array[self.beginning_of_queue] = None
        self.beginning_of_queue = (self.beginning_of_queue + 1) % self.size
        self.current_size -= 1
        if self.is_empty():
            self.beginning_of_queue = -1
            self.top_of_queue = -1
        return removed_value

    def peek(self):
        """Returns the element at the front of the queue without removing it."""
        if self.is_empty():
            raise Exception("Queue is empty")
        return self.array[self.beginning_of_queue]

    def delete_queue(self):
        """Deletes the entire queue by resetting all elements and pointers."""
        self.array = None
        self.beginning_of_queue = -1
        self.top_of_queue = -1
        self.current_size = 0

    def size(self):
        """Returns the current number of elements in the queue."""
        return self.current_size


if __name__ == "__main__":
    queue_size = int(input("Enter the size of the CircularQueue: "))
    queue = CircularQueue(queue_size)
    print("Enter commands (enQueue <value>, deQueue, peek, isEmpty, isFull, size, exit):")

    while True:
        command = input().strip()

        if command.lower() == "exit":
            break

        try:
            parts = command.split()
            if parts[0] == "enQueue":
                if len(parts) < 2:
                    print("Error: Missing value for enQueue")
                    continue
                value = int(parts[1])
                queue.enQueue(value)
                print(f"Enqueued: {value}")

            elif parts[0] == "deQueue":
                print(f"Dequeued: {queue.deQueue()}")

            elif parts[0] == "peek":
                print(f"Front of queue: {queue.peek()}")

            elif parts[0] == "isEmpty":
                print(f"Is empty: {queue.is_empty()}")

            elif parts[0] == "isFull":
                print(f"Is full: {queue.is_full()}")

            elif parts[0] == "size":
                print(f"Current size: {queue.size()}")

            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

# <END-OF-CODE>
