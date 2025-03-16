
import sys # Import the sys module for reading user input

class Node: # Define a Node class
    def __init__(self, data): # Constructor for Node
        self.data = data # Data to be stored in the node
        self.previous = None # Previous node in the linked list

class Main: # Define a Main class
    def __init__(self): # Constructor for Main class
        self.head = None # Initialize head of the stack as null
        self.size = 0 # Initialize size of the stack as 0

    def push(self, item): # Method to add an item to the stack
        newNode = Node(item) # Create a new node with the given item
        newNode.previous = self.head # Set the new node's previous as the current head
        self.head = newNode # Update the head to the new node
        self.size += 1 # Increment the size of the stack

    def pop(self): # Method to remove and return the top item from the stack
        if self.isEmpty(): # Check if the stack is empty
            raise Exception("Cannot pop from an empty stack.") # Throw an exception if empty
        data = self.head.data # Store the data of the top node
        self.head = self.head.previous # Update the head to the previous node
        self.size -= 1 # Decrement the size of the stack
        return data # Return the popped item

    def peek(self): # Method to return the top item from the stack without removing it
        if self.isEmpty(): # Check if the stack is empty
            raise Exception("Cannot peek from an empty stack.") # Throw an exception if empty
        return self.head.data # Return the data of the top node

    def isEmpty(self): # Method to check if the stack is empty or not
        return self.head == None # Return true if head is null, else false

    def size(self): # Method to return the size of the stack
        return self.size # Return the size of the stack

if __name__ == "__main__": # Check if the file is being run directly
    stack = Main() # Create an instance of the Main class for the stack

    while True: # Read user input until there is no more input
        command = input().strip() # Read the command from the user

        if command.lower() == "exit": # Check if the command is "exit"
            break # If yes, exit the loop

        try: # Try to parse the command
            parts = command.split(" ") # Split the command into parts based on space

            if parts[0].lower() == "push": # Check if the command is "push"
                if len(parts) < 2: # Check if the command has a value
                    print("Error: Missing value for push") # Print an error message if not
                    continue # Continue to the next iteration
                value = int(parts[1]) # Parse the value to an integer
                stack.push(value) # Add the value to the stack
                print("Pushed: " + str(value)) # Print a message confirming the push
            elif parts[0].lower() == "pop": # Check if the command is "pop"
                print("Popped: " + str(stack.pop())) # Print the popped item and pop it from the stack
            elif parts[0].lower() == "peek": # Check if the command is "peek"
                print("Top: " + str(stack.peek())) # Print the top item of the stack
            elif parts[0].lower() == "size": # Check if the command is "size"
                print("Size: " + str(stack.size())) # Print the size of the stack
            elif parts[0].lower() == "isEmpty": # Check if the command is "isEmpty"
                print("Is empty: " + str(stack.isEmpty())) # Print whether the stack is empty or not
            else:
                print("Unknown command: " + parts[0]) # Print an error message for unknown commands
        except Exception as e: # Catch any exceptions thrown
            print("Error: " + str(e)) # Print the error message

