
#include<stdio.h>
#include<stdlib.h>

class Node:
  def __init__(self,key):
    self.key = key
    self.p = None
    self.l = None
    self.r = None

NIL = Node(0)

def find(x,k):
  while(x!= NIL and k!= x.key):
    if(k < x.key):
      x = x.l
    else:
      x = x.r
  return x

def insert(k):
  y = NIL
  x = r
  z = Node(k)
  z.l = NIL
  z.r = NIL
  while(x!= NIL):
    y = x
    if(z.key < x.key):
      x = x.l
    else:
      x = x.r
  z.p = y
  if(y == NIL):
    r = z
  elif(z.key < y.key):
    y.l = z
  else:
    y.r = z

def inorder(u):
  if(u == NIL):
    return
  inorder(u.l)
  print(" %d" % u.key,end="")
  inorder(u.r)

def preorder(u):
  if(u == NIL):
    return
  print(" %d" % u.key,end="")
  preorder(u.l)
  preorder(u.r)

def print():
  inorder(r)
  print("")
  preorder(r)
  print("")

n = int(input())
for i in range(n):
  s = input()
  if(s[0] == 'f'):
    x = int(input())
    t = find(r,x)
    if(t == NIL):
      print("no")
    else:
      print("yes")
  elif(s[0] == 'i'):
    z = int(input())
    insert(z)
  else:
    print()

#