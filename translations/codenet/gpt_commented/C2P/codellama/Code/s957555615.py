#include<stdio.h>
#include<stdlib.h>

#define NIL None

class Node:
  def __init__(self, key, left=NIL, right=NIL, parent=NIL):
    self.key = key
    self.left = left
    self.right = right
    self.parent = parent

root = NIL

def treeMinimum(x):
  while x.left != NIL:
    x = x.left
  return x

def treeMaximum(x):
  while x.right != NIL:
    x = x.right
  return x

def treeSearch(u, k):
  if u == NIL or k == u.key:
    return u
  if k < u.key:
    return treeSearch(u.left, k)
  else:
    return treeSearch(u.right, k)

def treeSuccessor(x):
  y = x.parent
  while y != NIL and x == y.right:
    x = y
    y = y.parent
  return y

def treeDelete(z):
  y = z
  if z.left == NIL or z.right == NIL:
    y = z
  else:
    y = treeSuccessor(z)
  x = y.left if y.left != NIL else y.right
  if x != NIL:
    x.parent = y.parent
  if y.parent == NIL:
    root = x
  elif y == y.parent.left:
    y.parent.left = x
  else:
    y.parent.right = x
  if y != z:
    z.key = y.key

def insert(k):
  y = NIL
  x = root
  z = Node(k)
  while x != NIL:
    y = x
    if z.key < x.key:
      x = x.left
    else:
      x = x.right
  z.parent = y
  if y == NIL:
    root = z
  elif z.key < y.key:
    y.left = z
  else:
    y.right = z

def inorder(u):
  if u == NIL:
    return
  inorder(u.left)
  print(u.key, end=" ")
  inorder(u.right)

def preorder(u):
  if u == NIL:
    return
  print(u.key, end=" ")
  preorder(u.left)
  preorder(u.right)

def main():
  n = int(input())
  for i in range(n):
    com = input()
    if com[0] == 'f':
      x = int(input())
      t = treeSearch(root, x)
      if t != NIL:
        print("yes")
      else:
        print("no")
    elif com[0] == 'i':
      x = int(input())
      insert(x)
    elif com[0] == 'p':
      inorder(root)
      print()
      preorder(root)
      print()
    elif com[0] == 'd':
      x = int(input())
      treeDelete(treeSearch(root, x))
    else:
      print("Invalid command")

if __name__ == "__main__":
  main()

