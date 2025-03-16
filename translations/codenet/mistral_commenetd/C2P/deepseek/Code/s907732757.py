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
                prev = x.prev
                prev.next = x.next
                x.next.prev = prev
                del x
                break

    def deleteFirst(self):
        x = self.head.next
        self.head.next = x.next
        x.next.prev = self.head
        del x

    def deleteLast(self):
        x = self.head
        while x.next != self.head:
            x = x.next
        prev = x.prev
        prev.next = None
        self.head.prev = prev
        del x

    def printList(self):
        x = self.head
        while x.next != self.head:
            print(x.next.key, end=" ")
            x = x.next
        print()

if __name__ == "__main__":
    n = int(input())
    dll = DoublyLinkedList()
    for _ in range(n):
        op = input().strip()
        if op == "insert":
            a = int(input())
            dll.insert(a)
        elif op == "delete":
            a = int(input())
            dll.delete(a)
        elif op == "deleteFirst":
            dll.deleteFirst()
        elif op == "deleteLast":
            dll.deleteLast()
    dll.printList()

