class Node:
    def __init__(self, key):
        self.key = key  # Key value of the node
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(None)  # Create a head node
        self.head.next = self.head  # Circular link
        self.head.prev = self.head  # Circular link

    def print_list(self):
        cur = self.head.next  # Start from the first node
        snl = 1  # Flag to manage spacing
        while cur != self.head:  # Traverse until we reach the head again
            if snl == 0:
                print(" ", end="")  # Print space before the next number
            print(cur.key, end="")  # Print the key of the current node
            cur = cur.next  # Move to the next node
            snl = 0  # Set flag to indicate that we have printed at least one element
        print()  # Print a newline after the list

    def delete_first(self):
        if self.head.next == self.head:  # Check if the list is empty
            return
        t = self.head.next  # Node to be deleted (first node)
        self.head.next = t.next  # Update head's next to the second node
        t.next.prev = self.head  # Update the new first node's prev to head

    def delete_last(self):
        if self.head.prev == self.head:  # Check if the list is empty
            return
        delnode = self.head.prev  # Node to be deleted (last node)
        self.head.prev = delnode.prev  # Update head's prev to the second last node
        delnode.prev.next = self.head  # Update the new last node's next to head

    def delete(self, skey):
        n = self.head.next  # Pointer for traversal
        while n != self.head:  # Traverse the list to find the key
            if n.key == skey:
                break
            n = n.next
        else:
            return  # Key not found

        # If the key exists, proceed to delete the node
        n.prev.next = n.next  # Bypass the node to be deleted
        n.next.prev = n.prev  # Update the next node's prev pointer
        del n  # Free the memory of the deleted node

    def insert(self, skey):
        new_node = Node(skey)  # Create a new node
        new_node.next = self.head.next  # Point new node's next to the first node
        self.head.next.prev = new_node  # Update the first node's prev to new node
        self.head.next = new_node  # Update head's next to new node
        new_node.prev = self.head  # Point new node's prev to head

# Main function to execute the program
if __name__ == "__main__":
    n = int(input())  # Read the number of operations
    dll = DoublyLinkedList()  # Initialize the doubly linked list
    for _ in range(n):  # Loop through each operation
        command = input().strip()  # Read the command
        if command == "insert":  # Check if command is 'insert'
            key = int(input())  # Read the key to insert
            dll.insert(key)  # Call insert function
        elif command == "deleteFirst":  # Check if command is 'deleteFirst'
            dll.delete_first()  # Call deleteFirst function
        elif command == "deleteLast":  # Check if command is 'deleteLast'
            dll.delete_last()  # Call deleteLast function
        else:  # If command is 'delete'
            key = int(input())  # Read the key to delete
            dll.delete(key)  # Call delete function
    dll.print_list()  # Print the final state of the list

# <END-OF-CODE>
