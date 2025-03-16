#include<stdio.h>
#include<stdlib.h>

#define NIL NULL

class Node:
  def __init__(self, key):
    self.key = key
    self.left = NIL
    self.right = NIL
    self.parent = NIL

root = NIL

def treeMinimum(x):
  while(x.left!= NIL):
    x = x.left
  return x

def treeMaximum(x):
  while(x.right!= NIL):
    x = x.right
  return x

def treeSearch(u, k):
  if(u == NIL or k == u.key):
    return u
  if(k < u.key):
    return treeSearch(u.left, k)
  else:
    return treeSearch(u.right, k)

def treeSuccessor(x):
  y = NIL
  if(x.right!= NIL):
    return treeMinimum(x.right)
  y = x.parent
  while(y!= NIL and x == y.right):
    x = y
    y = y.parent
  return y

def treeDelete(z):
  y = NIL
  x = NIL
  if(z.left == NIL or z.right == NIL):
    y = z
  else:
    y = treeSuccessor(z)
  if(y.left!= NIL):
    x = y.left
  else:
    x = y.right
  if(x!= NIL):
    x.parent = y.parent
  if(y.parent == NIL):
    root = x
  elif(y == y.parent.left):
    y.parent.left = x
  else:
    y.parent.right = x
  if(y!= z):
    z.key = y.key

def insert(k):
  y = NIL
  x = root
  z = Node(k)
  while(x!= NIL):
    y = x
    if(z.key < x.key):
      x = x.left
    else:
      x = x.right
  z.parent = y
  if(y == NIL):
    root = z
  elif(z.key < y.key):
    y.left = z
  else:
    y.right = z

def inorder(u):
  if(u == NIL):
    return
  inorder(u.left)
  print(" %d" % u.key, end="")
  inorder(u.right)

def preorder(u):
  if(u == NIL):
    return
  print(" %d" % u.key, end="")
  preorder(u.left)
  preorder(u.right)

n = int(input())
for i in range(n):
  com = input()
  if(com[0] == 'f'):
    x = int(input())
    t = treeSearch(root, x)
    if(t!= NIL):
      print("yes\n", end="")
    else:
      print("no\n", end="")
  elif(com[0] == 'i'):
    x = int(input())
    insert(x)
  elif(com[0] == 'p'):
    inorder(root)
    print("\n", end="")
    preorder(root)
    print("\n", end="")
  elif(com[0] == 'd'):
    x = int(input())
    treeDelete(treeSearch(root, x))

#