
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
        # Check if the stack is empty and raise an exception if it is
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
        # Check if the stack is empty and raise an exception if it is
        if self.size == 0:
            raise NoSuchElementException("Empty stack. Nothing to peek")
        # Return the value of the head node
        return self.head.data

    def isEmpty(self):
        # Return True if the stack is empty, False otherwise
        return self.size == 0

    def getSize(self):
        # Return the size of the stack
        return self.size

    def makeEmpty(self):
        # Set the head to None and the size to 0 to clear the stack
        self.head = None
        self.size = 0

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Initialize a stack and a scanner for user input
stack = LinkedListStack()
scanner = Scanner(System.in)

# Read the number of operations
operations = scanner.nextInt()

# Loop through each operation
for i in range(operations):
    choice = scanner.nextInt()
    if choice == 1: 
        # Push a value onto the stack
        value = scanner.nextInt()
        stack.push(value)
        print("Pushed", value)
    elif choice == 2: 
        # Pop a value from the stack
        try:
            popped = stack.pop()
            print("Popped", popped)
        except NoSuchElementException as e:
            print(e.getMessage())
    elif choice == 3: 
        # Peek at the top value of the stack
        try:
            peeked = stack.peek()
            print("Top element:", peeked)
        except NoSuchElementException as e:
            print(e.getMessage())
    elif choice == 4: 
        # Get the size of the stack
        print("Stack size:", stack.getSize())
    elif choice == 5: 
        # Check if the stack is empty
        print("Is stack empty?", stack.isEmpty())
    elif choice == 6: 
        # Clear the stack
        stack.makeEmpty()
        print("Stack cleared.")
    else:
        # Handle invalid choice
        print("Invalid choice.")

scanner.close()

