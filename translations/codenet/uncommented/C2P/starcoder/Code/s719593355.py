
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None

nil = Node(0)
nil.next = nil
nil.prev = nil

def listSearch(key):
  cur = nil.next
  while cur!= nil and cur.key!= key:
    cur = cur.next
  return cur

def init():
  nil = Node(0)
  nil.next = nil
  nil.prev = nil

def printList():
  cur = nil.next
  isf = 1
  while cur!= nil:
    if isf == 0:
      print(" ", end="")
    print(cur.key, end="")
    cur = cur.next
    isf = 0
  print()

def deleteNode(t):
  t.prev.next = t.next
  t.next.prev = t.prev
  del t

def deleteFirst():
  t = nil.next
  if t == nil:
    return
  deleteNode(t)

def deleteLast():
  t = nil.prev
  if t == nil:
    return
  deleteNode(t)

def delete(key):
  t = listSearch(key)
  if t == nil:
    return
  deleteNode(t)

def insert(key):
  x = Node(key)
  x.next = nil.next
  nil.next.prev = x
  nil.next = x
  x.prev = nil

n = int(input())
init()
for i in range(n):
  com = input()
  if com[0] == 'i':
    key = int(com[2:])
    insert(key)
  elif com[0] == 'd':
    if len(com) > 6:
      if com[6] == 'F':
        deleteFirst()
      elif com[6] == 'L':
        deleteLast()
    else:
      key = int(com[2:])
      delete(key)
printList()

