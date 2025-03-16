

class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert(self, key):
        new_node = Node(key)
        if self.head is None:
            self.head = new_node
            new_node.prev = new_node
            new_node.next = new_node
        else:
            new_node.next = self.head.next
            self.head.next.prev = new_node
            self.head.next = new_node
            new_node.prev = self.head

    def delete(self, key):
        current = self.head
        while current.next!= self.head:
            current = current.next
            if current.key == key:
                prev = current.prev
                prev.next = current.next
                current.next.prev = prev
                break

    def delete_first(self):
        second = self.head.next
        self.head.next = second.next
        second.next.prev = self.head

    def delete_last(self):
        current = self.head
        while current.next!= self.head:
            current = current.next
        prev = current.prev
        prev.next = None
        self.head.prev = prev

if __name__ == "__main__":
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        operation = input().split()
        if operation[0] == "insert":
            dll.insert(int(operation[1]))
        elif operation[0] == "delete":
            dll.delete(int(operation[1]))
        elif operation[0] == "deleteFirst":
            dll.delete_first()
        elif operation[0] == "deleteLast":
            dll.delete_last()
    current = dll.head.next
    while current!= dll.head:
        print(current.key, end=" ")
        current = current.next
    print()

