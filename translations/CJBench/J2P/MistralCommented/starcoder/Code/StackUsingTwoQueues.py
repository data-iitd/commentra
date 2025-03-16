
class Main:
    # Initialize two queues, mainQueue and tempQueue
    mainQueue = []
    tempQueue = []
    
    def __init__(self):
        # Constructor initializes the mainQueue and tempQueue
        pass
    
    def push(self, item):
        # Add the new item to the tempQueue
        tempQueue.append(item)
        
        # Swap the queues
        swap = mainQueue
        mainQueue = tempQueue
        tempQueue = swap
        
        # Update the comments accordingly
        # Swap the mainQueue and tempQueue
    
    def pop(self):
        # Check if the mainQueue is empty
        if (mainQueue == []):
            raise Exception("Stack is empty")
        
        # Remove and return the head of the mainQueue
        return mainQueue.pop()
    
    def peek(self):
        # Check if the mainQueue is empty
        if (mainQueue == []):
            return None
        
        # Return the head of the mainQueue without removing it
        return mainQueue[0]
    
    def isEmpty(self):
        # Check if the mainQueue is empty
        return mainQueue == []
    
    def size(self):
        # Return the size of the mainQueue
        return len(mainQueue)

# Create an instance of the Main class
stack = Main()

# Read the number of operations from the user
n = int(input())

# Process each operation
for i in range(n):
    operation = input()
    
    if (operation == "push"):
        # Read the value to be pushed from the user
        value = int(input())
        
        # Call the push method with the value
        stack.push(value)
        
        # Print the message to the user
        print("Pushed: " + str(value))
    elif (operation == "pop"):
        try:
            # Call the pop method and print the popped value to the user
            print("Popped: " + str(stack.pop()))
        except Exception as e:
            # Print the error message to the user
            print("Error: " + str(e))
    elif (operation == "peek"):
        # Call the peek method and print the top element to the user
        top = stack.peek()
        if (top!= None):
            print("Top element: " + str(top))
        else:
            # Print the message if the stack is empty
            print("Stack is empty")
    elif (operation == "isEmpty"):
        # Print the result of the isEmpty method to the user
        print("Is stack empty? " + str(stack.isEmpty()))
    elif (operation == "size"):
        # Print the result of the size method to the user
        print("Stack size: " + str(stack.size()))
    else:
        # Print the message for invalid operations
        print("Invalid operation")

# 