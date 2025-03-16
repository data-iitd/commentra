import heapq

# Class representing a node in the Huffman tree
class MainNode:
    def __init__(self, c, data=0):
        self.c = c  # Character represented by the node
        self.data = data  # Frequency of the character
        self.left = None  # Left child node
        self.right = None  # Right child node

    # For the priority queue to compare nodes based on their frequencies
    def __lt__(self, other):
        return self.data < other.data

# Function to print Huffman codes for each character
def print_code(root, s):
    # Base case: if the node is a leaf node, print the character and its code
    if root.left is None and root.right is None and root.c.isalpha():
        print(f"{root.c}: {s}")
        return

    # Recursive case: print codes for left and right subtrees and append appropriate bit
    print_code(root.left, s + "0")
    print_code(root.right, s + "1")

def main():
    # Read number of characters and their frequencies from input
    n = int(input())
    char_array = []
    char_freq = []
    
    for _ in range(n):
        input_data = input().split()
        char_array.append(input_data[0])
        char_freq.append(int(input_data[1]))

    # Create a priority queue to store nodes based on their frequencies
    priority_queue = []
    
    # Create nodes for each character and add them to the priority queue
    for i in range(n):
        hn = MainNode(char_array[i], char_freq[i])
        heapq.heappush(priority_queue, hn)

    # Build the Huffman tree by merging nodes with the smallest frequencies
    root = None
    while len(priority_queue) > 1:
        x = heapq.heappop(priority_queue)
        y = heapq.heappop(priority_queue)

        # Create a new node as the root of the subtree merging x and y
        f = MainNode('-', x.data + y.data)
        f.left = x
        f.right = y

        # Update the root of the tree
        root = f

        # Add the new node to the priority queue
        heapq.heappush(priority_queue, f)

    # Print Huffman codes for all characters
    print_code(root, "")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
