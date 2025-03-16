
import sys

# Define a doubly linked list node structure
class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

# Method to recursively print the keys of the linked list starting from the current node
def rPrint(self, buf):
    buf.write(str(self.key)) # Append the current node's key to the buffer
    if self.next is not None:
        buf.write(" ") # Add a space if there is a next node
        self.next.rPrint(buf) # Recursively print the next node

# Method to delete the current node from the linked list
def delete(self, first, last):
    if self.prev is not None and self.next is not None:
        # Node is in the middle; update pointers of adjacent nodes
        self.prev.next = self.next
        self.next.prev = self.prev
        return first, last # Return unchanged first and last pointers
    if self.next is None and self.prev is None:
        # Node is the only node in the list
        return None, None # Return None for both first and last
    if self.prev is None:
        # Node is the first node
        first = self.next # Update first to the next node
        self.next.prev = None # Set the previous pointer of the new first node to None
    if self.next is None:
        # Node is the last node
        last = self.prev # Update last to the previous node
        self.prev.next = None # Set the next pointer of the new last node to None
    return first, last # Return updated first and last pointers

# Function to initialize a new node with a given key
def initNode(key):
    return Node(key)

# Main function to execute the program
def main():
    first, last = None, None # Initialize pointers for the first and last nodes of the list
    sys.stdin.readline() # Read the first line of input (not used)

    # Loop to process each command from the input
    for line in sys.stdin:
        cmd = line.strip() # Get the current command
        if cmd == "deleteFirst":
            # Command to delete the first node
            first, last = first.delete(first, last)
        elif cmd == "deleteLast":
            # Command to delete the last node
            first, last = last.delete(first, last)
        else:
            # Handle commands that involve inserting or deleting specific keys
            xcmd = cmd.split() # Split the command into parts
            k = int(xcmd[1]) # Convert the second part to an integer
            if xcmd[0] == "delete":
                # Command to delete a node with a specific key
                a = first
                while a is not None:
                    if a.key == k:
                        first, last = a.delete(first, last) # Delete the node and update first and last
                        break
                    a = a.next
            elif xcmd[0] == "insert":
                # Command to insert a new node at the beginning of the list
                n = initNode(k) # Initialize a new node
                n.next = first # Set the new node's next pointer to the current first node
                if first is not None:
                    first.prev = n # Update the previous pointer of the current first node
                first = n # Update first to the new node
                if last is None:
                    last = n # If the list was empty, set last to the new node
    buf = bytes() # Initialize a buffer to store the keys of the linked list
    first.rPrint(buf) # Print the keys of the linked list starting from the first node
    print(buf.decode()) # Output the result

if __name__ == "__main__":
    main()

