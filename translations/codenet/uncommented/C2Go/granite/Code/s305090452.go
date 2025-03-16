

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

type heap struct {
	array     []byte
	heap_size int
	max_size  int
	val_size  int
	cmp       func(a, b []byte) int
}

func newHeap(val_size int, cmp func(a, b []byte) int) *heap {
	h := &heap{
		array:     make([]byte, val_size*(1+1)),
		heap_size: 0,
		max_size:  1,
		val_size: val_size,
		cmp:       cmp,
	}
	return h
}

func (h *heap) getHeapSize() int {
	return h.heap_size
}

func (h *heap) is_empty() bool {
	return h.heap_size == 0
}

func (h *heap) freeHeap() {
	os.Remove("heap.txt")
}

func (h *heap) initHeap() {
	h.heap_size = 0
}

func heap_func_swap(a, b []byte, val_size int) {
	if (val_size & 7) == 0 {
		a_int64 := *(*int64)(unsafe.Pointer(&a[0]))
		b_int64 := *(*int64)(unsafe.Pointer(&b[0]))
		for i := 0; i < val_size/8; i++ {
			a_int64, b_int64 = b_int64, a_int64
			*(*int64)(unsafe.Pointer(&a[i*8])) = a_int64
			*(*int64)(unsafe.Pointer(&b[i*8])) = b_int64
		}
	} else {
		for i := 0; i < val_size; i++ {
			a[i], b[i] = b[i], a[i]
		}
	}
}

func heap_func_copy(dst, src []byte, val_size int) {
	if (val_size & 7) == 0 {
		for i := 0; i < val_size/8; i++ {
			*(*int64)(unsafe.Pointer(&dst[i*8])) = *(*int64)(unsafe.Pointer(&src[i*8]))
		}
	} else {
		for i := 0; i < val_size; i++ {
			dst[i] = src[i]
		}
	}
}

func (h *heap) push(val []byte) {
	if h.heap_size == h.max_size {
		h.max_size = 2 * h.max_size + 1
		h.array = append(h.array, make([]byte, h.val_size*(h.max_size+1))...)
	}
	h.heap_size++
	dst := h.array[h.heap_size*h.val_size:]
	src := val
	heap_func_copy(dst, src, h.val_size)
	for h.heap_size > 1 {
		parent := h.heap_size / 2
		if h.cmp(h.array[parent*h.val_size:], h.array[h.heap_size*h.val_size:]) <= 0 {
			break
		}
		heap_func_swap(h.array+parent*h.val_size, h.array+h.heap_size*h.val_size, h.val_size)
		h.heap_size--
	}
}

func (h *heap) pop(res []byte) {
	dst := h.array[h.val_size:]
	src := h.array[h.heap_size*h.val_size:]
	heap_func_copy(dst, src, h.val_size)
	h.heap_size--
	for {
		child := 2 * i + 1;
		if child < h.heap_size && h.cmp(h.array+child*h.val_size, h.array+i*h.val_size) <= 0 {
			break
		}
		heap_func_swap(h.array+i*h.val_size, h.array+child*h.val_size, h.val_size)
		h.heap_size--
	}
}

func (h *heap) top(res []byte) {
	heap_func_copy(res, h.array+i*h.val_size, h.val_size)
}

type UnionFind struct {
	parent []int32
	size int32
}

func newUnionFind(size int32) *UnionFind {
	parent := make([]int32, size)
	return &UnionFind{
		parent: parent,
		size: size,
	}
}

func (u *UnionFind) initUnionFind() {
	for i := 0; i < u->size; ++i) {
		u->parent[i] = -1;
	}
}

func (u *UnionFind) freeUnionFind() {
	free(u->parent);
	free(u);
}

func (u *UnionFind) root(i int32) {
	return u->parent[i];
}

func (u *UnionFind) same(i int32, j int32) {
	return u->parent[i] == u->parent[j];
}

func (u *UnionFind) getSize(i int32) {
	return - (u->parent[i]);
}

void unite(i int32, j int32) {
	u->parent[i] = j;
}

int32_t main() {
	int32_t n, d;
	scanf("%d %d", &n, &d);
	int32_t *a = (int32_t *)calloc(n, sizeof(int32_t));
	int32_t *p = (int32_t *)calloc(n, sizeof(int32_t));
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	}
	for (int32_t i = 0; i < n; ++i) {
		p[i] = i;
	}
	}