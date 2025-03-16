import java.util.NoSuchElementException;
import java.util.Scanner;

class Main:
    # Node class representing each element in the doubly linked list
    class MainNode:
        def __init__(self, val):
            self.val = val;
            self.next = None;
            self.prev = None;

    # Head and tail pointers for the doubly linked list
    head = None;
    tail = None;
    size = 0; # Size of the deque

    # Method to add a value to the front of the deque
    def addFirst(self, val):
        newNode = MainNode(val); # Create a new node
        if self.isEmpty(): # If the deque is empty
            self.head = newNode; # Set head and tail to the new node
            self.tail = newNode;
        else: # If the deque is not empty
            newNode.next = self.head; # Link new node to the current head
            self.head.prev = newNode; # Link current head back to the new node
            self.head = newNode; # Update head to the new node
        self.size++; # Increment the size of the deque

    # Method to add a value to the end of the deque
    def addLast(self, val):
        newNode = MainNode(val); # Create a new node
        if self.tail == None: # If the deque is empty
            self.head = newNode; # Set head and tail to the new node
            self.tail = newNode;
        else: # If the deque is not empty
            newNode.prev = self.tail; # Link new node back to the current tail
            self.tail.next = newNode; # Link current tail to the new node
            self.tail = newNode; # Update tail to the new node
        self.size++; # Increment the size of the deque

    # Method to remove and return the value from the front of the deque
    def pollFirst(self):
        if self.head == None: # Check if the deque is empty
            raise NoSuchElementException("Main is empty"); # Throw exception if empty
        oldHeadVal = self.head.val; # Store the value of the current head
        if self.head == self.tail: # If there's only one element
            self.head = None; # Set head and tail to null
            self.tail = None;
        else: # If there are multiple elements
            self.head = self.head.next; # Move head to the next node
            self.head.prev = None; # Clear the previous pointer of the new head
        self.size--; # Decrement the size of the deque
        return oldHeadVal; # Return the removed value

    # Method to remove and return the value from the end of the deque
    def pollLast(self):
        if self.tail == None: # Check if the deque is empty
            raise NoSuchElementException("Main is empty"); # Throw exception if empty
        oldTailVal = self.tail.val; # Store the value of the current tail
        if self.head == self.tail: # If there's only one element
            self.head = None; # Set head and tail to null
            self.tail = None;
        else: # If there are multiple elements
            self.tail = self.tail.prev; # Move tail to the previous node
            self.tail.next = None; # Clear the next pointer of the new tail
        self.size--; # Decrement the size of the deque
        return oldTailVal; # Return the removed value

    # Method to peek at the value at the front of the deque without removing it
    def peekFirst(self):
        return self.head!= None? self.head.val : None; # Return head value or null if empty

    # Method to peek at the value at the end of the deque without removing it
    def peekLast(self):
        return self.tail!= None? self.tail.val : None; # Return tail value or null if empty

    # Method to get the current size of the deque
    def size(self):
        return self.size; # Return the size of the deque

    # Method to check if the deque is empty
    def isEmpty(self):
        return self.size == 0; # Return true if size is 0, otherwise false

    # Method to represent the deque as a string
    def __str__(self):
        dequeString = "Head -> "; # Initialize string representation
        currNode = self.head; # Start from the head
        while currNode!= None: # Traverse the deque
            dequeString += str(currNode.val); # Append current node's value
            if currNode.next!= None: # If there is a next node
                dequeString += " <-> "; # Append separator
            currNode = currNode.next; # Move to the next node
        dequeString += " <- Tail"; # Append tail indication
        return dequeString; # Return the string representation

# Main method to run the deque operations based on user input
if __name__ == "__main__":
    scanner = Scanner(System.in); # Create a scanner for user input
    deque = Main(); # Initialize a new deque for integers

    # Loop to continuously read commands from the user
    while scanner.hasNextLine():
        command = scanner.nextLine().trim(); # Read and trim the command
        if command.equalsIgnoreCase("exit"): # Check for exit command
            break; # Exit the loop
        try:
            parts = command.split(" "); # Split command into parts
            if parts[0] == "addFirst":
                addFirstValue = Integer.parseInt(parts[1]); # Parse the value
                deque.addFirst(addFirstValue); # Add value to the front
                print("Added to front: " + addFirstValue); # Confirm addition
            elif parts[0] == "addLast":
                addLastValue = Integer.parseInt(parts[1]); # Parse the value
                deque.addLast(addLastValue); # Add value to the rear
                print("Added to rear: " + addLastValue); # Confirm addition
            elif parts[0] == "pollFirst":
                print("Removed from front: " + deque.pollFirst()); # Remove and display front value
            elif parts[0] == "pollLast":
                print("Removed from rear: " + deque.pollLast()); # Remove and display rear value
            elif parts[0] == "peekFirst":
                print("Front element: " + deque.peekFirst()); # Display front value without removal
            elif parts[0] == "peekLast":
                print("Rear element: " + deque.peekLast()); # Display rear value without removal
            elif parts[0] == "size":
                print("Size: " + deque.size()); # Display current size
            elif parts[0] == "isEmpty":
                print("Is empty: " + deque.isEmpty()); # Check if deque is empty
            elif parts[0] == "print":
                print(deque); # Print the current state of the deque
            else:
                print("Unknown command: " + parts[0]); # Handle unknown commands
        except Exception as e:
            print("Error: " + e.getMessage()); # Handle exceptions and display error message
scanner.close(); # Close the scanner
