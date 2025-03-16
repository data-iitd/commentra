import sys
from ctypes import *

# Define a structure for a binary heap
class BinaryHeap:
    def __init__(self, val_size, cmpF):
        self.array = (c_void_p * (1 + 1))()  # Pointer to the array that holds the heap elements
        self.heap_size = 0  # Current number of elements in the heap
        self.max_size = 1  # Maximum capacity of the heap
        self.val_size = val_size  # Size of each value in the heap
        self.cmp = cmpF  # Comparison function for heap elements

    def get_heap_size(self):
        return self.heap_size  # Return the current size of the heap

    def is_empty(self):
        return self.heap_size == 0  # Return True if the heap is empty, otherwise False

    def free_heap(self):
        # Freeing memory is handled by Python's garbage collector
        pass

    def push(self, val):
        if self.heap_size == self.max_size:
            self.max_size = 2 * self.max_size + 1  # Double the max size
            self.array = (c_void_p * (self.max_size + 1))()  # Resize the array
        self.heap_size += 1  # Increment the heap size
        k = self.heap_size  # Current index for the new element
        self.array[k] = val  # Copy the new value into the heap
        # Maintain the heap property by moving the new element up the heap
        while k > 1:
            parent = k // 2  # Calculate the parent index
            if self.cmp(self.array[parent], self.array[k]) <= 0:
                return  # If the heap property is satisfied, exit
            self.array[parent], self.array[k] = self.array[k], self.array[parent]  # Swap with parent
            k = parent  # Move up to the parent

    def pop(self):
        if self.is_empty():
            return None
        res = self.array[1]  # Get the top value
        self.array[1] = self.array[self.heap_size]  # Move the last element to the top
        self.heap_size -= 1  # Decrement the heap size
        k = 1  # Start from the root
        # Maintain the heap property by moving the top element down the heap
        while 2 * k <= self.heap_size:
            next = 2 * k + (1 if self.cmp(self.array[2 * k], self.array[2 * k + 1]) > 0 else 0)  # Choose the smaller child
            if self.cmp(self.array[k], self.array[next]) <= 0:
                return  # If heap property is satisfied, exit
            self.array[k], self.array[next] = self.array[next], self.array[k]  # Swap with the smaller child
            k = next  # Move down to the next level
        return res  # Return the popped value

    def top(self):
        return self.array[1] if not self.is_empty() else None  # Get the top value without removing it


# Define a structure for Union-Find (Disjoint Set Union)
class UnionFind:
    def __init__(self, size):
        self.parent = [-1] * size  # Array to hold the parent of each element
        self.size = size  # Size of the Union-Find structure

    def root(self, x):
        index = []
        while self.parent[x] >= 0:
            index.append(x)
            x = self.parent[x]
        for i in index:
            self.parent[i] = x  # Path compression
        return x  # Return the root

    def same(self, x, y):
        return self.root(x) == self.root(y)  # Return True if they have the same root, otherwise False

    def get_size(self, x):
        return -self.parent[self.root(x)]  # Return the size of the set

    def unite(self, x, y):
        x = self.root(x)  # Find the root of x
        y = self.root(y)  # Find the root of y
        if x == y:
            return  # If they are already in the same set, do nothing
        if self.parent[x] > self.parent[y]:  # Union by size
            x, y = y, x
        self.parent[x] += self.parent[y]  # Update the size of the new root
        self.parent[y] = x  # Make x the parent of y


