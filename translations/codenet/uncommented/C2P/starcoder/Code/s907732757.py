
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class node:
    def __init__(self, key):
        self.key = key
        self.next = None
        self.prev = None

head = node(0)
head.next = head
head.prev = head

def makenode(a):
    x = node(a)
    return x

def insert(a):
    x = makenode(a)
    x.next = head.next
    head.next.prev = x
    head.next = x
    x.prev = head

def delete(a):
    x = head
    while(x.next!= head):
        x = x.next
        if(x.key == a):
            x.prev.next = x.next
            x.next.prev = x.prev
            del x
            break

def deleteFirst():
    x = head.next
    head.next = x.next
    x.next.prev = head
    del x

def deleteLast():
    x = head.prev
    head.prev = x.prev
    x.prev.next = head
    del x

n = int(input())
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
    print(x.next.key, end = " ")
    x = x.next
print()

