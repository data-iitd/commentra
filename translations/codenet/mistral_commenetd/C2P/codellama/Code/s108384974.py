
#include<stdio.h>
#include<stdlib.h>

#define NIL None

class Node:
  def __init__(self, key, p, l, r):
    self.key = key
    self.p = p
    self.l = l
    self.r = r

class AVL:
  def __init__(self):
    self.r = NIL

  def find(self, x, k):
    while x != NIL and k != x.key:
      if k < x.key:
        x = x.l
      else:
        x = x.r
    return x

  def insert(self, k):
    y = NIL
    x = self.r
    z = Node(k, NIL, NIL, NIL)

    while x != NIL:
      y = x
      if z.key < x.key:
        x = x.l
      else:
        x = x.r

    z.p = y

    if y == NIL:
      self.r = z
    elif z.key < y.key:
      y.l = z
    else:
      y.r = z

  def inorder(self, u):
    if u == NIL:
      return
    self.inorder(u.l)
    print(u.key, end=" ")
    self.inorder(u.r)

  def preorder(self, u):
    if u == NIL:
      return
    print(u.key, end=" ")
    self.preorder(u.l)
    self.preorder(u.r)

  def print(self):
    self.inorder(self.r)
    print()
    self.preorder(self.r)
    print()

def main():
  n = int(input())
  for i in range(n):
    s = input()
    if s[0] == 'f':
      x = int(input())
      t = AVL().find(AVL().r, x)
      if t == NIL:
        print("no")
      else:
        print("yes")
    elif s[0] == 'i':
      z = int(input())
      AVL().insert(z)
    else:
      AVL().print()

main()

