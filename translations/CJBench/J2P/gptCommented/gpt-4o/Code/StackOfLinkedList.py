class Node:
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.next = None  # Reference to the next node in the stack

class LinkedListStack:
    def __init__(self):
        self.head = None  # Head of the linked list representing the stack
        self.size = 0     # Current size of the stack

    def push(self, x):
        new_node = Node(x)  # Create a new node with the given value
        new_node.next = self.head  # Point the new node to the current head
        self.head = new_node  # Update the head to the new node
        self.size += 1  # Increment the size of the stack

    def pop(self):
        if self.size == 0:
            raise Exception("Empty stack. Nothing to pop")  # Raise exception if stack is empty
        value = self.head.data  # Get the value of the top node
        self.head = self.head.next  # Update the head to the next node
        self.size -= 1  # Decrement the size of the stack
        return value  # Return the popped value

    def peek(self):
        if self.size == 0:
            raise Exception("Empty stack. Nothing to peek")  # Raise exception if stack is empty
        return self.head.data  # Return the value of the top node without removing it

    def is_empty(self):
        return self.size == 0  # Return True if size is 0, otherwise False

    def get_size(self):
        return self.size  # Return the current size of the stack

    def make_empty(self):
        self.head = None  # Set head to None to remove all nodes
        self.size = 0  # Reset size to 0

def main():
    stack = LinkedListStack()  # Create a new instance of LinkedListStack
    operations = int(input("Enter number of operations: "))  # Read the number of operations

    for _ in range(operations):
        choice = int(input("Enter operation choice: "))  # Read user's choice of operation
        if choice == 1:
            value = int(input("Enter value to push: "))  # Push a new value onto the stack
            stack.push(value)
            print(f"Pushed {value}")
        elif choice == 2:
            try:
                popped = stack.pop()  # Pop the top value from the stack
                print(f"Popped {popped}")
            except Exception as e:
                print(e)  # Print error message if the stack is empty
        elif choice == 3:
            try:
                peeked = stack.peek()  # Peek at the top value of the stack
                print(f"Top element: {peeked}")
            except Exception as e:
                print(e)  # Print error message if the stack is empty
        elif choice == 4:
            print(f"Stack size: {stack.get_size()}")  # Get and print the current size of the stack
        elif choice == 5:
            print(f"Is stack empty? {stack.is_empty()}")  # Check if the stack is empty
        elif choice == 6:
            stack.make_empty()  # Clear the stack of all elements
            print("Stack cleared.")
        else:
            print("Invalid choice.")  # Handle invalid choices

if __name__ == "__main__":
    main()  # Run the main function

# <END-OF-CODE>
