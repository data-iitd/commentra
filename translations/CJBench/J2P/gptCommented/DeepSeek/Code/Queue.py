class Main:
    # Default capacity for the queue
    DEFAULT_CAPACITY = 10

    # Constructor that initializes the queue with a specified capacity
    def __init__(self, capacity=DEFAULT_CAPACITY):
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.max_size = capacity
        self.queue_array = [None] * capacity
        self.front = 0
        self.rear = -1
        self.n_items = 0

    # Method to insert an element into the queue
    def insert(self, element):
        # Check if the queue is full
        if self.is_full():
            return False
        # Update rear index in a circular manner and add the element
        self.rear = (self.rear + 1) % self.max_size
        self.queue_array[self.rear] = element
        self.n_items += 1
        return True

    # Method to remove and return the front element of the queue
    def remove(self):
        # Check if the queue is empty
        if self.is_empty():
            raise IndexError("Main is empty, cannot remove element")
        # Retrieve the front element and update the front index
        removed_element = self.queue_array[self.front]
        self.queue_array[self.front] = None  # Clear the reference
        self.front = (self.front + 1) % self.max_size
        self.n_items -= 1
        return removed_element

    # Method to peek at the front element without removing it
    def peek_front(self):
        # Check if the queue is empty
        if self.is_empty():
            raise IndexError("Main is empty, cannot peek front")
        return self.queue_array[self.front]

    # Method to peek at the rear element without removing it
    def peek_rear(self):
        # Check if the queue is empty
        if self.is_empty():
            raise IndexError("Main is empty, cannot peek rear")
        return self.queue_array[self.rear]

    # Method to check if the queue is empty
    def is_empty(self):
        return self.n_items == 0

    # Method to check if the queue is full
    def is_full(self):
        return self.n_items == self.max_size

    # Method to get the current size of the queue
    def get_size(self):
        return self.n_items

    # Method to return a string representation of the queue
    def __str__(self):
        if self.is_empty():
            return "[]"  # Return empty representation if queue is empty
        elements = []
        # Iterate through the queue elements in order
        for i in range(self.n_items):
            index = (self.front + i) % self.max_size  # Calculate index in a circular manner
            elements.append(str(self.queue_array[index]))
        return "[" + ", ".join(elements) + "]"

    # Main method to execute the queue operations based on user input
    @staticmethod
    def main():
        import sys
        input = sys.stdin.readline
        # Read the size of the queue from user input
        size = int(input().strip())
        queue = Main(size)  # Create a queue with specified size

        # Process user commands until "exit" is entered
        while True:
            command = input().strip()
            if command.lower() == "exit":
                break  # Exit the loop if the command is "exit"
            try:
                parts = command.split()
                # Handle different commands for queue operations
                if parts[0].lower() == "insert":
                    if len(parts) < 2:
                        print("Error: Missing value for insert")
                        continue
                    value = int(parts[1])
                    if queue.insert(value):
                        print(f"Inserted: {value}")
                    else:
                        print("Main is full")
                elif parts[0].lower() == "remove":
                    print(f"Removed: {queue.remove()}")
                elif parts[0].lower() == "peekfront":
                    print(f"Front: {queue.peek_front()}")
                elif parts[0].lower() == "peekrear":
                    print(f"Rear: {queue.peek_rear()}")
                elif parts[0].lower() == "getsize":
                    print(f"Size: {queue.get_size()}")
                elif parts[0].lower() == "isempty":
                    print(f"Is empty: {queue.is_empty()}")
                elif parts[0].lower() == "print":
                    print(f"Main: {queue}")
                else:
                    print(f"Unknown command: {parts[0]}")
            except Exception as e:
                print(f"Error: {e}")


Main.main()
