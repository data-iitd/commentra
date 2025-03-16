class Main:
    DEFAULT_CAPACITY = 10  # Set default capacity of the queue

    def __init__(self, capacity=None):
        if capacity is None:
            capacity = self.DEFAULT_CAPACITY  # Initialize with default capacity
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")  # Raise exception if capacity is invalid
        self.max_size = capacity  # Set the max size to the given capacity
        self.queue_array = [None] * capacity  # Create a list to store the queue elements
        self.front = 0  # Set the front index to zero
        self.rear = -1  # Set the rear index to -1, indicating an empty queue
        self.n_items = 0  # Set the number of elements to zero

    def insert(self, value):
        if self.is_full():
            return False  # Return False if the queue is full
        self.rear = (self.rear + 1) % self.max_size  # Update rear index
        self.queue_array[self.rear] = value  # Insert the value
        self.n_items += 1  # Increment the number of items
        return True  # Return True if insertion is successful

    def remove(self):
        if self.is_empty():
            return None  # Return None if the queue is empty
        value = self.queue_array[self.front]  # Get the front value
        self.queue_array[self.front] = None  # Clear the front value
        self.front = (self.front + 1) % self.max_size  # Update front index
        self.n_items -= 1  # Decrement the number of items
        return value  # Return the removed value

    def peek_front(self):
        if self.is_empty():
            return None  # Return None if the queue is empty
        return self.queue_array[self.front]  # Return the front value

    def peek_rear(self):
        if self.is_empty():
            return None  # Return None if the queue is empty
        return self.queue_array[self.rear]  # Return the rear value

    def is_empty(self):
        return self.n_items == 0  # Check if the queue is empty

    def is_full(self):
        return self.n_items == self.max_size  # Check if the queue is full

    def get_size(self):
        return self.n_items  # Return the number of items in the queue

    def print_queue(self):
        if self.is_empty():
            print("Queue is empty")
            return
        for i in range(self.n_items):
            index = (self.front + i) % self.max_size
            print(self.queue_array[index], end=' ')
        print()  # New line after printing the queue

if __name__ == "__main__":
    import sys

    size = int(input("Enter the size of the queue: "))  # Read the size of the queue from the user
    queue = Main(size)  # Create a new Main object with the given size

    for line in sys.stdin:  # Read user commands until the end of the input
        command = line.strip()  # Read and trim the command string

        if command.lower() == "exit":  # Check if the command is "exit"
            break  # If it is, exit the loop

        parts = command.split()  # Split the command string into parts based on space

        if parts[0] == "insert":  # If the command is "insert"
            if len(parts) < 2:  # Check if the command has a value
                print("Error: Missing value for insert")  # Print an error message if it doesn't
                continue
            value = int(parts[1])  # Parse the value from the command
            if queue.insert(value):  # Try to insert the value into the queue
                print(f"Inserted: {value}")  # Print a success message if it's successful
            else:
                print("Main is full")  # Print a full message if the queue is full
        elif parts[0] == "remove":
            removed_value = queue.remove()  # Try to remove a value from the queue
            if removed_value is not None:
                print(f"Removed: {removed_value}")  # Print the removed value
            else:
                print("Main is empty")  # Print a message if the queue is empty
        elif parts[0] == "peekFront":
            front_value = queue.peek_front()  # Peek at the front value
            if front_value is not None:
                print(f"Front: {front_value}")  # Print the front value
            else:
                print("Main is empty")  # Print a message if the queue is empty
        elif parts[0] == "peekRear":
            rear_value = queue.peek_rear()  # Peek at the rear value
            if rear_value is not None:
                print(f"Rear: {rear_value}")  # Print the rear value
            else:
                print("Main is empty")  # Print a message if the queue is empty
        elif parts[0] == "getSize":
            print(f"Size: {queue.get_size()}")  # Print the size of the queue
        elif parts[0] == "isEmpty":
            print("Is empty:", queue.is_empty())  # Print if the queue is empty
        elif parts[0] == "print":
            queue.print_queue()  # Print the queue

# <END-OF-CODE>
