#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

type binaryHeap struct {
  array unsafe.Pointer
  heap_size int32
  max_size int32
  val_size int32
  cmp func(unsafe.Pointer, unsafe.Pointer) int32
}

func newBinaryHeap(val_size int32, cmp func(unsafe.Pointer, unsafe.Pointer) int32) *binaryHeap {
  h := &binaryHeap{
    array: unsafe.Pointer(C.malloc(C.size_t(val_size) * (1 + 1))),
    heap_size: 0,
    max_size: 1,
    val_size: val_size,
    cmp: cmp,
  }
  return h
}

func getHeapSize(h *binaryHeap) int32 {
  return h.heap_size
}

func isEmpty(h *binaryHeap) bool {
  return h.heap_size == 0
}

func freeHeap(h *binaryHeap) {
  C.free(h.array)
}

func initHeap(h *binaryHeap) {
  h.heap_size = 0
}

func heapFuncSwap(a unsafe.Pointer, b unsafe.Pointer, val_size int32) {
  if (val_size & 7) == 0 {
    p := (*[1 << 30]uint64)(a)
    q := (*[1 << 30]uint64)(b)
    val_size /= 8
    for val_size > 0 {
      tmp := p[0]
      p[0] = q[0]
      q[0] = tmp
      p = p[1:]
      q = q[1:]
      val_size--
    }
  } else {
    p := (*[1 << 30]uint8)(a)
    q := (*[1 << 30]uint8)(b)
    for val_size > 0 {
      tmp := p[0]
      p[0] = q[0]
      q[0] = tmp
      p = p[1:]
      q = q[1:]
      val_size--
    }
  }
}

func heapFuncCopy(dst unsafe.Pointer, src unsafe.Pointer, val_size int32) {
  if (val_size & 7) == 0 {
    p := (*[1 << 30]uint64)(src)
    q := (*[1 << 30]uint64)(dst)
    val_size /= 8
    for val_size > 0 {
      q[0] = p[0]
      p = p[1:]
      q = q[1:]
      val_size--
    }
  } else {
    p := (*[1 << 30]uint8)(src)
    q := (*[1 << 30]uint8)(dst)
    for val_size > 0 {
      q[0] = p[0]
      p = p[1:]
      q = q[1:]
      val_size--
    }
  }
}

func push(h *binaryHeap, val unsafe.Pointer) {
  if h.heap_size == h.max_size {
    h.max_size = 2 * h.max_size + 1
    h.array = unsafe.Pointer(C.realloc(h.array, C.size_t(h.val_size) * (C.size_t(h.max_size) + 1)))
  }
  h.heap_size++
  array := (*[1 << 30]uint8)(h.array)
  k := h.heap_size
  val_size := h.val_size
  cmp := h.cmp
  heapFuncCopy(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), val, val_size)
  for k > 1 {
    parent := k / 2
    if cmp(unsafe.Pointer(uintptr(array)+uintptr(parent)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size))) <= 0 {
      return
    }
    heapFuncSwap(unsafe.Pointer(uintptr(array)+uintptr(parent)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), val_size)
    k = parent
  }
}

func pop(h *binaryHeap, res unsafe.Pointer) {
  array := (*[1 << 30]uint8)(h.array)
  val_size := h.val_size
  if res != nil {
    heapFuncCopy(res, unsafe.Pointer(uintptr(array)+uintptr(val_size)), val_size)
  }
  heapFuncCopy(unsafe.Pointer(uintptr(array)+uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(val_size)*uintptr(h.heap_size)), val_size)
  h.heap_size--
  cmp := h.cmp
  n := h.heap_size
  k := 1
  for 2 * k + 1 <= n {
    next := 2 * k + (cmp(unsafe.Pointer(uintptr(array)+uintptr(2*k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*k+1)*uintptr(val_size))) <= 0)
    if cmp(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(next)*uintptr(val_size))) <= 0 {
      return
    }
    heapFuncSwap(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(next)*uintptr(val_size)), val_size)
    k = next
  }
  if 2 * k <= n && cmp(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*k)*uintptr(val_size))) > 0 {
    heapFuncSwap(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*k)*uintptr(val_size)), val_size)
  }
}

func top(h *binaryHeap, res unsafe.Pointer) {
  array := (*[1 << 30]uint8)(h.array)
  val_size := h.val_size
  if res != nil {
    heapFuncCopy(res, unsafe.Pointer(uintptr(array)+uintptr(val_size)), val_size)
  }
}

type UnionFind struct {
  parent *int32
  size int32
}

func initUnionFind(u *UnionFind) {
  for i := int32(0); i < u.size; i++ {
    u.parent[i] = -1
  }
}

func newUnionFind(size int32) *UnionFind {
  u := &UnionFind{
    parent: (*int32)(C.malloc(C.size_t(size) * (1 + 1))),
    size: size,
  }
  initUnionFind(u)
  return u
}

func freeUnionFind(u *UnionFind) {
  C.free(unsafe.Pointer(u.parent))
}

func root(u *UnionFind, x int32) int32 {
  index := make([]int32, 32)
  len := int32(0)
  for u.parent[x] >= 0 {
    index[len] = x
    x = u.parent[x]
    len++
  }
  for len > 0 {
    u.parent[index[len-1]] = x
    len--
  }
  return x
}

