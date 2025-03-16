class Stack:
    # Default capacity for the stack
    DEFAULT_CAPACITY = 10

    def __init__(self, size=None):
        # Initialize stack with default capacity if no size is provided
        if size is None:
            size = self.DEFAULT_CAPACITY
        # Validate the size to ensure it's greater than 0
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")
        self.max_size = size  # Set the maximum size
        self.stack_array = [None] * size  # Initialize the stack array
        self.top = -1  # Initialize top index

    # Method to add an element to the top of the stack
    def push(self, value):
        # Resize the stack if it is full
        if self.is_full():
            self.resize(self.max_size * 2)
        self.top += 1  # Increment top
        self.stack_array[self.top] = value  # Add the new value

    # Method to remove and return the top element of the stack
    def pop(self):
        # Check if the stack is empty before popping
        if self.is_empty():
            raise IndexError("Stack is empty, cannot pop element")
        value = self.stack_array[self.top]  # Retrieve the top value
        self.top -= 1  # Decrement top
        # Resize the stack if it is less than a quarter full
        if self.top + 1 < self.max_size // 4 and self.max_size > self.DEFAULT_CAPACITY:
            self.resize(self.max_size // 2)
        return value  # Return the popped value

    # Method to return the top element without removing it
    def peek(self):
        # Check if the stack is empty before peeking
        if self.is_empty():
            raise IndexError("Stack is empty, cannot peek element")
        return self.stack_array[self.top]  # Return the top value

    # Method to resize the stack array to a new size
    def resize(self, new_size):
        new_array = [None] * new_size  # Create a new array
        for i in range(self.top + 1):
            new_array[i] = self.stack_array[i]  # Copy elements to the new array
        self.stack_array = new_array  # Update the stack array reference
        self.max_size = new_size  # Update the maximum size

    # Method to check if the stack is full
    def is_full(self):
        return self.top + 1 == self.max_size  # Return true if top index is equal to max size

    # Method to check if the stack is empty
    def is_empty(self):
        return self.top == -1  # Return true if top index is -1

    # Method to clear the stack
    def make_empty(self):
        self.top = -1  # Reset top index to -1

    # Method to return the current size of the stack
    def size(self):
        return self.top + 1  # Return the number of elements in the stack

    # Method to return a string representation of the stack
    def __str__(self):
        return "Stack [" + ", ".join(str(self.stack_array[i]) for i in range(self.top + 1)) + "]"

# Main function to run the stack operations
if __name__ == "__main__":
    import sys

    stack = Stack()  # Create a new stack instance
    # Loop to process user commands
    for line in sys.stdin:
        command = line.strip()  # Read the command
        if command.lower() == "exit":
            break  # Exit the loop if the command is "exit"
        try:
            parts = command.split(" ")  # Split command into parts
            if parts[0] == "push":
                # Check for missing value in push command
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])  # Parse the value to push
                stack.push(value)  # Push the value onto the stack
                print(f"Pushed: {value}")  # Confirm the push
            elif parts[0] == "pop":
                print(f"Popped: {stack.pop()}")  # Pop and display the top value
            elif parts[0] == "peek":
                print(f"Top: {stack.peek()}")  # Display the top value without popping
            elif parts[0] == "size":
                print(f"Size: {stack.size()}")  # Display the current size of the stack
            elif parts[0] == "isEmpty":
                print(f"Is empty: {stack.is_empty()}")  # Check if the stack is empty
            else:
                print("Error: Unknown command")  # Handle unknown commands
        except Exception as e:
            print(f"Error: {e}")  # Handle exceptions and display error messages

# <END-OF-CODE>
