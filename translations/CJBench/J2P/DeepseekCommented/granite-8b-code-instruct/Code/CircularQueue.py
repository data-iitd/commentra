
class Main:
    def __init__(self, size):
        # Check if the size is valid
        if size < 1:
            raise ValueError("Size must be greater than 0")
        # Initialize the array with the given size
        self.array = [None] * size
        # Initialize indices and sizes
        self.top_of_queue = -1
        self.beginning_of_queue = -1
        self.size = size
        self.current_size = 0

    # Check if the queue is empty
    def is_empty(self):
        return self.current_size == 0

    # Check if the queue is full
    def is_full(self):
        return self.current_size == self.size

    # Add an element to the queue
    def en_queue(self, value):
        if self.is_full():
            raise RuntimeError("Queue is full")
        # Set beginning of queue if it's the first element
        if self.is_empty():
            self.beginning_of_queue = 0
        # Update the top of the queue and add the value
        self.top_of_queue = (self.top_of_queue + 1) % self.size
        self.array[self.top_of_queue] = value
        self.current_size += 1

    # Remove and return the front element from the queue
    def de_queue(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        # Get the value to be removed
        removed_value = self.array[self.beginning_of_queue]
        # Clear the position and update the beginning of the queue
        self.array[self.beginning_of_queue] = None
        self.beginning_of_queue = (self.beginning_of_queue + 1) % self.size
        self.current_size -= 1
        # If the queue is empty, reset the beginning and top indices
        if self.is_empty():
            self.beginning_of_queue = -1
            self.top_of_queue = -1

    # Return the front element without removing it
    def peek(self):
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        return self.array[self.beginning_of_queue]

    # Delete the queue
    def delete_queue(self):
        self.array = None
        self.beginning_of_queue = -1
        self.top_of_queue = -1
        self.current_size = 0

    # Return the current size of the queue
    def size(self):
        return self.current_size

# Main method to interact with the queue via command line
if __name__ == "__main__":
    import sys
    queue_size = int(input())
    queue = Main(queue_size)
    while True:
        line = input().strip()
        if line.lower() == "exit":
            break
        try:
            parts = line.split()
            if parts[0].lower() == "enqueue":
                if len(parts) < 2:
                    print("Error: Missing value for enQueue")
                    continue
                value = int(parts[1])
                queue.en_queue(value)
                print(f"Enqueued: {value}")
            elif parts[0].lower() == "dequeue":
                print(f"Dequeued: {queue.de_queue()}")
            elif parts[0].lower() == "peek":
                print(f"Front of queue: {queue.peek()}")
            elif parts[0].lower() == "isempty":
                print(f"Is empty: {queue.is_empty()}")
            elif parts[0].lower() == "isfull":
                print(f"Is full: {queue.is_full()}")
            elif parts[0].lower() == "size":
                print(f"Current size: {queue.size()}")
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

