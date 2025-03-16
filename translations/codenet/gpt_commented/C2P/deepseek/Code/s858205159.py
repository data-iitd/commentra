class Node:
    def __init__(self, key):
        self.key = key
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def listSearch(self, key):
        cur = self.nil.next
        while cur != self.nil:
            if cur.key == key:
                break
            cur = cur.next
        return cur

    def init(self):
        self.nil = Node(None)
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def printList(self):
        cur = self.nil.next
        isf = True
        while True:
            if cur == self.nil:
                break
            if not isf:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            isf = False
        print()

    def deleteNode(self, t):
        if t == self.nil:
            return
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def deleteFirst(self):
        t = self.nil.next
        if t == self.nil:
            return
        self.deleteNode(t)

    def deleteLast(self):
        t = self.nil.prev
        if t == self.nil:
            return
        self.deleteNode(t)

    def deleteKey(self, key):
        t = self.listSearch(key)
        if t != self.nil:
            self.deleteNode(t)

    def insert(self, key):
        x = Node(key)
        x.prev = self.nil
        x.next = self.nil.next
        x.next.prev = x
        self.nil.next = x

def main():
    n = int(input())
    dll = DoublyLinkedList()
    dll.init()
    np = 0
    nd = 0
    for _ in range(n):
        com = input().split()
        key = int(com[1])
        if com[0] == 'i':
            dll.insert(key)
            np += 1
        elif com[0] == 'd':
            if len(com) > 2:
                if com[2] == 'F':
                    dll.deleteFirst()
                elif com[2] == 'L':
                    dll.deleteLast()
            else:
                dll.deleteKey(key)
                nd += 1
    dll.printList()

if __name__ == "__main__":
    main()
