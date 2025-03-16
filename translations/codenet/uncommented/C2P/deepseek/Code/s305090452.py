import sys
import struct

class BinaryHeap:
    def __init__(self, val_size, cmpF):
        self.array = bytearray(val_size * (1 + 1))
        self.heap_size = 0
        self.max_size = 1
        self.val_size = val_size
        self.cmp = cmpF

    def new_binary_heap(val_size, cmpF):
        return BinaryHeap(val_size, cmpF)

    def get_heap_size(self):
        return self.heap_size

    def is_empty(self):
        return self.heap_size == 0

    def free_heap(self):
        del self.array
        del self

    def init_heap(self):
        self.heap_size = 0

    @staticmethod
    def heap_func_swap(a, b, val_size):
        if (val_size & 7) == 0:
            p = memoryview(a).cast('L')
            q = memoryview(b).cast('L')
            val_size //= 4
            while val_size:
                tmp = p[0]
                p[0] = q[0]
                q[0] = tmp
                val_size -= 1
        else:
            p = memoryview(a).cast('B')
            q = memoryview(b).cast('B')
            while val_size:
                tmp = p[0]
                p[0] = q[0]
                q[0] = tmp
                val_size -= 1

    @staticmethod
    def heap_func_copy(dst, src, val_size):
        if (val_size & 7) == 0:
            p = memoryview(src).cast('L')
            q = memoryview(dst).cast('L')
            val_size //= 4
            while val_size:
                q[0] = p[0]
                p += 1
                q += 1
                val_size -= 1
        else:
            p = memoryview(src).cast('B')
            q = memoryview(dst).cast('B')
            while val_size:
                q[0] = p[0]
                p += 1
                q += 1
                val_size -= 1

    def push(self, val):
        if self.heap_size == self.max_size:
            self.max_size = 2 * self.max_size + 1
            self.array = bytearray(self.val_size * (self.max_size + 1))
        self.heap_size += 1
        array = self.array
        k = self.heap_size
        val_size = self.val_size
        cmp = self.cmp
        self.heap_func_copy(array[k * val_size:], val, val_size)
        while k > 1:
            parent = k // 2
            if cmp(array[parent * val_size:], array[k * val_size:]) <= 0:
                return
            self.heap_func_swap(array[parent * val_size:], array[k * val_size:], val_size)
            k = parent

    def pop(self, res=None):
        array = self.array
        val_size = self.val_size
        if res is not None:
            self.heap_func_copy(res, array[:val_size], val_size)
        self.heap_func_copy(array[:val_size], array[val_size * self.heap_size:], val_size)
        self.heap_size -= 1
        cmp = self.cmp
        n = self.heap_size
        k = 1
        while 2 * k + 1 <= n:
            c = cmp(array[val_size * 2 * k:], array[val_size * (2 * k + 1):])
            next = 2 * k + (0 if c <= 0 else 1)
            if cmp(array[val_size * k:], array[val_size * next:]) <= 0:
                return
            self.heap_func_swap(array[val_size * k:], array[val_size * next:], val_size)
            k = next
        if 2 * k <= n and cmp(array[val_size * k:], array[val_size * 2 * k:]) > 0:
            self.heap_func_swap(array[val_size * k:], array[val_size * 2 * k:], val_size)

    def top(self, res=None):
        array = self.array
        val_size = self.val_size
        if res is not None:
            self.heap_func_copy(res, array[:val_size], val_size)

class UnionFind:
    def __init__(self, size):
        self.parent = [-1] * size
        self.size = size

    def initUnionFind(self):
        for i in range(self.size):
            self.parent[i] = -1

    def newUnionFind(size):
        u = UnionFind(size)
        u.initUnionFind()
        return u

    def freeUnionFind(u):
        del u.parent
        del u

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

