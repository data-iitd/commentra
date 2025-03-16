package main

import (
	"fmt"
	"math"
	"sort"
)

// Define a structure for index-value pairs
type IndexVal struct {
	Index int32
	Val   int32
}

// Comparison function for index-value pairs
func cmpIndexVal(a, b IndexVal) int {
	if a.Val == b.Val {
		return 0
	} else if a.Val > b.Val {
		return -1
	} else {
		return 1
	}
}

// Define a structure for segment nodes
type SegmentNode struct {
	Index int32
	Val   int64
}

// Function to combine two segment nodes
func funcSegmentNode(c, a, b *SegmentNode) {
	if a.Val < b.Val {
		*c = *a
	} else {
		*c = *b
	}
}

// Define a structure for edges
type Edge struct {
	A, B int32
	C    int64
}

// Comparison function for edges
func cmpEdge(a, b Edge) int {
	if a.C == b.C {
		return 0
	} else if a.C < b.C {
		return -1
	} else {
		return 1
	}
}

// Define a structure for Union-Find (Disjoint Set Union)
type UnionFind struct {
	Parent []int32
	Size   int32
}

// Function to create a new Union-Find structure
func newUnionFind(size int32) *UnionFind {
	u := &UnionFind{
		Parent: make([]int32, size),
		Size:   size,
	}
	for i := int32(0); i < size; i++ {
		u.Parent[i] = -1
	}
	return u
}

// Function to find the root of an element with path compression
func (u *UnionFind) root(x int32) int32 {
	index := make([]int32, 32)
	len := 0
	for u.Parent[x] >= 0 {
		index[len] = x
		len++
		x = u.Parent[x]
	}
	for i := len - 1; i >= 0; i-- {
		u.Parent[index[i]] = x
	}
	return x
}

// Function to check if two elements are in the same set
func (u *UnionFind) same(x, y int32) bool {
	return u.root(x) == u.root(y)
}

// Function to unite two sets containing elements x and y
func (u *UnionFind) unite(x, y int32) {
	x = u.root(x)
	y = u.root(y)
	if x == y {
		return
	}
	if u.Parent[x] > u.Parent[y] {
		x, y = y, x
	}
	u.Parent[x] += u.Parent[y]
	u.Parent[y] = x
}

// Define a structure for a segment tree
type SegmentTree struct {
	Array   []SegmentNode
	Size    int32
	ValSize int32
	Func    func(*SegmentNode, *SegmentNode, *SegmentNode)
}

// Function to create a new segment tree
func newSegmentTree(ini SegmentNode, n int32, valSize int32, f func(*SegmentNode, *SegmentNode, *SegmentNode)) *SegmentTree {
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &SegmentTree{
		Array:   make([]SegmentNode, 2*k),
		Size:    k,
		ValSize: valSize,
		Func:    f,
	}
	for i := k; i < 2*k; i++ {
		s.Array[i] = ini
	}
	for i := k - 1; i > 0; i-- {
		s.Func(&s.Array[i], &s.Array[2*i], &s.Array[2*i+1])
	}
	return s
}

// Function to update a value in the segment tree
func (s *SegmentTree) update(k int32, val SegmentNode) {
	k += s.Size
	s.Array[k] = val
	for k >>= 1; k > 0; k >>= 1 {
		s.Func(&s.Array[k], &s.Array[2*k], &s.Array[2*k+1])
	}
}

// Function to find the result in a range of the segment tree
func (s *SegmentTree) find(l, r int32) SegmentNode {
	l += s.Size
	r += s.Size
	var res SegmentNode
	res.Index = s.Size
	res.Val = int64((s.Size+2)*1000000000 + 1)
	for l < r {
		if l&1 != 0 {
			s.Func(&res, &res, &s.Array[l])
			l++
		}
		if r&1 != 0 {
			r--
			s.Func(&res, &res, &s.Array[r])
		}
		l >>= 1
		r >>= 1
	}
	return res
}

// Main function to run the algorithm
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
	l := newSegmentTree(ini, n, int32(unsafe.Sizeof(SegmentNode{})), funcSegmentNode)
	r := newSegmentTree(ini, n, int32(unsafe.Sizeof(SegmentNode{})), funcSegmentNode)

	for i := int32(0); i < n; i++ {
		l.update(i, SegmentNode{i, a[i] + (int64(n-1-i) * d)})
		r.update(i, SegmentNode{i, a[i] + (int64(i) * d)})
	}

	h := make([]Edge, 0)

	for i := int32(0); i < n; i++ {
		v := p[i].Index
		if v > 0 {
			t := l.find(0, v)
			h = append(h, Edge{v, t.Index, int64(p[i].Val + t.Val - (int64(n-1-v) * d))})
		}
		if v+1 < n {
			t := r.find(v+1, n)
			h = append(h, Edge{v, t.Index, int64(p[i].Val + t.Val - (int64(v) * d))})
		}
		l.update(v, ini)
		r.update(v, ini)
	}

	sum := int64(0)
	u := newUnionFind(n)

	sort.Slice(h, func(i, j int) bool {
		return cmpEdge(h[i], h[j]) < 0
	})

	for len(u.Parent) < int(n) {
		e := h[0]
		h = h[1:]
		if u.same(e.A, e.B) {
			continue
		}
		u.unite(e.A, e.B)
		sum += e.C
	}
	fmt.Printf("%d\n", sum)
}

// Main entry point of the program
func main() {
	run()
}

// <END-OF-CODE>
