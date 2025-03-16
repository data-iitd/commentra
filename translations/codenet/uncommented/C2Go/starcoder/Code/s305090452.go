
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type binaryHeap struct {
	array    []interface{}
	heapSize int
	maxSize  int
	valSize  int
	cmp      func(a, b interface{}) int
}

func newBinaryHeap(valSize int, cmp func(a, b interface{}) int) *binaryHeap {
	h := &binaryHeap{
		array:    make([]interface{}, 1+1),
		heapSize: 0,
		maxSize:  1,
		valSize:  valSize,
		cmp:      cmp,
	}
	h.array[0] = make([]byte, valSize)
	return h
}

func (h *binaryHeap) getHeapSize() int {
	return h.heapSize
}

func (h *binaryHeap) isEmpty() bool {
	return h.heapSize == 0
}

func (h *binaryHeap) freeHeap() {
	h.array = nil
	h.heapSize = 0
	h.maxSize = 0
	h.valSize = 0
	h.cmp = nil
}

func (h *binaryHeap) initHeap() {
	h.heapSize = 0
}

func (h *binaryHeap) swap(a, b int) {
	if h.valSize&7 == 0 {
		p := (*[8]uint64)(unsafe.Pointer(&h.array[a]))
		q := (*[8]uint64)(unsafe.Pointer(&h.array[b]))
		for i := 0; i < h.valSize/8; i++ {
			p[i], q[i] = q[i], p[i]
		}
	} else {
		p := (*[8]uint8)(unsafe.Pointer(&h.array[a]))
		q := (*[8]uint8)(unsafe.Pointer(&h.array[b]))
		for i := 0; i < h.valSize; i++ {
			p[i], q[i] = q[i], p[i]
		}
	}
}

func (h *binaryHeap) copy(dst, src int) {
	if h.valSize&7 == 0 {
		p := (*[8]uint64)(unsafe.Pointer(&h.array[src]))
		q := (*[8]uint64)(unsafe.Pointer(&h.array[dst]))
		for i := 0; i < h.valSize/8; i++ {
			q[i] = p[i]
		}
	} else {
		p := (*[8]uint8)(unsafe.Pointer(&h.array[src]))
		q := (*[8]uint8)(unsafe.Pointer(&h.array[dst]))
		for i := 0; i < h.valSize; i++ {
			q[i] = p[i]
		}
	}
}

func (h *binaryHeap) push(val interface{}) {
	if h.heapSize == h.maxSize {
		h.maxSize = 2*h.maxSize + 1
		h.array = append(h.array, make([]byte, h.valSize))
	}
	h.heapSize++
	h.copy(h.heapSize, 0)
	h.array[h.heapSize] = val
	for h.heapSize > 1 {
		parent := h.heapSize / 2
		if h.cmp(h.array[parent], h.array[h.heapSize]) <= 0 {
			break
		}
		h.swap(parent, h.heapSize)
		h.heapSize = parent
	}
}

func (h *binaryHeap) pop() interface{} {
	if h.heapSize == 0 {
		return nil
	}
	res := h.array[1]
	h.copy(0, h.heapSize)
	h.heapSize--
	h.array[h.heapSize] = nil
	for h.heapSize > 1 {
		min := 1
		left := 2 * min
		right := 2*min + 1
		if left <= h.heapSize && h.cmp(h.array[left], h.array[min]) < 0 {
			min = left
		}
		if right <= h.heapSize && h.cmp(h.array[right], h.array[min]) < 0 {
			min = right
		}
		if min == h.heapSize {
			break
		}
		h.swap(min, h.heapSize)
		h.heapSize = min
	}
	return res
}

func (h *binaryHeap) top() interface{} {
	if h.heapSize == 0 {
		return nil
	}
	return h.array[1]
}

type unionFind struct {
	parent []int32
	size   int32
}

func newUnionFind(size int32) *unionFind {
	u := &unionFind{
		parent: make([]int32, size),
		size:   size,
	}
	for i := int32(0); i < size; i++ {
		u.parent[i] = -1
	}
	return u
}

func (u *unionFind) initUnionFind() {
	for i := int32(0); i < u.size; i++ {
		u.parent[i] = -1
	}
}

func (u *unionFind) freeUnionFind() {
	u.parent = nil
	u.size = 0
}

