class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.next = None  # Reference to the next node


class Queue:
    def __init__(self):
        self.front = None  # Pointer to the front of the queue
        self.rear = None   # Pointer to the rear of the queue
        self.size = 0      # Size of the queue

    def is_empty(self):
        return self.size == 0  # Check if the queue is empty

    def enqueue(self, data):
        if data is None:  # Check if the data is None
            raise ValueError("Cannot enqueue null data")

        new_node = Node(data)  # Create a new node with the data

        if self.is_empty():  # If the queue is empty
            self.front = new_node
        else:
            self.rear.next = new_node  # Make the new node the next of the rear node

        self.rear = new_node  # Update the rear pointer
        self.size += 1  # Increment the size of the queue

    def dequeue(self):
        if self.is_empty():  # Check if the queue is empty
            raise IndexError("Queue is empty")

        ret_value = self.front.data  # Store the data of the front node
        self.front = self.front.next  # Update the front pointer to the next node
        self.size -= 1  # Decrement the size of the queue

        if self.is_empty():  # If the queue is now empty
            self.rear = None  # Set the rear pointer to None

        return ret_value  # Return the dequeued element

    def peek_front(self):
        if self.is_empty():  # Check if the queue is empty
            raise IndexError("Queue is empty")

        return self.front.data  # Return the data of the front node

    def peek_rear(self):
        if self.is_empty():  # Check if the queue is empty
            raise IndexError("Queue is empty")

        return self.rear.data  # Return the data of the rear node

    def size(self):
        return self.size  # Return the size of the queue

    def clear(self):
        self.front = None
        self.rear = None
        self.size = 0  # Clear the queue

    def __str__(self):
        if self.is_empty():
            return "[]"

        elements = []
        current = self.front  # Initialize a pointer to the front node

        while current is not None:  # Traverse the queue and add each element to the list
            elements.append(current.data)
            current = current.next

        return "[" + ", ".join(map(str, elements)) + "]"  # Return the string representation of the queue


def main():
    import sys

    queue = Queue()  # Create an instance of the queue

    for line in sys.stdin:  # Read commands from the standard input until EOF
        command = line.strip()  # Read a command line

        if command.lower() == "exit":  # Check if the command is "exit"
            break  # If so, exit the loop

        try:
            parts = command.split()  # Split the command into parts

            if parts[0] == "enqueue":
                if len(parts) < 2:  # Check if the command has a required argument
                    print("Error: Missing value for enqueue")
                    continue
                value = int(parts[1])  # Parse the value from the argument
                queue.enqueue(value)  # Enqueue the value
                print(f"Enqueued: {value}")  # Print a message
            elif parts[0] == "dequeue":
                print(f"Dequeued: {queue.dequeue()}")  # Dequeue and print the front element
            elif parts[0] == "peekFront":
                print(f"Front element: {queue.peek_front()}")  # Print the front element
            elif parts[0] == "peekRear":
                print(f"Rear element: {queue.peek_rear()}")  # Print the rear element
            elif parts[0] == "size":
                print(f"Size: {queue.size}")  # Print the size of the queue
            elif parts[0] == "isEmpty":
                print(f"Is empty: {queue.is_empty()}")  # Print whether the queue is empty or not
            elif parts[0] == "print":
                print(queue)  # Print the entire queue
            else:
                print(f"Unknown command: {parts[0]}")  # Print an error message for unknown commands
        except Exception as e:  # Catch any exceptions and print an error message
            print(f"Error: {e}")

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
