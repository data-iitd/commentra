

import heapq

# Class representing a node in the Main tree
class MainNode:
    def __init__(self, c, data):
        self.c = c
        self.data = data
        self.left = None
        self.right = None

# Comparator class for sorting nodes based on their frequencies
class MyComparator:
    def __init__(self):
        pass

    def __call__(self, x, y):
        # Compare nodes based on their frequencies
        return x.data - y.data

# Main function to print Main codes for each character
def printCode(root, s):
    # Base case: if the node is a leaf node, print the character and its code
    if root.left is None and root.right is None and root.c.isalpha():
        print(root.c + ": " + s)
        return

    # Recursive case: print codes for left and right subtrees and append appropriate bit
    printCode(root.left, s + "0")
    printCode(root.right, s + "1")

if __name__ == "__main__":
    # Initialize scanner for reading input
    sc = input()

    # Read number of characters and their frequencies from input
    n = int(sc)
    charArray = []
    charfreq = []
    for i in range(n):
        input = sc.readline().split()
        charArray.append(input[0][0])
        charfreq.append(int(input[1]))

    # Create a priority queue to store nodes based on their frequencies
    q = []
    for i in range(n):
        hn = MainNode(charArray[i], charfreq[i])
        heapq.heappush(q, hn)

    # Build the Main tree by merging nodes with the smallest frequencies
    root = None
    while len(q) > 1:
        x = heapq.heappop(q)
        y = heapq.heappop(q)

        # Create a new node as the root of the subtree merging x and y
        f = MainNode('-', x.data + y.data)
        f.left = x
        f.right = y

        # Update the root of the tree
        root = f

        # Add the new node to the priority queue
        heapq.heappush(q, f)

    # Print Main codes for all characters
    printCode(root, "")

    # Close the scanner
    sc.close()

