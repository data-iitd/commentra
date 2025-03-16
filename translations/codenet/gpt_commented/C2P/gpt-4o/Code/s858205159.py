class Node:
    def __init__(self, key):
        self.key = key          # Key value of the node
        self.next = None        # Pointer to the next node
        self.prev = None        # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)   # Sentinel node
        self.nil.next = self.nil # Point next of sentinel to itself
        self.nil.prev = self.nil # Point prev of sentinel to itself

    def list_search(self, key):
        cur = self.nil.next      # Start from the first node
        while cur != self.nil:   # Traverse until the sentinel node
            if cur.key == key:   # If the key is found, return the node
                return cur
            cur = cur.next       # Move to the next node
        return self.nil         # Return sentinel if not found

    def print_list(self):
        cur = self.nil.next      # Start from the first node
        is_first = True          # Flag to manage spacing between numbers
        while True:
            if cur == self.nil:   # Stop if we reach the sentinel node
                break
            if not is_first:      # Print space before the next number if not the first
                print(" ", end="")
            print(cur.key, end="") # Print the key of the current node
            cur = cur.next        # Move to the next node
            is_first = False      # Set flag to indicate that we have printed at least one number
        print()                  # Print a new line after printing all keys

    def delete_node(self, t):
        if t == self.nil: return  # Do nothing if the node is the sentinel
        t.prev.next = t.next      # Bypass the node in the next pointer of the previous node
        t.next.prev = t.prev      # Bypass the node in the prev pointer of the next node
        del t                     # Free the memory allocated for the node

    def delete_first(self):
        t = self.nil.next         # Get the first node
        if t == self.nil: return   # Do nothing if the list is empty
        self.delete_node(t)       # Delete the first node

    def delete_last(self):
        t = self.nil.prev         # Get the last node
        if t == self.nil: return   # Do nothing if the list is empty
        self.delete_node(t)       # Delete the last node

    def delete_key(self, key):
        t = self.list_search(key)  # Search for the node with the key
        if t != self.nil:           # If found, delete the node
            self.delete_node(t)

    def insert(self, key):
        x = Node(key)              # Create a new node
        x.prev = self.nil          # Set the previous pointer to the sentinel
        x.next = self.nil.next     # Set the next pointer to the current first node
        x.next.prev = x           # Update the previous pointer of the current first node to point to the new node
        self.nil.next = x         # Update the sentinel's next pointer to point to the new node

# Main function to execute the program
if __name__ == "__main__":
    n = int(input())            # Read the number of operations
    dll = DoublyLinkedList()    # Initialize the linked list
    for _ in range(n):          # Loop through each operation
        command, key = input().split()  # Read the command and key
        key = int(key)          # Convert key to integer
        if command[0] == 'i':   # If the command is 'insert'
            dll.insert(key)      # Insert the key
        elif command[0] == 'd': # If the command is 'delete'
            if len(command) > 6: # Check if the command specifies 'First' or 'Last'
                if command[6] == 'F':
                    dll.delete_first()  # Delete the first node
                elif command[6] == 'L':
                    dll.delete_last()   # Delete the last node
            else:
                dll.delete_key(key)   # Delete the node with the specified key

    dll.print_list()            # Print the final state of the list

# <END-OF-CODE>
