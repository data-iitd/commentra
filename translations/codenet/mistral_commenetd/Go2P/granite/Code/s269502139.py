

import sys

# Define a node structure with key, previous and next pointers
class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

# Recursive function to print the linked list in reverse order
def rPrint(n, buf):
    buf.write(str(n.key))
    if n.next is not None:
        # Recursively call rPrint function for next node
        buf.write(" ")
        rPrint(n.next, buf)
    # Return from the function
    return

# Function to delete a node from the linked list
def delete(n, first, last):
    # Base case: if node is the first and last node
    if n.prev is None and n.next is None:
        return None, None

    # Base case: if node is the first node
    if n.prev is None:
        first = n.next
        n.next.prev = None
        return first, last

    # Base case: if node is the last node
    if n.next is None:
        last = n.prev
        n.prev.next = None
        return first, last

    # General case: swap the pointers of previous and next nodes
    n.prev.next = n.next
    n.next.prev = n.prev
    # Return the first and last nodes after deletion
    return first, last

# Initialize a new node with given key
def initNode(key):
    return Node(key)

# Main function to read commands from stdin and perform the corresponding actions
def main():
    # Initialize standard input scanner
    stdin = sys.stdin

    # Initialize first and last pointers to None
    first, last = None, None

    # Read the first command from stdin
    cmd = stdin.readline().strip()

    # Process each command until EOF is reached
    while True:
        # Switch statement to perform the corresponding action based on the command
        if cmd == "deleteFirst":
            # Delete the first node from the linked list
            first, last = delete(first, first, last)
        elif cmd == "deleteLast":
            # Delete the last node from the linked list
            first, last = delete(last, first, last)
        else:
            # Split the command into parts using space as delimiter
            xcmd = cmd.split(" ")
            # Parse the key from the second part of the command
            k = int(xcmd[1])
            # Convert the key to int32 type
            k32 = int(k)
            # Switch statement to perform the corresponding action based on the command prefix
            if xcmd[0] == "delete":
                # Search for the node with the given key in the linked list
                a = first
                while a is not None:
                    # If the current node matches the given key, delete it
                    if a.key == k32:
                        first, last = delete(a, first, last)
                        break
                    a = a.next
            elif xcmd[0] == "insert":
                # Create a new node with the given key
                n = initNode(k32)
                # Insert the new node at the beginning of the linked list
                n.next = first
                if first is not None:
                    first.prev = n

                # Update the first and last pointers
                first = n
                if last is None:
                    last = n

        # Read the next command from stdin
        cmd = stdin.readline().strip()
        # If EOF is reached, break the loop
        if cmd == "":
            break

    # Print the linked list in reverse order
    buf = bytes.buffer()
    rPrint(first, buf)
    # Print the reversed linked list on the console
    print(buf.decode("utf-8"))
    # End of the code

