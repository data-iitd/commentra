import heapq
class MainNode:
    def __init__(self, data, c, left, right):
        self.data = data
        self.c = c
        self.left = left
        self.right = right
class MyComparator:
    def __init__(self):
        pass
    def compare(self, x, y):
        return x.data - y.data
def printCode(root, s):
    if root.left == None and root.right == None and root.c.isalpha():
        print(root.c + ": " + s)
        return
    printCode(root.left, s + "0")
    printCode(root.right, s + "1")
def main():
    sc = Scanner(System.in)
    n = sc.nextInt()
    sc.nextLine()
    charArray = [None] * n
    charfreq = [None] * n
    for i in range(n):
        input = sc.nextLine().split(" ")
        charArray[i] = input[0].charAt(0)
        charfreq[i] = int(input[1])
    q = []
    for i in range(n):
        hn = MainNode(charfreq[i], charArray[i], None, None)
        heapq.heappush(q, hn)
    root = None
    while len(q) > 1:
        x = heapq.heappop(q)
        y = heapq.heappop(q)
        f = MainNode(x.data + y.data, '-', x, y)
        root = f
        heapq.heappush(q, f)
    printCode(root, "")
    sc.close()
if __name__ == "__main__":
    main()

