import java.util.HashMap;
import java.util.Scanner;
import java.util.Stack;


class BinaryTree:

    class Node:
        def __init__(self, data):
            self.data = data
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    def createTree(self):
        sc = Scanner(System.in)
        self.root = Node(sc.nextInt())
        self.createTreeRecursive(self.root, sc)

    def createTreeRecursive(self, node, sc):
        if node == None:
            return
        leftData = sc.nextInt()
        if leftData!= -1:
            node.left = Node(leftData)
            self.createTreeRecursive(node.left, sc)
        rightData = sc.nextInt()
        if rightData!= -1:
            node.right = Node(rightData)
            self.createTreeRecursive(node.right, sc)


def isBalancedRecursive(root):
    if root == None:
        return True
    isBalanced = [True]
    isBalancedRecursiveHelper(root, isBalanced)
    return isBalanced[0]


def isBalancedRecursiveHelper(node, isBalanced):
    if node == None or not isBalanced[0]:
        return 0
    leftHeight = isBalancedRecursiveHelper(node.left, isBalanced)
    rightHeight = isBalancedRecursiveHelper(node.right, isBalanced)
    if Math.abs(leftHeight - rightHeight) > 1:
        isBalanced[0] = False
    return Math.max(leftHeight, rightHeight) + 1


def isBalancedIterative(root):
    if root == None:
        return True
    isBalanced = True
    stack = Stack()
    subtreeHeights = HashMap()
    lastVisited = None
    node = root
    while not stack.isEmpty() or node!= None:
        if node!= None:
            stack.push(node)
            node = node.left
        else:
            node = stack.peek()
            if node.right == None or node.right == lastVisited:
                leftHeight = subtreeHeights.getOrDefault(node.left, 0)
                rightHeight = subtreeHeights.getOrDefault(node.right, 0)
                if Math.abs(leftHeight - rightHeight) > 1:
                    isBalanced = False
                subtreeHeights.put(node, Math.max(leftHeight, rightHeight) + 1)
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

