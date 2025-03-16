class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)  # Create a nil node
        self.nil.next = self.nil  # Point next of nil to itself
        self.nil.prev = self.nil  # Point prev of nil to itself

    def list_search(self, key):
        cur = self.nil.next  # Start from the first node
        while cur != self.nil and cur.key != key:
            cur = cur.next
        return cur  # Return the found node or nil if not found

    def print_list(self):
        cur = self.nil.next  # Start from the first node
        is_first = True  # Flag to indicate if this is the first node to be printed
        while True:
            if cur == self.nil:
                break  # Exit if we reached the end of the list
            if not is_first:
                print(" ", end="")  # Print space before the key if not the first node
            print(cur.key, end="")  # Print the key of the current node
            cur = cur.next  # Move to the next node
            is_first = False  # Reset the flag for the next iteration
        print()  # Print a newline at the end

    def delete_node(self, t):
        t.prev.next = t.next  # Set the next pointer of the previous node
        t.next.prev = t.prev  # Set the prev pointer of the next node
        del t  # Free the memory occupied by the node

    def delete_first(self):
        t = self.nil.next  # Pointer to the first node
        if t == self.nil:
            return  # If the list is empty, return
        self.delete_node(t)  # Delete the first node

    def delete_last(self):
        t = self.nil.prev  # Pointer to the last node
        if t == self.nil:
            return  # If the list is empty, return
        self.delete_node(t)  # Delete the last node

    def delete(self, key):
        t = self.list_search(key)  # Search for the node with the given key
        if t == self.nil:
            return  # If the node is not found, return
        self.delete_node(t)  # Delete the node

    def insert(self, key):
        x = Node(key)  # Create a new node
        x.next = self.nil.next  # Insert the new node at the end of the list
        self.nil.next.prev = x
        self.nil.next = x
        x.prev = self.nil

def main():
    n = int(input())  # Read the number of commands
    dll = DoublyLinkedList()  # Initialize the linked list
    size = 0  # Current size of the list
    np = 0  # Number of insert operations
    nd = 0  # Number of delete operations

    for _ in range(n):
        command = input().split()  # Read the command
        com = command[0]
        key = int(command[1]) if len(command) > 1 else None

        if com[0] == 'i':  # Insert command
            dll.insert(key)
            np += 1
            size += 1
        elif com[0] == 'd':  # Delete command
            if len(com) > 6:  # Check for delete first or delete last
                if com[6] == 'F':
                    dll.delete_first()
                elif com[6] == 'L':
                    dll.delete_last()
            else:  # Delete by key
                dll.delete(key)
                nd += 1
                size -= 1

    # Print the final size of the list and the number of operations
    print(f"Size: {size}, Number of insert operations: {np}, Number of delete operations: {nd}")

    # Free the memory occupied by the linked list (handled by Python's garbage collector)

if __name__ == "__main__":
    main()

# <END-OF-CODE>
