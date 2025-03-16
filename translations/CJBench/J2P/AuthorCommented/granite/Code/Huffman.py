
import heapq

class MainNode:
    def __init__(self, data, c):
        self.data = data
        self.c = c
        self.left = None
        self.right = None

class MyComparator:
    def __init__(self):
        pass

    def __call__(self, x, y):
        return x.data - y.data

def printCode(root, s):
    if root.left is None and root.right is None and root.c.isalpha():
        print(root.c + ": " + s)
        return

    printCode(root.left, s + "0")
    printCode(root.right, s + "1")

if __name__ == "__main__":
    n = int(input())

    charArray = []
    charfreq = []

    for i in range(n):
        input_str = input()
        input_list = input_str.split(" ")
        charArray.append(input_list[0][0])
        charfreq.append(int(input_list[1]))

    q = []

    for i in range(n):
        hn = MainNode(charfreq[i], charArray[i])
        heapq.heappush(q, hn)

    while len(q) > 1:
        x = heapq.heappop(q)
        y = heapq.heappop(q)

        f = MainNode(x.data + y.data, "-")
        f.left = x
        f.right = y

        root = f
        heapq.heappush(q, f)

    printCode(root, "")

