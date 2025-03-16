class Node:
    def __init__(self, key):
        self.key = key  # The value stored in the node
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(0)  # Initialize the head node
        self.head.next = self.head
        self.head.prev = self.head

    def insert(self, key):
        new_node = Node(key)  # Create a new node
        new_node.next = self.head.next  # Set the next pointer of the new node
        self.head.next.prev = new_node  # Update the prev pointer of the current head->next
        self.head.next = new_node  # Set the next pointer of the head to the new node
        new_node.prev = self.head  # Set the prev pointer of the new node to the head

    def delete(self, key):
        current = self.head
        # Traverse the list to find the node with the given key
        while current.next != self.head:
            current = current.next
            if current.key == key:
                current.prev.next = current.next  # Update the next pointer of the previous node
                current.next.prev = current.prev  # Update the prev pointer of the next node
                del current  # Free the memory of the node to be deleted
                break  # Exit the loop after deleting the node

    def delete_first(self):
        if self.head.next != self.head:  # Check if the list is not empty
            first_node = self.head.next  # Get the first node
            self.head.next = first_node.next  # Update the next pointer of the head
            first_node.next.prev = self.head  # Update the prev pointer of the node after the first node
            del first_node  # Free the memory of the node to be deleted

    def delete_last(self):
        if self.head.prev != self.head:  # Check if the list is not empty
            last_node = self.head.prev  # Get the last node
            self.head.prev = last_node.prev  # Update the prev pointer of the head
            last_node.prev.next = self.head  # Update the next pointer of the node before the last node
            del last_node  # Free the memory of the node to be deleted

    def print_list(self):
        current = self.head
        result = []
        while current.next != self.head:
            current = current.next
            result.append(str(current.key))
        print(" ".join(result))

if __name__ == "__main__":
    n = int(input())  # Read the number of operations
    dll = DoublyLinkedList()  # Create a new doubly linked list

    for _ in range(n):
        op = input().strip()  # Read the operation type
        if op == "insert":
            a = int(input().strip())  # Read the value to insert
            dll.insert(a)
        elif op == "delete":
            a = int(input().strip())  # Read the value to delete
            dll.delete(a)
        elif op == "deleteFirst":
            dll.delete_first()
        elif op == "deleteLast":
            dll.delete_last()

    dll.print_list()  # Print the list

# <END-OF-CODE>
