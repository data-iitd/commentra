
class Main:
    # Initialize two queues, mainQueue and tempQueue
    mainQueue = []
    tempQueue = []
    
    def __init__(self):
        # Constructor initializes the mainQueue and tempQueue
        pass
    
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
            raise ValueError("Stack is empty")
        
        # Remove and return the head of the mainQueue
        return self.mainQueue.pop(0)
    
    def peek(self):
        # Check if the mainQueue is empty
        if not self.mainQueue:
            return None
        
        # Return the head of the mainQueue without removing it
        return self.mainQueue[0]
    
    def isEmpty(self):
        # Check if the mainQueue is empty
        return not self.mainQueue
    
    def size(self):
        # Return the size of the mainQueue
        return len(self.mainQueue)
    
    def main():
        # Create an instance of the Main class
        stack = Main()
        
        # Read the number of operations from the user
        n = int(input())
        
        # Process each operation
        for i in range(n):
            operation = input()
            
            if operation == "push":
                # Read the value to be pushed from the user
                value = int(input())
                
                # Call the push method with the value
                stack.push(value)
                
                # Print the message to the user
                print("Pushed:", value)
            elif operation == "pop":
                try:
                    # Call the pop method and print the popped value to the user
                    print("Popped:", stack.pop())
                except ValueError as e:
                    # Print the error message to the user
                    print("Error:", e)
            elif operation == "peek":
                # Call the peek method and print the top element to the user
                top = stack.peek()
                if top is not None:
                    print("Top element:", top)
                else:
                    # Print the message if the stack is empty
                    print("Stack is empty")
            elif operation == "isEmpty":
                # Print the result of the isEmpty method to the user
                print("Is stack empty?", stack.isEmpty())
            elif operation == "size":
                # Print the result of the size method to the user
                print("Stack size:", stack.size())
            else:
                # Print the message for invalid operations
                print("Invalid operation")
    
    if __name__ == "__main__":
        main()
        print("