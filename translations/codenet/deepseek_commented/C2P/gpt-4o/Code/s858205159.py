class Node:
    def __init__(self, key):
        self.key = key  # The integer key stored in the node
        self.next = None  # Pointer to the next node in the list
        self.prev = None  # Pointer to the previous node in the list

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)  # Sentinel node (dummy node)
        self.nil.next = self.nil  # The next pointer of the sentinel node points to itself
        self.nil.prev = self.nil  # The prev pointer of the sentinel node points to itself

    def list_search(self, key):
        cur = self.nil.next  # Start from the first node
        while cur != self.nil:  # Traverse the list until we reach the sentinel node
            if cur.key == key:
                return cur  # Return the node with the matching key
            cur = cur.next  # Move to the next node
        return self.nil  # Return nil if not found

    def print_list(self):
        cur = self.nil.next  # Start from the first node
        is_first = True  # Flag to check if it's the first node to be printed
        while True:
            if cur == self.nil:
                break  # If we reach the sentinel node, break the loop
            if not is_first:
                print(" ", end="")  # Print a space before each key except the first
            print(cur.key, end="")  # Print the key of the current node
            cur = cur.next  # Move to the next node
            is_first = False  # Update the flag to indicate that a node has been printed
        print()  # Print a newline character at the end

    def delete_node(self, t):
        if t == self.nil:
            return  # If the node is the sentinel node, do nothing
        t.prev.next = t.next  # Update the next pointer of the previous node
        t.next.prev = t.prev  # Update the prev pointer of the next node

    def delete_first(self):
        t = self.nil.next  # Get the first node
        if t == self.nil:
            return  # If the list is empty, do nothing
        self.delete_node(t)  # Delete the first node

    def delete_last(self):
        t = self.nil.prev  # Get the last node
        if t == self.nil:
            return  # If the list is empty, do nothing
        self.delete_node(t)  # Delete the last node

    def delete_key(self, key):
        t = self.list_search(key)  # Find the node with the specified key
        if t != self.nil:
            self.delete_node(t)  # If the node is found, delete it

    def insert(self, key):
        x = Node(key)  # Create a new node
        x.prev = self.nil  # The prev pointer of the new node points to the sentinel node
        x.next = self.nil.next  # The next pointer of the new node points to the current first node
        x.next.prev = x  # Update the prev pointer of the current first node
        self.nil.next = x  # Update the next pointer of the sentinel node to the new node

def main():
    n = int(input())  # Read the number of commands
    dll = DoublyLinkedList()  # Initialize the list
    for _ in range(n):
        command = input().split()  # Read the command and the key
        if command[0] == 'i':
            key = int(command[1])
            dll.insert(key)  # Insert a new node if the command is 'i'
        elif command[0] == 'd':
            if len(command) > 1:  # Check if the command is to delete the first or last node
                if command[1] == 'F':
                    dll.delete_first()
                elif command[1] == 'L':
                    dll.delete_last()
            else:
                key = int(command[1])
                dll.delete_key(key)  # Delete the node with the specified key

    dll.print_list()  # Print the final state of the list

if __name__ == "__main__":
    main()

# <END-OF-CODE>
