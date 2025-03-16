import sys

class Main:
    # Declare an ArrayList to represent the stack
    stack = []

    # Constructor to initialize the stack
    def __init__(self):
        self.stack = []

    # Method to push a value onto the stack
    def push(self, value):
        self.stack.append(value) # Add the value to the end of the list
        print("Pushed " + str(value)) # Print confirmation of the push operation

    # Method to pop a value from the stack
    def pop(self):
        # Check if the stack is empty before popping
        if len(self.stack) == 0:
            raise Exception("Stack is empty. Cannot pop.") # Throw exception if stack is empty
        removed = self.stack.pop() # Remove the last element
        print("Popped " + str(removed)) # Print confirmation of the pop operation
        return removed # Return the removed value

    # Method to peek at the top value of the stack without removing it
    def peek(self):
        # Check if the stack is empty before peeking
        if len(self.stack) == 0:
            raise Exception("Stack is empty. Cannot peek.") # Throw exception if stack is empty
        top = self.stack[len(self.stack) - 1] # Get the last element
        print("Top element: " + str(top)) # Print the top element
        return top # Return the top element

    # Method to check if the stack is empty
    def isEmpty(self):
        return len(self.stack) == 0 # Return true if the stack is empty

    # Method to clear the stack
    def makeEmpty(self):
        self.stack = [] # Clear all elements from the stack
        print("Stack cleared.") # Print confirmation of the clear operation

    # Method to get the current size of the stack
    def size(self):
        size = len(self.stack) # Get the size of the stack
        print("Stack size: " + str(size)) # Print the size of the stack
        return size # Return the size

# Main method to execute the stack operations
def main():
    operations = int(sys.stdin.readline()) # Read the number of operations to perform

    # Loop through the number of operations
    for i in range(operations):
        choice = int(sys.stdin.readline()) # Read the user's choice of operation
        if choice == 1: # Push operation
            value = int(sys.stdin.readline()) # Read the value to push
            stack.push(value) # Call the push method
        elif choice == 2: # Pop operation
            try:
                stack.pop() # Attempt to pop the top value
            except Exception as e:
                print("Stack is empty. Cannot pop.") # Handle empty stack case
        elif choice == 3: # Peek operation
            try:
                stack.peek() # Attempt to peek at the top value
            except Exception as e:
                print("Stack is empty. Cannot peek.") # Handle empty stack case
        elif choice == 4: # Size operation
            stack.size() # Call the size method
        elif choice == 5: # Clear operation
            stack.makeEmpty() # Call the makeEmpty method
        elif choice == 6: # Check if the stack is empty
            print("Is stack empty? " + str(stack.isEmpty())) # Print whether the stack is empty
        else: # Handle invalid choices
            print("Invalid choice. Try again.") # Print error message for invalid choice

if __name__ == "__main__":
    stack = Main() # Create an instance of the stack
    main() # Call the main method

