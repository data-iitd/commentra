

class Main:
    def __init__(self):
        self.mainQueue = [] # Queue to hold the main stack elements
        self.tempQueue = [] # Temporary queue used during push operation

    # Method to add an item to the stack
    def push(self, item):
        # Add the item to the tempQueue
        self.tempQueue.append(item)
        # Transfer all items from mainQueue to tempQueue
        while self.mainQueue:
            self.tempQueue.append(self.mainQueue.pop())
        # Swap mainQueue and tempQueue to maintain the correct order
        self.mainQueue, self.tempQueue = self.tempQueue, self.mainQueue

    # Method to remove and return the top element of the stack
    def pop(self):
        if not self.mainQueue:
            raise IndexError("Stack is empty")
        return self.mainQueue.pop()

    # Method to return the top element of the stack without removing it
    def peek(self):
        if not self.mainQueue:
            return None
        return self.mainQueue[-1]

    # Method to check if the stack is empty
    def isEmpty(self):
        return not self.mainQueue

    # Method to return the size of the stack
    def size(self):
        return len(self.mainQueue)

# Main method to provide a command-line interface for interacting with the stack
if __name__ == "__main__":
    stack = Main()
    n = int(input("Enter the number of operations: ")) # Read the number of operations
    for _ in range(n):
        operation = input("Enter the operation type (push/pop/peek/isEmpty/size): ") # Read the operation type
        if operation == "push":
            value = int(input("Enter the value to push: ")) # Read the value to push
            stack.push(value)
            print(f"Pushed: {value}") # Print the pushed value
        elif operation == "pop":
            try:
                print(f"Popped: {stack.pop()}") # Print the popped value
            except IndexError as e:
                print(f"Error: {e}") # Print the error message
        elif operation == "peek":
            top = stack.peek() # Get the top element
            if top is not None:
                print(f"Top element: {top}") # Print the top element
            else:
                print("Stack is empty") # Print stack empty message
        elif operation == "isEmpty":
            print(f"Is stack empty? {stack.isEmpty()}") # Print if stack is empty
        elif operation == "size":
            print(f"Stack size: {stack.size()}") # Print the stack size
        else:
            print("Invalid operation") # Print invalid operation message

This code now includes comments that explain each logical block, making it easier to understand the functionality of the `Main` class.