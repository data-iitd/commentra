class Node:
    def __init__(self, key):
        self.key = key  # Key value of the node
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.N = Node(None)  # Initialize a sentinel node
        self.N.next = self.N  # Initialize next pointer of the sentinel node to itself
        self.N.prev = self.N  # Initialize prev pointer of the sentinel node to itself
        self.count = 0  # Counter to keep track of the number of nodes

    def print_list(self):
        cur = self.N.next  # Initialize a pointer to traverse the list
        snl = 1  # Set a flag to control the printing of spaces between numbers
        while cur != self.N:  # Traverse the list until the end is reached
            if snl == 0:  # If a space is not required before the number, print a space
                print(" ", end="")
            print(cur.key, end="")  # Print the key value of the current node
            cur = cur.next  # Move to the next node
            snl = 0  # Reset the flag for the next iteration
        print()  # Print a newline at the end

    def delete_first(self):
        if self.count == 0:
            return  # List is empty, nothing to delete
        t = self.N.next  # Initialize a pointer to the first node
        self.N.next = t.next  # Update the next pointer of the sentinel node
        t.next.prev = self.N  # Update the prev pointer of the second node
        self.count -= 1  # Decrease the count of nodes

    def delete_last(self):
        if self.count == 0:
            return  # List is empty, nothing to delete
        delnode = self.N.prev  # Initialize a pointer to the last node
        self.N.prev = delnode.prev  # Update the prev pointer of the sentinel node
        delnode.prev.next = self.N  # Update the next pointer of the second last node
        self.count -= 1  # Decrease the count of nodes

    def delete(self, skey):
        cur = self.N.next  # Initialize a pointer to traverse the list
        while cur != self.N:  # Traverse the list to find the node to be deleted
            if cur.key == skey:  # If the key matches, delete the node
                cur.prev.next = cur.next  # Update the next pointer of the previous node
                cur.next.prev = cur.prev  # Update the prev pointer of the next node
                self.count -= 1  # Decrease the count of nodes
                return
            cur = cur.next  # Move to the next node

    def insert(self, skey):
        new_node = Node(skey)  # Create a new node
        if self.count == 0:  # If the list is empty, initialize the first node
            new_node.next = self.N
            self.N.next = new_node
            new_node.prev = self.N
            self.N.prev = new_node
        else:  # If the list is not empty, insert the new node at the end
            new_node.next = self.N
            new_node.prev = self.N.prev
            self.N.prev.next = new_node
            self.N.prev = new_node
        self.count += 1  # Increase the count of nodes

# Main function to read commands and perform the corresponding operations
if __name__ == "__main__":
    n = int(input())  # Read the number of operations to be performed
    dll = DoublyLinkedList()  # Initialize the linked list

    for _ in range(n):  # Perform each operation in the loop
        command = input().strip()  # Read the command string
        if command == "insert":  # If the command is to insert a node
            key = int(input())
            dll.insert(key)
        elif command == "deleteFirst":
            dll.delete_first()  # If the command is to delete the first node
        elif command == "deleteLast":
            dll.delete_last()  # If the command is to delete the last node
        else:  # If the command is to delete a node with a given key
            key = int(input())
            dll.delete(key)

    dll.print_list()  # Print the updated list after performing all the operations
# <END-OF-CODE>
