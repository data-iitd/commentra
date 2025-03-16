
import sys
from collections import deque

# Define the Node class
# This class represents a node in the Huffman tree. It contains:
# - data: an integer representing the frequency of the character.
# - c: a character.
# - left and right: references to the left and right children of the node.
class Node:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

# Define the MyComparator class
# This class implements the Comparator interface to compare Node objects based on their data field.
class MyComparator:
    def __init__(self):
        pass

    def __lt__(self, x, y):
        return x.data < y.data

# Define the printCode method
# This method takes a root node and a String representing the code, and recursively prints the Huffman codes for each character.
def printCode(root, s):
    if root.left == None and root.right == None and ord(root.c) >= 65 and ord(root.c) <= 90:
        print(root.c + ": " + s)
        return
    printCode(root.left, s + "0")
    printCode(root.right, s + "1")

# Define the main method
# This method reads the input, creates a priority queue of Node objects, constructs the Huffman tree, and finally prints the Huffman codes.
def main():
    n = int(sys.stdin.readline())
    charArray = []
    charfreq = []
    for i in range(n):
        line = sys.stdin.readline()
        charArray.append(line[0])
        charfreq.append(int(line[2:]))
    q = deque()
    for i in range(n):
        hn = Node(charfreq[i], charArray[i])
        q.append(hn)
    while len(q) > 1:
        x = q.popleft()
        y = q.popleft()
        f = Node(x.data + y.data, '-')
        f.left = x
        f.right = y
        q.append(f)
    root = q.popleft()
    printCode(root, "")

if __name__ == "__main__":
    main()

