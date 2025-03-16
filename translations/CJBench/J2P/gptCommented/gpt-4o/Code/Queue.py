class Main:
    # Default capacity for the queue
    DEFAULT_CAPACITY = 10

    def __init__(self, capacity=None):
        if capacity is None:
            capacity = self.DEFAULT_CAPACITY
        if capacity <= 0:
            raise ValueError("Main capacity must be greater than 0")
        self.max_size = capacity
        self.queue_array = [None] * capacity
        self.front = 0
        self.rear = -1
        self.n_items = 0

    # Method to insert an element into the queue
    def insert(self, element):
        if self.is_full():
            return False
        self.rear = (self.rear + 1) % self.max_size
        self.queue_array[self.rear] = element
        self.n_items += 1
        return True

    # Method to remove and return the front element of the queue
    def remove(self):
        if self.is_empty():
            raise Exception("Main is empty, cannot remove element")
        removed_element = self.queue_array[self.front]
        self.queue_array[self.front] = None  # Clear the reference
        self.front = (self.front + 1) % self.max_size
        self.n_items -= 1
        return removed_element

    # Method to peek at the front element without removing it
    def peek_front(self):
        if self.is_empty():
            raise Exception("Main is empty, cannot peek front")
        return self.queue_array[self.front]

    # Method to peek at the rear element without removing it
    def peek_rear(self):
        if self.is_empty():
            raise Exception("Main is empty, cannot peek rear")
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
            return "[]"
        elements = []
        for i in range(self.n_items):
            index = (self.front + i) % self.max_size
            elements.append(str(self.queue_array[index]))
        return "[" + ", ".join(elements) + "]"

# Main method to execute the queue operations based on user input
if __name__ == "__main__":
    import sys

    size = int(input("Enter the size of the queue: "))
    queue = Main(size)  # Create a queue with specified size

    # Process user commands until "exit" is entered
    while True:
        command = input().strip()
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            parts = command.split()
            # Handle different commands for queue operations
            if parts[0] == "insert":
                if len(parts) < 2:
                    print("Error: Missing value for insert")
                    continue
                value = int(parts[1])
                if queue.insert(value):
                    print(f"Inserted: {value}")
                else:
                    print("Main is full")
            elif parts[0] == "remove":
                print(f"Removed: {queue.remove()}")
            elif parts[0] == "peekFront":
                print(f"Front: {queue.peek_front()}")
            elif parts[0] == "peekRear":
                print(f"Rear: {queue.peek_rear()}")
            elif parts[0] == "getSize":
                print(f"Size: {queue.get_size()}")
            elif parts[0] == "isEmpty":
                print(f"Is empty: {queue.is_empty()}")
            elif parts[0] == "print":
                print(f"Main: {queue}")
            else:
                print(f"Unknown command: {parts[0]}")
        except Exception as e:
            print(f"Error: {e}")

# <END-OF-CODE>
