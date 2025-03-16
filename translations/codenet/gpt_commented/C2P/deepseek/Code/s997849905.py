class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = Node(None)  # Dummy head node
        self.head.next = self.head
        self.head.prev = self.head

    def insert(self, key):
        new_node = Node(key)
        new_node.next = self.head.next
        self.head.next.prev = new_node
        self.head.next = new_node
        new_node.prev = self.head

    def delete_first(self):
        if self.head.next != self.head:
            self.head.next = self.head.next.next
            self.head.next.prev = self.head

    def delete_last(self):
        if self.head.prev != self.head:
            self.head.prev = self.head.prev.prev
            self.head.prev.next = self.head

    def delete(self, key):
        current = self.head.next
        while current != self.head:
            if current.key == key:
                current.prev.next = current.next
                current.next.prev = current.prev
                return
            current = current.next

    def print_list(self):
        current = self.head.next
        while current != self.head:
            if current != self.head.next:
                print(" ", end="")
            print(current.key, end="")
            current = current.next
        print()

def main():
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        command = input().split()
        if command[0] == "insert":
            dll.insert(int(command[1]))
        elif command[0] == "deleteFirst":
            dll.delete_first()
        elif command[0] == "deleteLast":
            dll.delete_last()
        elif command[0] == "delete":
            dll.delete(int(command[1]))
    dll.print_list()

if __name__ == "__main__":
    main()
