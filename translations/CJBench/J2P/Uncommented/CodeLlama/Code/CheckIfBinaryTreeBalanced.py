import sys
class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None
    def __init__(self):
        self.root = None
    def createTree(self):
        sc = sys.stdin.readline
        self.root = BinaryTree.Node(int(sc()))
        self.createTreeRecursive(self.root, sc)
    def createTreeRecursive(self, node, sc):
        if node is None:
            return
        leftData = int(sc())
        if leftData != -1:
            node.left = BinaryTree.Node(leftData)
            self.createTreeRecursive(node.left, sc)
        rightData = int(sc())
        if rightData != -1:
            node.right = BinaryTree.Node(rightData)
            self.createTreeRecursive(node.right, sc)

def isBalancedRecursive(root):
    if root is None:
        return True
    isBalanced = True
    isBalancedRecursiveHelper(root, isBalanced)
    return isBalanced

def isBalancedRecursiveHelper(node, isBalanced):
    if node is None or not isBalanced:
        return 0
    leftHeight = isBalancedRecursiveHelper(node.left, isBalanced)
    rightHeight = isBalancedRecursiveHelper(node.right, isBalanced)
    if abs(leftHeight - rightHeight) > 1:
        isBalanced = False
    return max(leftHeight, rightHeight) + 1

def isBalancedIterative(root):
    if root is None:
        return True
    isBalanced = True
    stack = []
    subtreeHeights = {}
    lastVisited = None
    node = root
    while stack or node is not None:
        if node is not None:
            stack.append(node)
            node = node.left
        else:
            node = stack[-1]
            if node.right is None or node.right is lastVisited:
                leftHeight = subtreeHeights.get(node.left, 0)
                rightHeight = subtreeHeights.get(node.right, 0)
                if abs(leftHeight - rightHeight) > 1:
                    isBalanced = False
                subtreeHeights[node] = max(leftHeight, rightHeight) + 1
                lastVisited = node
                stack.pop()
                node = None
            else:
                node = node.right
    return isBalanced

tree = BinaryTree()
tree.createTree()
print("Is tree balanced (recursive): " + str(isBalancedRecursive(tree.root)))
print("Is tree balanced (iterative): " + str(isBalancedIterative(tree.root)))


