import sys
from collections import deque

class Node:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

class MyComparator:
    def __init__(self):
        pass

    def compare(self, x, y):
        return x.data - y.data

def printCode(root, s):
    if root.left == None and root.right == None and ord(root.c) >= 97 and ord(root.c) <= 122:
        print(root.c + ": " + s)
        return
    printCode(root.left, s + "0")
    printCode(root.right, s + "1")

def main():
    n = int(sys.stdin.readline())
    charArray = []
    charfreq = []
    for i in range(n):
        input = sys.stdin.readline().split()
        charArray.append(input[0][0])
        charfreq.append(int(input[1]))
    q = deque()
    for i in range(n):
        hn = Node(charfreq[i], charArray[i])
        q.append(hn)
    root = None
    while len(q) > 1:
        x = q.popleft()
        y = q.popleft()
        f = Node('-', '-')
        f.data = x.data + y.data
        f.left = x
        f.right = y
        root = f
        q.append(f)
    printCode(root, "")

if __name__ == "__main__":
    main()
    print("