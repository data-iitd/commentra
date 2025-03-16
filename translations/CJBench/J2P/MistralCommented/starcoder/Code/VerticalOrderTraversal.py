
# Binary tree node class
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


# Function to perform vertical traversal of a binary tree
def verticalTraversal(root):
    # Base case: if root is null, return an empty list
    if root is None:
        return []

    # Initialize queues for nodes and their corresponding indices
    queue = []
    index = []

    # Initialize a map to store the data at each index
    map = {}

    # Initialize minimum and maximum indices
    max = 0
    min = 0

    # Enqueue the root node and its index in the queues
    queue.append(root)
    index.append(0)

    # BFS traversal using queues
    while len(queue) > 0:
        # Dequeue a node and its corresponding index
        node = queue.pop(0)
        idx = index.pop(0)

        # Add the node's data to the map at the corresponding index
        map.setdefault(idx, [])
        map[idx].append(node.data)

        # Update the minimum and maximum indices
        max = max if max > idx else idx
        min = min if min < idx else idx

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
    for i in range(min, max + 1):
        result.extend(map[i])

    # Return the result list
    return result


# Main method to read input and call the verticalTraversal function
if __name__ == '__main__':
    # Read the number of nodes in the binary tree
    n = int(input())

    # Create an array of nodes for the binary tree
    nodes = [Node(i) for i in range(1, n + 1)]

    # Read the edges and their directions from the input
    for _ in range(n - 1):
        parent, child, direction = map(int, input().split())

        # Connect the parent and child nodes based on the direction
        if direction == 0:
            nodes[parent].left = nodes[child]
        else:
            nodes[parent].right = nodes[child]

    # Call the verticalTraversal function on the root node and print the result
    result = verticalTraversal(nodes[1])
    for value in result:
        print(value, end=' ')

