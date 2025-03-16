import java.util.NoSuchElementException;
import java.util.Scanner;
class Main:
    # Represents a node in the doubly linked list
    class MainNode:
        def __init__(self, val):
            self.val = val
            self.next = None # Reference to the next node
            self.prev = None # Reference to the previous node
    # Head of the doubly linked list
    head = None
    # Tail of the doubly linked list
    tail = None
    # Number of elements in the deque
    size = 0
    # Adds a new element to the front of the deque
    def addFirst(self, val):
        newNode = MainNode(val)
        if self.isEmpty(): # If the deque is empty, set both head and tail to the new node
            self.head = newNode
            self.tail = newNode
        else: # Otherwise, adjust the pointers to insert at the front
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode
        self.size += 1 # Increment the size of the deque
    # Adds a new element to the rear of the deque
    def addLast(self, val):
        newNode = MainNode(val)
        if self.tail == None: # If the deque is empty, set both head and tail to the new node
            self.head = newNode
            self.tail = newNode
        else: # Otherwise, adjust the pointers to insert at the rear
            newNode.prev = self.tail
            self.tail.next = newNode
            self.tail = newNode
        self.size += 1 # Increment the size of the deque
    # Removes and returns the first element from the deque
    def pollFirst(self):
        if self.head == None: # If the deque is empty, throw an exception
            raise NoSuchElementException("Main is empty")
        oldHeadVal = self.head.val # Store the value of the head node
        if self.head == self.tail: # If there's only one element, set both head and tail to null
            self.head = None
            self.tail = None
        else: # Otherwise, adjust the pointers to remove the head node
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1 # Decrement the size of the deque
        return oldHeadVal # Return the value of the removed node
    # Removes and returns the last element from the deque
    def pollLast(self):
        if self.tail == None: # If the deque is empty, throw an exception
            raise NoSuchElementException("Main is empty")
        oldTailVal = self.tail.val # Store the value of the tail node
        if self.head == self.tail: # If there's only one element, set both head and tail to null
            self.head = None
            self.tail = None
        else: # Otherwise, adjust the pointers to remove the tail node
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1 # Decrement the size of the deque
        return oldTailVal # Return the value of the removed node
    # Returns the first element of the deque without removing it
    def peekFirst(self):
        return self.head!= None and self.head.val or None # Return the value of the head node, or null if empty
    # Returns the last element of the deque without removing it
    def peekLast(self):
        return self.tail!= None and self.tail.val or None # Return the value of the tail node, or null if empty
    # Returns the number of elements in the deque
    def size(self):
        return self.size
    # Checks if the deque is empty
    def isEmpty(self):
        return self.size == 0
    # Returns a string representation of the deque
    def __str__(self):
        dequeString = "Head -> "
        currNode = self.head
        while currNode!= None:
            dequeString += str(currNode.val)
            if currNode.next!= None:
                dequeString += " <-> "
            currNode = currNode.next
        dequeString += " <- Tail"
        return dequeString
# Main method to run the deque through a command-line interface
if __name__ == "__main__":
    scanner = Scanner(System.in)
    deque = Main()
    while scanner.hasNextLine():
        command = scanner.nextLine().trim()
        if command.equalsIgnoreCase("exit"):
            break
        try:
            parts = command.split(" ")
            if parts[0] == "addFirst":
                addFirstValue = Integer.parseInt(parts[1])
                deque.addFirst(addFirstValue)
                print("Added to front: " + addFirstValue)
            elif parts[0] == "addLast":
                addLastValue = Integer.parseInt(parts[1])
                deque.addLast(addLastValue)
                print("Added to rear: " + addLastValue)
            elif parts[0] == "pollFirst":
                print("Removed from front: " + deque.pollFirst())
            elif parts[0] == "pollLast":
                print("Removed from rear: " + deque.pollLast())
            elif parts[0] == "peekFirst":
                print("Front element: " + deque.peekFirst())
            elif parts[0] == "peekLast":
                print("Rear element: " + deque.peekLast())
            elif parts[0] == "size":
                print("Size: " + deque.size())
            elif parts[0] == "isEmpty":
                print("Is empty: " + deque.isEmpty())
            elif parts[0] == "print":
                print(deque)
            else:
                print("Unknown command: " + parts[0])
        except Exception as e:
            print("Error: " + e.getMessage())
    scanner.close()