class SegmentTree:
    def __init__(self, ini, n, val_size, func):
        k = 1
        while k < n:
            k *= 2
        self.array = bytearray(2 * k * val_size)
        self.size = k
        self.val_size = val_size
        self.func = func
        for i in range(k, 2 * k):
            self.array[i * val_size:(i + 1) * val_size] = ini[i - k].to_bytes(val_size, 'little')
        for i in range(k - 1, 0, -1):
            self.func(self.array[i * val_size:(i + 1) * val_size], self.array[(2 * i) * val_size:(2 * i + 1) * val_size], self.array[(2 * i + 1) * val_size:(2 * i + 2) * val_size])

    def update(self, k, val):
        k += self.size
        p = self.array
        size = self.val_size
        for i in range(len(val)):
            p[k * size + i] = val[i]
        k >>= 1
        while k > 0:
            self.func(p[k * size:(k + 1) * size], p[(2 * k) * size:(2 * k + 1) * size], p[(2 * k + 1) * size:(2 * k + 2) * size])
            k >>= 1

    def update_tmp(self, k, val):
        k += self.size
        p = self.array
        size = self.val_size
        for i in range(len(val)):
            p[k * size + i] = val[i]

    def update_all(self):
        p = self.array
        size = self.val_size
        for i in range(self.size - 1, 0, -1):
            self.func(p[i * size:(i + 1) * size], p[(2 * i) * size:(2 * i + 1) * size], p[(2 * i + 1) * size:(2 * i + 2) * size])

    def find(self, l, r, res):
        lindex = []
        rindex = []
        llen = 0
        rlen = 0
        l += self.size
        r += self.size
        while l < r:
            if l & 1:
                lindex.append(l)
                l += 1
            if r & 1:
                rindex.append(r - 1)
                r -= 1
            l >>= 1
            r >>= 1
        if not lindex:
            lindex.append(rindex.pop())
        res_view = memoryview(res).cast('B')
        size = self.val_size
        for i in range(len(lindex)):
            res_view[:size] = self.array[lindex[i] * size:lindex[i] * size + size]
            res_view = memoryview(res).cast('B')
        for i in range(len(rindex) - 1, -1, -1):
            res_view[:size] = self.array[rindex[i] * size:rindex[i] * size + size]
            res_view = memoryview(res).cast('B')

def cmp_index_val(a, b):
    d = a['val'] - b['val']
    return 0 if d == 0 else -1 if d > 0 else 1

def func_segment_node(c, a, b):
    p = struct.unpack('ll', a)
    q = struct.unpack('ll', b)
    c = struct.pack('ll', p[0] if p[0] < q[0] else q[0])

def cmp_edge(a, b):
    d = a['c'] - b['c']
    return 0 if d == 0 else -1 if d < 0 else 1

def run():
    n, d = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    p = [{'index': i, 'val': a[i]} for i in range(n)]
    p.sort(key=lambda x: x['val'])
    ini = {'index': n, 'val': (n + 2) * 1000000000 + 1}
    l = SegmentTree(ini, n, 8, func_segment_node)
    r = SegmentTree(ini, n, 8, func_segment_node)
    for i in range(n):
        v = p[i]['index']
        t = struct.pack('ll', a[v] + (n - 1 - v) * d)
        l.update(v, t)
        t = struct.pack('ll', a[v] + v * d)
        r.update(v, t)
    h = BinaryHeap.new_binary_heap(12, cmp_edge)
    for i in range(n):
        v = p[i]['index']
        if v > 0:
            res = bytearray(8)
            l.find(0, v, res)
            t = struct.unpack('ll', res)
            push(h, {'a': v, 'b': t[0], 'c': p[i]['val'] + t[0] - (n - 1 - v) * d})
        if v + 1 < n:
            res = bytearray(8)
            r.find(v + 1, n, res)
            t = struct.unpack('ll', res)
            push(h, {'a': v, 'b': t[0], 'c': p[i]['val'] + t[0] - v * d})
        l.update(v, ini)
        r.update(v, ini)
    sum = 0
    u = UnionFind.newUnionFind(n)
    while u.getSize(0) < n:
        e = pop(h)
        if u.same(e['a'], e['b']):
            continue
        u.unite(e['a'], e['b'])
        sum += e['c']
    print(sum)

if __name__ == "__main__":
    run()
