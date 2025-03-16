class Stack:
    def __init__(self):
        # Initialize the stack as an empty list
        self.stack = []

    def push(self, value):
        # Add the value to the end of the list
        self.stack.append(value)
        print(f"Pushed {value}")  # Print confirmation of the push operation

    def pop(self):
        # Check if the stack is empty before popping
        if self.is_empty():
            raise IndexError("Stack is empty. Cannot pop.")  # Raise exception if stack is empty
        removed = self.stack.pop()  # Remove the last element
        print(f"Popped {removed}")  # Print confirmation of the pop operation
        return removed  # Return the removed value

    def peek(self):
        # Check if the stack is empty before peeking
        if self.is_empty():
            raise IndexError("Stack is empty. Cannot peek.")  # Raise exception if stack is empty
        top = self.stack[-1]  # Get the last element
        print(f"Top element: {top}")  # Print the top element
        return top  # Return the top element

    def is_empty(self):
        # Return true if the stack is empty
        return len(self.stack) == 0

    def make_empty(self):
        # Clear all elements from the stack
        self.stack.clear()
        print("Stack cleared.")  # Print confirmation of the clear operation

    def size(self):
        # Get the size of the stack
        size = len(self.stack)
        print(f"Stack size: {size}")  # Print the size of the stack
        return size  # Return the size


def main():
    import sys

    stack = Stack()  # Create an instance of the stack
    operations = int(input("Enter number of operations: "))  # Read the number of operations to perform

    # Loop through the number of operations
    for _ in range(operations):
        choice = int(input("Enter operation choice (1-6): "))  # Read the user's choice of operation
        if choice == 1:  # Push operation
            value = int(input("Enter value to push: "))  # Read the value to push
            stack.push(value)  # Call the push method
        elif choice == 2:  # Pop operation
            try:
                stack.pop()  # Attempt to pop the top value
            except IndexError as e:
                print(e)  # Handle empty stack case
        elif choice == 3:  # Peek operation
            try:
                stack.peek()  # Attempt to peek at the top value
            except IndexError as e:
                print(e)  # Handle empty stack case
        elif choice == 4:  # Size operation
            stack.size()  # Call the size method
        elif choice == 5:  # Clear operation
            stack.make_empty()  # Call the makeEmpty method
        elif choice == 6:  # Check if the stack is empty
            print("Is stack empty?", stack.is_empty())  # Print whether the stack is empty
        else:  # Handle invalid choices
            print("Invalid choice. Try again.")  # Print error message for invalid choice


if __name__ == "__main__":
    main()  # Execute the main function

# <END-OF-CODE>
