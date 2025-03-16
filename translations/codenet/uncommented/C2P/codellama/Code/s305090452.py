#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

class binaryHeap:
  def __init__(self, val_size, cmpF):
    self.array = bytearray(val_size * (1 + 1))
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
    del self.cmp

  def init_heap(self):
    self.heap_size = 0

  def heap_func_swap(self, a, b, val_size):
    if (val_size & 7) == 0:
      p = a
      q = b
      val_size //= 8
      while val_size > 0:
        tmp = p[0]
        p[0] = q[0]
        q[0] = tmp
        p += 1
        q += 1
        val_size -= 1
    else:
      p = a
      q = b
      while val_size > 0:
        tmp = p[0]
        p[0] = q[0]
        q[0] = tmp
        p += 1
        q += 1
        val_size -= 1

  def heap_func_copy(self, dst, src, val_size):
    if (val_size & 7) == 0:
      p = src
      q = dst
      val_size //= 8
      while val_size > 0:
        q[0] = p[0]
        p += 1
        q += 1
        val_size -= 1
    else:
      p = src
      q = dst
      while val_size > 0:
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
    self.heap_func_copy(array + k * val_size, val, val_size)
    while k > 1:
      parent = k // 2
      if cmp(array + parent * val_size, array + k * val_size) <= 0:
        return
      self.heap_func_swap(array + parent * val_size, array + k * val_size, val_size)
      k = parent

  def pop(self, res):
    array = self.array
    val_size = self.val_size
    if res is not None:
      self.heap_func_copy(res, array + val_size, val_size)
    self.heap_func_copy(array + val_size, array + val_size * self.heap_size, val_size)
    self.heap_size -= 1
    cmp = self.cmp
    n = self.heap_size
    k = 1
    while 2 * k + 1 <= n:
      next = 2 * k + (cmp(array + val_size * 2 * k, array + val_size * (2 * k + 1)) <= 0)
      if cmp(array + val_size * k, array + val_size * next) <= 0:
        return
      self.heap_func_swap(array + val_size * k, array + val_size * next, val_size)
      k = next
    if 2 * k <= n and cmp(array + val_size * k, array + val_size * 2 * k) > 0:
      self.heap_func_swap(array + val_size * k, array + val_size * 2 * k, val_size)

  def top(self, res):
    array = self.array
    val_size = self.val_size
    if res is not None:
      self.heap_func_copy(res, array + val_size, val_size)

class UnionFind:
  def __init__(self, size):
    self.parent = bytearray(size)
    self.size = size

  def initUnionFind(self):
    for i in range(self.size):
      self.parent[i] = -1

  def root(self, x):
    index = bytearray(32)
    len = 0
    while self.parent[x] >= 0:
      index[len] = x
      x = self.parent[x]
      len += 1
    while len > 0:
      self.parent[index[len - 1]] = x
      len -= 1
    return x

  def same(self, x, y):
    return self.root(x) == self.root(y)

  def getSize(self, x):
    return - (self.parent[self.root(x)])

  def unite(self, x, y):
    x = self.root(x)
    y = self.root(y)
    if x == y:
      return
    if self.parent[x] > self.parent[y]:
      swap = x
      x = y
      y = swap
    self.parent[x] += self.parent[y]
    self.parent[y] = x

class segment_tree:
  def __init__(self, ini, n, val_size, func):
    self.array = bytearray(2 * n)
    self.size = n
    self.val_size = val_size
    self.func = func
    for i in range(n, 2 * n):
      self.array[i] = ini
    self.array[n - 1] = ini
    for i in range(n - 1, 0, -1):
      self.func(self.array + i * val_size, self.array + (2 * i) * val_size, self.array + (2 * i + 1) * val_size)

  def update(self, k, val):
    k += self.size
    p = self.array
    val_size = self.val_size
    self.heap_func_copy(p + k * val_size, val, val_size)
    for k in range(k // 2, 0, -1):
      self.func(p + k * val_size, p + 2 * k * val_size, p + (2 * k + 1) * val_size)

  def update_tmp(self, k, val):
    k += self.size
    p = self.array
    val_size = self.val_size
    self.heap_func_copy(p + k * val_size, val, val_size)

  def update_all(self):
    p = self.array
    val_size = self.val_size
    for i in range(self.size - 1, 0, -1):
      self.func(p + i * val_size, p + (2 * i) * val_size, p + (2 * i + 1) * val_size)

  def find(self, l, r, res):
    lindex = bytearray(32)
    rindex = bytearray(32)
    llen = 0
    rlen = 0
    for l in range(l + self.size, r + self.size):
      if l & 1:
        lindex[llen] = l
        llen += 1
      if r & 1:
        rindex[rlen] = r - 1
        rlen += 1
    p = self.array
    if llen == 0:
      lindex[llen] = rindex[rlen - 1]
    self.heap_func_copy(res, p + lindex[0] * self.val_size, self.val_size)
    for i in range(1, llen):
      self.func(res, res, p + lindex[i] * self.val_size)
    for i in range(rlen - 1, -1, -1):
      self.func(res, res, p + rindex[i] * self.val_size)

def cmp_index_val(a, b):
  d = a.val - b.val
  return d == 0 and 0 or d > 0 and -1 or 1

class segment_node:
  def __init__(self, index, val):
    self.index = index
    self.val = val

def func_segment_node(c, a, b):
  c.val = a.val if a.val < b.val else b.val

def cmp_edge(a, b):
  d = a.c - b.c
  return d == 0 and 0 or d < 0 and -1 or 1

def run():
  n, d = map(int, input().split())
  a = bytearray(n)
  p = [segment_node(i, a[i]) for i in range(n)]
  p.sort(key=cmp_to_key(cmp_index_val))
  ini = segment_node(n, n + 2) * 1000000000 + 1
  l = segment_tree(ini, n, sizeof(segment_node), func_segment_node)
  r = segment_tree(ini, n, sizeof(segment_node), func_segment_node)
  for i in range(n):
    l.update_tmp(i, segment_node(i, p[i].val + (n - 1 - i) * d))
    r.update_tmp(i, segment_node(i, p[i].val + i * d))
  l.update_all()
  r.update_all()
  h = binaryHeap(sizeof(edge), cmp_edge)
  for i in range(n):
    v = p[i].index
    if v > 0:
      t = l.find(0, v, segment_node)
      h.push(edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d))
    if v + 1 < n:
      t = r.find(v + 1, n, segment_node)
      h.push(edge(v, t.index, p[i].val + t.val - v * d))
    l.update(v, ini)
    r.update(v, ini)
  sum = 0
  u = UnionFind(n)
  while u.getSize(0) < n:
    e = h.pop(edge)
    if u.same(e.a, e.b):
      continue
    u.unite(e.a, e.b)
    sum += e.c
  print(sum)

run()
#