
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
        self.head = None

    def init(self):
        if self.head == None:
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
                prev = x.prev
                prev.next = x.next
                x.next.prev = prev
                free(x)
                break

    def deleteFirst(self):
        x = self.head.next
        self.head.next = x.next
        x.next.prev = self.head
        free(x)

    def deleteLast(self):
        x = self.head
        while x.next != self.head:
            x = x.next
        prev = x.prev
        prev.next = None
        self.head.prev = prev
        free(x)

    def main():
        n = int(input())
        for i in range(n):
            op = input()
            if op == "insert":
                a = int(input())
                insert(a)
            elif op == "delete":
                a = int(input())
                delete(a)
            elif op == "deleteFirst":
                deleteFirst()
            elif op == "deleteLast":
                deleteLast()
        x = self.head
        while x.next != self.head:
            print(x.next.key, end=" ")
            x = x.next
        print()

    if __name__ == "__main__":
        main()

