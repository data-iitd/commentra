from queue import PriorityQueue

# Class representing a node in the Huffman tree
class HuffmanNode:
    def __init__(self, char=None, freq=0):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

# Function to print Huffman codes for each character
def print_code(node, s):
    if node.left is None and node.right is None and node.char is not None:
        print(f"{node.char}: {s}")
        return

    # Recursive case: print codes for left and right subtrees and append appropriate bit
    print_code(node.left, s + "0")
    print_code(node.right, s + "1")

# Main function
def main():
    # Read number of characters and their frequencies from input
    n = int(input())
    char_array = []
    freq_array = []
    for _ in range(n):
        char, freq = input().split()
        char_array.append(char[0])
        freq_array.append(int(freq))

    # Create a priority queue to store nodes based on their frequencies
    q = PriorityQueue()

    # Create nodes for each character and add them to the priority queue
    for i in range(n):
        hn = HuffmanNode(char_array[i], freq_array[i])
        q.put(hn)

    # Build the Huffman tree by merging nodes with the smallest frequencies
    root = None
    while q.qsize() > 1:
        x = q.get()
        y = q.get()

        # Create a new node as the root of the subtree merging x and y
        f = HuffmanNode('-', x.freq + y.freq)
        f.left = x
        f.right = y

        # Update the root of the tree
        root = f

        # Add the new node to the priority queue
        q.put(f)

    # Print Huffman codes for all characters
    print_code(root, "")

if __name__ == "__main__":
    main()

