# include<stdio.h>
# include<stdlib.h>

class BT:
  def __init__(self, parent, right, left):
    self.parent = parent
    self.right = right
    self.left = left

bt = []
n = 0

# Function to perform preorder traversal of the binary tree
def Preorder(a):
  if a == -1: return  # Base case: if the node is -1, return

  print(" %d" % a)      # Print the current node
  Preorder(bt[a].left) # Recursively call Preorder on the left child
  Preorder(bt[a].right)# Recursively call Preorder on the right child

# Function to perform inorder traversal of the binary tree
def Inorder(a):
  if a == -1: return  # Base case: if the node is -1, return

  Inorder(bt[a].left)  # Recursively call Inorder on the left child
  print(" %d" % a)      # Print the current node
  Inorder(bt[a].right) # Recursively call Inorder on the right child

# Function to perform postorder traversal of the binary tree
def Postorder(a):
  if a == -1: return  # Base case: if the node is -1, return

  Postorder(bt[a].left) # Recursively call Postorder on the left child
  Postorder(bt[a].right)# Recursively call Postorder on the right child
  print(" %d" % a)      # Print the current node

# Main function to read the number of nodes, initialize the tree, and print traversals
def main():
  global n
  i, j, num = 0, 0, 0

  scanf("%d", &n)  # Read the number of nodes

  # Initialize all parent nodes to -1
  for i in range(n):
    bt.append(BT(-1, -1, -1))

  # Read the left and right children for each node
  for i in range(n):
    scanf("%d", &num)
    scanf("%d%d", &(bt[num].left), &(bt[num].right))

    # Update the parent pointers of the left and right children
    if bt[num].left != -1 and bt[num].right != -1:
      bt[bt[num].left].parent = num
      bt[bt[num].right].parent = num
    elif bt[num].left != -1:
      bt[bt[num].left].parent = num
    elif bt[num].right != -1:
      bt[bt[num].right].parent = num

  # Find the root node (the node with no parent)
  for i in range(n):
    if bt[i].parent == -1:
      break

  # Print the preorder, inorder, and postorder traversals of the binary tree
  print("Preorder\n")
  Preorder(i)
  print("\n")

  print("Inorder\n")
  Inorder(i)
  print("\n")

  print("Postorder\n")
  Postorder(i)
  print("\n")

  return 0

main()

