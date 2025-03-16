import ctypes
from ctypes import c_int32, c_int64, POINTER, Structure, c_void_p, c_size_t, CFUNCTYPE

# Define a structure for binary heap
class Heap:
    def __init__(self, val_size, cmpF):
        self.array = (ctypes.c_byte * (val_size * (1 + 1)))()
        self.heap_size = 0
        self.max_size = 1
        self.val_size = val_size
        self.cmp = cmpF

# Function to create a new binary heap
def new_binary_heap(val_size, cmpF):
    return Heap(val_size, cmpF)

def get_heap_size(h):
    return h.heap_size

def is_empty(h):
    return h.heap_size == 0

def free_heap(h):
    del h.array
    del h

def init_heap(h):
    h.heap_size = 0

# Helper functions for heap manipulation
def heap_func_swap(a, b, val_size):
    for i in range(val_size):
        a[i], b[i] = b[i], a[i]

def heap_func_copy(dst, src, val_size):
    for i in range(val_size):
        dst[i] = src[i]

def push(h, val):
    if h.heap_size == h.max_size:
        h.max_size = 2 * h.max_size + 1
        h.array = (ctypes.c_byte * (h.val_size * (h.max_size + 1)))()
    
    h.heap_size += 1
    k = h.heap_size
    heap_func_copy(h.array[k * h.val_size:(k + 1) * h.val_size], val, h.val_size)
    
    while k > 1:
        parent = k // 2
        if h.cmp(h.array[parent * h.val_size:(parent + 1) * h.val_size], h.array[k * h.val_size:(k + 1) * h.val_size]) <= 0:
            return
        heap_func_swap(h.array[parent * h.val_size:(parent + 1) * h.val_size], h.array[k * h.val_size:(k + 1) * h.val_size], h.val_size)
        k = parent

def pop(h, res):
    if res is not None:
        heap_func_copy(res, h.array[1 * h.val_size:2 * h.val_size], h.val_size)
    
    heap_func_copy(h.array[1 * h.val_size:2 * h.val_size], h.array[h.heap_size * h.val_size:(h.heap_size + 1) * h.val_size], h.val_size)
    h.heap_size -= 1
    n = h.heap_size
    k = 1
    
    while 2 * k + 1 <= n:
        c = h.cmp(h.array[2 * k * h.val_size:(2 * k + 1) * h.val_size], h.array[(2 * k + 1) * h.val_size:(2 * k + 2) * h.val_size])
        next = 2 * k + (0 if c <= 0 else 1)
        if h.cmp(h.array[k * h.val_size:(k + 1) * h.val_size], h.array[next * h.val_size:(next + 1) * h.val_size]) <= 0:
            return
        heap_func_swap(h.array[k * h.val_size:(k + 1) * h.val_size], h.array[next * h.val_size:(next + 1) * h.val_size], h.val_size)
        k = next
    
    if 2 * k <= n and h.cmp(h.array[k * h.val_size:(k + 1) * h.val_size], h.array[2 * k * h.val_size:(2 * k + 1) * h.val_size]) > 0:
        heap_func_swap(h.array[k * h.val_size:(k + 1) * h.val_size], h.array[2 * k * h.val_size:(2 * k + 1) * h.val_size], h.val_size)

def top(h, res):
    if res is not None:
        heap_func_copy(res, h.array[1 * h.val_size:2 * h.val_size], h.val_size)

# Define a structure for Union-Find data structure
class UnionFind:
    def __init__(self, size):
        self.parent = (c_int32 * size)()
        self.size = size
        self.init_union_find()

    def init_union_find(self):
        for i in range(self.size):
            self.parent[i] = -1

def free_union_find(u):
    del u.parent
    del u

def root(u, x):
    index = []
    while u.parent[x] >= 0:
        index.append(x)
        x = u.parent[x]
    for i in reversed(index):
        u.parent[i] = x
    return x

def same(u, x, y):
    return root(u, x) == root(u, y)

def get_size(u, x):
    return -u.parent[root(u, x)]

def unite(u, x, y):
    x = root(u, x)
    y = root(u, y)
    if x == y:
        return
    if u.parent[x] > u.parent[y]:
        x, y = y, x
    u.parent[x] += u.parent[y]
    u.parent[y] = x

