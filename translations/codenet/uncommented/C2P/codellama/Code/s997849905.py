#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None
 
class List:
  def __init__(self):
    self.head = Node(0)
    self.head.next = self.head
    self.head.prev = self.head
 
  def printList(self):
    cur = self.head.next
    snl = 1
    while cur != self.head:
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
    delnode = self.head.prev
    self.head.prev = delnode.prev
    delnode.prev.next = self.head
 
  def delete(self, skey):
    judge = 0
    n = self.head.next
    while n != self.head:
      if n.key == skey:
        judge = 1
      n = n.next
    if judge == 1:
      n = self.head.next
      while n != self.head:
        if n.key == skey:
          break
        n = n.next
      t = n.prev
      t.next = n.next
      t.next.prev = t
      del n
 
  def insert(self, skey):
    new = Node(skey)
    if self.head.next == self.head:
      new.next = self.head
      self.head.next = new
      new.prev = self.head
      self.head.prev = new
    else:
      new.next = self.head.next
      self.head.next.prev = new
      self.head.next = new
      new.prev = self.head
 
  def main():
    n = int(input())
    L = List()
    for i in range(n):
      com = input()
      if com == "insert":
        key = int(input())
        L.insert(key)
      elif com == "deleteFirst":
        L.deleteFirst()
      elif com == "deleteLast":
        L.deleteLast()
      else:
        key = int(input())
        L.delete(key)
    L.printList()
 
  if __name__ == "__main__":
    main()
