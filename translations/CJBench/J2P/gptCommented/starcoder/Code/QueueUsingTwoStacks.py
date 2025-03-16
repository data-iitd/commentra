import sys

class Main:
    # Declare two stacks to simulate queue behavior
    inStack = []  # Stack for incoming elements
    outStack = [] # Stack for outgoing elements

    # Constructor to initialize the stacks
    def __init__(self):
        self.inStack = []
        self.outStack = []

    # Method to insert an element into the queue
    def insert(self, x):
        self.inStack.append(x) # Push the element onto the inStack

    # Method to remove and return the front element of the queue
    def remove(self):
        # If outStack is empty, transfer elements from inStack to outStack
        if len(self.outStack) == 0:
            while len(self.inStack) > 0:
                self.outStack.append(self.inStack.pop())
        # If outStack is not empty, pop and return the top element
        if len(self.outStack) > 0:
            return self.outStack.pop()
        return "Queue is empty" # Return message if queue is empty

    # Method to peek at the front element of the queue without removing it
    def peekFront(self):
        # If outStack is empty, transfer elements from inStack to outStack
        if len(self.outStack) == 0:
            while len(self.inStack) > 0:
                self.outStack.append(self.inStack.pop())
        # If outStack is not empty, return the top element without removing it
        if len(self.outStack) > 0:
            return self.outStack[-1]
        return "Queue is empty" # Return message if queue is empty

    # Method to peek at the back element of the queue without removing it
    def peekBack(self):
        # Return the top element of inStack if it is not empty
        if len(self.inStack) > 0:
            return self.inStack[-1]
        return "Queue is empty" # Return message if queue is empty

    # Method to check if the queue is empty
    def isEmpty(self):
        return (len(self.inStack) == 0 and len(self.outStack) == 0) # Return true if both stacks are empty

# Main method to execute the program
if __name__ == "__main__":
    # Read the number of operations to perform
    operations = int(sys.stdin.readline())
    # Loop through the number of operations
    for i in range(operations):
        command = sys.stdin.readline().split(" ") # Read and split the command input
        if command[0] == "INSERT":
            queue.insert(int(command[1])) # Insert the specified element
        elif command[0] == "REMOVE":
            print(queue.remove()) # Remove and print the front element
        elif command[0] == "PEEK_FRONT":
            print(queue.peekFront()) # Print the front element without removing it
        elif command[0] == "PEEK_BACK":
            print(queue.peekBack()) # Print the back element without removing it
        elif command[0] == "IS_EMPTY":
            print(queue.isEmpty()) # Print whether the queue is empty
        else:
            print("Invalid command") # Handle invalid commands

