

class Main:
    def __init__(self):
        self.mainQueue = []
        self.tempQueue = []
        # Constructor initializes the mainQueue and tempQueue

    def push(self, item):
        # Add the new item to the tempQueue
        self.tempQueue.append(item)
        
        # Swap the queues
        self.mainQueue, self.tempQueue = self.tempQueue, self.mainQueue
        
        # Update the comments accordingly
        # Swap the mainQueue and tempQueue

    def pop(self):
        # Check if the mainQueue is empty
        if not self.mainQueue:
            raise IndexError("Stack is empty")
        
        # Remove and return the head of the mainQueue
        return self.mainQueue.pop()

    def peek(self):
        # Check if the mainQueue is empty
        if not self.mainQueue:
            return None
        
        # Return the head of the mainQueue without removing it
        return self.mainQueue[-1]

    def isEmpty(self):
        # Check if the mainQueue is empty
        return not self.mainQueue

    def size(self):
        # Return the size of the mainQueue
        return len(self.mainQueue)

if __name__ == "__main__":
    # Create an instance of the Main class
    stack = Main()
    
    n = int(input("Enter the number of operations: "))
    
    # Process each operation
    for _ in range(n):
        operation = input("Enter the operation (push/pop/peek/isEmpty/size): ")
        
        if operation == "push":
            # Read the value to be pushed from the user
            value = int(input("Enter the value to be pushed: "))
            
            # Call the push method with the value
            stack.push(value)
            
            # Print the message to the user
            print(f"Pushed: {value}")
        elif operation == "pop":
            try:
                # Call the pop method and print the popped value to the user
                print(f"Popped: {stack.pop()}")
            except IndexError:
                # Print the error message to the user
                print("Error: Stack is empty")
        elif operation == "peek":
            # Call the peek method and print the top element to the user
            top = stack.peek()
            if top is not None:
                print(f"Top element: {top}")
            else:
                # Print the message if the stack is empty
                print("Stack is empty")
        elif operation == "isEmpty":
            # Print the result of the isEmpty method to the user
            print(f"Is stack empty? {stack.isEmpty()}")
        elif operation == "size":
            # Print the result of the size method to the user
            print(f"Stack size: {stack.size()}")
        else:
            # Print the message for invalid operations
            print("Invalid operation")

Translate the above Python code to C++ and end with comment "