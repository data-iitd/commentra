#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// Include necessary header files

type binaryHeap struct {
  array unsafe.Pointer
  heap_size int
  max_size int
  val_size int
  cmp func(unsafe.Pointer, unsafe.Pointer) int
}

// Define a structure for binary heap

func newBinaryHeap(val_size int, cmp func(unsafe.Pointer, unsafe.Pointer) int) *binaryHeap {
  h := &binaryHeap{
    array: unsafe.Pointer(C.malloc(C.size_t(val_size) * (1 + 1))),
    heap_size: 0,
    max_size: 1,
    val_size: val_size,
    cmp: cmp,
  }
  // Allocate memory for heap structure

  return h
}

// Function to create a new binary heap

func getHeapSize(h *binaryHeap) int {
  // Function to get the current size of the heap

  return h.heap_size
}

func isEmpty(h *binaryHeap) bool {
  // Function to check if the heap is empty

  return h.heap_size == 0
}

func freeHeap(h *binaryHeap) {
  C.free(h.array)
  C.free(unsafe.Pointer(h))
  // Function to free the memory allocated for the heap
}

func initHeap(h *binaryHeap) {
  h.heap_size = 0
  // Function to initialize an empty heap
}

// Implementation of various heap functions

func heapFuncSwap(a, b unsafe.Pointer, val_size int) {
  // Helper function to swap two elements in the heap

  if (val_size & 7) == 0 {
    p := (*uint64)(a)
    q := (*uint64)(b)
    val_size /= 8
    for val_size > 0 {
      tmp := *p
      *p++ = *q
      *q++ = tmp
      val_size--
    }
  } else {
    p := (*uint8)(a)
    q := (*uint8)(b)
    for val_size > 0 {
      tmp := *p
      *p++ = *q
      *q++ = tmp
      val_size--
    }
  }
}

func heapFuncCopy(dst, src unsafe.Pointer, val_size int) {
  // Helper function to copy elements from one location to another

  if (val_size & 7) == 0 {
    p := (*uint64)(src)
    q := (*uint64)(dst)
    val_size /= 8
    for val_size > 0 {
      *q++ = *p++
      val_size--
    }
  } else {
    p := (*uint8)(src)
    q := (*uint8)(dst)
    for val_size > 0 {
      *q++ = *p++
      val_size--
    }
  }
}

// Helper functions for heap manipulation

func push(h *binaryHeap, val unsafe.Pointer) {
  // Function to add a new element to the heap

  if h.heap_size == h.max_size {
    h.max_size = 2 * h.max_size + 1
    h.array = unsafe.Pointer(C.realloc(h.array, C.size_t(h.val_size) * (C.size_t(h.max_size) + 1)))
  }
  h.heap_size++
  array := (*uint8)(h.array)
  k := h.heap_size
  val_size := h.val_size
  cmp := h.cmp
  heapFuncCopy(array + k * val_size, val, val_size)
  for k > 1 {
    parent := k / 2
    if cmp(array + parent * val_size, array + k * val_size) <= 0 {
      return
    }
    heapFuncSwap(array + parent * val_size, array + k * val_size, val_size)
    k = parent
  }
}

func pop(h *binaryHeap, res unsafe.Pointer) {
  // Function to remove and return the root element from the heap

  array := (*uint8)(h.array)
  val_size := h.val_size
  if res != nil {
    heapFuncCopy(res, array + val_size, val_size)
  }
  heapFuncCopy(array + val_size, array + val_size * h.heap_size, val_size)
  h.heap_size--
  cmp := h.cmp
  n := h.heap_size
  k := 1
  for 2 * k + 1 <= n {
    next := 2 * k + (cmp(array + val_size * 2 * k, array + val_size * (2 * k + 1)) <= 0)
    if cmp(array + val_size * k, array + val_size * next) <= 0 {
      return
    }
    heapFuncSwap(array + val_size * k, array + val_size * next, val_size)
    k = next
  }
  if 2 * k <= n && cmp(array + val_size * k, array + val_size * 2 * k) > 0 {
    heapFuncSwap(array + val_size * k, array + val_size * 2 * k, val_size)
  }
}

func top(h *binaryHeap, res unsafe.Pointer) {
  // Function to get the root element of the heap without removing it

  array := (*uint8)(h.array)
  val_size := h.val_size
  if res != nil {
    heapFuncCopy(res, array + val_size, val_size)
  }
}

// Implementation of various heap functions

type UnionFind struct {
  parent *int32
  size int32
}

// Define a structure for Union-Find data structure

func initUnionFind(u *UnionFind) {
  for i := int32(0); i < u.size; i++ {
    u.parent[i] = -1
  }
  // Initialize the parent array with -1 for all elements
}

func newUnionFind(size int32) *UnionFind {
  u := &UnionFind{
    parent: (*int32)(C.malloc(C.size_t(size) * 4)),
    size: size,
  }
  initUnionFind(u)
  return u
}

func freeUnionFind(u *UnionFind) {
  C.free(unsafe.Pointer(u.parent))
  C.free(unsafe.Pointer(u))
  // Free the memory allocated for the Union-Find data structure
}

