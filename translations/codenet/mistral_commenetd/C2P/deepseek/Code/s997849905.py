class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(None)
        self.head.next = self.head
        self.head.prev = self.head
        self.count = 0

    def insert(self, key):
        new_node = Node(key)
        if self.count == 0:
            new_node.next = self.head
            self.head.next = new_node
            new_node.prev = self.head
            self.head.prev = new_node
            self.count += 1
        else:
            new_node.next = self.head.next
            self.head.next.prev = new_node
            self.head.next = new_node
            new_node.prev = self.head
            self.count += 1

    def delete_first(self):
        if self.count > 0:
            first_node = self.head.next
            self.head.next = first_node.next
            first_node.next.prev = self.head
            self.count -= 1

    def delete_last(self):
        if self.count > 0:
            last_node = self.head.prev
            self.head.prev = last_node.prev
            last_node.prev.next = self.head
            self.count -= 1

    def delete(self, key):
        found = False
        current = self.head.next
        while current != self.head:
            if current.key == key:
                found = True
                break
            current = current.next

        if found:
            current.prev.next = current.next
            current.next.prev = current.prev
            self.count -= 1

    def print_list(self):
        current = self.head.next
        snl = 1
        while current != self.head:
            if snl == 0:
                print(" ", end="")
            print(current.key, end="")
            current = current.next
            snl = 0
        print()

# Main function to read commands and perform the corresponding operations
def main():
    n = int(input())
    dll = DoublyLinkedList()

    for _ in range(n):
        com = input().strip()
        if com == "insert":
            key = int(input())
            dll.insert(key)
        elif com == "deleteFirst":
            dll.delete_first()
        elif com == "deleteLast":
            dll.delete_last()
        elif com == "delete":
            key = int(input())
            dll.delete(key)

    dll.print_list()

if __name__ == "__main__":
    main()
