
# include<stdio.h>
# include<stdlib.h>

# define MAX 26

# typedef struct{
  int parent;
  int right;
  int left;
}BT;

BT bt[MAX];
int n;

def Preorder(a):
  if(a == -1):
    return
  print(" %d",a)
  Preorder(bt[a].left)
  Preorder(bt[a].right)

def Inorder(a):
  if(a==-1):
    return
  Inorder(bt[a].left)
  print(" %d",a)
  Inorder(bt[a].right)

def Postorder(a):
  if(a==-1):
    return
  Postorder(bt[a].left)
  Postorder(bt[a].right)
  print(" %d",a)

def main():
  i,j,num = 0,0,0
  depth = 0
  scanf("%d",&n)
  for i in range(n):
    bt[i].parent = -1
  for i in range(n):
    scanf("%d",&num)
    bt[num].left = -1
    bt[num].right = -1
    scanf("%d%d",&(bt[num].left),&(bt[num].right))
    if(bt[num].left != -1 && bt[num].right != -1):
      bt[bt[num].left].parent = num
      bt[bt[num].right].parent = num
    elif(bt[num].left != -1):
      bt[bt[num].left].parent = num
    elif(bt[num].right != -1):
      bt[bt[num].right].parent = num
  for i in range(n):
    if(bt[i].parent == -1):
      break
  print("Preorder\n")
  Preorder(i)
  print("\n")
  print("Inorder\n")
  Inorder(i)
  print("\n")
  print("Postorder\n")
  Postorder(i)
  print("\n")

