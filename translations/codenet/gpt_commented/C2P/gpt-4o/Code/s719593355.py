class Node:
    def __init__(self, key):
        self.key = key          # Key value of the node
        self.next = None       # Pointer to the next node
        self.prev = None       # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)   # Sentinel node to represent the head and tail of the list
        self.nil.next = self.nil # Point next of nil to itself
        self.nil.prev = self.nil # Point prev of nil to itself

    def list_search(self, key):
        cur = self.nil.next      # Start searching from the first node
        while cur != self.nil and cur.key != key:
            cur = cur.next
        return cur              # Return the found node or nil if not found

    def print_list(self):
        cur = self.nil.next      # Start from the first node
        isf = True               # Flag to manage spacing between numbers
        result = []

        while True:
            if cur == self.nil:
                break            # Stop if we reach the sentinel node
            if not isf:
                result.append(" ") # Print space before subsequent numbers
            result.append(str(cur.key)) # Print the key of the current node
            cur = cur.next        # Move to the next node
            isf = False           # Set flag to indicate that the first number has been printed

        print("".join(result))   # Print all keys in one line

    def delete_node(self, t):
        t.prev.next = t.next     # Bypass the node to be deleted
        t.next.prev = t.prev     # Bypass the node to be deleted

    def delete_first(self):
        t = self.nil.next         # Get the first node
        if t == self.nil:         # Check if the list is empty
            return
        self.delete_node(t)      # Delete the first node

    def delete_last(self):
        t = self.nil.prev         # Get the last node
        if t == self.nil:         # Check if the list is empty
            return
        self.delete_node(t)      # Delete the last node

    def delete(self, key):
        t = self.list_search(key) # Search for the node with the given key
        if t == self.nil:         # If the node is not found, return
            return
        self.delete_node(t)      # Delete the found node

    def insert(self, key):
        x = Node(key)             # Create a new node
        # Insert the new node at the beginning of the list
        x.next = self.nil.next    # Point the new node's next to the current first node
        self.nil.next.prev = x    # Update the current first node's previous to point to the new node
        self.nil.next = x         # Update the sentinel's next to point to the new node
        x.prev = self.nil         # Set the new node's previous to the sentinel

def main():
    n = int(input())           # Read the number of operations to perform
    dll = DoublyLinkedList()   # Initialize the doubly linked list
    size = 0                   # Variable to keep track of the size of the list
    np = 0                     # Counter for number of insertions
    nd = 0                     # Counter for number of deletions

    for _ in range(n):
        command = input().split() # Read command and key value
        com = command[0]
        key = int(command[1])

        if com[0] == 'i':
            dll.insert(key)       # Insert the key into the list
            np += 1               # Increment the insertion counter
            size += 1             # Increment the size of the list
        elif com[0] == 'd':
            if len(com) > 6:
                if com[6] == 'F':
                    dll.delete_first() # Delete the first node
                elif com[6] == 'L':
                    dll.delete_last()  # Delete the last node
            else:
                dll.delete(key)      # Delete the node with the specified key
                nd += 1              # Increment the deletion counter
            size -= 1               # Decrement the size of the list

    dll.print_list()            # Print the final state of the list

if __name__ == "__main__":
    main()

# <END-OF-CODE>
