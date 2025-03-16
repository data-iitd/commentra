import sys
import ctypes
from ctypes import c_int32, c_int64, POINTER, Structure, c_void_p, c_size_t

class BinaryHeap:
    def __init__(self, val_size, cmpF):
        self.array = (c_void_p * (1 + 1))()
        self.heap_size = 0
        self.max_size = 1
        self.val_size = val_size
        self.cmp = cmpF

    def push(self, val):
        if self.heap_size == self.max_size:
            self.max_size = 2 * self.max_size + 1
            self.array = (c_void_p * (self.max_size + 1))()
        self.heap_size += 1
        k = self.heap_size
        self.array[k] = val
        while k > 1:
            parent = k // 2
            if self.cmp(self.array[parent], self.array[k]) <= 0:
                return
            self.array[parent], self.array[k] = self.array[k], self.array[parent]
            k = parent

    def pop(self):
        if self.heap_size == 0:
            return None
        res = self.array[1]
        self.array[1] = self.array[self.heap_size]
        self.heap_size -= 1
        k = 1
        while 2 * k + 1 <= self.heap_size:
            next_k = 2 * k + (self.cmp(self.array[2 * k], self.array[2 * k + 1]) <= 0)
            if self.cmp(self.array[k], self.array[next_k]) <= 0:
                return res
            self.array[k], self.array[next_k] = self.array[next_k], self.array[k]
            k = next_k
        if 2 * k <= self.heap_size and self.cmp(self.array[k], self.array[2 * k]) > 0:
            self.array[k], self.array[2 * k] = self.array[2 * k], self.array[k]
        return res

    def top(self):
        return self.array[1] if self.heap_size > 0 else None

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

    def get_size(self, x):
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

class SegmentTree:
    def __init__(self, ini, n, val_size, func):
        k = 1
        while k < n:
            k *= 2
        self.array = (ctypes.c_void_p * (2 * k))()
        self.size = k
        self.val_size = val_size
        self.func = func
        for i in range(k, 2 * k):
            self.array[i] = ini
        for i in range(k - 1, 0, -1):
            self.func(self.array[i], self.array[2 * i], self.array[2 * i + 1])

    def update(self, k, val):
        k += self.size
        self.array[k] = val
        while k > 1:
            k //= 2
            self.func(self.array[k], self.array[2 * k], self.array[2 * k + 1])

    def find(self, l, r):
        l += self.size
        r += self.size
        res = self.array[l]
        while l < r:
            if l & 1:
                res = self.func(res, self.array[l])
                l += 1
            if r & 1:
                r -= 1
                res = self.func(res, self.array[r])
            l //= 2
            r //= 2
        return res

class IndexVal(Structure):
    _fields_ = [("index", c_int32), ("val", c_int32)]

class SegmentNode(Structure):
    _fields_ = [("index", c_int32), ("val", c_int64)]

class Edge(Structure):
    _fields_ = [("a", c_int32), ("b", c_int32), ("c", c_int64)]

def cmp_index_val(a, b):
    return (a.val > b.val) - (a.val < b.val)

def func_segment_node(c, a, b):
    p = ctypes.cast(a, POINTER(SegmentNode)).contents
    q = ctypes.cast(b, POINTER(SegmentNode)).contents
    ctypes.cast(c, POINTER(SegmentNode)).contents = p if p.val < q.val else q

def cmp_edge(a, b):
    return (a.c > b.c) - (a.c < b.c)

def run():
    n, d = map(int, sys.stdin.readline().split())
    a = (c_int32 * n)()
    p = (IndexVal * n)()
    for i in range(n):
        a[i] = int(sys.stdin.readline())
        p[i] = IndexVal(i, a[i])
    p[:] = sorted(p, key=lambda x: x.val)
    ini = SegmentNode(n, (n + 2) * 1000000000 + 1)
    l = SegmentTree(ini, n, ctypes.sizeof(SegmentNode), func_segment_node)
    r = SegmentTree(ini, n, ctypes.sizeof(SegmentNode), func_segment_node)
    for i in range(n):
        l.update(i, SegmentNode(i, a[i] + (n - 1 - i) * d))
        r.update(i, SegmentNode(i, a[i] + i * d))
    h = BinaryHeap(ctypes.sizeof(Edge), cmp_edge)
    for i in range(n):
        v = p[i].index
        if v > 0:
            t = l.find(0, v)
            h.push(Edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d))
        if v + 1 < n:
            t = r.find(v + 1, n)
            h.push(Edge(v, t.index, p[i].val + t.val - v * d))
        l.update(v, ini)
        r.update(v, ini)
    sum = 0
    u = UnionFind(n)
    while u.get_size(0) < n:
        e = h.pop()
        if u.same(e.a, e.b):
            continue
        u.unite(e.a, e.b)
        sum += e.c
    print(sum)

if __name__ == "__main__":
    run()

# <END-OF-CODE>
