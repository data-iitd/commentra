
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
        rootValue = values[0]
        root = Node(rootValue)
        self.root = root
        queue = [root]
        i = 1
        while queue and i < len(values):
            node = queue[0]
            del queue[0]
            leftChildValue = values[i]
            if leftChildValue != -1:
                node.left = Node(leftChildValue)
                queue.append(node.left)
            i += 1
            if i < len(values):
                rightChildValue = values[i]
                if rightChildValue != -1:
                    node.right = Node(rightChildValue)
                    queue.append(node.right)
            i += 1


def isBalancedRecursive(root):
    if root is None:
        return True

    isBalanced = [True]

    def isBalancedRecursiveHelper(node, isBalanced):
        if node is None or not isBalanced[0]:
            return 0

        leftHeight = isBalancedRecursiveHelper(node.left, isBalanced)
        rightHeight = isBalancedRecursiveHelper(node.right, isBalanced)

        if abs(leftHeight - rightHeight) > 1:
            isBalanced[0] = False

        return max(leftHeight, rightHeight) + 1

    isBalancedRecursiveHelper(root, isBalanced)
    return isBalanced[0]


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


if __name__ == "__main__":
    tree = BinaryTree()
    tree.createTree()

    print("Is tree balanced (recursive): " + str(isBalancedRecursive(tree.root)))
    print("Is tree balanced (iterative): " + str(isBalancedIterative(tree.root)))


