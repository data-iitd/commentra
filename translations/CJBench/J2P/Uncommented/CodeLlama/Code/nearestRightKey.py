
import sys

class Node:
    def __init__(self, value, left=None, right=None):
        self.value = value
        self.left = left
        self.right = right

def main():
    n = int(sys.stdin.readline())
    nodeMap = {}
    root = None
    for i in range(n):
        value, left, right = map(int, sys.stdin.readline().split())
        nodeMap[value] = Node(value, left, right)
        if root is None:
            root = nodeMap[value]
        if left != -1:
            nodeMap[value].left = nodeMap[left]
        if right != -1:
            nodeMap[value].right = nodeMap[right]
    x0 = int(sys.stdin.readline())
    toPrint = main(root, x0)
    if toPrint == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key:", toPrint)

def main(root, x0):
    if root is None:
        return 0
    elif root.value > x0:
        temp = main(root.left, x0)
        if temp == 0:
            return root.value
        return temp
    else:
        return main(root.right, x0)

if __name__ == "__main__":
    main()

