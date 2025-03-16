class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.nil = Node(None)
        self.nil.next = self.nil
        self.nil.prev = self.nil

    def listSearch(self, key):
        cur = self.nil.next
        while cur != self.nil and cur.key != key:
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

    def delete(self, key):
        t = self.listSearch(key)
        if t == self.nil:
            return
        self.deleteNode(t)

    def insert(self, key):
        x = Node(key)
        x.next = self.nil.next
        self.nil.next.prev = x
        self.nil.next = x
        x.prev = self.nil

# Main function to handle input and operations
def main():
    n = int(input())
    dll = DoublyLinkedList()
    np = 0
    nd = 0
    size = 0

    for _ in range(n):
        com = input().split()
        key = int(com[1])

        if com[0] == 'i':
            dll.insert(key)
            np += 1
            size += 1
        elif com[0] == 'd':
            if len(com) > 1 and com[1] == 'F':
                dll.deleteFirst()
            elif len(com) > 1 and com[1] == 'L':
                dll.deleteLast()
            else:
                dll.delete(key)
                nd += 1
            size -= 1

    dll.printList()

if __name__ == "__main__":
    main()
