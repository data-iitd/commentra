#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None

class List:
  def __init__(self):
    self.nil = Node(0)
    self.nil.next = self.nil
    self.nil.prev = self.nil

  def search(self, key):
    cur = self.nil.next
    while cur != self.nil and cur.key != key:
      cur = cur.next
    return cur

  def printList(self):
    cur = self.nil.next
    isf = 1
    while 1:
      if cur == self.nil: break
      if isf == 0: print(" ", end="")
      print(cur.key, end="")
      cur = cur.next
      isf = 0
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
    t = self.search(key)
    if t == self.nil:
      return
    self.deleteNode(t)

  def insert(self, key):
    x = Node(key)
    x.next = self.nil.next
    self.nil.next.prev = x
    self.nil.next = x
    x.prev = self.nil


def main():
  n, i = map(int, input().split())
  l = List()
  for i in range(n):
    com, key = input().split()
    key = int(key)
    if com == "i":
      l.insert(key)
    elif com == "d":
      if len(com) > 6:
        if com[6] == "F":
          l.deleteFirst()
        elif com[6] == "L":
          l.deleteLast()
      else:
        l.delete(key)

  l.printList()


main()

