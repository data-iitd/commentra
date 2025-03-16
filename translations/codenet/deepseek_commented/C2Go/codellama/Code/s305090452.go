#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// Define the structure of a binary heap and its operations.
type heap struct {
  array unsafe.Pointer
  heap_size int32
  max_size int32
  val_size int32
  cmp func(unsafe.Pointer, unsafe.Pointer) int32
}

// Initialize a new binary heap with a given value size and comparison function.
func new_binary_heap(val_size int32, cmpF func(unsafe.Pointer, unsafe.Pointer) int32) *heap {
  h := &heap{}
  h.array = unsafe.Pointer(malloc(val_size * (1 + 1)))
  h.heap_size = 0
  h.max_size = 1
  h.val_size = val_size
  h.cmp = cmpF
  return h
}

// Return the current size of the heap.
func get_heap_size(h *heap) int32 {
  return h.heap_size
}

// Check if the heap is empty.
func is_empty(h *heap) bool {
  return h.heap_size == 0
}

// Free the memory allocated for the heap.
func free_heap(h *heap) {
  free(h.array)
  free(h)
}

// Initialize the heap size to zero.
func init_heap(h *heap) {
  h.heap_size = 0
}

// Swap two elements of the heap.
func heap_func_swap(a unsafe.Pointer, b unsafe.Pointer, val_size int32) {
  if (val_size & 7) == 0 {
    p := (*uint64)(a)
    q := (*uint64)(b)
    val_size /= unsafe.Sizeof(uint64(0))
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

// Copy one element to another.
func heap_func_copy(dst unsafe.Pointer, src unsafe.Pointer, val_size int32) {
  if (val_size & 7) == 0 {
    p := (*uint64)(src)
    q := (*uint64)(dst)
    val_size /= unsafe.Sizeof(uint64(0))
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

// Add a new element to the heap.
func push(h *heap, val unsafe.Pointer) {
  if h.heap_size == h.max_size {
    h.max_size = 2 * h.max_size + 1
    h.array = unsafe.Pointer(realloc(h.array, h.val_size * (h.max_size + 1)))
  }
  h.heap_size++
  array := (*uint8)(h.array)
  k := h.heap_size
  val_size := h.val_size
  cmp := h.cmp
  heap_func_copy(array + k * val_size, val, val_size)
  for k > 1 {
    parent := k / 2
    if cmp(array + parent * val_size, array + k * val_size) <= 0 {
      return
    }
    heap_func_swap(array + parent * val_size, array + k * val_size, val_size)
    k = parent
  }
}

// Remove the top element from the heap.
func pop(h *heap, res unsafe.Pointer) {
  array := (*uint8)(h.array)
  val_size := h.val_size
  if res != nil {
    heap_func_copy(res, array + val_size, val_size)
  }
  heap_func_copy(array + val_size, array + val_size * h.heap_size, val_size)
  h.heap_size--
  cmp := h.cmp
  n := h.heap_size
  k := 1
  for 2 * k + 1 <= n {
    next := 2 * k + (cmp(array + val_size * 2 * k, array + val_size * (2 * k + 1)) <= 0)
    if cmp(array + val_size * k, array + val_size * next) <= 0 {
      return
    }
    heap_func_swap(array + val_size * k, array + val_size * next, val_size)
    k = next
  }
  if 2 * k <= n && cmp(array + val_size * k, array + val_size * 2 * k) > 0 {
    heap_func_swap(array + val_size * k, array + val_size * 2 * k, val_size)
  }
}

// Return the top element of the heap without removing it.
func top(h *heap, res unsafe.Pointer) {
  array := (*uint8)(h.array)
  val_size := h.val_size
  if res != nil {
    heap_func_copy(res, array + val_size, val_size)
  }
}

// Define the structure of Union-Find and its operations.
type UnionFind struct {
  parent *int32
  size int32
}

// Initialize the parent array to -1.
func initUnionFind(u *UnionFind) {
  for i := int32(0); i < u.size; i++ {
    u.parent[i] = -1
  }
}

// Initialize a new Union-Find structure with a given size.
func newUnionFind(size int32) *UnionFind {
  u := &UnionFind{}
  u.parent = (*int32)(malloc(size * unsafe.Sizeof(int32(0))))
  u.size = size
  initUnionFind(u)
  return u
}

// Free the memory allocated for the Union-Find structure.
func freeUnionFind(u *UnionFind) {
  free(u.parent)
  free(u)
}

// Find the root of a given element.
func root(u *UnionFind, x int32) int32 {
  index := make([]int32, 32)
  len := int32(0)
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

// Check if two elements are in the same set.
func same(u *UnionFind, x int32, y int32) bool {
  return root(u, x) == root(u, y)
}

// Return the size of the set containing a given element.
func getSize(u *UnionFind, x int32) int32 {
  return - (u.parent[root(u, x)])
}

// Merge two sets.
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

// Define the structure of a segment tree and its operations.
type segment_tree struct {
  array unsafe.Pointer
  size int32
  val_size int32
  func func(unsafe.Pointer, unsafe.Pointer, unsafe.Pointer)
}

// Copy one memory area to another.
func segment_tree_memcpy(dst unsafe.Pointer, src unsafe.Pointer, size int32) {
  p := (*uint8)(dst)
  q := (*uint8)(src)
  for size > 0 {
    *p++ = *q++
    size--
  }
}

// Initialize a new segment tree with an initial array, size, value size, and merge function.
func new_segment_tree(ini unsafe.Pointer, n int32, val_size int32, func func(unsafe.Pointer, unsafe.Pointer, unsafe.Pointer)) *segment_tree {
  k := int32(1)
  for k < n {
    k *= 2
  }
  s := &segment_tree{}
  s.array = unsafe.Pointer(malloc(2 * k * val_size))
  s.size = k
  s.val_size = val_size
  s.func = func
  for i := int32(k); i < 2 * k; i++ {
    segment_tree_memcpy((*uint8)(s.array) + i * val_size, ini, val_size)
  }
  a := (*uint8)(s.array)
  for i := k - 1; i > 0; i-- {
    func((*uint8)(s.array) + i * val_size, (*uint8)(s.array) + 2 * i * val_size, (*uint8)(s.array) + (2 * i + 1) * val_size)
  }
  return s
}

// Update a segment tree node.
func update(s *segment_tree, k int32, val unsafe.Pointer) {
  k += s.size
  p := (*uint8)(s.array)
  size := s.val_size
  segment_tree_memcpy(p + k * size, val, size)
  for k >>= 1; k > 0; k >>= 1 {
    s.func(p + k * size, p + 2 * k * size, p + (2 * k + 1) * size)
  }
}

// Temporarily update a segment tree node.
func update_tmp(s *segment_tree, k int32, val unsafe.Pointer) {
  k += s.size
  p := (*uint8)(s.array)
  size := s.val_size
  segment_tree_memcpy(p + k * size, val, size)
}

// Update all segment tree nodes.
func update_all(s *segment_tree) {
  a := (*uint8)(s.array)
  size := s.val_size
  for i := s.size - 1; i > 0; i-- {
    s.func(a + i * size, a + (2 * i) * size, a + (2 * i + 1) * size)
  }
}

// Find the result of applying the merge function to a range of segment tree nodes.
func find(s *segment_tree, l int32, r int32, res unsafe.Pointer) {
  lindex := make([]int32, 32)
  rindex := make([]int32, 32)
  llen := int32(0)
  rlen := int32(0)
  for l < r {
    if l & 1 == 1 {
      lindex[llen] = l
      llen++
    }
    if r & 1 == 1 {
      rindex[rlen] = r - 1
      rlen++
    }
    l >>= 1
    r >>= 1
  }
  if llen == 0 {
    lindex[llen] = rindex[rlen - 1]
  }
  p := (*uint8)(s.array)
  segment_tree_memcpy(res, p + lindex[0] * s.val_size, s.val_size)
  for i := int32(1); i < llen; i++ {
    s.func(res, res, p + lindex[i] * s.val_size)
  }
  for i := rlen - 1; i >= 0; i-- {
    s.func(res, res, p + rindex[i] * s.val_size)
  }
}

// Define the main function to run the program.
type i32 int32
type i64 int64

type index_val struct {
  index i32
  val i32
}

// Compare two index_val structures based on their values.
func cmp_index_val(a unsafe.Pointer, b unsafe.Pointer) int32 {
  d := (*index_val)(a).val - (*index_val)(b).val
  if d == 0 {
    return 0
  }
  if d > 0 {
    return -1
  }
  return 1
}

type segment_node struct {
  index i32
  val i64
}

// Merge two segment_node structures based on their values.
func func_segment_node(c unsafe.Pointer, a unsafe.Pointer, b unsafe.Pointer) {
  p := (*segment_node)(a)
  q := (*segment_node)(b)
  *(*segment_node)(c) = *p
  if p.val < q.val {
    *(*segment_node)(c) = *p
  } else {
    *(*segment_node)(c) = *q
  }
}

type edge struct