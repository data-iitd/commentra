from collections import deque

# Class for a tree node
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# A class to represent a queue item. The queue is used to do Level
# order traversal. Every Queue item contains node and horizontal
# distance of node from root
class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

# Class for a Binary Tree
class Tree:
    def __init__(self, root):
        self.root = root

    # This method prints nodes in top view of binary tree
    def print_top_view(self):
        # base case
        if self.root is None:
            return

        # Creates an empty hashset
        seen = set()

        # Create a queue and add root to it
        queue = deque()
        queue.append(QItem(self.root, 0))

        # Standard BFS or level order traversal loop
        while queue:
            # Remove the front item and get its details
            qi = queue.popleft()
            hd = qi.hd
            node = qi.node

            # If this is the first node at its horizontal distance,
            # then this node is in top view
            if hd not in seen:
                seen.add(hd)
                print(node.key, end=" ")

            # Enqueue left and right children of current node
            if node.left is not None:
                queue.append(QItem(node.left, hd - 1))
            if node.right is not None:
                queue.append(QItem(node.right, hd + 1))

# Driver code to test above methods
if __name__ == "__main__":
    n = int(input())
    node_map = {}

    for _ in range(n):
        key, left, right = map(int, input().split())
        if key not in node_map:
            node_map[key] = TreeNode(key)
        current_node = node_map[key]

        if left != -1:
            if left not in node_map:
                node_map[left] = TreeNode(left)
            current_node.left = node_map[left]

        if right != -1:
            if right not in node_map:
                node_map[right] = TreeNode(right)
            current_node.right = node_map[right]

    root_key = int(input())
    tree = Tree(node_map[root_key])
    print("Top view of the binary tree:")
    tree.print_top_view()

# <END-OF-CODE>
