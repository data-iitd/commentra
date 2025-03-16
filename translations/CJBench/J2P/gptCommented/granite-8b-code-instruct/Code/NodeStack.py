
class Main:
    # Node class representing each element in the stack
    class Node:
        def __init__(self, data):
            self.data = data  # Data stored in the node
            self.previous = None  # Reference to the previous node in the stack

        # Constructor to initialize a new node with data
        def __init__(self, data):
            self.data = data
            self.previous = None  # Initially, previous is None

    def __init__(self):
        self.head = None  # Head of the stack (top element)
        self.size = 0  # Size of the stack

    # Method to add an item to the top of the stack
    def push(self, item):
        new_node = Main.Node(item)  # Create a new node with the given item
        new_node.previous = self.head  # Link the new node to the current head
        self.head = new_node  # Update head to the new node
        self.size += 1  # Increment the size of the stack

    # Method to remove and return the top item from the stack
    def pop(self):
        # Check if the stack is empty before popping
        if self.isEmpty():
            raise Exception("Cannot pop from an empty stack.")
        data = self.head.data  # Get the data from the head node
        self.head = self.head.previous  # Move head to the previous node
        self.size -= 1  # Decrement the size of the stack
        return data  # Return the popped data

    # Method to return the top item without removing it from the stack
    def peek(self):
        # Check if the stack is empty before peeking
        if self.isEmpty():
            raise Exception("Cannot peek from an empty stack.")
        return self.head.data  # Return the data from the head node

    # Method to check if the stack is empty
    def isEmpty(self):
        return self.head is None  # Returns True if head is None, indicating an empty stack

    # Method to return the current size of the stack
    def size(self):
        return self.size  # Return the size of the stack

# Main method to run the stack operations based on user input
if __name__ == "__main__":
    import sys

    stack = Main()  # Create a new stack instance for Integer type

    # Loop to continuously read commands until "exit" is entered
    while True:
        command = input().strip()  # Read and trim the input command
        if command.lower() == "exit":  # Check for exit command
            break  # Exit the loop
        try:
            parts = command.split()  # Split the command into parts
            if parts[0].lower() == "push":
                # Check if a value is provided for push
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])  # Parse the value to an integer
                stack.push(value)  # Push the value onto the stack
                print("Pushed:", value)  # Confirm the push operation
            elif parts[0].lower() == "pop":
                print("Popped:", stack.pop())  # Pop and display the top value
            elif parts[0].lower() == "peek":
                print("Top:", stack.peek())  # Peek and display the top value
            elif parts[0].lower() == "size":
                print("Size:", stack.size())  # Display the current size of the stack
            elif parts[0].lower() == "isempty":
                print("Is empty:", stack.isEmpty())  # Check and display if the stack is empty
            else:
                print("Unknown command:", parts[0])  # Handle unknown commands
        except Exception as e:
            print("Error:", e)  # Handle exceptions and display error messages

