
class Queue:
    def __init__(self, size):
        # Validate that the size is greater than 0
        if size < 1:
            raise ValueError("Size must be greater than 0")
        # Initialize the array and other variables
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
        # Check if the queue is full before adding an element
        if self.is_full():
            raise RuntimeError("Queue is full")
        # If the queue is empty, set the beginning index
        if self.is_empty():
            self.beginning_of_queue = 0
        # Update the top index in a circular manner and add the new value
        self.top_of_queue = (self.top_of_queue + 1) % self.size
        self.array[self.top_of_queue] = value
        self.current_size += 1

    def de_queue(self):
        # Check if the queue is empty before removing an element
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        # Store the value to be removed
        removed_value = self.array[self.beginning_of_queue]
        # Clear the position in the array
        self.array[self.beginning_of_queue] = None
        # Update the beginning index in a circular manner
        self.beginning_of_queue = (self.beginning_of_queue + 1) % self.size
        self.current_size -= 1
        # Reset indices if the queue is empty after removal
        if self.is_empty():
            self.beginning_of_queue = -1
            self.top_of_queue = -1

    def peek(self):
        # Check if the queue is empty before peeking
        if self.is_empty():
            raise RuntimeError("Queue is empty")
        return self.array[self.beginning_of_queue]

    def delete_queue(self):
        self.array = None  # Clear the array reference
        self.beginning_of_queue = -1  # Reset beginning index
        self.top_of_queue = -1  # Reset top index
        self.current_size = 0  # Reset current size

    def size(self):
        return self.current_size

# Main method to execute the program
if __name__ == "__main__":
    import sys

    queue_size = int(input("Enter the size of the queue: "))
    queue = Queue(queue_size)

    # Loop to process user commands until "exit" is entered
    while True:
        command = input("Enter a command (or 'exit' to quit): ").strip().lower()
        if command == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            # Split the command into parts for processing
            parts = command.split()
            if parts[0] == "en_queue":
                # Check for missing value in the command
                if len(parts) < 2:
                    print("Error: Missing value for en_queue")
                    continue
                # Parse the value and enqueue it
                value = int(parts[1])
                queue.en_queue(value)
                print(f"Enqueued: {value}")
            elif parts[0] == "de_queue":
                # Dequeue an element and print it
                removed_value = queue.de_queue()
                print(f"Dequeued: {removed_value}")
            elif parts[0] == "peek":
                # Peek at the front element of the queue
                print(f"Front of queue: {queue.peek()}")
            elif parts[0] == "is_empty":
                # Check if the queue is empty and print the result
                print(f"Is empty: {queue.is_empty()}")
            elif parts[0] == "is_full":
                # Check if the queue is full and print the result
                print(f"Is full: {queue.is_full()}")
            elif parts[0] == "size":
                # Print the current size of the queue
                print(f"Current size: {queue.size()}")
            else:
                # Handle unknown commands
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            # Handle any exceptions that occur during command processing
            print(f"Error: {e}")

# End of code
