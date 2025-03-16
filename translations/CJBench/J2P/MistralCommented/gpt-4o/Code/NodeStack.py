class Node:  # Define a Node class
    def __init__(self, data):  # Constructor for Node
        self.data = data  # Data to be stored in the node
        self.previous = None  # Previous node in the linked list


class Stack:  # Define a Stack class
    def __init__(self):  # Constructor for Stack
        self.head = None  # Initialize head of the stack as None
        self.size = 0  # Initialize size of the stack as 0

    def push(self, item):  # Method to add an item to the stack
        new_node = Node(item)  # Create a new node with the given item
        new_node.previous = self.head  # Set the new node's previous as the current head
        self.head = new_node  # Update the head to the new node
        self.size += 1  # Increment the size of the stack

    def pop(self):  # Method to remove and return the top item from the stack
        if self.is_empty():  # Check if the stack is empty
            raise Exception("Cannot pop from an empty stack.")  # Raise an exception if empty
        data = self.head.data  # Store the data of the top node
        self.head = self.head.previous  # Update the head to the previous node
        self.size -= 1  # Decrement the size of the stack
        return data  # Return the popped item

    def peek(self):  # Method to return the top item from the stack without removing it
        if self.is_empty():  # Check if the stack is empty
            raise Exception("Cannot peek from an empty stack.")  # Raise an exception if empty
        return self.head.data  # Return the data of the top node

    def is_empty(self):  # Method to check if the stack is empty or not
        return self.head is None  # Return True if head is None, else False

    def size(self):  # Method to return the size of the stack
        return self.size  # Return the size of the stack


if __name__ == "__main__":  # Main method
    import sys  # Import sys for reading input
    stack = Stack()  # Create an instance of the Stack class

    for line in sys.stdin:  # Read user input until EOF
        command = line.strip()  # Read the command from the user

        if command.lower() == "exit":  # Check if the command is "exit"
            break  # If yes, exit the loop

        try:  # Try to parse the command
            parts = command.split()  # Split the command into parts based on space

            if parts[0] == "push":  # Check if the command is "push"
                if len(parts) < 2:  # Check if the command has a value
                    print("Error: Missing value for push")  # Print an error message if not
                    continue  # Continue to the next iteration
                value = int(parts[1])  # Parse the value to an integer
                stack.push(value)  # Add the value to the stack
                print(f"Pushed: {value}")  # Print a message confirming the push
            elif parts[0] == "pop":  # Check if the command is "pop"
                print(f"Popped: {stack.pop()}")  # Print the popped item and pop it from the stack
            elif parts[0] == "peek":  # Check if the command is "peek"
                print(f"Top: {stack.peek()}")  # Print the top item of the stack
            elif parts[0] == "size":  # Check if the command is "size"
                print(f"Size: {stack.size}")  # Print the size of the stack
            elif parts[0] == "isEmpty":  # Check if the command is "isEmpty"
                print(f"Is empty: {stack.is_empty()}")  # Print whether the stack is empty or not
            else:  # For unknown commands
                print(f"Unknown command: {parts[0]}")  # Print an error message for unknown commands
        except Exception as e:  # Catch any exceptions thrown
            print(f"Error: {e}")  # Print the error message

# <END-OF-CODE>
