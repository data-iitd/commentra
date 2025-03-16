class BT:
    def __init__(self):
        self.parent = -1  # Parent node index
        self.right = -1   # Right child index
        self.left = -1    # Left child index

# Array to hold the binary tree nodes
bt = [BT() for _ in range(26)]
n = 0  # Number of nodes in the binary tree

# Function to perform preorder traversal of the binary tree
def preorder(a):
    if a == -1:
        return
    print(f" {a}", end="")
    preorder(bt[a].left)
    preorder(bt[a].right)

# Function to perform inorder traversal of the binary tree
def inorder(a):
    if a == -1:
        return
    inorder(bt[a].left)
    print(f" {a}", end="")
    inorder(bt[a].right)

# Function to perform postorder traversal of the binary tree
def postorder(a):
    if a == -1:
        return
    postorder(bt[a].left)
    postorder(bt[a].right)
    print(f" {a}", end="")

def main():
    global n
    n = int(input())  # Read the number of nodes in the binary tree

    # Initialize the parent of each node to -1 (indicating no parent)
    for i in range(n):
        bt[i].parent = -1

    # Read the tree structure from input
    for i in range(n):
        num = int(input())  # Read the current node index
        left, right = map(int, input().split())  # Read the left and right child indices
        bt[num].left = left
        bt[num].right = right

        # Update the parent index for the left and right children if they exist
        if left != -1:
            bt[left].parent = num
        if right != -1:
            bt[right].parent = num

    # Find the root of the binary tree (the node with no parent)
    root = next(i for i in range(n) if bt[i].parent == -1)

    # Perform and print preorder traversal
    print("Preorder")
    preorder(root)
    print()

    # Perform and print inorder traversal
    print("Inorder")
    inorder(root)
    print()

    # Perform and print postorder traversal
    print("Postorder")
    postorder(root)
    print()

if __name__ == "__main__":
    main()

# <END-OF-CODE>
