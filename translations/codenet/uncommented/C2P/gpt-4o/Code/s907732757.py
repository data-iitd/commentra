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

    def insert(self, key):
        new_node = Node(key)
        new_node.next = self.head.next
        self.head.next.prev = new_node
        self.head.next = new_node
        new_node.prev = self.head

    def delete(self, key):
        current = self.head
        while current.next != self.head:
            current = current.next
            if current.key == key:
                current.prev.next = current.next
                current.next.prev = current.prev
                del current
                break

    def delete_first(self):
        if self.head.next != self.head:  # Check if the list is not empty
            first_node = self.head.next
            self.head.next = first_node.next
            first_node.next.prev = self.head
            del first_node

    def delete_last(self):
        if self.head.prev != self.head:  # Check if the list is not empty
            last_node = self.head.prev
            self.head.prev = last_node.prev
            last_node.prev.next = self.head
            del last_node

    def display(self):
        current = self.head
        result = []
        while current.next != self.head:
            current = current.next
            result.append(current.key)
        return result

if __name__ == "__main__":
    n = int(input())
    dll = DoublyLinkedList()
    
    for _ in range(n):
        operation = input().strip().split()
        if operation[0] == "insert":
            dll.insert(int(operation[1]))
        elif operation[0] == "delete":
            dll.delete(int(operation[1]))
        elif operation[0] == "deleteFirst":
            dll.delete_first()
        elif operation[0] == "deleteLast":
            dll.delete_last()

    print(" ".join(map(str, dll.display())))

# <END-OF-CODE>
