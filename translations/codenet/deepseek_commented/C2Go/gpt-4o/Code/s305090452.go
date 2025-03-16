package main

import (
	"fmt"
	"math"
	"sort"
)

// Define the structure of a binary heap and its operations.
type Heap struct {
	array     []interface{}
	heapSize  int
	maxSize   int
	valSize   int
	cmp       func(a, b interface{}) int
}

// Initialize a new binary heap with a given value size and comparison function.
func NewBinaryHeap(valSize int, cmpF func(a, b interface{}) int) *Heap {
	h := &Heap{
		array:   make([]interface{}, 0, 1),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:     cmpF,
	}
	return h
}

// Return the current size of the heap.
func (h *Heap) GetHeapSize() int {
	return h.heapSize
}

// Check if the heap is empty.
func (h *Heap) IsEmpty() bool {
	return h.heapSize == 0
}

// Free the memory allocated for the heap.
func (h *Heap) FreeHeap() {
	h.array = nil
}

// Swap two elements of the heap.
func swap(a, b interface{}) (interface{}, interface{}) {
	return b, a
}

// Add a new element to the heap.
func (h *Heap) Push(val interface{}) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		newArray := make([]interface{}, h.maxSize)
		copy(newArray, h.array)
		h.array = newArray
	}
	h.heapSize++
	h.array = append(h.array, val)
	k := h.heapSize - 1
	for k > 0 {
		parent := (k - 1) / 2
		if h.cmp(h.array[parent], h.array[k]) <= 0 {
			return
		}
		h.array[parent], h.array[k] = swap(h.array[parent], h.array[k])
		k = parent
	}
}

// Remove the top element from the heap.
func (h *Heap) Pop() (interface{}, bool) {
	if h.IsEmpty() {
		return nil, false
	}
	res := h.array[0]
	h.array[0] = h.array[h.heapSize-1]
	h.heapSize--
	h.array = h.array[:h.heapSize]
	h.heapify(0)
	return res, true
}

func (h *Heap) heapify(k int) {
	n := h.heapSize
	for {
		left := 2*k + 1
		right := 2*k + 2
		smallest := k
		if left < n && h.cmp(h.array[left], h.array[smallest]) < 0 {
			smallest = left
		}
		if right < n && h.cmp(h.array[right], h.array[smallest]) < 0 {
			smallest = right
		}
		if smallest == k {
			break
		}
		h.array[k], h.array[smallest] = swap(h.array[k], h.array[smallest])
		k = smallest
	}
}

// Define the structure of Union-Find and its operations.
type UnionFind struct {
	parent []int32
	size   int32
}

// Initialize a new Union-Find structure with a given size.
func NewUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		parent: make([]int32, size),
		size:   size,
	}
	u.InitUnionFind()
	return u
}

// Initialize the parent array to -1.
func (u *UnionFind) InitUnionFind() {
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1
	}
}

// Find the root of a given element.
func (u *UnionFind) Root(x int32) int32 {
	index := make([]int32, 0, 32)
	for u.parent[x] >= 0 {
		index = append(index, x)
		x = u.parent[x]
	}
	for _, idx := range index {
		u.parent[idx] = x
	}
	return x
}

// Check if two elements are in the same set.
func (u *UnionFind) Same(x, y int32) bool {
	return u.Root(x) == u.Root(y)
}

