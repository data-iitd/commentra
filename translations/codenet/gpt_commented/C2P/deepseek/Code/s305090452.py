import sys
import heapq

# Define a class for a binary heap
class BinaryHeap:
    def __init__(self, val_size, cmpF):
        self.array = [None] * (1 + 1)  # Allocate memory for the heap array
        self.heap_size = 0  # Initialize heap size to 0
        self.max_size = 1  # Set initial maximum size
        self.val_size = val_size  # Set the value size
        self.cmp = cmpF  # Set the comparison function

    def push(self, val):
        # Check if the heap needs to be resized
        if self.heap_size == self.max_size:
            self.max_size = 2 * self.max_size + 1  # Double the max size
            self.array = self.array + [None] * (self.max_size + 1 - len(self.array))  # Resize the array
        self.heap_size += 1  # Increment the heap size
        array = self.array  # Get the array
        k = self.heap_size  # Current index for the new element
        val_size = self.val_size  # Size of the value
        cmp = self.cmp  # Get the comparison function
        # Copy the new value into the heap
        array[k] = val
        # Maintain the heap property by moving the new element up the heap
        while k > 1:
            parent = k // 2
            if cmp(array[parent], array[k]) <= 0:
                return
            array[parent], array[k] = array[k], array[parent]  # Swap with parent
            k = parent

    def pop(self):
        array = self.array  # Get the array
        val_size = self.val_size  # Size of the value
        if self.heap_size == 0:
            return None
        res = array[1]  # Copy the top value to the result
        array[1] = array[self.heap_size]  # Move the last element to the top
        self.heap_size -= 1  # Decrement the heap size
        n = self.heap_size  # Current size of the heap
        k = 1  # Start from the root
        # Maintain the heap property by moving the top element down the heap
        while 2 * k + 1 <= n:
            c = cmp(array[2 * k], array[2 * k + 1])  # Compare children
            next = 2 * k + (c <= 0)  # Choose the smaller child
            if cmp(array[k], array[next]) <= 0:
                return res
            array[k], array[next] = array[next], array[k]  # Swap with the smaller child
            k = next
        # Check if the last child needs to be swapped
        if 2 * k <= n and cmp(array[k], array[2 * k]) > 0:
            array[k], array[2 * k] = array[2 * k], array[k]
        return res

    def top(self):
        return self.array[1] if self.heap_size > 0 else None

# Define a class for Union-Find (Disjoint Set Union)
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

# Define a class for segment tree nodes
class SegmentNode:
    def __init__(self, index, val):
        self.index = index
        self.val = val

# Function to combine two segment nodes
def func_segment_node(c, a, b):
    c.val = min(a.val, b.val).val

# Define a class for edges
class Edge:
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c

# Comparison function for edges
def cmp_edge(a, b):
    return (a.c < b.c) - (a.c > b.c)

# Main function to run the algorithm
def run():
    n, d = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    p = [index_val(i, a[i]) for i in range(n)]
    p.sort(key=lambda x: x.val)
    ini = SegmentNode(n, n + 2) * 1000000000 + 1
    l = new_segment_tree(ini, n, sizeof(SegmentNode), func_segment_node)
    r = new_segment_tree(ini, n, sizeof(SegmentNode), func_segment_node)
    for i in range(n):
        update_tmp(l, i, SegmentNode(i, a[i] + (n - 1 - i) * d))
        update_tmp(r, i, SegmentNode(i, a[i] + i * d))
    update_all(l)
    update_all(r)
    h = BinaryHeap(sizeof(Edge), cmp_edge)
    for i in range(n):
        v = p[i].index
        if v > 0:
            t = find(l, 0, v)
            push(h, Edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d))
        if v + 1 < n:
            t = find(r, v + 1, n)
            push(h, Edge(v, t.index, p[i].val + t.val - v * d))
        update(l, v, ini)
        update(r, v, ini)
    sum = 0
    u = UnionFind(n)
    while u.getSize(0) < n:
        e = pop(h)
        if u.same(e.a, e.b):
            continue
        u.unite(e.a, e.b)
        sum += e.c
    print(sum)

# Main entry point of the program
if __name__ == "__main__":
    run()
