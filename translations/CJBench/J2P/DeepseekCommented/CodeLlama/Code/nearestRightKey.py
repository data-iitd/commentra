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
        if value not in nodeMap:
            nodeMap[value] = Node(value)
        current = nodeMap[value]
        if root is None:
            root = current
        if left != -1:
            if left not in nodeMap:
                nodeMap[left] = Node(left)
            current.left = nodeMap[left]
        if right != -1:
            if right not in nodeMap:
                nodeMap[right] = Node(right)
            current.right = nodeMap[right]

    inputX0 = int(sys.stdin.readline())
    toPrint = main(root, inputX0)
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


