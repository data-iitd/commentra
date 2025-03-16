class BT:
    def __init__(self):
        self.parent = -1  # To store the parent node index
        self.left = -1    # To store the index of the left child
        self.right = -1   # To store the index of the right child

# Array to hold the nodes of the binary tree
bt = [BT() for _ in range(26)]
n = 0  # Number of nodes in the binary tree

# Function to perform preorder traversal of the binary tree
def preorder(a):
    if a == -1:
        return  # Base case: if the node is -1, return

    print(f" {a}", end='')  # Print the current node
    preorder(bt[a].left)    # Recursively call preorder on the left child
    preorder(bt[a].right)   # Recursively call preorder on the right child

# Function to perform inorder traversal of the binary tree
def inorder(a):
    if a == -1:
        return  # Base case: if the node is -1, return

    inorder(bt[a].left)     # Recursively call inorder on the left child
    print(f" {a}", end='')  # Print the current node
    inorder(bt[a].right)    # Recursively call inorder on the right child

# Function to perform postorder traversal of the binary tree
def postorder(a):
    if a == -1:
        return  # Base case: if the node is -1, return

    postorder(bt[a].left)   # Recursively call postorder on the left child
    postorder(bt[a].right)  # Recursively call postorder on the right child
    print(f" {a}", end='')  # Print the current node

# Main function to read the number of nodes, initialize the tree, and print traversals
if __name__ == "__main__":
    n = int(input())  # Read the number of nodes

    # Read the left and right children for each node
    for _ in range(n):
        num = int(input())
        left, right = map(int, input().split())
        bt[num].left = left
        bt[num].right = right

        # Update the parent pointers of the left and right children
        if left != -1:
            bt[left].parent = num
        if right != -1:
            bt[right].parent = num

    # Find the root node (the node with no parent)
    root = next(i for i in range(n) if bt[i].parent == -1)

    # Print the preorder, inorder, and postorder traversals of the binary tree
    print("Preorder")
    preorder(root)
    print()

    print("Inorder")
    inorder(root)
    print()

    print("Postorder")
    postorder(root)
    print()

# <END-OF-CODE>
