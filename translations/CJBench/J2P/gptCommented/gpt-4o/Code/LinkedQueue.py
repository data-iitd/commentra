class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.next = None  # Reference to the next node in the queue


class Queue:
    def __init__(self):
        self.front = None  # Initially, the queue is empty
        self.rear = None
        self.size = 0  # Size is zero

    def is_empty(self):
        return self.size == 0  # Returns True if size is zero

    def enqueue(self, data):
        if data is None:
            raise ValueError("Cannot enqueue null data")  # Prevent null data
        new_node = Node(data)  # Create a new node with the given data
        if self.is_empty():
            self.front = new_node  # If the queue is empty, set front to the new node
        else:
            self.rear.next = new_node  # Link the new node to the end of the queue
        self.rear = new_node  # Update the rear to the new node
        self.size += 1  # Increment the size of the queue

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")  # Prevent dequeue from an empty queue
        ret_value = self.front.data  # Store the data of the front node
        self.front = self.front.next  # Move the front pointer to the next node
        self.size -= 1  # Decrement the size of the queue
        if self.is_empty():
            self.rear = None  # If the queue is now empty, set rear to None
        return ret_value  # Return the dequeued value

    def peek_front(self):
        if self.is_empty():
            raise IndexError("Queue is empty")  # Prevent peek from an empty queue
        return self.front.data  # Return the data of the front node

    def peek_rear(self):
        if self.is_empty():
            raise IndexError("Queue is empty")  # Prevent peek from an empty queue
        return self.rear.data  # Return the data of the rear node

    def size(self):
        return self.size  # Return the size of the queue

    def clear(self):
        self.front = None  # Set front to None
        self.rear = None  # Set rear to None
        self.size = 0  # Reset size to zero

    def __str__(self):
        if self.is_empty():
            return "[]"  # Return empty representation if the queue is empty
        elements = []  # Start building the string
        current = self.front  # Start from the front of the queue
        while current is not None:
            elements.append(current.data)  # Append the current node's data
            current = current.next  # Move to the next node
        return "[" + ", ".join(map(str, elements)) + "]"  # Return the final string


def main():
    import sys

    queue = Queue()  # Create a new queue instance for integers

    # Loop to process user commands
    for line in sys.stdin:
        command = line.strip()  # Read the command from user input
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            parts = command.split(" ")  # Split the command into parts
            if parts[0] == "enqueue":
                if len(parts) < 2:
                    print("Error: Missing value for enqueue")  # Error for missing value
                    continue
                value = int(parts[1])  # Parse the value to enqueue
                queue.enqueue(value)  # Enqueue the value
                print(f"Enqueued: {value}")  # Confirm enqueue operation
            elif parts[0] == "dequeue":
                print(f"Dequeued: {queue.dequeue()}")  # Dequeue and print the result
            elif parts[0] == "peekFront":
                print(f"Front element: {queue.peek_front()}")  # Print the front element
            elif parts[0] == "peekRear":
                print(f"Rear element: {queue.peek_rear()}")  # Print the rear element
            elif parts[0] == "size":
                print(f"Size: {queue.size}")  # Print the current size of the queue
            elif parts[0] == "isEmpty":
                print(f"Is empty: {queue.is_empty()}")  # Check if the queue is empty
            elif parts[0] == "print":
                print(queue)  # Print the string representation of the queue
            else:
                print(f"Unknown command: {parts[0]}")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Print any errors encountered


if __name__ == "__main__":
    main()

# <END-OF-CODE>
