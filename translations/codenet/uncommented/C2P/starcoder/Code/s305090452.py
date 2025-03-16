
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

class binaryHeap:
  def __init__(self, val_size, cmpF):
    self.array = [0] * (1 + 1)
    self.heap_size = 0
    self.max_size = 1
    self.val_size = val_size
    self.cmp = cmpF

  def get_heap_size(self):
    return self.heap_size

  def is_empty(self):
    return self.heap_size == 0

  def free_heap(self):
    del self.array

  def init_heap(self):
    self.heap_size = 0

  def heap_func_swap(self, a, b):
    if ((self.val_size & 7) == 0):
      p = (uint64_t *) a
      q = (uint64_t *) b
      self.val_size /= sizeof (uint64_t)
      while (self.val_size > 0):
        tmp = p[0]
        p[0] = q[0]
        q[0] = tmp
        p += 1
        q += 1
    else:
      p = (uint8_t *) a
      q = (uint8_t *) b
      while (self.val_size > 0):
        tmp = p[0]
        p[0] = q[0]
        q[0] = tmp
        p += 1
        q += 1

  def heap_func_copy(self, dst, src):
    if ((self.val_size & 7) == 0):
      p = (uint64_t *) src
      q = (uint64_t *) dst
      self.val_size /= sizeof (uint64_t)
      while (self.val_size > 0):
        q[0] = p[0]
        p += 1
        q += 1
    else:
      p = (uint8_t *) src
      q = (uint8_t *) dst
      while (self.val_size > 0):
        q[0] = p[0]
        p += 1
        q += 1

  def push(self, val):
    if (self.heap_size == self.max_size):
      self.max_size = 2 * self.max_size + 1
      self.array = self.array + [0] * (self.max_size + 1)
    self.heap_size += 1
    k = self.heap_size
    array = self.array
    val_size = self.val_size
    cmp = self.cmp
    self.heap_func_copy(array[k] + val_size, val)
    while(k>1):
      parent = k / 2
      if (cmp (array[parent] + val_size, array[k] + val_size) <= 0):
        return
      self.heap_func_swap (array[parent] + val_size, array[k] + val_size)
      k = parent

  def pop(self, res):
    array = self.array
    val_size = self.val_size
    if (res!= None):
      self.heap_func_copy (res, array[val_size] + val_size, val_size)
    self.heap_func_copy (array[val_size] + val_size, array[val_size] + val_size * self.heap_size, val_size)
    self.heap_size -= 1
    cmp = self.cmp
    n = self.heap_size
    k = 1
    while (2 * k  + 1 <= n):
      c = cmp (array[val_size * 2 * k] + val_size, array[val_size * (2 * k + 1)] + val_size)
      next = 2 * k + (c <= 0? 0 : 1)
      if (cmp (array[val_size * k] + val_size, array[val_size * next] + val_size) <= 0):
        return
      self.heap_func_swap (array[val_size * k] + val_size, array[val_size * next] + val_size)
      k = next
    if (2 * k <= n and cmp (array[val_size * k] + val_size, array[val_size * 2 * k] + val_size) > 0):
      self.heap_func_swap (array[val_size * k] + val_size, array[val_size * 2 * k] + val_size)

  def top(self, res):
    array = self.array
    val_size = self.val_size
    if (res!= None):
      self.heap_func_copy (res, array[val_size] + val_size, val_size)

class UnionFind:
  def __init__(self, size):
    self.parent = [0] * size
    self.size = size
    for i in range(size):
      self.parent[i] = -1

  def initUnionFind(self):
    for i in range(self.size):
      self.parent[i] = -1

  def newUnionFind(self, size):
    u = UnionFind(size)
    u.parent = [0] * size
    u.size = size
    u.initUnionFind()
    return u

  def freeUnionFind(self):
    del self.parent

  def root(self, x):
    index = [0] * 32
    len = 0
    while (self.parent[x] >= 0):
      index[len] = x
      x = self.parent[x]
    while (len > 0):
      self.parent[index[--len]] = x
    return x

  def same(self, x, y):
    return self.root(x) == self.root(y)

  def getSize(self, x):
    return - (self.parent[self.root(x)])

  def unite(self, x, y):
    x = self.root(x)
    y = self.root(y)
    if (x == y): return
    if (self.parent[x] > self.parent[y]):
      swap = x
      x = y
      y = swap
    self.parent[x] += self.parent[y]
    self.parent[y] = x

  def __init__(self, size):
    self.parent = [0] * size
    self.size = size
    for i in range(size):
      self.parent[i] = -1

  def initUnionFind(self):
    for i in range(self.size):
      self.parent[i] = -1

  def newUnionFind(self, size):
    u = UnionFind(size)
    u.parent = [0] * size
    u.size = size
    u.initUnionFind()
    return u

  def freeUnionFind(self):
    del self.parent

