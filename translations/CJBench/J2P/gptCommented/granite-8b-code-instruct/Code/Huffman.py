
import heapq

# Class representing a node in the Main tree
class MainNode:
    def __init__(self, data, c, left=None, right=None):
        self.data = data  # Frequency of the character
        self.c = c  # Character
        self.left = left  # Left child
        self.right = right  # Right child

# Comparator class to compare MainNode objects based on their frequency
class MyComparator:
    def __init__(self):
        pass

    def __call__(self, x, y):
        return x.data - y.data  # Compare based on frequency

def print_code(root, s):
    # Base case: if the node is a leaf node (no children)
    if root.left is None and root.right is None and root.c.isalpha():
        print(f"{root.c}: {s}")  # Print the character and its code
        return

    # Traverse left and append '0' to the code
    print_code(root.left, s + "0")

    # Traverse right and append '1' to the code
    print_code(root.right, s + "1")

if __name__ == "__main__":
    n = int(input())  # Read the number of characters

    # Arrays to hold characters and their frequencies
    charArray = []
    charfreq = []

    # Read characters and their frequencies from input
    for _ in range(n):
        input_str = input()
        char, freq = input_str.split()
        charArray.append(char)  # Store the character
        charfreq.append(int(freq))  # Store the frequency

    # Priority queue to build the Main tree
    q = []

    # Create a leaf node for each character and add it to the priority queue
    for i in range(n):
        hn = MainNode(charfreq[i], charArray[i])
        heapq.heappush(q, hn)

    root = None  # Root of the Main tree

    # Build the Main tree
    while len(q) > 1:
        # Remove the two nodes of lowest frequency
        x = heapq.heappop(q)
        y = heapq.heappop(q)

        # Create a new internal node with these two nodes as children
        f = MainNode(x.data + y.data, "-")
        f.left = x
        f.right = y

        root = f
        heapq.heappush(q, f)

    # Print the Main codes for each character
    print_code(root, "")

