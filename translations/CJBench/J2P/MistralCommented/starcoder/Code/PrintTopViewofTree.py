
# Create a TreeNode class with key, left and right references
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Create a QItem class with node and horizontal distance references
class QItem:
    def __init__(self, n, h):
        self.node = n
        self.hd = h

# Create a Tree class with root reference
class Tree:
    def __init__(self, n):
        self.root = n

    # Method to print the top view of the binary tree
    def printTopView(self):
        if self.root == None: # Check if the root is null, if yes then return
            return

        # Create an empty HashSet and LinkedList
        set = set()
        queue = []

        # Add root node to the queue with horizontal distance 0
        queue.append(QItem(self.root, 0))

        # Traverse the tree level by level and print the nodes at the same horizontal distance
        while len(queue) > 0:
            qi = queue.pop(0) # Dequeue a QItem from the queue
            hd = qi.hd # Get the horizontal distance of the current node
            n = qi.node # Get the current node

            # If the node is not already present in the HashSet, print its key and add it to the HashSet
            if hd not in set:
                set.add(hd)
                print(n.key, end=" ")

            # If the left child of the current node is not null, add it to the queue with horizontal distance decreased by 1
            if n.left!= None:
                queue.append(QItem(n.left, hd - 1))

            # If the right child of the current node is not null, add it to the queue with horizontal distance increased by 1
            if n.right!= None:
                queue.append(QItem(n.right, hd + 1))

# Main class to read input and call the printTopView method
if __name__ == "__main__":
    scanner = Scanner(sys.stdin) # Create a Scanner object to read input

    # Read the number of nodes in the binary tree
    n = scanner.nextInt()

    # Create a HashMap to store TreeNodes with their keys as keys
    nodeMap = {}

    # Read the nodes of the binary tree and create TreeNodes, add them to the HashMap and link them together
    for i in range(n):
        key = scanner.nextInt()
        left = scanner.nextInt()
        right = scanner.nextInt()

        # Create a new TreeNode with the given key and add it to the HashMap with the key as its key
        if key not in nodeMap:
            nodeMap[key] = TreeNode(key)
        currentNode = nodeMap[key]

        # If the left child is not null, create a new TreeNode with the given left key and add it to the HashMap, then link the current node with its left child
        if left!= -1:
            if left not in nodeMap:
                nodeMap[left] = TreeNode(left)
            currentNode.left = nodeMap[left]

        # If the right child is not null, create a new TreeNode with the given right key and add it to the HashMap, then link the current node with its right child
        if right!= -1:
            if right not in nodeMap:
                nodeMap[right] = TreeNode(right)
            currentNode.right = nodeMap[right]

    # Read the root key and create a Tree object with the root node
    rootKey = scanner.nextInt()
    t = Tree(nodeMap[rootKey])

    # Call the printTopView method of the Tree object to print the top view of the binary tree
    t.printTopView()

    # Close the Scanner object
    scanner.close()

