#include<stdio.h>
#include<stdlib.h>

class Node:
  def __init__(self,key,p,l,r):
    self.key = key
    self.p = p
    self.l = l
    self.r = r

class Tree:
  def __init__(self):
    self.r = None
    self.NIL = None

  def find(self,x,k):
    while x != self.NIL and k != x.key:
      if k < x.key:
        x = x.l
      else:
        x = x.r
    return x

  def insert(self,k):
    y = self.NIL
    x = self.r

    z = Node(k,None,None,None)

    while x != self.NIL:
      y = x
      if z.key < x.key:
        x = x.l
      else:
        x = x.r

    z.p = y

    if y == self.NIL:
      self.r = z
    elif z.key < y.key:
      y.l = z
    else:
      y.r = z

  def inorder(self,u):
    if u == self.NIL:
      return
    self.inorder(u.l)
    print(" %d" % u.key)
    self.inorder(u.r)

  def preorder(self,u):
    if u == self.NIL:
      return
    print(" %d" % u.key)
    self.preorder(u.l)
    self.preorder(u.r)

  def print(self):
    self.inorder(self.r)
    print("")
    self.preorder(self.r)
    print("")

t = Tree()

n = int(input())
for i in range(n):
  s = input()
  if s[0] == 'f':
    x = int(input())
    t.find(t.r,x)
    if t.find(t.r,x) == None:
      print("no\n")
    else:
      print("yes\n")
  elif s[0] == 'i':
    z = int(input())
    t.insert(z)
  else:
    t.print()

# 