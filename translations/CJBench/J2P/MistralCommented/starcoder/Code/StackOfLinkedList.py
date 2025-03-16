
import java.util.NoSuchElementException;
import java.util.Scanner;

class LinkedListStack:
    # Initialize the head node and size of the stack to null and 0, respectively
    head = None
    size = 0

    # Constructor for an empty stack
    def __init__(self):
        self.head = None
        self.size = 0

    # Add an integer value to the top of the stack
    def push(self, x):
        newNode = Node(x)

        # Connect the new node to the top of the stack
        newNode.next = self.head
        self.head = newNode

        # Increment the size of the stack
        self.size += 1

    # Remove and return the top element of the stack
    def pop(self):
        if self.size == 0:
            # If the stack is empty, throw an exception
            raise NoSuchElementException("Empty stack. Nothing to pop")

        # Store the top element in a variable and remove it from the stack
        value = self.head.data
        self.head = self.head.next

        # Decrement the size of the stack
        self.size -= 1

        # Return the popped value
        return value

    # Return the top element of the stack without removing it
    def peek(self):
        if self.size == 0:
            # If the stack is empty, throw an exception
            raise NoSuchElementException("Empty stack. Nothing to peek")

        # Return the data of the top node
        return self.head.data

    # Check if the stack is empty or not
    def isEmpty(self):
        # Return true if the size of the stack is 0, else false
        return self.size == 0

    # Return the size of the stack
    def getSize(self):
        # Return the size of the stack
        return self.size

    # Clear the stack
    def makeEmpty(self):
        self.head = None
        self.size = 0

class Node:
    data = None
    next = None

    # Constructor for a node with a given integer value
    def __init__(self, data):
        self.data = data
        self.next = None

# Initialize an empty stack using LinkedListStack
stack = LinkedListStack()

# Initialize a Scanner to read input from the user
scanner = Scanner(System.in)

# Read the number of operations from the user
operations = scanner.nextInt()

# Perform each operation
for i in range(operations):
    choice = scanner.nextInt()

    # Switch on the user's choice and perform the corresponding operation
    if choice == 1:
        # Read an integer value from the user and push it onto the stack
        value = scanner.nextInt()
        stack.push(value)
        print("Pushed " + value)
    elif choice == 2:
        try:
            # Pop an integer value from the stack and print it
            popped = stack.pop()
            print("Popped " + popped)
        except NoSuchElementException as e:
            # If the stack is empty, print an error message
            print(e.getMessage())
    elif choice == 3:
        try:
            # Peek at the top element of the stack and print it
            peeked = stack.peek()
            print("Top element: " + peeked)
        except NoSuchElementException as e:
            # If the stack is empty, print an error message
            print(e.getMessage())
    elif choice == 4:
        # Print the size of the stack
        print("Stack size: " + stack.getSize())
    elif choice == 5:
        # Print whether the stack is empty or not
        print("Is stack empty? " + stack.isEmpty())
    elif choice == 6:
        # Clear the stack
        stack.makeEmpty()
        print("Stack cleared.")
    else:
        # If the user's choice is invalid, print an error message
        print("Invalid choice.")

# Close the Scanner
scanner.close()

