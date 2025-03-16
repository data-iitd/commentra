class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = self.make_node(0)  # Initialize head with a dummy node
        self.head.next = self.head
        self.head.prev = self.head

    def make_node(self, a):
        return Node(a)  # Create a new node with the given key

    def insert(self, a):
        new_node = self.make_node(a)  # Create a new node
        # Insert new node at the end of the list
        new_node.next = self.head.next
        self.head.next.prev = new_node
        self.head.next = new_node
        new_node.prev = self.head

    def delete(self, a):
        current = self.head
        # Search for the node to be deleted
        while current.next != self.head:
            current = current.next
            if current.key == a:  # Found the node to be deleted
                prev_node = current.prev  # Save the previous node
                prev_node.next = current.next  # Update the previous node's next pointer
                current.next.prev = prev_node  # Update the next node's prev pointer
                del current  # Free the memory occupied by the deleted node
                break

    def delete_first(self):
        first_node = self.head.next  # Save the second node in a temporary variable
        # Update the head pointer and the previous node's next pointer
        self.head.next = first_node.next
        first_node.next.prev = self.head
        del first_node  # Free the memory occupied by the first node

    def delete_last(self):
        current = self.head
        # Search for the second last node
        while current.next != self.head:
            current = current.next
        prev_node = current.prev  # Save the previous node
        # Update the previous node's next pointer
        prev_node.next = self.head
        self.head.prev = prev_node
        del current  # Free the memory occupied by the last node

    def print_list(self):
        current = self.head
        result = []
        while current.next != self.head:  # Traverse the list and collect keys
            current = current.next
            result.append(current.key)
        print(" ".join(map(str, result)))  # Print the keys

if __name__ == "__main__":
    n = int(input())  # Read the number of operations
    dll = DoublyLinkedList()  # Initialize the doubly linked list

    for _ in range(n):
        op = input().strip()  # Read the operation
        if op == "insert":  # If the operation is to insert a node
            a = int(input())  # Read the key value of the node to be inserted
            dll.insert(a)  # Call the insert function
        elif op == "delete":  # If the operation is to delete a node
            a = int(input())  # Read the key value of the node to be deleted
            dll.delete(a)  # Call the delete function
        elif op == "deleteFirst":  # If the operation is to delete the first node
            dll.delete_first()  # Call the deleteFirst function
        elif op == "deleteLast":  # If the operation is to delete the last node
            dll.delete_last()  # Call the deleteLast function

    dll.print_list()  # Print the list

# <END-OF-CODE>