func same(u *UnionFind, x int32, y int32) bool {
  return root(u, x) == root(u, y)
}

func getSize(u *UnionFind, x int32) int32 {
  return - (u.parent[root(u, x)])
}

func unite(u *UnionFind, x int32, y int32) {
  x = root(u, x)
  y = root(u, y)
  if x == y {
    return
  }
  if u.parent[x] > u.parent[y] {
    swap := x
    x = y
    y = swap
  }
  u.parent[x] += u.parent[y]
  u.parent[y] = x
}

type segmentTree struct {
  array unsafe.Pointer
  size int32
  val_size int32
  func func(unsafe.Pointer, unsafe.Pointer, unsafe.Pointer)
}

func segmentTreeMemcpy(dst unsafe.Pointer, src unsafe.Pointer, size int32) {
  p := (*[1 << 30]uint8)(src)
  q := (*[1 << 30]uint8)(dst)
  for size > 0 {
    q[0] = p[0]
    p = p[1:]
    q = q[1:]
    size--
  }
}

func newSegmentTree(ini unsafe.Pointer, n int32, val_size int32, func func(unsafe.Pointer, unsafe.Pointer, unsafe.Pointer)) *segmentTree {
  k := int32(1)
  for k < n {
    k *= 2
  }
  s := &segmentTree{
    array: unsafe.Pointer(C.malloc(C.size_t(val_size) * (1 + 1))),
    size: k,
    val_size: val_size,
    func: func,
  }
  for i := k; i < 2 * k; i++ {
    segmentTreeMemcpy(unsafe.Pointer(uintptr(s.array)+uintptr(i)*uintptr(val_size)), ini, val_size)
  }
  array := (*[1 << 30]uint8)(s.array)
  for i := k - 1; i > 0; i-- {
    func(unsafe.Pointer(uintptr(array)+uintptr(i)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*i)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*i+1)*uintptr(val_size)))
  }
  return s
}

func update(s *segmentTree, k int32, val unsafe.Pointer) {
  k += s.size
  array := (*[1 << 30]uint8)(s.array)
  val_size := s.val_size
  segmentTreeMemcpy(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), val, val_size)
  for k >>= 1; k > 0; k >>= 1 {
    s.func(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*k)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*k+1)*uintptr(val_size)))
  }
}

func updateTmp(s *segmentTree, k int32, val unsafe.Pointer) {
  k += s.size
  array := (*[1 << 30]uint8)(s.array)
  val_size := s.val_size
  segmentTreeMemcpy(unsafe.Pointer(uintptr(array)+uintptr(k)*uintptr(val_size)), val, val_size)
}

func updateAll(s *segmentTree) {
  array := (*[1 << 30]uint8)(s.array)
  val_size := s.val_size
  for i := s.size - 1; i > 0; i-- {
    s.func(unsafe.Pointer(uintptr(array)+uintptr(i)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*i)*uintptr(val_size)), unsafe.Pointer(uintptr(array)+uintptr(2*i+1)*uintptr(val_size)))
  }
}

func find(s *segmentTree, l int32, r int32, res unsafe.Pointer) {
  lindex := make([]int32, 32)
  rindex := make([]int32, 32)
  llen := int32(0)
  rlen := int32(0)
  for l < r {
    if l & 1 == 1 {
      lindex[llen] = l
      l++
      llen++
    }
    if r & 1 == 1 {
      rindex[rlen] = r - 1
      r--
      rlen++
    }
    l >>= 1
    r >>= 1
  }
  if llen == 0 {
    lindex[llen] = rindex[rlen-1]
    rlen--
  }
  array := (*[1 << 30]uint8)(s.array)
  segmentTreeMemcpy(res, unsafe.Pointer(uintptr(array)+uintptr(lindex[0])*uintptr(s.val_size)), s.val_size)
  for i := int32(1); i < llen; i++ {
    s.func(res, res, unsafe.Pointer(uintptr(array)+uintptr(lindex[i])*uintptr(s.val_size)))
  }
  for i := rlen - 1; i >= 0; i-- {
    s.func(res, res, unsafe.Pointer(uintptr(array)+uintptr(rindex[i])*uintptr(s.val_size)))
  }
}

type i32 int32
type i64 int64

type indexVal struct {
  index int32
  val int32
}

func cmpIndexVal(a unsafe.Pointer, b unsafe.Pointer) int32 {
  d := (*indexVal)(a).val - (*indexVal)(b).val
  if d == 0 {
    return 0
  }
  if d > 0 {
    return -1
  }
  return 1
}

type segmentNode struct {
  index int32
  val i64
}

func funcSegmentNode(c unsafe.Pointer, a unsafe.Pointer, b unsafe.Pointer) {
  p := (*segmentNode)(a)
  q := (*segmentNode)(b)
  *(*segmentNode)(c) = *p
  if p.val < q.val {
    *(*segmentNode)(c) = *p
  } else {
    *(*segmentNode)(c) = *q
  }
}

type edge struct {
  a int32
  b int32
  c i64
}

func cmpEdge(a unsafe.Pointer, b unsafe.Pointer) int32 {
  d := (*edge)(a).