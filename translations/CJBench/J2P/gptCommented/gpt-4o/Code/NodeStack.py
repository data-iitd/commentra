class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.previous = None  # Initially, previous is None


class Stack:
    def __init__(self):
        self.head = None  # Head of the stack (top element)
        self.size = 0  # Size of the stack

    def push(self, item):
        new_node = Node(item)  # Create a new node with the given item
        new_node.previous = self.head  # Link the new node to the current head
        self.head = new_node  # Update head to the new node
        self.size += 1  # Increment the size of the stack

    def pop(self):
        if self.is_empty():  # Check if the stack is empty before popping
            raise Exception("Cannot pop from an empty stack.")
        data = self.head.data  # Get the data from the head node
        self.head = self.head.previous  # Move head to the previous node
        self.size -= 1  # Decrement the size of the stack
        return data  # Return the popped data

    def peek(self):
        if self.is_empty():  # Check if the stack is empty before peeking
            raise Exception("Cannot peek from an empty stack.")
        return self.head.data  # Return the data from the head node

    def is_empty(self):
        return self.head is None  # Returns True if head is None, indicating an empty stack

    def size(self):
        return self.size  # Return the size of the stack


def main():
    import sys

    stack = Stack()  # Create a new stack instance for Integer type

    # Loop to continuously read commands until "exit" is entered
    for line in sys.stdin:
        command = line.strip()  # Read and trim the input command
        if command.lower() == "exit":  # Check for exit command
            break  # Exit the loop
        try:
            parts = command.split(" ")  # Split the command into parts
            if parts[0] == "push":
                if len(parts) < 2:  # Check if a value is provided for push
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])  # Parse the value to an integer
                stack.push(value)  # Push the value onto the stack
                print(f"Pushed: {value}")  # Confirm the push operation
            elif parts[0] == "pop":
                print(f"Popped: {stack.pop()}")  # Pop and display the top value
            elif parts[0] == "peek":
                print(f"Top: {stack.peek()}")  # Peek and display the top value
            elif parts[0] == "size":
                print(f"Size: {stack.size}")  # Display the current size of the stack
            elif parts[0] == "isEmpty":
                print(f"Is empty: {stack.is_empty()}")  # Check and display if the stack is empty
            else:
                print(f"Unknown command: {parts[0]}")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Handle exceptions and display error messages


if __name__ == "__main__":
    main()

# <END-OF-CODE>
