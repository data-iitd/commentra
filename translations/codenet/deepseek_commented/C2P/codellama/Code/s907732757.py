#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define head head_node

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

    def insert(self, a):
        x = Node(a)
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
            print(x.next.key, end=" ")
            x = x.next
        print()

# Driver code
if __name__ == "__main__":
    d = DoublyLinkedList()
    n = int(input())
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
    d.printList()

