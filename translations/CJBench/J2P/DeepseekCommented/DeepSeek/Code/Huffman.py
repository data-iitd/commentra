import heapq

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def print_codes(node, val=''):
    if node.left:
        print_codes(node.left, val + '0')
    if node.right:
        print_codes(node.right, val + '1')
    if not node.left and not node.right:
        print(f"{node.char}: {val}")

# Read input
n = int(input().strip())
char_freq = []
for _ in range(n):
    char, freq = input().strip().split()
    char_freq.append((char[0], int(freq)))

# Create priority queue
heap = [Node(char, freq) for char, freq in char_freq]
heapq.heapify(heap)

# Build the Huffman tree
while len(heap) > 1:
    left = heapq.heappop(heap)
    right = heapq.heappop(heap)
    merged = Node('-', left.freq + right.freq)
    merged.left = left
    merged.right = right
    heapq.heappush(heap, merged)

root = heap[0]
print_codes(root, '')
