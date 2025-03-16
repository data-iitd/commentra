class Node:
    def __init__(self, key):
        self.key = key  # Value of the node
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.head = self.make_node(0)  # Initialize the head node
        self.head.next = self.head  # Point next of head to itself (circular)
        self.head.prev = self.head  # Point prev of head to itself (circular)

    def make_node(self, key):
        return Node(key)  # Create a new node with the given key

    def insert(self, key):
        new_node = self.make_node(key)  # Create a new node
        new_node.next = self.head.next  # Set the new node's next to the current first node
        self.head.next.prev = new_node  # Update the current first node's previous to the new node
        self.head.next = new_node  # Update head's next to the new node
        new_node.prev = self.head  # Set the new node's previous to head

    def delete(self, key):
        current = self.head  # Start from the head
        while current.next != self.head:  # Traverse the list
            current = current.next  # Move to the next node
            if current.key == key:  # Check if the current node's key matches the key to delete
                # Update the pointers to remove the node from the list
                current.prev.next = current.next  # Bypass the node to delete it
                current.next.prev = current.prev  # Update the previous node's next pointer
                del current  # Free the memory of the deleted node
                break  # Exit the loop after deletion

    def delete_first(self):
        first_node = self.head.next  # Get the first node
        self.head.next = first_node.next  # Update head's next to the second node
        first_node.next.prev = self.head  # Update the new first node's previous to head
        del first_node  # Free the memory of the deleted node

    def delete_last(self):
        last_node = self.head.prev  # Get the last node
        self.head.prev = last_node.prev  # Update head's previous to the second last node
        last_node.prev.next = self.head  # Update the new last node's next to head
        del last_node  # Free the memory of the deleted node

    def print_list(self):
        current = self.head
        result = []
        while current.next != self.head:  # Traverse the list until we reach the head again
            current = current.next  # Move to the next node
            result.append(str(current.key))  # Collect the key of the next node
        print(" ".join(result))  # Print the remaining elements in the list

if __name__ == "__main__":
    n = int(input())  # Read the number of operations to perform
    dll = DoublyLinkedList()  # Create a new doubly linked list

    for _ in range(n):
        op = input().strip()  # Read the operation command
        if op == "insert":  # Check if the operation is "insert"
            a = int(input())  # Read the value to insert
            dll.insert(a)  # Call insert function
        elif op == "delete":  # Check if the operation is "delete"
            a = int(input())  # Read the value to delete
            dll.delete(a)  # Call delete function
        elif op == "deleteFirst":  # Check if the operation is "deleteFirst"
            dll.delete_first()  # Call function to delete the first node
        elif op == "deleteLast":  # Check if the operation is "deleteLast"
            dll.delete_last()  # Call function to delete the last node

    dll.print_list()  # Print the remaining elements in the list

# <END-OF-CODE>
