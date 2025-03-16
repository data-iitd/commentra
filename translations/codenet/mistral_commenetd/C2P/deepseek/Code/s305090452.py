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

    def heap_func_swap(a, b, val_size):
        if (val_size & 7) == 0:
            p = memoryview(a).cast('L')
            q = memoryview(b).cast('L')
            val_size //= 8
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

    def heap_func_copy(dst, src, val_size):
        if (val_size & 7) == 0:
            p = memoryview(src).cast('L')
            q = memoryview(dst).cast('L')
            val_size //= 8
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

    def newUnionFind(size):
        return UnionFind(size)

    def initUnionFind(self):
        for i in range(self.size):
            self.parent[i] = -1

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
            self.array[i * val_size:(i + 1) * val_size] = ini[i - k]
        for i in range(k - 1, 0, -1):
            self.func(self.array[i * val_size:(i + 1) * val_size], self.array[(2 * i) * val_size:(2 * i + 1) * val_size], self.array[(2 * i + 1) * val_size:(2 * i + 2) * val_size])

    def new_segment_tree(ini, n, val_size, func):
        return SegmentTree(ini, n, val_size, func)

    def update(self, k, val):
        k += self.size
        self.array[k * self.val_size:(k + 1) * self.val_size] = val
        k >>= 1
        while k > 0:
            self.func(self.array[k * self.val_size:(k + 1) * self.val_size], self.array[(2 * k) * self.val_size:(2 * k + 1) * self.val_size], self.array[(2 * k + 1) * self.val_size:(2 * k + 2) * self.val_size])
            k >>= 1

    def update_tmp(self, k, val):
        k += self.size
        self.array[k * self.val_size:(k + 1) * self.val_size] = val

    def update_all(self):
        for i in range(self.size - 1, 0, -1):
            self.func(self.array[i * self.val_size:(i + 1) * self.val_size], self.array[(2 * i) * self.val_size:(2 * i + 1) * self.val_size], self.array[(2 * i + 1) * self.val_size:(2 * i + 2) * self.val_size])

    def find(self, l, r):
        lindex = []
        rindex = []
        llen = 0
        rlen = 0
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
        res = self.array[lindex[0] * self.val_size:(lindex[0] + 1) * self.val_size]
        for i in lindex[1:]:
            self.func(res, res, self.array[i * self.val_size:(i + 1) * self.val_size])
        for i in reversed(rindex):
            self.func(res, res, self.array[i * self.val_size:(i + 1) * self.val_size])
        return res

def cmp_index_val(a, b):
    d = a['val'] - b['val']
    return 0 if d == 0 else -1 if d > 0 else 1

def func_segment_node(c, a, b):
    p = a['val']
    q = b['val']
    c['val'] = p if p < q else q

def cmp_edge(a, b):
    d = a['c'] - b['c']
    return 0 if d == 0 else -1 if d < 0 else 1

def run():
    n, d = map(int, input().split())
    a = list(map(int, input().split()))
    p = [{'index': i, 'val': a[i]} for i in range(n)]
    p.sort(key=lambda x: x['val'])
    ini = {'index': n, 'val': (n + 2) * 1000000000 + 1}
    l = SegmentTree.new_segment_tree([ini] * n, n, 8, func_segment_node)
    r = SegmentTree.new_segment_tree([ini] * n, n, 8, func_segment_node)
    for i in range(n):
        l.update(i, {'index': i, 'val': a[i] + (n - 1 - i) * d})
        r.update(i, {'index': i, 'val': a[i] + i * d})
    h = BinaryHeap.new_binary_heap(8, cmp_edge)
    for i in range(n):
        v = p[i]['index']
        if v > 0:
            t = l.find(0, v)
            push(h, {'a': v, 'b': t['index'], 'c': p[i]['val'] + t['val']})
