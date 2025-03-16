
# -*- coding: utf-8 -*-

class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

class DoubleLinkedList:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head
        self.count = 0

    def printList(self):
        cur = self.head.next
        snl = 1
        while cur!= self.tail:
            if snl == 0:
                print(" ", end="")
            print(cur.key, end="")
            cur = cur.next
            snl = 0
        print()

    def deleteFirst(self):
        t = self.head.next
        self.head.next = t.next
        t.next.prev = self.head

    def deleteLast(self):
        delnode = self.tail.prev
        self.tail.prev = delnode.prev
        delnode.prev.next = self.tail
        del delnode

    def delete(self, skey):
        judge = 0
        n = self.head.next
        while n!= self.tail:
            if n.key == skey:
                judge = 1
            n = n.next
        if judge == 1:
            n = self.head.next
            while n!= self.tail:
                if n.key == skey:
                    break
                n = n.next
            t = n.prev
            t.next = n.next
            t.next.prev = t
            del n

    def insert(self, skey):
        new = Node(skey)
        if self.count == 0:
            new.next = self.head
            self.head.next = new
            new.prev = self.head
            self.head.prev = new
            self.count += 1
        else:
            new.next = self.head.next
            self.head.next.prev = new
            self.head.next = new
            new.prev = self.head
            self.count += 1

if __name__ == "__main__":
    n = int(input())
    dll = DoubleLinkedList()
    for i in range(n):
        com = input().split()
        if com[0] == "insert":
            dll.insert(int(com[1]))
        elif com[0] == "deleteFirst":
            dll.deleteFirst()
        elif com[0] == "deleteLast":
            dll.deleteLast()
        else:
            dll.delete(int(com[1]))
    dll.printList()

