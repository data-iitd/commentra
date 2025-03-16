
# Python code

# Define the structure Node
class Node:
  def __init__(self, parent, left, right):
    self.parent = parent
    self.left = left
    self.right = right

# Declare an array of Node objects and an integer variable n
n = int(input())
R = [Node(-1, -1, -1) for _ in range(n)]

# Implement the preorder function
def preorder(x):
  if x == -1:
    return
  print(" {}".format(x), end="")
  preorder(R[x].left)
  preorder(R[x].right)

# Implement the inorder function
def inorder(x):
  if x == -1:
    return
  inorder(R[x].left)
  print(" {}".format(x), end="")
  inorder(R[x].right)

# Implement the postorder function
def postorder(x):
  if x == -1:
    return
  postorder(R[x].left)
  postorder(R[x].right)
  print(" {}".format(x), end="")

# Implement the main function
if __name__ == "__main__":
  for i in range(n):
    parent, left, right = map(int, input().split())
    R[left].parent = parent
    R[right].parent = parent
    if left!= -1:
      R[left].left = -1
      R[left].right = -1
    if right!= -1:
      R[right].left = -1
      R[right].right = -1
  for i in range(n):
    if R[i].parent == -1:
      root = i
  print("Preorder")
  preorder(root)
  print()
  print("Inorder")
  inorder(root)
  print()
  print("Postorder")
  postorder(root)
  print()

