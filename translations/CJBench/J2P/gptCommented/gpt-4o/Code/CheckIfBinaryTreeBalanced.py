class Node:
    def __init__(self, data):
        self.data = data  # Value of the node
        self.left = None  # Pointer to left child
        self.right = None  # Pointer to right child


class BinaryTree:
    def __init__(self):
        self.root = None  # Root of the binary tree

    def create_tree(self):
        data = int(input("Enter root node data: "))  # Create root node
        self.root = Node(data)  # Initialize root
        self.create_tree_recursive(self.root)  # Recursively create the tree

    def create_tree_recursive(self, node):
        if node is None:
            return  # Base case: if node is null, return

        # Read left child data and create left subtree
        left_data = int(input("Enter left child data (-1 for no child): "))
        if left_data != -1:  # -1 indicates no child
            node.left = Node(left_data)
            self.create_tree_recursive(node.left)  # Recursive call for left child

        # Read right child data and create right subtree
        right_data = int(input("Enter right child data (-1 for no child): "))
        if right_data != -1:  # -1 indicates no child
            node.right = Node(right_data)
            self.create_tree_recursive(node.right)  # Recursive call for right child


def is_balanced_recursive(root):
    if root is None:
        return True  # An empty tree is balanced

    is_balanced = [True]  # List to hold balanced status
    is_balanced_recursive_helper(root, is_balanced)  # Start recursive check
    return is_balanced[0]  # Return the balanced status


def is_balanced_recursive_helper(node, is_balanced):
    if node is None or not is_balanced[0]:
        return 0  # Base case

    # Recursively get heights of left and right subtrees
    left_height = is_balanced_recursive_helper(node.left, is_balanced)
    right_height = is_balanced_recursive_helper(node.right, is_balanced)

    # Check if current node is balanced
    if abs(left_height - right_height) > 1:
        is_balanced[0] = False

    # Return height of the current node
    return max(left_height, right_height) + 1


def is_balanced_iterative(root):
    if root is None:
        return True  # An empty tree is balanced

    is_balanced = True  # Initialize as balanced
    stack = []  # Stack for traversal
    subtree_heights = {}  # Dictionary to store heights
    last_visited = None  # Track the last visited node
    node = root  # Start from the root

    # Iterative traversal using stack
    while stack or node is not None:
        if node is not None:
            stack.append(node)  # Push current node to stack
            node = node.left  # Move to left child
        else:
            node = stack[-1]  # Peek the top node in the stack
            # Check if we can process the current node
            if node.right is None or node.right == last_visited:
                # Get heights of left and right subtrees
                left_height = subtree_heights.get(node.left, 0)
                right_height = subtree_heights.get(node.right, 0)
                # Check if current node is balanced
                if abs(left_height - right_height) > 1:
                    is_balanced = False

                # Store the height of the current node
                subtree_heights[node] = max(left_height, right_height) + 1
                last_visited = node  # Update last visited node
                stack.pop()  # Remove current node from stack
                node = None  # Set node to null to process next node
            else:
                node = node.right  # Move to right child

    return is_balanced  # Return the balanced status


# Main method to execute the program
if __name__ == "__main__":
    tree = BinaryTree()  # Create a new binary tree
    tree.create_tree()  # Create the tree from user input
    # Check and print if the tree is balanced using recursive method
    print("Is tree balanced (recursive):", is_balanced_recursive(tree.root))
    # Check and print if the tree is balanced using iterative method
    print("Is tree balanced (iterative):", is_balanced_iterative(tree.root))

# <END-OF-CODE>
