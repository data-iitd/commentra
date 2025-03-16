class BT:
    def __init__(self):
        self.parent = -1  # Parent node index
        self.right = -1   # Index of right child
        self.left = -1    # Index of left child

# Initialize an array of size 26 to store binary tree nodes
bt = [BT() for _ in range(26)]
n = 0  # Number of nodes in the binary tree

# Recursive function to print tree in preorder traversal
def preorder(a):
    # Base case: if current node index is -1, return
    if a == -1:
        return

    # Print the current node value
    print(f" {a}", end='')

    # Recursively call for left and right subtrees
    preorder(bt[a].left)
    preorder(bt[a].right)

# Recursive function to print tree in inorder traversal
def inorder(a):
    # Base case: if current node index is -1, return
    if a == -1:
        return

    # Recursively call for left subtree
    inorder(bt[a].left)

    # Print the current node value
    print(f" {a}", end='')

    # Recursively call for right subtree
    inorder(bt[a].right)

# Recursive function to print tree in postorder traversal
def postorder(a):
    # Base case: if current node index is -1, return
    if a == -1:
        return

    # Recursively call for left and right subtrees
    postorder(bt[a].left)
    postorder(bt[a].right)

    # Print the current node value
    print(f" {a}", end='')

# Main function to read input and print tree traversals
if __name__ == "__main__":
    n = int(input())  # Read number of nodes in the binary tree

    # Initialize all nodes as root
    for i in range(n):
        bt[i].parent = -1

    # Read node values and their left and right children
    for _ in range(n):
        num = int(input())  # Read node value

        # Initialize left and right children as -1
        bt[num].left = -1
        bt[num].right = -1

        # Read left and right child indices if they exist
        children = list(map(int, input().split()))
        if len(children) != 2:
            break

        bt[num].left, bt[num].right = children

        # Set parent of left and right children to current node
        if bt[num].left != -1 and bt[num].right != -1:
            bt[bt[num].left].parent = num
            bt[bt[num].right].parent = num
        elif bt[num].left != -1:
            bt[bt[num].left].parent = num
        elif bt[num].right != -1:
            bt[bt[num].right].parent = num

    # Find the index of the last node (root) in the tree
    root_index = next(i for i in range(n) if bt[i].parent == -1)

    # Print tree traversals
    print("Preorder")
    preorder(root_index)
    print()

    print("Inorder")
    inorder(root_index)
    print()

    print("Postorder")
    postorder(root_index)
    print()

# <END-OF-CODE>
