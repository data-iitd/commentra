class TreeNode:
    def __init__(self, index):
        self.parent = -1
        self.right = -1
        self.left = -1

# Array to hold the binary tree nodes
bt = [TreeNode(i) for i in range(26)]
n = 0  # Number of nodes in the binary tree

# Function to perform preorder traversal of the binary tree
def Preorder(a, tree):
    # Base case: if the node index is -1, return
    if a == -1: return

    # Print the current node index
    print(" " + str(a), end="")
    # Recursively traverse the left subtree
    Preorder(tree[a].left, tree)
    # Recursively traverse the right subtree
    Preorder(tree[a].right, tree)

# Function to perform inorder traversal of the binary tree
def Inorder(a, tree):
    # Base case: if the node index is -1, return
    if a == -1: return

    # Recursively traverse the left subtree
    Inorder(tree[a].left, tree)
    # Print the current node index
    print(" " + str(a), end="")
    # Recursively traverse the right subtree
    Inorder(tree[a].right, tree)

# Function to perform postorder traversal of the binary tree
def Postorder(a, tree):
    # Base case: if the node index is -1, return
    if a == -1: return

    # Recursively traverse the left subtree
    Postorder(tree[a].left, tree)
    # Recursively traverse the right subtree
    Postorder(tree[a].right, tree)
    # Print the current node index
    print(" " + str(a), end="")

# Main function
if __name__ == "__main__":
    # Read the number of nodes in the binary tree
    n = int(input())

    # Read the tree structure from input
    for i in range(n):
        # Read the current node index
        num = int(input())
        # Read the left and right child indices
        left_child, right_child = map(int, input().split())

        # Update the tree structure
        bt[num].left = left_child
        bt[num].right = right_child

        # Update the parent index for the left and right children if they exist
        if left_child != -1:
            bt[left_child].parent = num
        if right_child != -1:
            bt[right_child].parent = num

    # Find the root of the binary tree (the node with no parent)
    for i in range(n):
        if bt[i].parent == -1:
            root = i
            break

    # Perform and print preorder traversal
    print("Preorder")
    Preorder(root, bt)
    print()

    # Perform and print inorder traversal
    print("Inorder")
    Inorder(root, bt)
    print()

    # Perform and print postorder traversal
    print("Postorder")
    Postorder(root, bt)
    print()
