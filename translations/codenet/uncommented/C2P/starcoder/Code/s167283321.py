
#include <stdio.h>
#define NIL -1
class Node:
  def __init__(self):
    self.parent=NIL
    self.left=NIL
    self.right=NIL
R=[Node() for i in range(10000)]
n=0
def preorder(x):
  if(x==NIL)
    return
  print(" %d",x)
  preorder(R[x].left)
  preorder(R[x].right)
def inorder(x):
  if(x==NIL)
    return
  inorder(R[x].left)
  print(" %d",x)
  inorder(R[x].right)
def postorder(x):
  if(x==NIL)
    return
  postorder(R[x].left)
  postorder(R[x].right)
  print(" %d",x)

def main():
  global n
  n=int(input())
  for i in range(n):
    a,b,c=map(int,input().split())
    R[a].left=b
    R[a].right=c
    if(b!=NIL)R[b].parent=a
    if(c!=NIL)R[c].parent=a
  for i in range(n):
    if(R[i].parent==NIL):
      root=i
  print("Preorder")
  preorder(root)
  print("")
  print("Inorder")
  inorder(root)
  print("")
  print("Postorder")
  postorder(root)
  print("")
  return 0

