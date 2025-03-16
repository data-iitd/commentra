
# Represents a node in a binary tree
class TreeNode:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

# Used to store node and its horizontal distance
class QItem:
    def __init__(self, node, hd):
        self.node = node
        self.hd = hd

# Represents a binary tree
class Tree:
    def __init__(self, root):
        self.root = root

    # Prints the top view of the binary tree
    def printTopView(self):
        if self.root is None:
            return
        set = set()
        queue = []
        queue.append(QItem(self.root, 0))
        while len(queue) > 0:
            qi = queue.pop(0)
            hd = qi.hd
            n = qi.node
            if hd not in set:
                set.add(hd)
                print(n.key, end=" ")
            if n.left is not None:
                queue.append(QItem(n.left, hd - 1))
            if n.right is not None:
                queue.append(QItem(n.right, hd + 1))

# Main class to run the program
class Main:
    def __init__(self):
        pass

    def main(self):
        scanner = Scanner(sys.stdin)
        n = scanner.nextInt()
        nodeMap = {}
        for i in range(n):
            key = scanner.nextInt()
            left = scanner.nextInt()
            right = scanner.nextInt()
            nodeMap[key] = TreeNode(key)
            currentNode = nodeMap[key]
            if left != -1:
                nodeMap[left] = TreeNode(left)
                currentNode.left = nodeMap[left]
            if right != -1:
                nodeMap[right] = TreeNode(right)
                currentNode.right = nodeMap[right]
        rootKey = scanner.nextInt()
        t = Tree(nodeMap[rootKey])
        print("Top view of the binary tree:")
        t.printTopView()
        scanner.close()

if __name__ == "__main__":
    Main().main()

