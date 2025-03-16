

class LinkedListStack:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, x):
        newNode = Node(x)
        newNode.next = self.head
        self.head = newNode
        self.size += 1

    def pop(self):
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to pop")
        value = self.head.data
        self.head = self.head.next
        self.size -= 1
        return value

    def peek(self):
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to peek")
        return self.head.data

    def isEmpty(self):
        return self.size == 0

    def getSize(self):
        return self.size

    def makeEmpty(self):
        self.head = None
        self.size = 0

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Initialize an empty stack using LinkedListStack
stack = LinkedListStack()

# Initialize a Scanner to read input from the user
import sys

# Read the number of operations from the user
operations = int(input())

# Perform each operation
for i in range(operations):
    choice = int(input())

    # Switch on the user's choice and perform the corresponding operation
    if choice == 1:
        # Read an integer value from the user and push it onto the stack
        value = int(input())
        stack.push(value)
        print("Pushed", value)
    elif choice == 2:
        try:
            # Pop an integer value from the stack and print it
            popped = stack.pop()
            print("Popped", popped)
        except NoSuchElementException as e:
            # If the stack is empty, print an error message
            print(e)
    elif choice == 3:
        try:
            # Peek at the top element of the stack and print it
            peeked = stack.peek()
            print("Top element:", peeked)
        except NoSuchElementException as e:
            # If the stack is empty, print an error message
            print(e)
    elif choice == 4:
        # Print the size of the stack
        print("Stack size:", stack.getSize())
    elif choice == 5:
        # Print whether the stack is empty or not
        print("Is stack empty?", stack.isEmpty())
    elif choice == 6:
        # Clear the stack
        stack.makeEmpty()
        print("Stack cleared.")
    else:
        # If the user's choice is invalid, print an error message
        print("Invalid choice.")

