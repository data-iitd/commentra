
import sys
from collections import deque

# node class is the basic structure
# of each node present in the Main - tree.
class MainNode:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

# comparator class helps to compare the node
# on the basis of one of its attribute.
# Here we will be compared
# on the basis of data values of the nodes.
class MyComparator:
    def __init__(self):
        pass

    def compare(self, x, y):
        return x.data - y.data

# recursive function to print the
# huffman-code through the tree traversal.
# Here s is the huffman - code generated.
def printCode(root, s):
    if root.left == None and root.right == None and root.c.isalpha():
        # c is the character in the node
        print(root.c + ": " + s)
        return

    # if we go to left then add "0" to the code.
    # if we go to the right add"1" to the code.
    # recursive calls for left and
    # right sub-tree of the generated tree.
    printCode(root.left, s + "0")
    printCode(root.right, s + "1")

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    charArray = []
    charfreq = []

    for i in range(n):
        input = sys.stdin.readline().split(" ")
        charArray.append(input[0][0])
        charfreq.append(int(input[1]))

    q = deque()

    for i in range(n):
        # creating a Main node object
        # and add it to the priority queue.
        hn = MainNode(charfreq[i], charArray[i])
        q.append(hn)

    root = None

    # Here we will extract the two minimum value
    # from the heap each time until
    # its size reduces to 1, extract until
    # all the nodes are extracted.
    while len(q) > 1:
        x = q.popleft()
        y = q.popleft()

        # new node f which is equal
        f = MainNode(x.data + y.data, '-')
        # first extracted node as left child.
        f.left = x
        # second extracted node as the right child.
        f.right = y

        # marking the f node as the root node.
        root = f
        # add this node to the priority-queue.
        q.append(f)

    # print the codes by traversing the tree
    printCode(root, "")

