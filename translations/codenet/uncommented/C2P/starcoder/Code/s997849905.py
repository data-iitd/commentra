
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None
 
class DoubleLinkedList:
  def __init__(self):
    self.head = Node(None)
    self.tail = Node(None)
    self.head.next = self.tail
    self.tail.prev = self.head
    self.size = 0
 
  def printList(self):
    cur = self.head.next
    snl = 1
    while(cur!= self.tail):
      if ( snl == 0)  print(" ", end="")
      print(cur.key, end="")
      cur = cur.next
      snl = 0
    print("\n")
 
  def deleteFirst(self):
    t = self.head.next
    self.head.next = t.next
    t.next.prev = self.head
    self.size -= 1
 
  def deleteLast(self):
    delnode = self.tail.prev
    self.tail.prev = delnode.prev
    delnode.prev.next = self.tail
    self.size -= 1
 
  def delete(self, skey):
    judge = 0
    n = self.head.next
    while(n!= self.tail):
      if(n.key == skey):
	judge = 1
	break
      n=n.next
    if(judge == 1):
      t = n.prev
      t.next = n.next
      t.next.prev = t
      self.size -= 1
 
  def insert(self, skey):
    new = Node(skey)
    if(self.size == 0):
      new.next = self.tail
      self.tail.prev = new
      self.head.next = new
      new.prev = self.head
      self.size += 1
    else:
      new.next = self.head.next
      self.head.next.prev = new
      self.head.next = new
      new.prev = self.head
      self.size += 1
 
  def getSize(self):
    return self.size
 
  def isEmpty(self):
    return self.size == 0
 
  def getFirst(self):
    return self.head.next
 
  def getLast(self):
    return self.tail.prev
 
  def getAt(self, index):
    if(index < 0 or index >= self.size):
      return None
    cur = self.head.next
    for i in range(index):
      cur = cur.next
    return cur
 
  def getIndex(self, key):
    cur = self.head.next
    for i in range(self.size):
      if(cur.key == key):
	return i
      cur = cur.next
    return -1
 
  def getPrev(self, cur):
    if(cur == self.head.next):
      return None
    return cur.prev
 
  def getNext(self, cur):
    if(cur == self.tail.prev):
      return None
    return cur.next
 
  def insertBefore(self, cur, new):
    if(cur == None):
      return
    new.next = cur
    new.prev = cur.prev
    cur.prev.next = new
    cur.prev = new
    self.size += 1
 
  def insertAfter(self, cur, new):
    if(cur == None):
      return
    new.next = cur.next
    new.prev = cur
    cur.next.prev = new
    cur.next = new
    self.size += 1
 
  def deleteNode(self, cur):
    if(cur == None):
      return
    cur.prev.next = cur.next
    cur.next.prev = cur.prev
    self.size -= 1
 
  def deleteList(self):
    cur = self.head.next
    while(cur!= self.tail):
      t = cur
      cur = cur.next
      free(t)
    self.head.next = self.tail
    self.tail.prev = self.head
    self.size = 0
 
  def reverse(self):
    cur = self.head.next
    while(cur!= self.tail):
      t = cur.next
      cur.next = cur.prev
      cur.prev = t
      cur = t
    self.tail.prev = self.head
    self.head.next = self.tail
 
  def merge(self, l):
    if(self.size == 0):
      self.head.next = l.head.next
      self.tail.prev = l.tail.prev
      self.head.next.prev = self.head
      self.tail.prev.next = self.tail
      self.size = l.size
    else:
      self.tail.prev.next = l.head.next
      l.head.next.prev = self.tail.prev
      self.tail.prev = l.tail.prev
      self.tail.prev.next = self.tail
      self.size += l.size
 
  def split(self, index):
    if(index < 0 or index >= self.size):
      return None
    if(index == 0):
      l = DoubleLinkedList()
      l.head.next = self.head.next
      l.tail.prev = self.tail
      l.head.next.prev = l.head
      l.tail.prev.next = l.tail
      l.size = self.size
      self.head.next = self.tail
      self.tail.prev = self.head
      self.size = 0
      return l
    elif(index == self.size - 1):
      l = DoubleLinkedList()
      l.head.next = self.head
      l.tail.prev = self.tail.prev
      l.head.next.prev = l.head
      l.tail.prev.next = l.tail
      l.size = self.size
      self.head.next = self.tail
      self.tail.prev = self.head
      self.size = 0
      return l
    else:
      l = DoubleLinkedList()
      cur = self.head.next
      for i in range(index):
	cur = cur.next
      l.head.next = cur
      l.tail.prev = self.tail
      cur.prev.next = l.head
      self.tail.prev.next = l.tail
      l.head.next.prev = cur.prev
      l.tail.prev.next = self.tail
      l.size = index + 1
      self.tail.prev = cur.prev
      self.size -= index + 1
      return l
 
  def swap(self, l):
    t = self.head.next
    self.head.next = l.head.next
    l.head.next = t
    t = self.tail.prev
    self.tail.prev = l.tail.prev
    l.tail.prev = t
    t = self.size
    self.size = l.size
    l.size = t
 
  def rotateLeft(self, k):
    if(k == 0 or self.size == 0):
      return
    if(k > self.size):
      k = k % self.size
    if(k == self.size):
      return
    cur = self.head.next
    for i in range(k):
      cur = cur.next
    self.tail.prev.next = self.head.next
    self.head.next.prev = self.tail.prev
    self.tail.prev = cur.prev
    self.tail.prev.next = self.tail
    cur.prev.next = self.head
    self.head.next = cur
 
  def rotateRight(self, k):
    if(k == 0 or self.size == 0):
      return
    if(k > self.size):
      k = k % self.size
    if(k == self.size):
      return
    cur = self.tail.prev
    for i in range(k):
      cur = cur.prev
    self.head.next.prev = self.tail.prev
    self.tail.prev.next = self.head.next
    self.head.next = cur.next
    self.head.next.prev = self.head
    cur.next.next = self.tail
    self.tail.prev = cur
 
  def reverseBetween(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween2(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween3(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween4(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween5(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween6(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween7(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween8(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in range(i, j + 1):
      t = t.next
    t1 = cur.next
    t2 = t.prev
    for k in range(j - i + 1):
      t1.next, t1.prev, t2.next, t2.prev = t2, t1, t1, t2
      t1 = t1.next
      t2 = t2.prev
    self.tail.prev = t2
    self.head.next = t1
 
  def reverseBetween9(self, i, j):
    if(i == 0):
      self.reverse()
      return
    if(i > j or i < 0 or j >= self.size):
      return
    if(i == j):
      return
    cur = self.head.next
    for k in range(i):
      cur = cur.next
    t = cur
    for k in ran