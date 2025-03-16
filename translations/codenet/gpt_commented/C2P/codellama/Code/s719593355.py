#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil None

class Node:
    def __init__(self, key):
        self.key = key
        self.next = nil
        self.prev = nil

    def __str__(self):
        return str(self.key)

    def __repr__(self):
        return str(self.key)

class List:
    def __init__(self):
        self.head = Node(None)
        self.tail = Node(None)
        self.head.next = self.tail
        self.tail.prev = self.head

    def __str__(self):
        cur = self.head.next
        isf = 1
        s = ""
        while cur != self.tail:
            if isf == 0:
                s += " "
            s += str(cur)
            cur = cur.next
            isf = 0
        return s

    def search(self, key):
        cur = self.head.next
        while cur != self.tail and cur.key != key:
            cur = cur.next
        return cur

    def insert(self, key):
        x = Node(key)
        x.next = self.head.next
        self.head.next.prev = x
        self.head.next = x
        x.prev = self.head

    def delete(self, key):
        t = self.search(key)
        if t == nil:
            return
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def deleteFirst(self):
        t = self.head.next
        if t == self.tail:
            return
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def deleteLast(self):
        t = self.tail.prev
        if t == self.head:
            return
        t.prev.next = t.next
        t.next.prev = t.prev
        del t

    def printList(self):
        print(self)

# Main function
def main():
    n = int(input())
    l = List()
    for i in range(n):
        com = input().split()
        if com[0] == "i":
            l.insert(int(com[1]))
        elif com[0] == "d":
            if len(com) == 2:
                l.delete(int(com[1]))
            elif com[1] == "F":
                l.deleteFirst()
            elif com[1] == "L":
                l.deleteLast()
        l.printList()

if __name__ == "__main__":
    main()