func (u *unionFind) root(x int32) int32 {
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

func (u *unionFind) same(x, y int32) bool {
	return u.root(x) == u.root(y)
}

func (u *unionFind) getSize(x int32) int32 {
	return -u.parent[u.root(x)]
}

func (u *unionFind) unite(x, y int32) {
	x = u.root(x)
	y = u.root(y)
	if x == y {
		return
	}
	if u.parent[x] > u.parent[y] {
		x, y = y, x
	}
	u.parent[x] += u.parent[y]
	u.parent[y] = x
}

type segmentTree struct {
	array    []interface{}
	size     int32
	valSize  int
	func     func(c, a, b interface{})
	funcSize int
}

func newSegmentTree(ini interface{}, n int32, valSize int, func_ func(c, a, b interface{})) *segmentTree {
	k := int32(1)
	for k < n {
		k *= 2
	}
	s := &segmentTree{
		array:    make([]interface{}, 2*k),
		size:     k,
		valSize:  valSize,
		func:     func_,
		funcSize: int(unsafe.Sizeof(func_)),
	}
	s.array[k] = make([]byte, valSize)
	for i := k; i < 2*k; i++ {
		s.array[i] = ini
	}
	a := s.array
	for i := k - 1; i > 0; i-- {
		s.func(a[i], a[2*i], a[2*i+1])
	}
	return s
}

func (s *segmentTree) update(k int32, val interface{}) {
	k += s.size
	s.array[k] = val
	for k > 1 {
		s.func(s.array[k], s.array[2*k], s.array[2*k+1])
		k >>= 1
	}
}

func (s *segmentTree) update_tmp(k int32, val interface{}) {
	k += s.size
	s.array[k] = val
}

func (s *segmentTree) update_all() {
	a := s.array
	for i := s.size - 1; i > 0; i-- {
		s.func(a[i], a[2*i], a[2*i+1])
	}
}

func (s *segmentTree) find(l, r int32, res interface{}) {
	lindex := make([]int32, 32)
	rindex := make([]int32, 32)
	llen := int32(0)
	rlen := int32(0)
	for l += s.size; l < r; l >>= 1 {
		if l&1 > 0 {
			lindex[llen] = l
			llen++
		}
		if r&1 > 0 {
			rindex[rlen] = r - 1
			rlen++
		}
		r >>= 1
	}
	if llen == 0 {
		lindex[llen] = rindex[rlen-1]
	}
	copy(res, s.array[lindex[0]])
	for i := int32(1); i < llen; i++ {
		s.func(res, res, s.array[lindex[i]])
	}
	for i := rlen - 1; i >= 0; i-- {
		s.func(res, res, s.array[rindex[i]])
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	n, d := readTwoNums(reader)
	a := make([]int, n)
	p := make([]index_val, n)
	for i := int(0); i < n; i++ {
		a[i], _ = readInt(reader)
		p[i] = index_val{i, a[i]}
	}
	sort.Slice(p, func(i, j int) bool {
		return p[i].val < p[j].val
	})
	ini := segment_node{n, int64(n+2)*1000000000 + 1}
	l := newSegmentTree(ini, n, int(unsafe.Sizeof(ini)), func_segment_node)
	r := newSegmentTree(ini, n, int(unsafe.Sizeof(ini)), func_segment_node)
	for i := int32(0); i < n; i++ {
		update_tmp(l, i, segment_node{i, int64(a[i]) + int64(n-1-i)*int64(d)})
		update_tmp(r, i, segment_node{i, int64(a[i]) + int64(i)*int64(d)})
	}
	update_all(l)
	update_all(r)
	h := newBinaryHeap(int(unsafe.Sizeof(edge{})), cmp_edge)
	for i := int32(0); i < n; i++ {
		v := p[i].index
		if v > 0 {
			var t segment_node
			find(l, 0, v, &t)
			push(h, edge{v, t.index, p[i].val + t.val - int64(n-1-v)*int64(d)})
		}
		if v+1 < n {
			var t segment_node
			find(r, v+1, n, &t)
			push(h, edge{v, t.index, p[i].val + t.val - int64(v)*int64(d)})
		}
		update(l, v, ini)
		update(r, v, ini)
	}
	sum := int64(0)
	u := newUnionFind(int32(n))
	for getSize(u, 0) < n {
		var e edge
		pop(h, &e)
		if same(u, e.a, e.b) {
			continue
		}
		unite(u, e.a, e.b)
		sum += e.c
	}
	fmt.Printf("%d\n", sum)
}

func readInt(reader *bufio.Reader) (a int, err error) {
	var bs []byte
	bs, err = reader.ReadBytes('\n')
	if err!= nil {
		return
	}
	a, err = strconv.Atoi(strings.TrimSpace(string(bs)))
	return
}

func readTwoNums(reader *bufio.Reader) (a int, b int, err error) {
	var bs []byte
	bs, err = reader.ReadBytes('\n')
	if err!= nil {
		return
	}
	bs = bs[:len(bs)-1]
	i := 0
	a = -1
	for i < len(bs) && bs[i] >= '0' && bs[i] <= '9' {
		a = a*10 + int(bs[i]-'0')
		i++
	}
	if i == 0 {
		return
	}
	b, err = strconv.Atoi(strings.TrimSpace(string(bs[i:])))
	return
}

type index_val struct {
	index int
	val   int
}

type segment_node struct {
	index int
	val   int64
}

func func_segment_node(c, a, b interface{}) {
	p := a.(segment_node)
	q := b.(segment_node)
	c.(segment_node) = p.val < q.val
}

type edge struct {
	a, b int
	c    int64
}

func cmp_edge(a, b interface{}) int {
	d := a.(edge).c - b.(edge).c
	if d == 0 {
		return 0
	}
	if d < 0 {
		return -1
	}
	return 1
}

