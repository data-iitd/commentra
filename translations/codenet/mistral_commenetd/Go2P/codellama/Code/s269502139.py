
# Define a node structure with key, previous and next pointers
class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

# Recursive function to print the linked list in reverse order
def rPrint(n):
    if n is None:
        return
    print(n.key, end=" ")
    rPrint(n.next)

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
    # Initialize first and last pointers to None
    first = None
    last = None

    # Read the first command from stdin
    cmd = input()

    # Process each command until EOF is reached
    while cmd != "":
        # Split the command into parts using space as delimiter
        xcmd = cmd.split()
        # Parse the key from the second part of the command
        k = int(xcmd[1])
        # Switch statement to perform the corresponding action based on the command
        if xcmd[0] == "deleteFirst":
            # Delete the first node from the linked list
            first, last = delete(first, first, last)
        elif xcmd[0] == "deleteLast":
            # Delete the last node from the linked list
            first, last = delete(last, first, last)
        else:
            # Switch statement to perform the corresponding action based on the command prefix
            if xcmd[0] == "delete":
                # Search for the node with the given key in the linked list
                for a in range(first):
                    # If the current node matches the given key, delete it
                    if first.key == k:
                        first, last = delete(first, first, last)
                        break
            elif xcmd[0] == "insert":
                # Create a new node with the given key
                n = initNode(k)
                # Insert the new node at the beginning of the linked list
                n.next = first
                if first is not None:
                    first.prev = n

                # Update the first and last pointers
                first = n
                if last is None:
                    last = n

        # Read the next command from stdin
        cmd = input()

    # Print the linked list in reverse order
    rPrint(first)
    # Print the reversed linked list on the console
    print()
    # End of the code

