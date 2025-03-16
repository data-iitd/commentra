
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def createTree(self):
        data = int(input())
        self.root = Node(data)
        self.createTreeRecursive(self.root)

    def createTreeRecursive(self, node):
        leftData = int(input())
        if leftData!= -1:
            node.left = Node(leftData)
            self.createTreeRecursive(node.left)
        rightData = int(input())
        if rightData!= -1:
            node.right = Node(rightData)
            self.createTreeRecursive(node.right)

def isBalancedRecursive(node):
    if node is None:
        return True
    isBalanced = True
    leftHeight = isBalancedRecursiveHelper(node.left)
    rightHeight = isBalancedRecursiveHelper(node.right)
    if abs(leftHeight - rightHeight) > 1:
        isBalanced = False
    return isBalanced and max(leftHeight, rightHeight) + 1

def isBalancedRecursiveHelper(node):
    if node is None:
        return 0
    return isBalancedRecursiveHelper(node.left) + 1

def isBalancedIterative(node):
    if node is None:
        return True
    isBalanced = True
    stack = []
    subtreeHeights = {}
    lastVisited = None
    while stack or node:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            if node.right is None or node.right == lastVisited:
                leftHeight = subtreeHeights.get(node.left, 0)
                rightHeight = subtreeHeights.get(node.right, 0)
                if abs(leftHeight - rightHeight) > 1:
                    isBalanced = False
                subtreeHeights[node] = max(leftHeight, rightHeight) + 1
                lastVisited = node
                node = None
            else:
                node = node.right
    return isBalanced

if __name__ == "__main__":
    tree = BinaryTree()
    tree.createTree()
    print("Is tree balanced (recursive):", isBalancedRecursive(tree.root))
    print("Is tree balanced (iterative):", isBalancedIterative(tree.root))

