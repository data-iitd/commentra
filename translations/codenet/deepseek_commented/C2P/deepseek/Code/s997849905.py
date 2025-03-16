class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class CircularDoublyLinkedList:
    def __init__(self):
        self.sentinel = Node(None)
        self.sentinel.next = self.sentinel
        self.sentinel.prev = self.sentinel

    def insert(self, key):
        new_node = Node(key)
        if self.sentinel.next is self.sentinel:
            new_node.next = self.sentinel
            self.sentinel.next = new_node
            new_node.prev = self.sentinel
            self.sentinel.prev = new_node
        else:
            new_node.next = self.sentinel.next
            self.sentinel.next.prev = new_node
            self.sentinel.next = new_node
            new_node.prev = self.sentinel

    def delete_first(self):
        if self.sentinel.next is not self.sentinel:
            first_node = self.sentinel.next
            self.sentinel.next = first_node.next
            first_node.next.prev = self.sentinel
            first_node.next = None
            first_node.prev = None

    def delete_last(self):
        if self.sentinel.prev is not self.sentinel:
            last_node = self.sentinel.prev
            self.sentinel.prev = last_node.prev
            last_node.prev.next = self.sentinel
            last_node.next = None
            last_node.prev = None

    def delete(self, key):
        found = False
        current = self.sentinel.next
        while current is not self.sentinel:
            if current.key == key:
                found = True
                break
            current = current.next

        if found:
            current.prev.next = current.next
            current.next.prev = current.prev
            current.next = None
            current.prev = None

    def print_list(self):
        current = self.sentinel.next
        first_element = True
        while current is not self.sentinel:
            if not first_element:
                print(" ", end="")
            print(current.key, end="")
            current = current.next
            first_element = False
        print()

# Main function to execute the operations on the circular doubly linked list
def main():
    n = int(input())
    cdll = CircularDoublyLinkedList()
    for _ in range(n):
        com = input().split()
        if com[0] == "insert":
            key = int(com[1])
            cdll.insert(key)
        elif com[0] == "deleteFirst":
            cdll.delete_first()
        elif com[0] == "deleteLast":
            cdll.delete_last()
        elif com[0] == "delete":
            key = int(com[1])
            cdll.delete(key)
    cdll.print_list()

if __name__ == "__main__":
    main()
