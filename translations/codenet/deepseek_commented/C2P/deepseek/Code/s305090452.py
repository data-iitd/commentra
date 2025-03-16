import sys
import heapq

# Define the structure of a binary heap and its operations.
class BinaryHeap:
    def __init__(self, val_size, cmpF):
        self.array = [None] * (1 + 1)
        self.heap_size = 0
        self.max_size = 1
        self.val_size = val_size
        self.cmp = cmpF

    def push(self, val):
        if self.heap_size == self.max_size:
            self.max_size = 2 * self.max_size + 1
            self.array = [None] * (self.max_size + 1)
        self.heap_size += 1
        array = self.array
        k = self.heap_size
        val_size = self.val_size
        int_val_size = self.val_size // 8
        if int_val_size * 8 == self.val_size:
            while k > 1:
                parent = k // 2
                if self.cmp(array[parent], val) <= 0:
                    break
                array[parent], array[k] = array[k], array[parent]
                k = parent
        else:
            while k > 1:
                parent = k // 2
                if self.cmp(array[parent * int_val_size:(parent + 1) * int_val_size], val) <= 0:
                    break
                array[parent * int_val_size:(parent + 1) * int_val_size] = val
                k = parent

    def pop(self):
        if self.heap_size == 0:
            return None
        res = self.array[1]
        self.array[1] = self.array[self.heap_size]
        self.heap_size -= 1
        array = self.array
        n = self.heap_size
        k = 1
        int_val_size = self.val_size // 8
        if int_val_size * 8 == self.val_size:
            while 2 * k + 1 <= n:
                c = self.cmp(array[2 * k], array[2 * k + 1])
                next = 2 * k + (c <= 0)
                if self.cmp(array[k], array[next]) <= 0:
                    break
                array[k], array[next] = array[next], array[k]
                k = next
        else:
            while 2 * k + 1 <= n:
                c = self.cmp(array[2 * k], array[2 * k + 1])
                next = 2 * k + (c <= 0)
                if self.cmp(array[k], array[next]) <= 0:
                    break
                array[k], array[next] = array[next], array[k]
                k = next
        if 2 * k <= n:
            if self.cmp(array[k], array[2 * k]) > 0:
                array[k], array[2 * k] = array[2 * k], array[k]
        return res

    def top(self):
        return self.array[1]

# Define the structure of Union-Find and its operations.
class UnionFind:
    def __init__(self, size):
        self.parent = [-1] * size
        self.size = size

    def root(self, x):
        index = []
        while self.parent[x] >= 0:
            index.append(x)
            x = self.parent[x]
        for i in index:
            self.parent[i] = x
        return x

    def same(self, x, y):
        return self.root(x) == self.root(y)

    def getSize(self, x):
        return -self.parent[self.root(x)]

    def unite(self, x, y):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return
        if self.parent[x] > self.parent[y]:
            x, y = y, x
        self.parent[x] += self.parent[y]
        self.parent[y] = x

# Define the structure of a segment tree and its operations.
class SegmentTree:
    def __init__(self, ini, n, val_size, func):
        k = 1
        while k < n:
            k *= 2
        self.array = [None] * (2 * k)
        self.size = k
        self.val_size = val_size
        self.func = func
        for i in range(k, 2 * k):
            self.array[i] = ini[i - k]
        for i in range(k - 1, 0, -1):
            self.func(self.array[i], self.array[2 * i], self.array[2 * i + 1])

    def update(self, k, val):
        k += self.size
        self.array[k] = val
        while k > 1:
            k //= 2
            self.func(self.array[k], self.array[2 * k], self.array[2 * k + 1])

    def find(self, l, r):
        res = self.array[l + self.size]
        while l < r:
            if l & 1:
                self.func(res, res, self.array[l])
                l += 1
            if r & 1:
                r -= 1
                self.func(res, res, self.array[r])
            l //= 2
            r //= 2
        return res

# Define the main function to run the program.
def run():
    n, d = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    p = [{"index": i, "val": a[i]} for i in range(n)]
    p.sort(key=lambda x: x["val"])
    l = SegmentTree([{"index": n, "val": (n + 2) * 1000000000 + 1}], n,