
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

    def compare(self, x, y):
        # Compare nodes based on their frequencies
        return x.data - y.data

# Main class
class Main:
    def __init__(self):
        pass

    # Function to print Main codes for each character
    def printCode(self, root, s):
        # Base case: if the node is a leaf node, print the character and its code
        if root.left == None and root.right == None and root.c.isalpha():
            print(root.c + ": " + s)
            return

        # Recursive case: print codes for left and right subtrees and append appropriate bit
        self.printCode(root.left, s + "0")
        self.printCode(root.right, s + "1")

    def main(self):
        # Read number of characters and their frequencies from input
        n = int(input())
        charArray = list(input().split(" "))
        charfreq = list(map(int, input().split(" ")))

        # Create a priority queue to store nodes based on their frequencies
        q = []

        # Create nodes for each character and add them to the priority queue
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
        self.printCode(root, "")

# Create a new instance of Main class and call the main function
if __name__ == "__main__":
    obj = Main()
    obj.main()

# 