// Merge two sets.
func (u *UnionFind) Unite(x, y int32) {
	x = u.Root(x)
	y = u.Root(y)
	if x == y {
		return
	}
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

// Define the structure of a segment tree and its operations.
type SegmentTree struct {
	array   []interface{}
	size    int32
	valSize int
	funcMerge func(c, a, b interface{})
}

// Initialize a new segment tree with an initial array, size, value size, and merge function.
func NewSegmentTree(ini interface{}, n int32, valSize int, funcMerge func(c, a, b interface{})) *SegmentTree {
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &SegmentTree{
		array:   make([]interface{}, 2*k),
		size:    k,
		valSize: valSize,
		funcMerge: funcMerge,
	}
	for i := k; i < 2*k; i++ {
		s.array[i] = ini
	}
	for i := k - 1; i > 0; i-- {
		funcMerge(s.array[i], s.array[2*i], s.array[2*i+1])
	}
	return s
}

// Update a segment tree node.
func (s *SegmentTree) Update(k int32, val interface{}) {
	k += s.size
	s.array[k] = val
	for k >>= 1; k > 0; k >>= 1 {
		s.funcMerge(s.array[k], s.array[2*k], s.array[2*k+1])
	}
}

// Find the result of applying the merge function to a range of segment tree nodes.
func (s *SegmentTree) Find(l, r int32, res interface{}) {
	l += s.size
	r += s.size
	lIndex := make([]int32, 0, 32)
	rIndex := make([]int32, 0, 32)
	for l < r {
		if l&1 == 1 {
			lIndex = append(lIndex, l)
			l++
		}
		if r&1 == 1 {
			r--
			rIndex = append(rIndex, r)
		}
		l >>= 1
		r >>= 1
	}
	if len(lIndex) == 0 {
		lIndex = append(lIndex, rIndex[len(rIndex)-1])
	}
	copy(res.([]interface{}), s.array[lIndex[0]].([]interface{}))
	for _, idx := range lIndex[1:] {
		s.funcMerge(res, res, s.array[idx])
	}
	for i := len(rIndex) - 1; i >= 0; i-- {
		s.funcMerge(res, res, s.array[rIndex[i]])
	}
}

// Define the structure for index and value.
type IndexVal struct {
	index int32
	val   int32
}

// Compare two IndexVal structures based on their values.
func cmpIndexVal(a, b interface{}) int {
	d := a.(IndexVal).val - b.(IndexVal).val
	if d == 0 {
		return 0
	} else if d > 0 {
		return -1
	}
	return 1
}

// Define the structure for segment nodes.
type SegmentNode struct {
	index int32
	val   int64
}

// Merge two SegmentNode structures based on their values.
func funcSegmentNode(c, a, b interface{}) {
	p := a.(*SegmentNode)
	q := b.(*SegmentNode)
	if p.val < q.val {
		c.(*SegmentNode) = *p
	} else {
		c.(*SegmentNode) = *q
	}
}

// Define the structure for edges.
type Edge struct {
	a, b int32
	c    int64
}

// Compare two Edge structures based on their costs.
func cmpEdge(a, b interface{}) int {
	d := a.(Edge).c - b.(Edge).c
	if d == 0 {
		return 0
	} else if d < 0 {
		return -1
	}
	return 1
}

// Main function to run the program.
func run() {
	var n, d int32
	fmt.Scanf("%d %d", &n, &d)
	a := make([]int32, n)
	p := make([]IndexVal, n)
	for i := int32(0); i < n; i++ {
		fmt.Scanf("%d", &a[i])
		p[i] = IndexVal{i, a[i]}
	}
	sort.Slice(p, func(i, j int) bool {
		return cmpIndexVal(p[i], p[j]) < 0
	})
	ini := SegmentNode{n, int64((n+2)*1000000000 + 1)}
	l := NewSegmentTree(&ini, n, int(unsafe.Sizeof(SegmentNode{})), funcSegmentNode)
	r := NewSegmentTree(&ini, n, int(unsafe.Sizeof(SegmentNode{})), funcSegmentNode)
	for i := int32(0); i < n; i++ {
		l.Update(i, SegmentNode{i, int64(a[i] + (n - 1 - i)*d)})
		r.Update(i, SegmentNode{i, int64(a[i] + i*d)})
	}
	h := NewBinaryHeap(int(unsafe.Sizeof(Edge{})), cmpEdge)
	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t SegmentNode
			l.Find(0, v, &t)
			h.Push(Edge{v, t.index, p[i].val + t.val - int64((n-1-v)*d)})
		}
		if v+1 < n {
			var t SegmentNode
			r.Find(v+1, n, &t)
			h.Push(Edge{v, t.index, p[i].val + t.val - int64(v*d)})
		}
		l.Update(v, ini)
		r.Update(v, ini)
	}
	sum := int64(0)
	u := NewUnionFind(n)
	for u.GetSize(0) < n {
		e, _ := h.Pop()
		if u.Same(e.(Edge).a, e.(Edge).b) {
			continue
		}
		u.Unite(e.(Edge).a, e.(Edge).b)
		sum += e.(Edge).c
	}
	fmt.Printf("%d\n", sum)
}

func main() {
	run()
}

// <END-OF-CODE>