class segment_tree:
  def __init__(self, ini, n, val_size, func):
    k = 1
    while (k < n): k *= 2
    self.array = [0] * (2 * k)
    self.size = k
    self.val_size = val_size
    self.func = func
    for i in range(k, 2 * k):
      self.array[i] = ini
    a = self.array
    for i in range(k - 1, 0, -1):
      self.func (a[i] + i, a[2 * i] + 2 * i, a[2 * i + 1] + 2 * i + 1)

  def update(self, k, val):
    k += self.size
    p = self.array
    size = self.val_size
    self.heap_func_copy (p[k] + size, val, size)
    for k >>= 1; k > 0; k >>= 1:
      self.func (p[k] + k, p[2 * k] + 2 * k, p[2 * k + 1] + 2 * k + 1)

  def update_tmp(self, k, val):
    k += self.size
    p = self.array
    size = self.val_size
    self.heap_func_copy (p[k] + size, val, size)

  def update_all(self):
    a = self.array
    size = self.val_size
    for i in range(self.size - 1, 0, -1):
      self.func (a[i] + i, a[2 * i] + 2 * i, a[2 * i + 1] + 2 * i + 1)

  def find(self, l, r, res):
    lindex = [0] * 32
    rindex = [0] * 32
    llen = 0
    rlen = 0
    for l += self.size, r += self.size; l < r; l >>= 1, r >>= 1:
      if (l & 1): lindex[llen++] = l++;
      if (r & 1): rindex[rlen++] = --r;
    p = self.array
    if (llen == 0):
      lindex[llen++] = rindex[--rlen];
    self.heap_func_copy (res, p[lindex[0]] + size, size)
    for i in range(1, llen):
      self.func (res, res, p[lindex[i]] + size)
    for i in range(rlen - 1, -1, -1):
      self.func (res, res, p[rindex[i]] + size)

class index_val:
  def __init__(self, index, val):
    self.index = index
    self.val = val

def cmp_index_val (a, b):
  d = a.val - b.val
  return d == 0? 0 : d > 0? -1 : 1

class segment_node:
  def __init__(self, index, val):
    self.index = index
    self.val = val

def func_segment_node (c, a, b):
  p = (segment_node *)a
  q = (segment_node *)b
  *(segment_node *)c = p->val < q->val? *p : *q

class edge:
  def __init__(self, a, b, c):
    self.a = a
    self.b = b
    self.c = c

def cmp_edge (a, b):
  d = a.c - b.c
  return d == 0? 0 : d < 0? -1 : 1

def run():
  n, d = map(int, input().split())
  a = [0] * n
  p = [0] * n
  for i in range(n):
    a[i] = int(input())
    p[i] = index_val(i, a[i])
  qsort(p, n, sizeof(index_val), cmp_index_val)
  ini = segment_node(n, (n + 2) * 1000000000 + 1)
  l = new_segment_tree(ini, n, sizeof(segment_node), func_segment_node)
  r = new_segment_tree(ini, n, sizeof(segment_node), func_segment_node)
  for i in range(n):
    update_tmp(l, i, segment_node(i, a[i] + (n - 1 - i) * d))
    update_tmp(r, i, segment_node(i, a[i] + i * d))
  update_all(l)
  update_all(r)
  h = new_binary_heap(sizeof(edge), cmp_edge)
  for i in range(n):
    v = p[i].index
    if (v > 0):
      t = segment_node()
      find(l, 0, v, t)
      push(h, edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d))
    if (v + 1 < n):
      t = segment_node()
      find(r, v + 1, n, t)
      push(h, edge(v, t.index, p[i].val + t.val - v * d))
    update(l, v, ini)
    update(r, v, ini)
  sum = 0
  u = newUnionFind(n)
  while (getSize(u, 0) < n):
    e = edge()
    pop(h, e)
    if (same(u, e.a, e.b)): continue
    unite(u, e.a, e.b)
    sum += e.c
  print(sum)

run()

