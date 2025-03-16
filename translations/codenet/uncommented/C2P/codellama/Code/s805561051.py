# include<stdio.h>
# include<stdlib.h>

class BT:
  def __init__(self):
    self.parent = -1
    self.right = -1
    self.left = -1

bt = [BT() for i in range(26)]
n = 0

def Preorder(a):
  if a == -1:
    return

  print(" %d" % a,end="")
  Preorder(bt[a].left)
  Preorder(bt[a].right)

def Inorder(a):
  if a == -1:
    return

  Inorder(bt[a].left)
  print(" %d" % a,end="")
  Inorder(bt[a].right)

def Postorder(a):
  if a == -1:
    return

  Postorder(bt[a].left)
  Postorder(bt[a].right)
  print(" %d" % a,end="")

def main():
  global n
  i,j,num,depth = 0,0,0,0

  scanf("%d",&n)

  for i in range(n):
    bt[i].parent = -1

  for i in range(n):
    scanf("%d",&num)
    scanf("%d%d",&(bt[num].left),&(bt[num].right))

    if bt[num].left != -1 and bt[num].right != -1:
      bt[bt[num].left].parent = num
      bt[bt[num].right].parent = num

    elif bt[num].left != -1:
      bt[bt[num].left].parent = num

    elif bt[num].right != -1:
      bt[bt[num].right].parent = num

  for i in range(n):
    if bt[i].parent != -1:
      break

  print("Preorder")
  Preorder(i)
  print()

  print("Inorder")
  Inorder(i)
  print()

  print("Postorder")
  Postorder(i)
  print()

  return 0