# Define a structure for segment tree
class SegmentTree:
    def __init__(self, ini, n, val_size, func):
        k = 1
        while k < n:
            k *= 2  # Find the next power of 2 greater than n
        self.array = (c_void_p * (2 * k))()  # Allocate memory for the segment tree array
        self.size = k  # Set the size of the segment tree
        self.val_size = val_size  # Set the value size
        self.func = func  # Set the function to combine values
        for i in range(k, 2 * k):
            self.array[i] = ini  # Initialize the leaves of the segment tree
        for i in range(k - 1, 0, -1):
            self.func(self.array[i], self.array[2 * i], self.array[2 * i + 1])  # Build the segment tree

    def update(self, k, val):
        k += self.size  # Move to the leaf position
        self.array[k] = val  # Update the value at the leaf
        for k in range(k // 2, 0, k // 2):
            self.func(self.array[k], self.array[2 * k], self.array[2 * k + 1])  # Update the segment tree upwards

    def find(self, l, r):
        lindex = []
        rindex = []
        llen = 0
        rlen = 0
        for l += self.size, r += self.size; l < r; l >>= 1, r >>= 1:
            if l & 1:
                lindex.append(l)
                l += 1
            if r & 1:
                r -= 1
                rindex.append(r)
        if llen == 0:
            lindex.append(rindex.pop())
        res = self.array[lindex[0]]  # Initialize result with the first left index
        for i in range(1, llen):
            self.func(res, res, self.array[lindex[i]])  # Combine results from left indices
        for i in range(rlen - 1, -1, -1):
            self.func(res, res, self.array[rindex[i]])  # Combine results from right indices
        return res


# Define integer types for convenience
i32 = c_int32
i64 = c_int64

# Define a structure for index-value pairs
class IndexVal:
    def __init__(self, index, val):
        self.index = index  # Index of the value
        self.val = val  # Value


# Comparison function for index-value pairs
def cmp_index_val(a, b):
    d = a.val - b.val  # Compare values
    return (d > 0) - (d < 0)  # Return comparison result


# Define a structure for segment tree nodes
class SegmentNode:
    def __init__(self, index, val):
        self.index = index  # Index of the node
        self.val = val  # Value of the node


# Function to combine two segment nodes
def func_segment_node(c, a, b):
    c[0] = a if a.val < b.val else b  # Choose the node with the smaller value


# Define a structure for edges
class Edge:
    def __init__(self, a, b, c):
        self.a = a  # Endpoint of the edge
        self.b = b  # Endpoint of the edge
        self.c = c  # Cost of the edge


# Comparison function for edges
def cmp_edge(a, b):
    d = a.c - b.c  # Compare costs
    return (d > 0) - (d < 0)  # Return comparison result


# Main function to run the algorithm
def run():
    n, d = map(int, sys.stdin.readline().split())  # Read n and d
    a = (i32 * n)()  # Allocate array for values
    p = (IndexVal * n)()  # Allocate array for index-value pairs
    # Read values and initialize index-value pairs
    for i in range(n):
        a[i] = i32(int(sys.stdin.readline().strip()))
        p[i] = IndexVal(i, a[i])
    p = sorted(p, key=lambda x: x.val)  # Sort index-value pairs by value
    ini = SegmentNode(n, (n + 2) * 1000000000 + 1)  # Initialize segment node
    l = SegmentTree(ini, n, sizeof(SegmentNode), func_segment_node)  # Create left segment tree
    r = SegmentTree(ini, n, sizeof(SegmentNode), func_segment_node)  # Create right segment tree
    # Update segment trees with adjusted values
    for i in range(n):
        l.update(i, SegmentNode(i, a[i] + (n - 1 - i) * d))
        r.update(i, SegmentNode(i, a[i] + i * d))
    h = BinaryHeap(sizeof(Edge), cmp_edge)  # Create a new binary heap for edges
    # Process each index-value pair
    for i in range(n):
        v = p[i].index  # Get the original index
        if v > 0:
            t = l.find(0, v)  # Find the minimum in the left segment tree
            h.push(Edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d))  # Push edge to heap
        if v + 1 < n:
            t = r.find(v + 1, n)  # Find the minimum in the right segment tree
            h.push(Edge(v, t.index, p[i].val + t.val - v * d))  # Push edge to heap
        l.update(v, ini)  # Update left segment tree
        r.update(v, ini)  # Update right segment tree
    sum_cost = 0  # Initialize sum of costs
    u = UnionFind(n)  # Create a new Union-Find structure
    # Process edges in the heap to find the minimum spanning tree
    while u.get_size(0) < n:
        e = h.pop()  # Pop the minimum edge from the heap
        if u.same(e.a, e.b):
            continue  # If they are already connected, skip
        u.unite(e.a, e.b)  # Union the sets
        sum_cost += e.c  # Add the cost of the edge to the sum
    print(sum_cost)  # Print the total cost


# Main entry point of the program
if __name__ == "__main__":
    run()  # Execute the run function

# <END-OF-CODE>
