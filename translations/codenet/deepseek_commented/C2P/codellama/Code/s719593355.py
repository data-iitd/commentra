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

  def init(self):
    self.nil = Node(0)
    self.nil.next = self.nil
    self.nil.prev = self.nil

  def printList(self):
    cur = self.nil.next
    isf = 1
    while 1:
      if cur == self.nil:
        break
      if isf == 0:
        print(" ", end="")
      print(cur.key, end="")
      cur = cur.next
      isf = 0
    print("\n")

  def deleteNode(self, t):
    t.prev.next = t.next
    t.next.prev = t.prev
    free(t)

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

  def main(self):
    n = int(input())
    self.init()
    for i in range(n):
      com = input()
      key = int(input())
      if com[0] == 'i':
        self.insert(key)
      elif com[0] == 'd':
        if len(com) > 6:
          if com[6] == 'F':
            self.deleteFirst()
          elif com[6] == 'L':
            self.deleteLast()
        else:
          self.delete(key)

if __name__ == "__main__":
  l = List()
  l.main()

