

class BT:
  def __init__(self, parent=-1, left=-1, right=-1):
    self.parent = parent
    self.left = left
    self.right = right

n = int(input())

bt = [BT() for _ in range(n)]

for _ in range(n):
  num = int(input())
  left, right = map(int, input().split())

  if left!= -1 and right!= -1:
    bt[left].parent = num
    bt[right].parent = num
  elif left!= -1:
    bt[left].parent = num
  elif right!= -1:
    bt[right].parent = num

for i in range(n):
  if bt[i].parent == -1:
    root = i
    break

def preorder(i):
  if i == -1:
    return
  print(f" {i}", end="")
  preorder(bt[i].left)
  preorder(bt[i].right)

def inorder(i):
  if i == -1:
    return
  inorder(bt[i].left)
  print(f" {i}", end="")
  inorder(bt[i].right)

def postorder(i):
  if i == -1:
    return
  postorder(bt[i].left)
  postorder(bt[i].right)
  print(f" {i}", end="")

print("Preorder")
preorder(root)
print()

print("Inorder")
inorder(root)
print()

print("Postorder")
postorder(root)
print()

