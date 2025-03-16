#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
        x = Node(a)
        return x

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
                del x
                break

    def deleteFirst(self):
        x = self.head.next
        self.head.next = x.next
        x.next.prev = self.head
        del x

    def deleteLast(self):
        x = self.head.prev
        self.head.prev = x.prev
        x.prev.next = self.head
        del x


if __name__ == "__main__":
    n = int(input())
    d = DoublyLinkedList()
    for i in range(n):
        op = input().split()
        if op[0] == "insert":
            d.insert(int(op[1]))
        elif op[0] == "delete":
            d.delete(int(op[1]))
        elif op[0] == "deleteFirst":
            d.deleteFirst()
        elif op[0] == "deleteLast":
            d.deleteLast()

    x = d.head
    while x.next != d.head:
        print(x.next.key, end=" ")
        x = x.next
    print()

