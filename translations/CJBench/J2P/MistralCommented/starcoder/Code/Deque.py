
# Custom node class for the doubly linked list
class MainNode(object):
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None

    # Getter for the value of the node
    def getValue(self):
        return self.val

    # Setter for the next reference of the node
    def setNext(self, nextNode):
        self.next = nextNode

    # Setter for the prev reference of the node
    def setPrev(self, prevNode):
        self.prev = prevNode


# The main class for the doubly linked list
class Main(object):
    # Head and tail references for the doubly linked list
    head = None
    tail = None

    # Size of the doubly linked list
    size = 0

    # Add a new node to the front of the doubly linked list
    def addFirst(self, val):
        newNode = MainNode(val)  # Create a new node with the given value

        if self.isEmpty():  # If the doubly linked list is empty
            self.head = newNode  # Set head and tail to the new node
            self.tail = newNode
        else:  # If the doubly linked list is not empty
            newNode.next = self.head  # Set the next reference of the new node to the current head
            self.head.prev = newNode  # Set the prev reference of the current head to the new node
            self.head = newNode  # Set head to the new node
        self.size += 1  # Increment the size of the doubly linked list

    # Add a new node to the end of the doubly linked list
    def addLast(self, val):
        newNode = MainNode(val)  # Create a new node with the given value

        if self.tail is None:  # If the doubly linked list is empty
            self.head = newNode
            self.tail = newNode
        else:  # If the doubly linked list is not empty
            newNode.prev = self.tail  # Set the prev reference of the new node to the current tail
            self.tail.next = newNode  # Set the next reference of the current tail to the new node
            self.tail = newNode  # Set tail to the new node
        self.size += 1  # Increment the size of the doubly linked list

    # Remove and return the node at the front of the doubly linked list
    def pollFirst(self):
        if self.head is None:  # If the doubly linked list is empty
            raise NoSuchElementException("Main is empty")

        oldHeadVal = self.head.getValue()  # Get the value of the current head node

        if self.head == self.tail:  # If the doubly linked list has only one node
            self.head = None
            self.tail = None
        else:  # If the doubly linked list has more than one node
            self.head = self.head.next  # Set head to the next node
            self.head.prev = None  # Set the prev reference of the new head to null
        self.size -= 1  # Decrement the size of the doubly linked list

        return oldHeadVal  # Return the value of the removed node

    # Remove and return the node at the end of the doubly linked list
    def pollLast(self):
        if self.tail is None:  # If the doubly linked list is empty
            raise NoSuchElementException("Main is empty")

        oldTailVal = self.tail.getValue()  # Get the value of the current tail node

        if self.head == self.tail:  # If the doubly linked list has only one node
            self.head = None
            self.tail = None
        else:  # If the doubly linked list has more than one node
            self.tail = self.tail.prev  # Set tail to the previous node
            self.tail.next = None  # Set the next reference of the new tail to null
        self.size -= 1  # Decrement the size of the doubly linked list

        return oldTailVal  # Return the value of the removed node

    # Return the value of the node at the front of the doubly linked list without removing it
    def peekFirst(self):
        return self.head.getValue() if self.head is not None else None  # Return the value of the current head node if it exists, otherwise return null

    # Return the value of the node at the end of the doubly linked list without removing it
    def peekLast(self):
        return self.tail.getValue() if self.tail is not None else None  # Return the value of the current tail node if it exists, otherwise return null

    # Return the size of the doubly linked list
    def size(self):
        return self.size

    # Check if the doubly linked list is empty
    def isEmpty(self):
        return self.size == 0

    # Override the toString method to print the doubly linked list in a readable format
    def __str__(self):
        dequeString = "Head -> "
        currNode = self.head
        while currNode is not None:
            dequeString += str(currNode.getValue())
            if currNode.next is not None:
                dequeString += " <-> "
            currNode = currNode.next
        dequeString += " <- Tail"
        return dequeString


# Main method to test the doubly linked list implementation
if __name__ == "__main__":
    import sys
    import java.util.NoSuchElementException

    scanner = java.util.Scanner(sys.stdin)
    deque = Main()  # Create an instance of the Main class for integers

    while scanner.hasNextLine():
        command = scanner.nextLine().trim()
        if command.equalsIgnoreCase("exit"):
            break
        try:
            parts = command.split(" ")
            if parts[0] == "addFirst":
                addFirstValue = int(parts[1])
                deque.addFirst(addFirstValue)  # Add a new node to the front of the doubly linked list
                print("Added to front: " + addFirstValue)
            elif parts[0] == "addLast":
                addLastValue = int(parts[1])
                deque.addLast(addLastValue)  # Add a new node to the end of the doubly linked list
                print("Added to rear: " + addLastValue)
            elif parts[0] == "pollFirst":
                print("Removed from front: " + deque.pollFirst())  # Remove and print the node at the front of the doubly linked list
            elif parts[0] == "pollLast":
                print("Removed from rear: " + deque.pollLast())  # Remove and print the node at the end of the doubly linked list
            elif parts[0] == "peekFirst":
                print("Front element: " + deque.peekFirst())  # Print the value of the node at the front of the doubly linked list without removing it
            elif parts[0] == "peekLast":
                print("Rear element: " + deque.peekLast())  # Print the value of the node at the end of the doubly linked list without removing it
            elif parts[0] == "size":
                print("Size: " + deque.size())  # Print the size of the doubly linked list
            elif parts[0] == "isEmpty":
                print("Is empty: " + deque.isEmpty())  # Print whether the doubly linked list is empty or not
            elif parts[0] == "print":
                print(deque)  # Print the doubly linked list in a readable format
            else:
                print("Unknown command: " + parts[0])  # Print an error message for unknown commands
        except Exception as e:
            print("Error: " + e.getMessage())  # Print an error message for any exceptions thrown
    scanner.close()

