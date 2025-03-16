
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 1000000

#define init() N = [Node(0)]

class Node:
  def __init__(self, key):
    self.key = key
    self.next = None
    self.prev = None

N = [Node(0)]

def printList():
  cur = N[0].next
  snl = 1
  while cur!= N[0]:
    if snl == 0:
      print(" ", end="")
    print(cur.key, end="")
    cur = cur.next
    snl = 0
  print()

def deleteFirst():
  t = N[0].next
  N[0].next = t.next
  t.next.prev = N[0]

def deleteLast():
  delnode = N[0].prev
  N[0].prev = delnode.prev
  delnode.prev.next = N[0]
  del delnode

def delete(skey):
  judge = 0
  n = N[0].next
  t = n.prev
  while n!= N[0]:
    if n.key == skey:
      judge = 1
      break
    n = n.next
    t = t.next
  if judge == 1:
    t.next = n.next
    t.next.prev = t
    del n

def insert(skey):
  new = Node(skey)
  global N
  if len(N) == 1:
    new.next = N[0]
    N[0].next = new
    new.prev = N[0]
    N[0].prev = new
    N.append(new)
  else:
    new.next = N[0].next
    N[0].next.prev = new
    N[0].next = new
    new.prev = N[0]
    N.append(new)

def main():
  n, i, key
  com = [0] * 12
  init()
  scanf("%d", &n)
  for i in range(n):
    scanf("%s", com)
    if strcmp(com, "insert") == 0:
      scanf("%d", &key)
      insert(key)
    elif strcmp(com, "deleteFirst") == 0:
      deleteFirst()
    elif strcmp(com, "deleteLast") == 0:
      deleteLast()
    else:
      scanf("%d", &key)
      delete(key)
  printList()

main()

