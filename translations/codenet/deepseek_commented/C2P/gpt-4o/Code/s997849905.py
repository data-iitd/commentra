class Node:
    def __init__(self, key):
        self.key = key  # Integer key stored in the node
        self.next = None  # Pointer to the next node in the list
        self.prev = None  # Pointer to the previous node in the list

class CircularDoublyLinkedList:
    def __init__(self):
        self.sentinel = Node(None)  # Create a sentinel node
        self.sentinel.next = self.sentinel  # Point next to itself
        self.sentinel.prev = self.sentinel  # Point prev to itself
        self.count = 0  # Track the number of nodes

    def print_list(self):
        cur = self.sentinel.next  # Start from the first node
        elements = []
        while cur != self.sentinel:  # Iterate until the sentinel node is reached
            elements.append(str(cur.key))  # Collect keys for printing
            cur = cur.next  # Move to the next node
        print(" ".join(elements))  # Print all keys in one line

    def delete_first(self):
        if self.count == 0:
            return  # List is empty
        first_node = self.sentinel.next  # Store the first node
        self.sentinel.next = first_node.next  # Update the next pointer of the sentinel node
        first_node.next.prev = self.sentinel  # Update the previous pointer of the new first node
        self.count -= 1  # Decrease the count
        del first_node  # Free the memory of the deleted node

    def delete_last(self):
        if self.count == 0:
            return  # List is empty
        last_node = self.sentinel.prev  # Store the last node
        self.sentinel.prev = last_node.prev  # Update the previous pointer of the sentinel node
        last_node.prev.next = self.sentinel  # Update the next pointer of the new last node
        self.count -= 1  # Decrease the count
        del last_node  # Free the memory of the deleted node

    def delete(self, skey):
        cur = self.sentinel.next  # Start from the first node
        while cur != self.sentinel:  # Iterate through the list
            if cur.key == skey:  # If the key is found
                cur.prev.next = cur.next  # Bypass the current node
                cur.next.prev = cur.prev  # Bypass the current node
                self.count -= 1  # Decrease the count
                del cur  # Free the memory of the deleted node
                return  # Exit after deleting the node
            cur = cur.next  # Move to the next node

    def insert(self, skey):
        new_node = Node(skey)  # Create a new node
        if self.count == 0:  # Special case: if the list is empty
            new_node.next = self.sentinel
            new_node.prev = self.sentinel
            self.sentinel.next = new_node
            self.sentinel.prev = new_node
        else:
            new_node.next = self.sentinel.next  # Set the next pointer of the new node
            new_node.prev = self.sentinel  # Set the previous pointer of the new node
            self.sentinel.next.prev = new_node  # Update the previous pointer of the current first node
            self.sentinel.next = new_node  # Update the next pointer of the sentinel node
        self.count += 1  # Increase the count

# Main function to execute the operations on the circular doubly linked list
if __name__ == "__main__":
    n = int(input())  # Read the number of commands
    cdll = CircularDoublyLinkedList()  # Initialize the circular doubly linked list
    for _ in range(n):  # Loop through the number of commands
        command = input().strip()  # Read the command
        if command == "insert":  # If the command is to insert
            key = int(input())  # Read the key to insert
            cdll.insert(key)  # Insert the key into the list
        elif command == "deleteFirst":  # If the command is to delete the first node
            cdll.delete_first()
        elif command == "deleteLast":  # If the command is to delete the last node
            cdll.delete_last()
        else:  # If the command is to delete a specific node
            key = int(input())  # Read the key to delete
            cdll.delete(key)  # Delete the node with the specified key
    cdll.print_list()  # Print the final state of the list

# <END-OF-CODE>
