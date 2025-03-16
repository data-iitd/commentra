
import sys
from collections import deque

# Class representing a node in the Main tree
class MainNode:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

# Comparator class to compare MainNode objects based on their frequency
class MyComparator:
    def __init__(self):
        pass

    def __lt__(self, x, y):
        return x.data < y.data

# Recursive method to print the Main codes for each character
def printCode(root, s):
    # Base case: if the node is a leaf node (no children)
    if root.left is None and root.right is None and root.c.isalpha():
        print(root.c + ": " + s)
        return
    # Traverse left and append '0' to the code
    printCode(root.left, s + "0")
    # Traverse right and append '1' to the code
    printCode(root.right, s + "1")

if __name__ == "__main__":
    # Read the number of characters
    n = int(sys.stdin.readline())

    # Arrays to hold characters and their frequencies
    charArray = []
    charfreq = []

    # Read characters and their frequencies from input
    for i in range(n):
        input = sys.stdin.readline().split()
        charArray.append(input[0][0])
        charfreq.append(int(input[1]))

    # Priority queue to build the Main tree
    q = deque()

    # Create a leaf node for each character and add it to the priority queue
    for i in range(n):
        hn = MainNode(charfreq[i], charArray[i])
        q.append(hn)

    root = None

    # Build the Main tree
    while len(q) > 1:
        # Remove the two nodes of lowest frequency
        x = q.popleft()
        y = q.popleft()

        # Create a new internal node with these two nodes as children
        f = MainNode(x.data + y.data, '-')
        f.left = x
        f.right = y

        root = f
        q.append(f)

    # Print the Main codes for each character
    printCode(root, "")

