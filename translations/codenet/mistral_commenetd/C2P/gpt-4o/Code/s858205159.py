class Node:
    def __init__(self, key):
        self.key = key  # Key value of the node
        self.next = None  # Pointer to the next node
        self.prev = None  # Pointer to the previous node

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)  # Initialize nil node
        self.nil.next = self.nil  # Initialize next pointer of nil to itself
        self.nil.prev = self.nil  # Initialize prev pointer of nil to itself

    def list_search(self, key):
        cur = self.nil.next  # Initialize current node as the first node after nil
        while cur != self.nil:  # Traverse the list until nil is reached
            if cur.key == key:
                return cur  # Return the found node
            cur = cur.next  # Move to the next node
        return None  # Return None if not found

    def print_list(self):
        cur = self.nil.next  # Initialize current node as the first node after nil
        is_first = True  # Initialize isFirst flag
        while True:
            if cur == self.nil:  # If the current node is nil, break the loop
                break
            if is_first:
                print(f"[{cur.key}]", end=" ")  # Print with brackets for the first node
            else:
                print(cur.key, end=" ")  # Print normally for subsequent nodes
            cur = cur.next  # Move to the next node
            is_first = False  # Set isFirst flag to False
        print()  # Print a newline after the list is printed

    def delete_node(self, t):
        if t == self.nil:  # Return if the node to be deleted is nil
            return
        t.prev.next = t.next  # Update the next pointer of the previous node
        t.next.prev = t.prev  # Update the prev pointer of the next node
        del t  # Free the memory allocated to the deleted node

    def delete_first(self):
        t = self.nil.next  # Initialize the node to be deleted as the first node
        if t == self.nil:  # Return if the list is empty
            return
        self.delete_node(t)  # Delete the first node

    def delete_last(self):
        t = self.nil.prev  # Initialize the node to be deleted as the last node
        if t == self.nil:  # Return if the list is empty
            return
        self.delete_node(t)  # Delete the last node

    def delete_key(self, key):
        t = self.list_search(key)  # Search for the node with the given key
        if t is not None:  # Delete the node if it's found
            self.delete_node(t)

    def insert(self, key):
        x = Node(key)  # Allocate memory for the new node
        x.prev = self.nil  # Set the prev pointer of the new node to nil
        x.next = self.nil.next  # Set the next pointer of the new node to the first node after nil
        self.nil.next.prev = x  # Update the prev pointer of the first node after nil
        self.nil.next = x  # Update the next pointer of nil to point to the new node

def main():
    n = int(input())  # Read the number of commands
    dll = DoublyLinkedList()  # Initialize the linked list
    for _ in range(n):  # Traverse the commands
        command = input().split()  # Read the command and the key value
        if command[0] == 'i':  # If the command is 'i', insert a new node
            key = int(command[1])
            dll.insert(key)
        elif command[0] == 'd':  # If the command is 'd', delete a node
            if len(command) > 1:  # If the command is 'd F' or 'd L'
                if command[1] == 'F':
                    dll.delete_first()
                elif command[1] == 'L':
                    dll.delete_last()
            else:  # Otherwise, delete a node with the given key
                key = int(command[1])
                dll.delete_key(key)

    dll.print_list()  # Print the updated linked list

if __name__ == "__main__":
    main()  # Call the main function

# <END-OF-CODE>