# Define a structure for segment tree
class SegmentTree:
    def __init__(self, ini, n, val_size, func):
        k = 1
        while k < n:
            k *= 2
        self.array = (ctypes.c_byte * (2 * k * val_size))()
        self.size = k
        self.val_size = val_size
        self.func = func
        for i in range(k, 2 * k):
            heap_func_copy(self.array[i * val_size:(i + 1) * val_size], ini, val_size)
        for i in range(k - 1, 0, -1):
            self.func(self.array[i * val_size:(i + 1) * val_size], self.array[2 * i * val_size:(2 * i + 1) * val_size], self.array[(2 * i + 1) * val_size:(2 * i + 2) * val_size])

def segment_tree_memcpy(dst, src, size):
    for i in range(size):
        dst[i] = src[i]

def update(s, k, val):
    k += s.size
    segment_tree_memcpy(s.array[k * s.val_size:(k + 1) * s.val_size], val, s.val_size)
    for k in range(k >> 1, 0, k >> 1):
        s.func(s.array[k * s.val_size:(k + 1) * s.val_size], s.array[2 * k * s.val_size:(2 * k + 1) * s.val_size], s.array[(2 * k + 1) * s.val_size:(2 * k + 2) * s.val_size])

def update_tmp(s, k, val):
    k += s.size
    segment_tree_memcpy(s.array[k * s.val_size:(k + 1) * s.val_size], val, s.val_size)

def update_all(s):
    for i in range(s.size - 1, 0, -1):
        s.func(s.array[i * s.val_size:(i + 1) * s.val_size], s.array[2 * i * s.val_size:(2 * i + 1) * s.val_size], s.array[(2 * i + 1) * s.val_size:(2 * i + 2) * s.val_size])

def find(s, l, r, res):
    lindex = []
    rindex = []
    llen = 0
    rlen = 0
    for l += s.size, r += s.size; l < r; l >>= 1, r >>= 1:
        if l & 1:
            lindex.append(l)
            l += 1
        if r & 1:
            r -= 1
            rindex.append(r)
    if llen == 0:
        lindex.append(rindex.pop())
    segment_tree_memcpy(res, s.array[lindex[0] * s.val_size:(lindex[0] + 1) * s.val_size], s.val_size)
    for i in range(1, llen):
        s.func(res, res, s.array[lindex[i] * s.val_size:(lindex[i] + 1) * s.val_size])
    for i in reversed(rindex):
        s.func(res, res, s.array[i * s.val_size:(i + 1) * s.val_size])

# Define types and comparison functions
class IndexVal(Structure):
    _fields_ = [("index", c_int32), ("val", c_int32)]

def cmp_index_val(a, b):
    d = a.val - b.val
    return 0 if d == 0 else (-1 if d > 0 else 1)

class SegmentNode(Structure):
    _fields_ = [("index", c_int32), ("val", c_int64)]

def func_segment_node(c, a, b):
    p = a.contents
    q = b.contents
    c.contents = p if p.val < q.val else q

class Edge(Structure):
    _fields_ = [("a", c_int32), ("b", c_int32), ("c", c_int64)]

def cmp_edge(a, b):
    d = a.c - b.c
    return 0 if d == 0 else (-1 if d < 0 else 1)

# Implementation of the main function
def run():
    n, d = map(int, input().split())
    a = (c_int32 * n)()
    p = (IndexVal * n)()
    for i in range(n):
        a[i] = int(input())
        p[i] = IndexVal(i, a[i])
    
    p = sorted(p, key=lambda x: x.val, reverse=True)
    ini = SegmentNode(n, (n + 2) * 1000000000 + 1)
    l = new_segment_tree(ini, n, ctypes.sizeof(SegmentNode), func_segment_node)
    r = new_segment_tree(ini, n, ctypes.sizeof(SegmentNode), func_segment_node)
    
    for i in range(n):
        update_tmp(l, i, SegmentNode(i, a[i] + (n - 1 - i) * d))
        update_tmp(r, i, SegmentNode(i, a[i] + i * d))
    
    update_all(l)
    update_all(r)
    h = new_binary_heap(ctypes.sizeof(Edge), cmp_edge)
    
    for i in range(n):
        v = p[i].index
        if v > 0:
            t = SegmentNode()
            find(l, 0, v, t)
            push(h, Edge(v, t.index, p[i].val + t.val))

# Call the run function
run()

# <END-OF-CODE>
