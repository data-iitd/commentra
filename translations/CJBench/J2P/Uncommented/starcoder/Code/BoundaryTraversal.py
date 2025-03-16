
import sys
import collections

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
        cur = (cur.left is not None) and cur.left or cur.right

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
    temp = collections.deque()
    while cur is not None:
        if not isLeaf(cur):
            temp.appendleft(cur.data)
        cur = (cur.right is not None) and cur.right or cur.left
    while temp:
        result.append(temp.popleft())

def isLeaf(node):
    return node.left is None and node.right is None

def buildTree(scanner):
    n = scanner.next()
    map = {}
    root = None
    for i in range(n):
        parent = scanner.next()
        direction = scanner.next()
        child = scanner.next()
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
    n = scanner.next()
    root = buildTree(scanner)
    result = boundaryTraversal(root)
    for value in result:
        print value,
    print

if __name__ == "__main__":
    main()

