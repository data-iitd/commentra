import sys; # Import the sys module for reading user input

class Main:
    # Define the Node class which represents a node in the linked list
    class Node:
        def __init__(self, data):
            self.data = data; # The data stored in the node
            self.previous = None; # Reference to the previous node in the list

    # The head of the linked list (top of the stack)
    head = None;
    # The size of the stack
    size = 0;

    # Constructor for the Main class, initializes the stack
    def __init__(self):
        self.head = None; # Initialize the head to null
        self.size = 0; # Initialize the size to 0

    # Method to add an item to the top of the stack
    def push(self, item):
        newNode = self.Node(item); # Create a new node with the given item
        newNode.previous = self.head; # Set the new node's previous reference to the current head
        self.head = newNode; # Update the head to be the new node
        self.size += 1; # Increment the size of the stack

    # Method to remove and return the item from the top of the stack
    def pop(self):
        if self.isEmpty(): # Check if the stack is empty
            raise Exception("Cannot pop from an empty stack."); # Throw an exception if the stack is empty
        data = self.head.data; # Get the data from the top node
        self.head = self.head.previous; # Update the head to be the previous node
        self.size -= 1; # Decrement the size of the stack
        return data; # Return the data from the top node

    # Method to return the item from the top of the stack without removing it
    def peek(self):
        if self.isEmpty(): # Check if the stack is empty
            raise Exception("Cannot peek from an empty stack."); # Throw an exception if the stack is empty
        return self.head.data; # Return the data from the top node

    # Method to check if the stack is empty
    def isEmpty(self):
        return self.head == None; # Return true if the head is null, indicating the stack is empty

    # Method to return the size of the stack
    def size(self):
        return self.size; # Return the current size of the stack

    # Main method to run the stack application
    def main(self):
        scanner = sys.stdin; # Create a Scanner object for reading user input
        stack = Main(); # Create a new instance of the Main class
        while True: # Continuously read lines from the user
            command = scanner.readline().strip(); # Read the command and trim any extra whitespace
            if command.lower() == "exit": # Check if the user wants to exit
                break; # Exit the loop if the user wants to exit
            try:
                parts = command.split(" "); # Split the command into parts
                if parts[0].lower() == "push":
                    if len(parts) < 2: # Check if a value was provided
                        print("Error: Missing value for push"); # Print an error message if no value was provided
                        break;
                    value = int(parts[1]); # Parse the value from a string to an integer
                    stack.push(value); # Push the value onto the stack
                    print("Pushed: " + str(value)); # Print a confirmation message
                elif parts[0].lower() == "pop":
                    print("Popped: " + str(stack.pop())); # Pop the top item from the stack and print it
                elif parts[0].lower() == "peek":
                    print("Top: " + str(stack.peek())); # Peek at the top item of the stack and print it
                elif parts[0].lower() == "size":
                    print("Size: " + str(stack.size())); # Print the size of the stack
                elif parts[0].lower() == "isEmpty":
                    print("Is empty: " + str(stack.isEmpty())); # Print whether the stack is empty
                else:
                    print("Unknown command: " + parts[0]); # Print an error message for an unknown command
            except Exception as e:
                print("Error: " + str(e)); # Print an error message if an exception occurs
        scanner.close(); # Close the Scanner object

# 