class Stack:
    def __init__(self):
        # Initialize an empty list to represent the stack
        self.stack = []
        print("Created a new stack.")

    def push(self, value):
        # Add the given value to the stack
        self.stack.append(value)
        print(f"Pushed {value}")

    def pop(self):
        # Check if the stack is empty before attempting to pop
        if self.is_empty():
            print("Stack is empty. Cannot pop.")
            raise IndexError("pop from empty stack")

        # Remove and return the last element of the stack
        removed = self.stack.pop()
        return removed

    def peek(self):
        # Check if the stack is empty before attempting to peek
        if self.is_empty():
            print("Stack is empty. Cannot peek.")
            raise IndexError("peek from empty stack")

        # Get and return the last element of the stack without removing it
        top = self.stack[-1]
        return top

    def is_empty(self):
        # Check if the stack is empty
        return len(self.stack) == 0

    def make_empty(self):
        # Clear the stack and print a message
        self.stack.clear()
        print("Stack cleared.")

    def size(self):
        # Get the size of the stack and print a message
        size = len(self.stack)
        print(f"Stack size: {size}")
        return size


def main():
    # Create a new instance of the Stack class to represent the stack
    stack = Stack()

    # Read the number of operations from the console
    operations = int(input("Enter number of operations: "))
    print(f"Number of operations: {operations}")

    # Process each operation
    for _ in range(operations):
        choice = int(input("Enter operation choice: "))

        # Switch on the choice and perform the corresponding operation
        if choice == 1:
            value = int(input("Enter value to push: "))
            stack.push(value)
        elif choice == 2:
            try:
                stack.pop()
            except IndexError:
                print("Stack is empty. Cannot pop.")
        elif choice == 3:
            try:
                top_value = stack.peek()
                print(f"Top value: {top_value}")
            except IndexError:
                print("Stack is empty. Cannot peek.")
        elif choice == 4:
            stack.size()
        elif choice == 5:
            stack.make_empty()
        elif choice == 6:
            print("Is stack empty?", stack.is_empty())
        else:
            print("Invalid choice. Try again.")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
