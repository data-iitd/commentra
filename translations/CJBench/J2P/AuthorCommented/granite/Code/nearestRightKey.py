

import sys

class NRKTree:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

def Main(root, x0):
    if root is None:
        return 0
    elif root.data > x0:
        temp = Main(root.left, x0)
        if temp == 0:
            return root.data
        return temp
    else:
        return Main(root.right, x0)

if __name__ == "__main__":
    n = int(input())

    nodeMap = {}
    root = None

    for i in range(n):
        value, left, right = map(int, input().split())
        nodeMap[value] = NRKTree(value)
        current = nodeMap[value]

        if root is None:
            root = current # Assign the first node as the root
        if left!= -1:
            nodeMap[left] = NRKTree(left)
            current.left = nodeMap[left]
        if right!= -1:
            nodeMap[right] = NRKTree(right)
            current.right = nodeMap[right]

    x0 = int(input())

    toPrint = Main(root, x0)
    if toPrint == 0:
        print("No nearest right key found.")
    else:
        print("Nearest Right Key: " + str(toPrint))

