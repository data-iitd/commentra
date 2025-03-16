
class Main:
    # Default capacity for the stack
    DEFAULT_CAPACITY = 10
    maxSize = 0  # Maximum size of the stack
    stackArray = []  # Array to hold stack elements
    top = -1  # Index of the top element in the stack

    # Default constructor initializing stack with default capacity
    def __init__(self):
        self.maxSize = Main.DEFAULT_CAPACITY
        self.stackArray = [None] * self.maxSize
        self.top = -1

    # Constructor to initialize stack with a specified size
    def __init__(self, size):
        # Validate the size to ensure it's greater than 0
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")
        self.maxSize = size
        self.stackArray = [None] * self.maxSize
        self.top = -1

    # Method to add an element to the top of the stack
    def push(self, value):
        # Resize the stack if it is full
        if self.isFull():
            self.resize(self.maxSize * 2)
        self.stackArray[self.top + 1] = value
        self.top += 1

    # Method to remove and return the top element of the stack
    def pop(self):
        # Check if the stack is empty before popping
        if self.isEmpty():
            raise IllegalStateException("Stack is empty, cannot pop element")
        value = self.stackArray[self.top]
        self.stackArray[self.top] = None
        self.top -= 1
        # Resize the stack if it is less than a quarter full
        if self.top + 1 < self.maxSize / 4 and self.maxSize > Main.DEFAULT_CAPACITY:
            self.resize(self.maxSize / 2)
        return value

    # Method to return the top element without removing it
    def peek(self):
        # Check if the stack is empty before peeking
        if self.isEmpty():
            raise IllegalStateException("Stack is empty, cannot peek element")
        return self.stackArray[self.top]

    # Method to resize the stack array to a new size
    def resize(self, newSize):
        newArray = [None] * newSize
        for i in range(self.top + 1):
            newArray[i] = self.stackArray[i]
        self.stackArray = newArray
        self.maxSize = newSize

    # Method to check if the stack is full
    def isFull(self):
        return self.top + 1 == self.maxSize

    # Method to check if the stack is empty
    def isEmpty(self):
        return self.top == -1

    # Method to clear the stack
    def makeEmpty(self):
        self.top = -1

    # Method to return the current size of the stack
    def size(self):
        return self.top + 1

    # Method to return a string representation of the stack
    def __str__(self):
        sb = ""
        sb += "Main ["
        # Append each element in the stack to the string builder
        for i in range(self.top + 1):
            sb += str(self.stackArray[i])
            if i < self.top:
                sb += ", "
        sb += "]"
        return sb

    # Main method to run the stack operations
    def main(self):
        scanner = Scanner(System.in)  # Create a scanner for user input
        stack = Main()  # Create a new stack instance
        # Loop to process user commands
        while scanner.hasNextLine():
            command = scanner.nextLine().trim()  # Read the command
            if command.equalsIgnoreCase("exit"):
                break  # Exit the loop if the command is "exit"
            try:
                parts = command.split(" ")  # Split command into parts
                if parts[0] == "push":
                    # Check for missing value in push command
                    if len(parts) < 2:
                        print("Error: Missing value for push")
                        break
                    value = int(parts[1])  # Parse the value to push
                    stack.push(value)  # Push the value onto the stack
                    print("Pushed: " + str(value))  # Confirm the push
                elif parts[0] == "pop":
                    print("Popped: " + str(stack.pop()))  # Pop and display the top value
                elif parts[0] == "peek":
                    print("Top: " + str(stack.peek()))  # Display the top value without popping
                elif parts[0] == "size":
                    print("Size: " + str(stack.size()))  # Display the current size of the stack
                elif parts[0] == "isEmpty":
                    print("Is empty: " + str(stack.isEmpty()))  # Check if the stack is empty
                else:
                    print("Error: Unknown command")  # Handle unknown commands
            except Exception as e:
                print("Error: " + str(e.getMessage()))  # Handle exceptions and display error messages
        scanner.close()  # Close the scanner resource


