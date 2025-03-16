
# Default capacity for the stack
DEFAULT_CAPACITY = 10

class Main:
    # Constructor to initialize stack with a specified size
    def __init__(self, size=DEFAULT_CAPACITY):
        # Validate the size to ensure it's greater than 0
        if size <= 0:
            raise Exception("Stack size must be greater than 0")
        self.maxSize = size # Set the maximum size
        self.stackArray = [None] * size # Initialize the stack array
        self.top = -1 # Initialize top index

    # Method to add an element to the top of the stack
    def push(self, value):
        # Resize the stack if it is full
        if self.isFull():
            self.resize(self.maxSize * 2)
        self.stackArray[self.top + 1] = value # Add the new value and increment top

    # Method to remove and return the top element of the stack
    def pop(self):
        # Check if the stack is empty before popping
        if self.isEmpty():
            raise Exception("Stack is empty, cannot pop element")
        value = self.stackArray[self.top] # Retrieve the top value and decrement top
        # Resize the stack if it is less than a quarter full
        if self.top + 1 < self.maxSize / 4 and self.maxSize > DEFAULT_CAPACITY:
            self.resize(self.maxSize / 2)
        self.top -= 1 # Decrement top
        return value # Return the popped value

    # Method to return the top element without removing it
    def peek(self):
        # Check if the stack is empty before peeking
        if self.isEmpty():
            raise Exception("Stack is empty, cannot peek element")
        return self.stackArray[self.top] # Return the top value

    # Method to resize the stack array to a new size
    def resize(self, newSize):
        self.stackArray = self.stackArray[:self.top + 1] + [None] * (newSize - self.top - 1) # Create a new array
        self.maxSize = newSize # Update the maximum size

    # Method to check if the stack is full
    def isFull(self):
        return self.top + 1 == self.maxSize # Return true if top index is equal to max size

    # Method to check if the stack is empty
    def isEmpty(self):
        return self.top == -1 # Return true if top index is -1

    # Method to clear the stack
    def makeEmpty(self):
        self.top = -1 # Reset top index to -1

    # Method to return the current size of the stack
    def size(self):
        return self.top + 1 # Return the number of elements in the stack

    # Method to return a string representation of the stack
    def __str__(self):
        return "Main [" + ", ".join(str(x) for x in self.stackArray[:self.top + 1]) + "]" # Return the string representation

# Main method to run the stack operations
if __name__ == "__main__":
    import sys
    import re
    scanner = sys.stdin # Create a scanner for user input
    stack = Main() # Create a new stack instance
    # Loop to process user commands
    while True:
        command = scanner.readline().strip() # Read the command
        if command.lower() == "exit":
            break # Exit the loop if the command is "exit"
        try:
            parts = re.split("\\s+", command) # Split command into parts
            if parts[0].lower() == "push":
                # Check for missing value in push command
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1]) # Parse the value to push
                stack.push(value) # Push the value onto the stack
                print("Pushed: " + str(value)) # Confirm the push
            elif parts[0].lower() == "pop":
                print("Popped: " + str(stack.pop())) # Pop and display the top value
            elif parts[0].lower() == "peek":
                print("Top: " + str(stack.peek())) # Display the top value without popping
            elif parts[0].lower() == "size":
                print("Size: " + str(stack.size())) # Display the current size of the stack
            elif parts[0].lower() == "isEmpty":
                print("Is empty: " + str(stack.isEmpty())) # Check if the stack is empty
            else:
                print("Error: Unknown command") # Handle unknown commands
        except Exception as e:
            print("Error: " + str(e)) # Handle exceptions and display error messages

