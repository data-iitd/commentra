
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

nil = Node(None)  # Sentinel node to represent the head and tail of the list

def list_search(key):
    cur = nil.next  # Start searching from the first node
    while cur!= nil and cur.key!= key:
        cur = cur.next
    return cur

def init():
    global nil
    nil = Node(None)  # Allocate memory for the sentinel node
    nil.next = nil  # Point next of nil to itself
    nil.prev = nil  # Point prev of nil to itself

def print_list():
    cur = nil.next  # Start from the first node
    isf = True  # Flag to manage spacing between numbers
    while True:
        if cur == nil:
            break  # Stop if we reach the sentinel node
        if isf is False:
            print(" ", end="")  # Print space before subsequent numbers
        print(cur.key, end="")  # Print the key of the current node
        cur = cur.next  # Move to the next node
        isf = False  # Set flag to indicate that the first number has been printed
    print()  # Print a newline at the end

def delete_node(t):
    t.prev.next = t.next  # Bypass the node to be deleted
    t.next.prev = t.prev  # Bypass the node to be deleted
    del t  # Free the memory allocated for the node

def delete_first():
    t = nil.next  # Get the first node
    if t == nil:  # Check if the list is empty
        return
    delete_node(t)  # Delete the first node

def delete_last():
    t = nil.prev  # Get the last node
    if t == nil:  # Check if the list is empty
        return
    delete_node(t)  # Delete the last node

def delete(key):
    t = list_search(key)  # Search for the node with the given key
    if t == nil:  # If the node is not found, return
        return
    delete_node(t)  # Delete the found node

def insert(key):
    x = Node(key)  # Create a new node
    x.next = nil.next  # Point the new node's next to the current first node
    nil.next.prev = x  # Update the current first node's previous to point to the new node
    nil.next = x  # Update the sentinel's next to point to the new node
    x.prev = nil  # Set the new node's previous to the sentinel

# Read the number of operations to perform
n = int(input())

# Initialize the doubly linked list
init()

# Loop to process each operation
for i in range(n):
    # Read command and key value
    com, key = input().split()
    key = int(key)

    # If the command is to insert a node
    if com[0] == 'i':
        insert(key)  # Insert the key into the list
    # If the command is to delete a node
    elif com[0] == 'd':
        # Check for specific delete commands (delete first or last)
        if len(com) > 6:
            if com[6] == 'F':
                delete_first()  # Delete the first node
            elif com[6] == 'L':
                delete_last()  # Delete the last node
        else:
            delete(key)  # Delete the node with the specified key

# Print the final state of the list
print_list()

