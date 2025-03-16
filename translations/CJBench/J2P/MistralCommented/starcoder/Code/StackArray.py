
# Class definition for Main with generic type T
class Main:

    # Declare private constants and instance variables
    DEFAULT_CAPACITY = 10
    maxSize = 0
    stackArray = []
    top = -1

    # Constructor without arguments
    def __init__(self):
        self.maxSize = DEFAULT_CAPACITY
        self.stackArray = [None] * self.maxSize

    # Constructor with given size
    def __init__(self, size):
        # Validate size argument
        if size <= 0:
            raise Exception("Stack size must be greater than 0")

        # Initialize instance variables
        self.maxSize = size
        self.stackArray = [None] * self.maxSize
        self.top = -1

    # Push method to add an element to the stack
    def push(self, value):
        # Check if stack is full and resize if necessary
        if self.isFull():
            self.resize(self.maxSize * 2)

        # Increment top and add value to the stack
        self.stackArray[self.top + 1] = value
        self.top += 1

    # Pop method to remove and return the top element from the stack
    def pop(self):
        # Check if stack is empty and throw an exception if it is
        if self.isEmpty():
            raise Exception("Stack is empty, cannot pop element")

        # Get the top element and decrement top
        value = self.stackArray[self.top]
        self.top -= 1

        # Check if stack size is less than half of the maximum size and resize if necessary
        if self.top + 1 < self.maxSize / 4 and self.maxSize > DEFAULT_CAPACITY:
            self.resize(self.maxSize / 2)

        # Return the popped value
        return value

    # Peek method to return the top element without removing it from the stack
    def peek(self):
        # Check if stack is empty and throw an exception if it is
        if self.isEmpty():
            raise Exception("Stack is empty, cannot peek element")

        # Return the top element
        return self.stackArray[self.top]

    # Resize method to increase the size of the stackArray
    def resize(self, newSize):
        # Allocate a new array with the given size
        newArray = [None] * newSize

        # Copy the elements from the old array to the new array
        for i in range(self.top + 1):
            newArray[i] = self.stackArray[i]

        # Update the stackArray and maxSize
        self.stackArray = newArray
        self.maxSize = newSize

    # Check if the stack is full
    def isFull(self):
        return self.top + 1 == self.maxSize

    # Check if the stack is empty
    def isEmpty(self):
        return self.top == -1

    # Make the stack empty
    def makeEmpty(self):
        self.top = -1

    # Get the size of the stack
    def size(self):
        return self.top + 1

    # Override toString method to print the stack elements
    def __str__(self):
        sb = []
        sb.append("Main [")

        # Iterate through the stack and append each element to the StringBuilder
        for i in range(self.top + 1):
            sb.append(self.stackArray[i])
            if i < self.top:
                sb.append(", ")

        sb.append("]")
        return "".join(sb)

    # Main method to test the stack implementation
    def main(self):
        scanner = Scanner(System.in)
        stack = Main() # Create an instance of the Main class with Integer type

        # Read user input and process the commands
        while scanner.hasNextLine():
            command = scanner.nextLine().trim()
            if command.equalsIgnoreCase("exit"):
                break
            try:
                parts = command.split(" ")
                if parts[0] == "push":
                    # Validate command arguments and push the value to the stack
                    if len(parts) < 2:
                        print("Error: Missing value for push")
                        break
                    value = int(parts[1])
                    stack.push(value)
                    print("Pushed: " + value)
                elif parts[0] == "pop":
                    # Pop the top element from the stack and print it
                    print("Popped: " + stack.pop())
                elif parts[0] == "peek":
                    # Print the top element of the stack
                    print("Top: " + stack.peek())
                elif parts[0] == "size":
                    # Print the size of the stack
                    print("Size: " + stack.size())
                elif parts[0] == "isEmpty":
                    # Print whether the stack is empty or not
                    print("Is empty: " + stack.isEmpty())
                else:
                    # Handle unknown commands
            except Exception as e:
                # Print error messages for exceptions
                print("Error: " + e.getMessage())

        # Close the scanner
        scanner.close()

