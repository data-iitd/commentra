#include<stdio.h>
#include<stdlib.h>

class Node:
  def __init__(self, key, left, right, parent):
    self.key = key
    self.left = left
    self.right = right
    self.parent = parent

root = None

# This function finds the node with the minimum key in the subtree rooted at x
def treeMinimum(x):
  while x.left != None:
    x = x.left
  return x

# This function finds the node with the maximum key in the subtree rooted at x
def treeMaximum(x):
  while x.right != None:
    x = x.right
  return x

# This function searches for a node with a given key k in the subtree rooted at u
def treeSearch(u, k):
  if u == None or k == u.key:
    return u
  if k < u.key:
    return treeSearch(u.left, k)
  else:
    return treeSearch(u.right, k)

# This function finds the successor of a given node x in the tree
def treeSuccessor(x):
  y = None
  if x.right != None:
    return treeMinimum(x.right)
  y = x.parent
  while y != None and x == y.right:
    x = y
    y = y.parent
  return y

# This function deletes a node z from the tree
def treeDelete(z):
  y = None
  x = None
  if z.left == None or z.right == None:
    y = z
  else:
    y = treeSuccessor(z)
  if y.left != None:
    x = y.left
  else:
    x = y.right
  if x != None:
    x.parent = y.parent
  if y.parent == None:
    root = x
  else:
    if y.key < y.parent.key:
      y.parent.left = x
    else:
      y.parent.right = x
  if y != z:
    z.key = y.key

# This function inserts a new node with key k into the tree
def insert(k):
  y = None
  x = root
  z = Node(k, None, None, None)
  while x != None:
    y = x
    if z.key < x.key:
      x = x.left
    else:
      x = x.right
  z.parent = y
  if y == None:
    root = z
  else:
    if z.key < y.key:
      y.left = z
    else:
      y.right = z

# This function performs an inorder traversal of the tree and prints the keys
def inorder(u):
  if u == None:
    return
  inorder(u.left)
  print(u.key, end=" ")
  inorder(u.right)

# This function performs a preorder traversal of the tree and prints the keys
def preorder(u):
  if u == None:
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
      if t != None:
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

if __name__ == "__main__":
  main()

