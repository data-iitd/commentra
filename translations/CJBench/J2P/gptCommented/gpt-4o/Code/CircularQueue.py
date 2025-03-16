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

    # Method to check if the queue is empty
    def is_empty(self):
        return self.current_size == 0

    # Method to check if the queue is full
    def is_full(self):
        return self.current_size == self.size

    # Method to add an element to the queue
    def en_queue(self, value):
        # Check if the queue is full before adding an element
        if self.is_full():
            raise Exception("Queue is full")
        # If the queue is empty, set the beginning index
        if self.is_empty():
            self.beginning_of_queue = 0
        # Update the top index in a circular manner and add the new value
        self.top_of_queue = (self.top_of_queue + 1) % self.size
        self.array[self.top_of_queue] = value
        self.current_size += 1

    # Method to remove and return the front element of the queue
    def de_queue(self):
        # Check if the queue is empty before removing an element
        if self.is_empty():
            raise Exception("Queue is empty")
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
        return removed_value

    # Method to view the front element of the queue without removing it
    def peek(self):
        # Check if the queue is empty before peeking
        if self.is_empty():
            raise Exception("Queue is empty")
        return self.array[self.beginning_of_queue]

    # Method to delete the queue and free resources
    def delete_queue(self):
        self.array = None  # Clear the array reference
        self.beginning_of_queue = -1  # Reset beginning index
        self.top_of_queue = -1  # Reset top index
        self.current_size = 0  # Reset current size

    # Method to get the current size of the queue
    def size(self):
        return self.current_size


# Main function to execute the program
if __name__ == "__main__":
    import sys

    # Read the size of the queue from user input
    queue_size = int(input("Enter the size of the queue: "))
    # Create a new queue instance
    queue = Queue(queue_size)

    # Loop to process user commands until "exit" is entered
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            # Split the command into parts for processing
            parts = command.split()
            if parts[0] == "enQueue":
                # Check for missing value in the command
                if len(parts) < 2:
                    print("Error: Missing value for enQueue")
                    continue
                # Parse the value and enqueue it
                value = int(parts[1])
                queue.en_queue(value)
                print(f"Enqueued: {value}")
            elif parts[0] == "deQueue":
                # Dequeue an element and print it
                print(f"Dequeued: {queue.de_queue()}")
            elif parts[0] == "peek":
                # Peek at the front element of the queue
                print(f"Front of queue: {queue.peek()}")
            elif parts[0] == "isEmpty":
                # Check if the queue is empty and print the result
                print(f"Is empty: {queue.is_empty()}")
            elif parts[0] == "isFull":
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

# <END-OF-CODE>
