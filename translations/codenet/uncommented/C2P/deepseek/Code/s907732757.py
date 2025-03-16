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

    def makenode(self, a):
        return Node(a)

    def insert(self, a):
        x = self.makenode(a)
        x.next = self.head.next
        self.head.next.prev = x
        self.head.next = x
        x.prev = self.head

    def delete(self, a):
        x = self.head
        while x.next != self.head:
            x = x.next
            if x.key == a:
                x.prev.next = x.next
                x.next.prev = x.prev
                x = None
                break

    def deleteFirst(self):
        x = self.head.next
        self.head.next = x.next
        x.next.prev = self.head
        x = None

    def deleteLast(self):
        x = self.head.prev
        self.head.prev = x.prev
        x.prev.next = self.head
        x = None

    def printList(self):
        x = self.head
        while x.next != self.head:
            print(x.next.key, end="")
            x = x.next
            if x.next != self.head:
                print(" ", end="")
        print()


if __name__ == "__main__":
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        op = input().strip()
        if op == "insert":
            a = int(input().strip())
            dll.insert(a)
        elif op == "delete":
            a = int(input().strip())
            dll.delete(a)
        elif op == "deleteFirst":
            dll.deleteFirst()
        elif op == "deleteLast":
            dll.deleteLast()
    dll.printList()
