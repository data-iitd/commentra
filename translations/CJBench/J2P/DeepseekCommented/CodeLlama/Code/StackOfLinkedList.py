
class LinkedListStack:
    def __init__(self):
        self.head = None
        self.size = 0

    def push(self, x):
        # Create a new node with the given value
        newNode = Node(x)
        # Set the new node's next reference to the current head
        newNode.next = self.head
        # Update the head to be the new node
        self.head = newNode
        # Increment the size of the stack
        self.size += 1

    def pop(self):
        # Check if the stack is empty and throw an exception if it is
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to pop")
        # Store the value of the head node
        value = self.head.data
        # Update the head to be the next node in the stack
        self.head = self.head.next
        # Decrement the size of the stack
        self.size -= 1
        # Return the stored value
        return value

    def peek(self):
        # Check if the stack is empty and throw an exception if it is
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to peek")
        # Return the value of the head node
        return self.head.data

    def isEmpty(self):
        # Return true if the stack is empty, false otherwise
        return self.size == 0

    def getSize(self):
        # Return the size of the stack
        return self.size

    def makeEmpty(self):
        # Set the head to null and the size to 0 to clear the stack
        self.head = None
        self.size = 0

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class NoSuchElementException(Exception):
    pass

# Test the stack
stack = LinkedListStack()
stack.push(1)
stack.push(2)
stack.push(3)
print(stack.peek())
print(stack.pop())
print(stack.pop())
print(stack.pop())
print(stack.isEmpty())
print(stack.getSize())
stack.makeEmpty()
print(stack.isEmpty())
print(stack.getSize())

