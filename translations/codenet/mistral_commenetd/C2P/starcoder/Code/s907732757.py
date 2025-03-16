
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class Node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

head = None

def init():
    global head
    head = Node(0)
    head.next = head
    head.prev = head

def insert(a):
    x = Node(a)
    x.next = head.next
    head.next.prev = x
    head.next = x
    x.prev = head

def delete(a):
    x = head
    while(x.next!= head):
        x = x.next
        if(x.key == a):
            prev = x.prev
            prev.next = x.next
            x.next.prev = prev
            del x
            break

def deleteFirst():
    x = head.next
    head.next = x.next
    x.next.prev = head
    del x

def deleteLast():
    x = head
    while(x.next!= head):
        x = x.next
    prev = x.prev
    prev.next = None
    head.prev = prev
    del x

def main():
    n, a = map(int, input().split())
    init()
    for i in range(n):
        op = input()
        if(op == "insert"):
            a = int(input())
            insert(a)
        elif(op == "delete"):
            a = int(input())
            delete(a)
        elif(op == "deleteFirst"):
            deleteFirst()
        elif(op == "deleteLast"):
            deleteLast()
    x = head
    while(x.next!= head):
        print(x.next.key, end=" ")
        x = x.next
    print()

main()

