import sys
from queue import PriorityQueue

# Class representing a node in the Main tree
class MainNode:
    def __init__(self):
        self.data = 0
        self.c = ''
        self.left = None
        self.right = None

# Comparator class to compare MainNode objects based on their frequency
class MyComparator:
    def __init__(self):
        pass
    def __call__(self, x, y):
        return x.data - y.data

# Recursive method to print the Main codes for each character
def printCode(root, s):
    # Base case: if the node is a leaf node (no children)
    if root.left == None and root.right == None and root.c.isalpha():
        print(root.c + ": " + s) # Print the character and its code
        return
    # Traverse left and append '0' to the code
    printCode(root.left, s + "0")
    # Traverse right and append '1' to the code
    printCode(root.right, s + "1")

def main():
    # Read the number of characters
    n = int(input())
    # Read characters and their frequencies from input
    charArray = []
    charfreq = []
    for i in range(n):
        input = input().split(" ")
        charArray.append(input[0].strip()) # Store the character
        charfreq.append(int(input[1])) # Store the frequency
    # Priority queue to build the Main tree
    q = PriorityQueue(n, MyComparator())
    # Create a leaf node for each character and add it to the priority queue
    for i in range(n):
        hn = MainNode()
        hn.c = charArray[i] # Set character
        hn.data = charfreq[i] # Set frequency
        hn.left = None # Initialize left child
        hn.right = None # Initialize right child
        q.put(hn) # Add node to the priority queue
    root = None # Root of the Main tree
    # Build the Main tree
    while q.qsize() > 1:
        # Remove the two nodes of lowest frequency
        x = q.get()
        y = q.get()
        # Create a new internal node with these two nodes as children
        f = MainNode()
        f.data = x.data + y.data # Frequency of the new node
        f.c = '-' # Internal node does not represent a character
        f.left = x # Set left child
        f.right = y # Set right child
        root = f # Update the root to the new internal node
        q.put(f) # Add the new node to the priority queue
    # Print the Main codes for each character
    printCode(root, "")

if __name__ == "__main__":
    main()

# 