#include <stdio.h>

#define MAX 25

class node:
  def __init__(self):
    self.l = -1
    self.r = -1
    self.par = -1

N = [node() for i in range(MAX)]

def init(n):
  for i in range(n):
    N[i].l = -1
    N[i].r = -1
    N[i].par = -1

def Preorder(p):
  if p != -1:
    print(" %d" % p)
    Preorder(N[p].l)
    Preorder(N[p].r)

def Inorder(p):
  if p != -1:
    Inorder(N[p].l)
    print(" %d" % p)
    Inorder(N[p].r)

def Postorder(p):
  if p != -1:
    Postorder(N[p].l)
    Postorder(N[p].r)
    print(" %d" % p)

n = int(input())
init(n)

for i in range(n):
  id,l,r = map(int,input().split())

  if l != -1:
    N[id].l = l
    N[l].par = id
  if r != -1:
    N[id].r = r
    N[r].par = id

p = -1
for i in range(n):
  if N[i].par == -1:
    p = i
    break

print("Preorder")
Preorder(p)
print("")

print("Inorder")
Inorder(p)
print("")

print("Postorder")
Postorder(p)
print("")

