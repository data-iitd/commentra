
import sys

class Main:
    # Initialize two stacks for input and output elements
    inStack = []
    outStack = []

    def __init__(self):
        # Initialize the constructor
        pass

    def insert(self, x):
        # Push the given object into the input stack
        self.inStack.append(x)

    def remove(self):
        # If the output stack is empty, transfer all elements from input stack to output stack
        if len(self.outStack) == 0:
            while len(self.inStack) > 0:
                self.outStack.append(self.inStack.pop())
        # If there is an element in the output stack, pop it and return it
        if len(self.outStack) > 0:
            return self.outStack.pop()
        # If the queue is empty, return a message
        return "Queue is empty"

    def peekFront(self):
        # If the output stack is empty, transfer all elements from input stack to output stack
        if len(self.outStack) == 0:
            while len(self.inStack) > 0:
                self.outStack.append(self.inStack.pop())
        # If there is an element in the output stack, return a reference to it without popping it
        if len(self.outStack) > 0:
            return self.outStack[len(self.outStack) - 1]
        # If the queue is empty, return a message
        return "Queue is empty"

    def peekBack(self):
        # If the input stack is not empty, return a reference to the top element
        if len(self.inStack) > 0:
            return self.inStack[len(self.inStack) - 1]
        # If the queue is empty, return a message
        return "Queue is empty"

    def isEmpty(self):
        # Return true if both input and output stacks are empty
        return (len(self.inStack) == 0 and len(self.outStack) == 0)

if __name__ == "__main__":
    main = Main() # Create an instance of the Main class
    operations = int(sys.stdin.readline()) # Read the number of operations from the standard input
    for i in range(operations):
        command = sys.stdin.readline().split(" ") # Read a line from the standard input and split it into words
        cmd = command[0] # Get the command name

        if cmd == "INSERT":
            main.insert(int(command[1]))
        elif cmd == "REMOVE":
            print(main.remove())
        elif cmd == "PEEK_FRONT":
            print(main.peekFront())
        elif cmd == "PEEK_BACK":
            print(main.peekBack())
        elif cmd == "IS_EMPTY":
            print(main.isEmpty())
        else:
            print("Invalid command")

