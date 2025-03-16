from collections import defaultdict, deque

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

def vertical_traversal(root):
    if root is None:
        return []

    # Initialize queues for nodes and their corresponding indices
    queue = deque()
    index = deque()

    # Initialize a map to store the data at each index
    map = defaultdict(list)

    # Initialize minimum and maximum indices
    max_idx = 0
    min_idx = 0

    # Enqueue the root node and its index in the queues
    queue.append(root)
    index.append(0)

    # BFS traversal using queues
    while queue:
        node = queue.popleft()
        idx = index.popleft()

        # Add the node's data to the map at the corresponding index
        map[idx].append(node.data)

        # Update the minimum and maximum indices
        max_idx = max(max_idx, idx)
        min_idx = min(min_idx, idx)

        # Enqueue the left and right children and their indices
        if node.left is not None:
            queue.append(node.left)
            index.append(idx - 1)
        if node.right is not None:
            queue.append(node.right)
            index.append(idx + 1)

    # Create an empty result list
    result = []

    # Add all the data from the map to the result list
    for i in range(min_idx, max_idx + 1):
        result.extend(map[i])

    return result

def main():
    import sys
    input = sys.stdin.read
    data = input().splitlines()

    # Read the number of nodes in the binary tree
    n = int(data[0])

    # Create an array of nodes for the binary tree
    nodes = [None] * (n + 1)
    for i in range(1, n + 1):
        nodes[i] = BinaryTree.Node(i)

    # Read the edges and their directions from the input
    for i in range(1, n):
        parent, child, direction = data[i].split()
        parent = int(parent)
        child = int(child)

        # Connect the parent and child nodes based on the direction
        if direction == "L":
            nodes[parent].left = nodes[child]
        elif direction == "R":
            nodes[parent].right = nodes[child]

    # Call the vertical_traversal function on the root node and print the result
    result = vertical_traversal(nodes[1])
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()

# <END-OF-CODE>
