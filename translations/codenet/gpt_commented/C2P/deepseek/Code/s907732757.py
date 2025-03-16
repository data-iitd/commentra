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

    def makenode(self, key):
        return Node(key)

    def insert(self, key):
        x = self.makenode(key)
        x.next = self.head.next
        self.head.next.prev = x
        self.head.next = x
        x.prev = self.head

    def delete(self, key):
        x = self.head
        while x.next != self.head:
            x = x.next
            if x.key == key:
                x.prev.next = x.next
                x.next.prev = x.prev
                x = None
                break

    def delete_first(self):
        x = self.head.next
        self.head.next = x.next
        x.next.prev = self.head
        x = None

    def delete_last(self):
        x = self.head.prev
        self.head.prev = x.prev
        x.prev.next = self.head
        x = None

    def print_list(self):
        x = self.head
        while x.next != self.head:
            print(x.next.key, end=" ")
            x = x.next
        print()

# Main function to handle operations
def main():
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        op = input().split()
        if op[0] == "insert":
            dll.insert(int(op[1]))
        elif op[0] == "delete":
            dll.delete(int(op[1]))
        elif op[0] == "deleteFirst":
            dll.delete_first()
        elif op[0] == "deleteLast":
            dll.delete_last()
    dll.print_list()

if __name__ == "__main__":
    main()
