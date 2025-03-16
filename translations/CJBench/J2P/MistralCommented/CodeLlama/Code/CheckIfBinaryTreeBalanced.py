
import math

class BinaryTree:
    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def createTree(self):
        sc = input().split()
        self.root = self.Node(int(sc[0]))
        self.createTreeRecursive(self.root, sc)

    def createTreeRecursive(self, node, sc):
        if node is None:
            return

        leftData = int(sc[1])
        if leftData != -1:
            node.left = self.Node(leftData)
            self.createTreeRecursive(node.left, sc[2:])

        rightData = int(sc[3])
        if rightData != -1:
            node.right = self.Node(rightData)
            self.createTreeRecursive(node.right, sc[4:])

def isBalancedRecursive(root):
    isBalanced = True

    def isBalancedRecursiveHelper(node, isBalanced):
        if node is None:
            return 0

        leftHeight = isBalancedRecursiveHelper(node.left, isBalanced)
        rightHeight = isBalancedRecursiveHelper(node.right, isBalanced)

        if abs(leftHeight - rightHeight) > 1:
            isBalanced = False

        return max(leftHeight, rightHeight) + 1

    isBalancedRecursiveHelper(root, isBalanced)

    return isBalanced

def isBalancedIterative(root):
    isBalanced = True
    stack = []
    subtreeHeights = {}

    node = root
    lastVisited = None

    while stack or node is not None:
        if node is not None:
            stack.append(node)
            node = node.left

            if node is None or node == lastVisited:
                leftHeight = subtreeHeights.get(node.left, 0)
                rightHeight = subtreeHeights.get(node.right, 0)

                if abs(leftHeight - rightHeight) > 1:
                    isBalanced = False

                subtreeHeights[node] = max(leftHeight, rightHeight) + 1
                lastVisited = node

                node = None
            else:
                node = node.right
        else:
            node = stack.pop()

    return isBalanced

tree = BinaryTree()
tree.createTree()

print("Is tree balanced (recursive):", isBalancedRecursive(tree.root))
print("Is tree balanced (iterative):", isBalancedIterative(tree.root))

# 