
class Main:
    # Declare two queues to simulate stack behavior
    mainQueue = []
    tempQueue = []

    # Constructor to initialize the queues
    def __init__(self):
        self.mainQueue = []
        self.tempQueue = []

    # Method to push an item onto the stack
    def push(self, item):
        # Add the new item to the temporary queue
        self.tempQueue.append(item)
        
        # Move all elements from the main queue to the temporary queue
        while len(self.mainQueue) > 0:
            self.tempQueue.append(self.mainQueue.pop())
        
        # Swap the references of the main queue and the temporary queue
        self.mainQueue, self.tempQueue = self.tempQueue, self.mainQueue

    # Method to pop an item from the stack
    def pop(self):
        # Check if the main queue is empty and throw an exception if it is
        if len(self.mainQueue) == 0:
            raise Exception("Stack is empty")
        # Remove and return the top item from the main queue
        return self.mainQueue.pop()

    # Method to peek at the top item of the stack without removing it
    def peek(self):
        # If the main queue is empty, return null
        if len(self.mainQueue) == 0:
            return None
        # Return the top item of the main queue
        return self.mainQueue[len(self.mainQueue) - 1]

    # Method to check if the stack is empty
    def isEmpty(self):
        # Return true if the main queue is empty, false otherwise
        return len(self.mainQueue) == 0

    # Method to get the size of the stack
    def size(self):
        # Return the size of the main queue
        return len(self.mainQueue)

# Main method to run the program
if __name__ == "__main__":
    # Create an instance of the Main class (stack)
    stack = Main()
    scanner = Scanner(System.in)
    
    # Read the number of operations to perform
    n = scanner.nextInt() 
    
    # Loop through the number of operations
    for i in range(n):
        # Read the operation type
        operation = scanner.next()
        if operation == "push":
            # Read the value to push onto the stack
            value = scanner.nextInt()
            stack.push(value)
            print("Pushed: " + str(value))
        elif operation == "pop":
            # Attempt to pop an item from the stack and handle exceptions
            try:
                print("Popped: " + str(stack.pop()))
            except Exception as e:
                print("Error: " + str(e))
        elif operation == "peek":
            # Peek at the top item of the stack
            top = stack.peek()
            if top!= None:
                print("Top element: " + str(top))
            else:
                print("Stack is empty")
        elif operation == "isEmpty":
            # Check if the stack is empty
            print("Is stack empty? " + str(stack.isEmpty()))
        elif operation == "size":
            # Get the size of the stack
            print("Stack size: " + str(stack.size()))
        else:
            # Handle invalid operations
            print("Invalid operation")

# Close the scanner to prevent resource leaks
scanner.close()

