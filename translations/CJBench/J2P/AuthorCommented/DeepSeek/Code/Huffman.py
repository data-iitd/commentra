import heapq

class Node:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    def __lt__(self, other):
        return self.freq < other.freq

def print_code(node, s):
    if node.left is None and node.right is None and node.char.isalpha():
        print(f"{node.char}: {s}")
        return

    print_code(node.left, s + "0")
    print_code(node.right, s + "1")

n = int(input())
char_freq = []

for _ in range(n):
    char, freq = input().split()
    char_freq.append((char, int(freq)))

heapq.heapify(char_freq)

while len(char_freq) > 1:
    left = heapq.heappop(char_freq)
    right = heapq.heappop(char_freq)

    new_freq = left[1] + right[1]
    new_node = Node(char='-', freq=new_freq)
    new_node.left = Node(char=left[0], freq=left[1])
    new_node.right = Node(char=right[0], freq=right[1])

    heapq.heappush(char_freq, (new_node.char, new_node.freq))

root = char_freq[0][0]

print_code(root, "")
