#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000000000

#define init() {head = 0; tail = 0;}
#define printList() {print(head);}
#define deleteFirst() {head = head.next;}
#define deleteLast() {tail = tail.prev;}
#define delete(key) {NodePointer t = head; while(t != None and t.key != key): t = t.next; if(t != None): t.prev.next = t.next; t.next.prev = t.prev;}
#define insert(key) {NodePointer new = NodePointer(key); if(head == None): head = new; else: tail.next = new; new.prev = tail; tail = new;}

class NodePointer:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

    def __str__(self):
        return str(self.key)

    def __repr__(self):
        return str(self.key)

def main():
    n = int(input())
    init()
    for i in range(n):
        com = input()
        if com == "insert":
            key = int(input())
            insert(key)
        elif com == "deleteFirst":
            deleteFirst()
        elif com == "deleteLast":
            deleteLast()
        else:
            key = int(input())
            delete(key)
    printList()

if __name__ == "__main__":
    main()

