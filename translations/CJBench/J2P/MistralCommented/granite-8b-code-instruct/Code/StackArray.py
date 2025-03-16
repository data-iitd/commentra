

class Main:
    def __init__(self, size=10):
        # Validate size argument
        if size <= 0:
            raise ValueError("Stack size must be greater than 0")

        # Initialize instance variables
        self.maxSize = size
        self.stackArray = [None] * size
        self.top = -1

    def push(self, value):
        # Check if stack is full and resize if necessary
        if self.isFull():
            self.resize(self.maxSize * 2)

        # Increment top and add value to the stack
        self.top += 1
        self.stackArray[self.top] = value

    def pop(self):
        # Check if stack is empty and raise an exception if it is
        if self.isEmpty():
            raise IndexError("Stack is empty, cannot pop element")

        # Get the top element and decrement top
        value = self.stackArray[self.top]
        self.top -= 1

        # Check if stack size is less than half of the maximum size and resize if necessary
        if self.top + 1 < self.maxSize // 4 and self.maxSize > 10:
            self.resize(self.maxSize // 2)

        # Return the popped value
        return value

    def peek(self):
        # Check if stack is empty and raise an exception if it is
        if self.isEmpty():
            raise IndexError("Stack is empty, cannot peek element")

        # Return the top element
        return self.stackArray[self.top]

    def resize(self, newSize):
        # Allocate a new array with the given size
        newArray = [None] * newSize

        # Copy the elements from the old array to the new array
        for i in range(self.top + 1):
            newArray[i] = self.stackArray[i]

        # Update the stackArray and maxSize
        self.stackArray = newArray
        self.maxSize = newSize

    def isFull(self):
        return self.top + 1 == self.maxSize

    def isEmpty(self):
        return self.top == -1

    def makeEmpty(self):
        self.top = -1

    def size(self):
        return self.top + 1

    def __str__(self):
        return "Main [" + ", ".join(map(str, self.stackArray[:self.top + 1])) + "]"

# Main method to test the stack implementation
if __name__ == "__main__":
    stack = Main() # Create an instance of the Main class with Integer type

    while True:
        command = input("Enter command (exit to quit): ")
        if command.lower() == "exit":
            break
        try:
            parts = command.split()
            if parts[0].lower() == "push":
                # Validate command arguments and push the value to the stack
                if len(parts) < 2:
                    print("Error: Missing value for push")
                    continue
                value = int(parts[1])
                stack.push(value)
                print("Pushed:", value)
            elif parts[0].lower() == "pop":
                # Pop the top element from the stack and print it
                print("Popped:", stack.pop())
            elif parts[0].lower() == "peek":
                # Print the top element of the stack
                print("Top:", stack.peek())
            elif parts[0].lower() == "size":
                # Print the size of the stack
                print("Size:", stack.size())
            elif parts[0].lower() == "isempty":
                # Print whether the stack is empty or not
                print("Is empty:", stack.isEmpty())
            else:
                # Handle unknown commands
                print("Error: Unknown command")
        except Exception as e:
            # Print error messages for exceptions
            print("Error:", e)

