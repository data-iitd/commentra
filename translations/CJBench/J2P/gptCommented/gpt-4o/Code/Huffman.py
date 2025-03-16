import heapq

# Class representing a node in the Huffman tree
class MainNode:
    def __init__(self, char, freq):
        self.data = freq  # Frequency of the character
        self.c = char      # Character
        self.left = None   # Left child
        self.right = None  # Right child

# Comparator function to compare MainNode objects based on their frequency
def compare_nodes(node):
    return node.data

def print_code(root, s):
    # Base case: if the node is a leaf node (no children)
    if root.left is None and root.right is None and root.c.isalpha():
        print(f"{root.c}: {s}")  # Print the character and its code
        return
    # Traverse left and append '0' to the code
    print_code(root.left, s + "0")
    # Traverse right and append '1' to the code
    print_code(root.right, s + "1")

def main():
    n = int(input())  # Read the number of characters
    
    # Lists to hold characters and their frequencies
    char_array = []
    char_freq = []
    
    # Read characters and their frequencies from input
    for _ in range(n):
        input_data = input().split()
        char_array.append(input_data[0])  # Store the character
        char_freq.append(int(input_data[1]))  # Store the frequency
    
    # Priority queue to build the Huffman tree
    priority_queue = []
    
    # Create a leaf node for each character and add it to the priority queue
    for i in range(n):
        node = MainNode(char_array[i], char_freq[i])  # Create a new node
        heapq.heappush(priority_queue, (node.data, node))  # Push to priority queue
    
    root = None  # Root of the Huffman tree
    
    # Build the Huffman tree
    while len(priority_queue) > 1:
        # Remove the two nodes of lowest frequency
        x = heapq.heappop(priority_queue)[1]
        y = heapq.heappop(priority_queue)[1]
        
        # Create a new internal node with these two nodes as children
        f = MainNode('-', x.data + y.data)  # Internal node does not represent a character
        f.left = x  # Set left child
        f.right = y  # Set right child
        
        root = f  # Update the root to the new internal node
        heapq.heappush(priority_queue, (f.data, f))  # Add the new node to the priority queue
    
    # Print the Huffman codes for each character
    print_code(root, "")

if __name__ == "__main__":
    main()

# <END-OF-CODE>
