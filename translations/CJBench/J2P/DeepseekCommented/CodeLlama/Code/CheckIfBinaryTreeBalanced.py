
import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self):
        self.root = None

    def createTree(self):
        values = list(map(int, sys.stdin.readline().split()))
        if not values:
            return
        rootData = values[0]
        root = Node(rootData)
        self.root = root
        queue = [root]
        i = 1
        while queue:
            node = queue[0]
            del queue[0]
            leftChildData = values[i]
            if leftChildData != -1:
                leftChild = Node(leftChildData)
                node.left = leftChild
                queue.append(leftChild)
            i += 1
            rightChildData = values[i]
            if rightChildData != -1:
                rightChild = Node(rightChildData)
                node.right = rightChild
                queue.append(rightChild)
            i += 1

def isBalancedRecursive(root):
    if root is None:
        return True
    leftHeight = isBalancedRecursive(root.left)
    rightHeight = isBalancedRecursive(root.right)
    if abs(leftHeight - rightHeight) > 1:
        return False
    return True

def isBalancedIterative(root):
    if root is None:
        return True
    stack = [root]
    subtreeHeights = {}
    lastVisited = None
    while stack or root is not None:
        if root is not None:
            stack.append(root)
            root = root.left
        else:
            root = stack[-1]
            if root.right is None or root.right == lastVisited:
                leftHeight = subtreeHeights.get(root.left, 0)
                rightHeight = subtreeHeights.get(root.right, 0)
                if abs(leftHeight - rightHeight) > 1:
                    return False
                subtreeHeights[root] = max(leftHeight, rightHeight) + 1
                lastVisited = root
                stack.pop()
                root = None
            else:
                root = root.right
    return True

tree = BinaryTree()
tree.createTree()
print("Is tree balanced (recursive):", isBalancedRecursive(tree.root))
print("Is tree balanced (iterative):", isBalancedIterative(tree.root))

