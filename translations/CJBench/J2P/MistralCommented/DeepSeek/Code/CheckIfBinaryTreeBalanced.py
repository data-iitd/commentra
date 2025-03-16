class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def create_tree(self):
        data = int(input())
        self.root = Node(data)
        self._create_tree_recursive(self.root)

    def _create_tree_recursive(self, node):
        left_data = int(input())
        if left_data != -1:
            node.left = Node(left_data)
            self._create_tree_recursive(node.left)
        
        right_data = int(input())
        if right_data != -1:
            node.right = Node(right_data)
            self._create_tree_recursive(node.right)

def is_balanced_recursive(root):
    is_balanced = [True]

    def is_balanced_recursive_helper(node):
        if node is None:
            return 0
        
        left_height = is_balanced_recursive_helper(node.left)
        right_height = is_balanced_recursive_helper(node.right)
        
        if abs(left_height - right_height) > 1:
            is_balanced[0] = False
        
        return max(left_height, right_height) + 1

    is_balanced_recursive_helper(root)
    return is_balanced[0]

def is_balanced_iterative(root):
    is_balanced = True
    stack = []
    subtree_heights = {}
    node = root
    last_visited = None

    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            peek_node = stack[-1]
            if peek_node.right and peek_node.right != last_visited:
                node = peek_node.right
            else:
                stack.pop()
                left_height = subtree_heights.get(peek_node.left, 0)
                right_height = subtree_heights.get(peek_node.right, 0)
                
                if abs(left_height - right_height) > 1:
                    is_balanced = False
                
                subtree_heights[peek_node] = max(left_height, right_height) + 1
                last_visited = peek_node

    return is_balanced

# Main function to create the binary tree and check balance
if __name__ == "__main__":
    tree = BinaryTree()
    tree.create_tree()
    print("Is tree balanced (recursive):", is_balanced_recursive(tree.root))
    print("Is tree balanced (iterative):", is_balanced_iterative(tree.root))