func root(u *UnionFind, x int32) int32 {
  index := make([]int32, 32)
  len := 0
  for u.parent[x] >= 0 {
    index[len] = x
    x = u.parent[x]
    len++
  }
  for len > 0 {
    u.parent[index[len - 1]] = x
    len--
  }
  return x
}

func same(u *UnionFind, x, y int32) bool {
  return root(u, x) == root(u, y)
}

func getSize(u *UnionFind, x int32) int32 {
  return - (u.parent[root(u, x)])
}

func unite(u *UnionFind, x, y int32) {
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

// Implementation of various Union-Find functions

type segmentTree struct {
  array unsafe.Pointer
  size int32
  val_size int
  func func(unsafe.Pointer, unsafe.Pointer, unsafe.Pointer)
}

// Define a structure for segment tree

func segmentTreeMemcpy(dst, src unsafe.Pointer, size int) {
  // Helper function to copy a block of memory

  p := (*uint8)(dst)
  q := (*uint8)(src)
  for size > 0 {
    *p++ = *q++
    size--
  }
}

func newSegmentTree(ini unsafe.Pointer, n int32, val_size int, func func(unsafe.Pointer, unsafe.Pointer, unsafe.Pointer)) *segmentTree {
  k := 1
  for k < n {
    k *= 2
  }
  s := &segmentTree{
    array: unsafe.Pointer(C.malloc(C.size_t(val_size) * (2 * k + 1))),
    size: k,
    val_size: val_size,
    func: func,
  }
  for i := int32(k); i < 2 * k; i++ {
    segmentTreeMemcpy(s.array + i * val_size, ini, val_size)
  }
  a := (*uint8)(s.array)
  for i := k - 1; i > 0; i-- {
    func(a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size)
  }
  return s
}

// Function to create a new segment tree

func update(s *segmentTree, k int32, val unsafe.Pointer) {
  k += s.size
  p := (*uint8)(s.array)
  size := s.val_size
  segmentTreeMemcpy(p + k * size, val, size)
  for k >>= 1; k > 0; k >>= 1 {
    s.func(p + k * size, p + 2 * k * size, p + (2 * k + 1) * size)
  }
}

func updateTmp(s *segmentTree, k int32, val unsafe.Pointer) {
  k += s.size
  p := (*uint8)(s.array)
  size := s.val_size
  segmentTreeMemcpy(p + k * size, val, size)
}

func updateAll(s *segmentTree) {
  a := (*uint8)(s.array)
  size := s.val_size
  for i := s.size - 1; i > 0; i-- {
    s.func(a + i * size, a + (2 * i) * size, a + (2 * i + 1) * size)
  }
}

// Implementation of various segment tree functions

func find(s *segmentTree, l, r int32, res unsafe.Pointer) {
  lindex := make([]int32, 32)
  rindex := make([]int32, 32)
  llen := 0
  rlen := 0
  for l += s.size; l < r; l >>= 1, r >>= 1 {
    if l & 1 != 0 {
      lindex[llen] = l
      llen++
      l++
    }
    if r & 1 != 0 {
      rindex[rlen] = r - 1
      rlen++
      r--
    }
  }
  if llen == 0 {
    lindex[llen] = rindex[rlen - 1]
    rlen--
  }
  p := (*uint8)(s.array)
  segmentTreeMemcpy(res, p + lindex[0] * s.val_size, s.val_size)
  for i := 1; i < llen; i++ {
    s.func(res, res, p + lindex[i] * s.val_size)
  }
  for i := rlen - 1; i >= 0; i-- {
    s.func(res, res, p + rindex[i] * s.val_size)
  }
}

type i32 int32
type i64 int64

type indexVal struct {
  index int32
  val int32
}

func cmpIndexVal(a, b unsafe.Pointer) int {
  d := (*indexVal)(a).val - (*indexVal)(b).val
  if d == 0 {
    return 0
  }
  if d < 0 {
    return -1
  }
  return 1
}

type segmentNode struct {
  index int32
  val i64
}

func funcSegmentNode(c, a, b unsafe.Pointer) {
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

func cmpEdge(a, b unsafe.Pointer) int {
  d := (*edge)(a).c - (*edge)(b).c
  if d == 0 {
    return 0
  }
  if d < 0 {
    return -1
  }
  return 1
}

// Implementation of various helper functions

func run() {
  var n, d int32
  fmt.Scan(&n, &d)
  a := (*int32)(C.malloc(C.size_t(n) * 4))
  p := (*indexVal)(C.malloc(C.size_t(n) * 8))
  for i := int32(0); i < n; i++ {
    fmt.Scan(&(*a)[i])
    (*p)[i] = indexVal{i, (*a)[i]}
  }
  qsort(unsafe.Pointer(p), n, 8, cmpIndexVal)
  ini := segmentNode{n, (i64)(n + 2) * 1000000000 + 1}
  l := newSegmentTree(unsafe.Pointer(&ini), n, 16, funcSegmentNode)
  r := newSegmentTree(unsafe.Pointer(&ini), n, 16, funcSegmentNode)
  for i := int32(0); i < n; i++ {
    v := (*p)[i].index
    if v > 0 {
      t := segmentNode{}
      find(l, 0, v, unsafe.Pointer(&t))
      updateTmp(l, i, unsafe.Pointer(&segmentNode{i, (*a)[i] + (i64)(n - 1 - i) * d}))
      updateTmp(