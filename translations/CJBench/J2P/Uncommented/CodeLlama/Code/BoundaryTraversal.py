
import sys
class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def boundaryTraversal(root):
    result = []
    if root is None:
        return result
    if not isLeaf(root):
        result.append(root.data)
    addLeftBoundary(root, result)
    addLeaves(root, result)
    addRightBoundary(root, result)
    return result

def addLeftBoundary(node, result):
    cur = node.left
    while cur is not None:
        if not isLeaf(cur):
            result.append(cur.data)
        cur = cur.left if cur.left is not None else cur.right

def addLeaves(node, result):
    if node is None:
        return
    if isLeaf(node):
        result.append(node.data)
    else:
        addLeaves(node.left, result)
        addLeaves(node.right, result)

def addRightBoundary(node, result):
    cur = node.right
    temp = []
    while cur is not None:
        if not isLeaf(cur):
            temp.append(cur.data)
        cur = cur.right if cur.right is not None else cur.left
    while len(temp) > 0:
        result.append(temp.pop())

def isLeaf(node):
    return node.left is None and node.right is None

def buildTree(scanner):
    n = int(scanner.next())
    map = {}
    root = None
    for i in range(n):
        parent = int(scanner.next())
        direction = scanner.next()
        child = int(scanner.next())
        parentNode = map.get(parent, Node(parent))
        childNode = Node(child)
        if direction == "L":
            parentNode.left = childNode
        else:
            parentNode.right = childNode
        map[parent] = parentNode
        map[child] = childNode
        if root is None:
            root = parentNode
    return root

def main():
    scanner = sys.stdin
    print("Enter the number of nodes and edges:")
    root = buildTree(scanner)
    print("Boundary traversal:")
    result = boundaryTraversal(root)
    for value in result:
        print(value, end=" ")
    print()
    scanner.close()

if __name__ == "__main__":
    main()

