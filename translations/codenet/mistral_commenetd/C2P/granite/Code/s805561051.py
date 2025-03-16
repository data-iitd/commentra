

# Python code to implement the above C code

# Define a class for a binary tree node
class BT:
  def __init__(self, parent=-1, left=-1, right=-1):
    self.parent = parent
    self.left = left
    self.right = right

# Initialize an array of size 26 to store binary tree nodes
bt = [BT() for _ in range(26)]
n = int(input("Enter the number of nodes in the binary tree: "))

# Read node values and their left and right children
for i in range(n):
  num = int(input("Enter the node value: "))
  # Initialize left and right children as -1
  bt[num].left = -1
  bt[num].right = -1

  # Read left and right child indices if they exist
  if(input("Do you have left and right children? (y/n): ") == "y"):
    bt[num].left = int(input("Enter the left child index: "))
    bt[num].right = int(input("Enter the right child index: "))

    # Set parent of left and right children to current node
    if(bt[num].left!= -1 and bt[num].right!= -1):
      bt[bt[num].left].parent = num
      bt[bt[num].right].parent = num
    # Set parent of left child if it exists
    elif(bt[num].left!= -1):
      bt[bt[num].left].parent = num
    # Set parent of right child if it exists
    elif(bt[num].right!= -1):
      bt[bt[num].right].parent = num

# Find the index of the last node (root) in the tree
root = -1
for i in range(n):
  if(bt[i].parent == -1):
    root = i
    break

# Print tree traversals
print("Preorder traversal:")
def Preorder(node):
  if(node == -1): return
  print(node, end=" ")
  Preorder(bt[node].left)
  Preorder(bt[node].right)
Preorder(root)
print()

print("Inorder traversal:")
def Inorder(node):
  if(node == -1): return
  Inorder(bt[node].left)
  print(node, end=" ")
  Inorder(bt[node].right)
Inorder(root)
print()

print("Postorder traversal:")
def Postorder(node):
  if(node == -1): return
  Postorder(bt[node].left)
  Postorder(bt[node].right)
  print(node, end=" ")
Postorder(root)
print()

