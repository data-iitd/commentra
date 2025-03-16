class Node:
    def __init__(self, val):
        self.val = val  # Value of the node
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node


class Deque:
    def __init__(self):
        self.head = None  # Head pointer for the deque
        self.tail = None  # Tail pointer for the deque
        self.size = 0  # Size of the deque

    def add_first(self, val):
        new_node = Node(val)  # Create a new node
        if self.is_empty():  # If the deque is empty
            self.head = new_node  # Set head and tail to the new node
            self.tail = new_node
        else:  # If the deque is not empty
            new_node.next = self.head  # Link new node to the current head
            self.head.prev = new_node  # Link current head back to the new node
            self.head = new_node  # Update head to the new node
        self.size += 1  # Increment the size of the deque

    def add_last(self, val):
        new_node = Node(val)  # Create a new node
        if self.tail is None:  # If the deque is empty
            self.head = new_node  # Set head and tail to the new node
            self.tail = new_node
        else:  # If the deque is not empty
            new_node.prev = self.tail  # Link new node back to the current tail
            self.tail.next = new_node  # Link current tail to the new node
            self.tail = new_node  # Update tail to the new node
        self.size += 1  # Increment the size of the deque

    def poll_first(self):
        if self.head is None:  # Check if the deque is empty
            raise Exception("Deque is empty")  # Throw exception if empty
        old_head_val = self.head.val  # Store the value of the current head
        if self.head == self.tail:  # If there's only one element
            self.head = None  # Set head and tail to None
            self.tail = None
        else:  # If there are multiple elements
            self.head = self.head.next  # Move head to the next node
            self.head.prev = None  # Clear the previous pointer of the new head
        self.size -= 1  # Decrement the size of the deque
        return old_head_val  # Return the removed value

    def poll_last(self):
        if self.tail is None:  # Check if the deque is empty
            raise Exception("Deque is empty")  # Throw exception if empty
        old_tail_val = self.tail.val  # Store the value of the current tail
        if self.head == self.tail:  # If there's only one element
            self.head = None  # Set head and tail to None
            self.tail = None
        else:  # If there are multiple elements
            self.tail = self.tail.prev  # Move tail to the previous node
            self.tail.next = None  # Clear the next pointer of the new tail
        self.size -= 1  # Decrement the size of the deque
        return old_tail_val  # Return the removed value

    def peek_first(self):
        return self.head.val if self.head is not None else None  # Return head value or None if empty

    def peek_last(self):
        return self.tail.val if self.tail is not None else None  # Return tail value or None if empty

    def get_size(self):
        return self.size  # Return the size of the deque

    def is_empty(self):
        return self.size == 0  # Return True if size is 0, otherwise False

    def __str__(self):
        deque_string = "Head -> "  # Initialize string representation
        curr_node = self.head  # Start from the head
        while curr_node is not None:  # Traverse the deque
            deque_string += str(curr_node.val)  # Append current node's value
            if curr_node.next is not None:  # If there is a next node
                deque_string += " <-> "  # Append separator
            curr_node = curr_node.next  # Move to the next node
        deque_string += " <- Tail"  # Append tail indication
        return deque_string  # Return the string representation


def main():
    import sys

    deque = Deque()  # Initialize a new deque for integers

    # Loop to continuously read commands from the user
    for line in sys.stdin:
        command = line.strip()  # Read and trim the command
        if command.lower() == "exit":  # Check for exit command
            break  # Exit the loop
        try:
            parts = command.split(" ")  # Split command into parts
            if parts[0] == "addFirst":
                add_first_value = int(parts[1])  # Parse the value
                deque.add_first(add_first_value)  # Add value to the front
                print(f"Added to front: {add_first_value}")  # Confirm addition
            elif parts[0] == "addLast":
                add_last_value = int(parts[1])  # Parse the value
                deque.add_last(add_last_value)  # Add value to the rear
                print(f"Added to rear: {add_last_value}")  # Confirm addition
            elif parts[0] == "pollFirst":
                print(f"Removed from front: {deque.poll_first()}")  # Remove and display front value
            elif parts[0] == "pollLast":
                print(f"Removed from rear: {deque.poll_last()}")  # Remove and display rear value
            elif parts[0] == "peekFirst":
                print(f"Front element: {deque.peek_first()}")  # Display front value without removal
            elif parts[0] == "peekLast":
                print(f"Rear element: {deque.peek_last()}")  # Display rear value without removal
            elif parts[0] == "size":
                print(f"Size: {deque.get_size()}")  # Display current size
            elif parts[0] == "isEmpty":
                print(f"Is empty: {deque.is_empty()}")  # Check if deque is empty
            elif parts[0] == "print":
                print(deque)  # Print the current state of the deque
            else:
                print(f"Unknown command: {parts[0]}")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Handle exceptions and display error message


if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
