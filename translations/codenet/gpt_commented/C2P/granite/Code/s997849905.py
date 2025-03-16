
class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(0)
        self.head.next = self.head
        self.head.prev = self.head

    def print_list(self):
        cur = self.head.next
        is_first = True
        while cur!= self.head:
            if not is_first:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            is_first = False
        print()

    def delete_first(self):
        t = self.head.next
        self.head.next = t.next
        t.next.prev = self.head

    def delete_last(self):
        delnode = self.head.prev
        self.head.prev = delnode.prev
        delnode.prev.next = self.head
        del delnode

    def delete(self, key):
        is_found = False
        n = self.head.next
        while n!= self.head:
            if n.key == key:
                is_found = True
                break
            n = n.next
        if is_found:
            t = n.prev
            t.next = n.next
            n.next.prev = t

    def insert(self, key):
        new = Node(key)
        if self.head.next == self.head:
            new.next = self.head
            self.head.next = new
            new.prev = self.head
            self.head.prev = new
        else:
            new.next = self.head.next
            self.head.next.prev = new
            self.head.next = new
            new.prev = self.head

# Main function to execute the program
def main():
    n = int(input())  # Read the number of operations
    dll = DoublyLinkedList()  # Initialize the doubly linked list
    for _ in range(n):  # Loop through each operation
        com = input()  # Read the command
        if com == "insert":
            key = int(input())  # Read the key to insert
            dll.insert(key)  # Call insert function
        elif com == "deleteFirst":
            dll.delete_first()  # Call deleteFirst function
        elif com == "deleteLast":
            dll.delete_last()  # Call deleteLast function
        else:
            key = int(input())  # Read the key to delete
            dll.delete(key)  # Call delete function
    dll.print_list()  # Print the final state of the list

if __name__ == "__main__":
    main()

