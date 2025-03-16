

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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

func getHeapSize(h *heap) int {
	return h.heap_size
}

func isHeapEmpty(h *heap) bool {
	return h.heap_size == 0
}

func freeHeap(h *heap) {
	os.Stdout.Sync()
	os.Stdout.WriteString("free_heap\n")
	os.Stdout.WriteString(strconv.Itoa(int(h.val_size)) + "\n")
	os.Stdout.Sync()
	os.Stdout.WriteString("end_free_heap\n")
	os.Stdout.Sync()
	os.Stdout.WriteString("0\n")
	os.Stdout.Sync()
	os.Stdout.WriteString("end_output\n")
	os.Stdout.Sync()
	os.Exit(0)
}

func initHeap(h *heap) {
	h.heap_size = 0
}

func heapSize(h *heap) int {
	return h.heap_size
}

func heapLess(h *heap, i, j int) bool {
	return h.cmp(h.array[i*h.val_size:(i+1)*h.val_size], h.array[j*h.val_size:(j+1)*h.val_size]) < 0
}

func heapSwap(h *heap, a, b int) {
	val_size := h.val_size
	array := h.array
	for i := 0; i < val_size; i++ {
		array[a*val_size+i], array[b*val_size+i] = array[b*val_size+i], array[a*val_size+i]
	}
}

func heapCopy(dst, src []byte, val_size int) {
	for i := 0; i < val_size; i++ {
		dst[i] = src[i]
	}
}

func push(h *heap, val []byte) {
	if h.heap_size == h.max_size {
		h.max_size = 2 * h.max_size + 1
		h.array = append(h.array, make([]byte, h.val_size*(h.max_size+1))
	}
	h.heap_size++
	val_size := h.val_size
	array := h.array
	i := h.heap_size
	for i > 1 && h.cmp(array+(i/2)*val_size, val) < 0 {
		heapCopy(array+i*val_size, val, val_size)
		i /= 2
	}
	heapCopy(array+i*val_size, val, val_size)
}

func pop(h *heap, res []byte) {
	val_size := h.val_size
	array := h.array
	if res!= nil {
		heapCopy(res, array+val_size, val_size)
	}
	heapCopy(array+val_size, array+h.heap_size*val_size, val_size)
	h.heap_size--
	int i = 1;
	while (i < h.heap_size) {
		int j = i;
		while (j > 0) {
			int k = j / 2;
			if (k > 0 && h.cmp(array+k*val_size, array+(j-1)*val_size) > 0) {
				heapCopy(array+k*val_size, array+(j-1)*val_size, val_size)
				j = k;
			}
		}
	}
}

func top(h *heap, res []byte) {
	int val_size = h.val_size;
	heapCopy(res, array+val_size, val_size)
}

func cmp(a, b []byte) int {
	return memcmp(a, b, val_size);
}

int main() {
	int n, d;
	scanf("%d %d", &n, &d);
	int *a = (int *)calloc(n, sizeof(int));
	index_val *p = (index_val *)calloc(n, sizeof(index_val));
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	qsort(p, n, sizeof(index_val), cmp_index_val);
	heap *l = newHeap(sizeof(segment_node), cmp_segment_node);
	heap *r = newHeap(sizeof(segment_node), cmp_segment_node);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	update(l, i, &((segment_node){i, a[i]});
	update(r, i, &((segment_node){i, a[i]});
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		l = newHeap(sizeof(segment_node), cmp_segment_node);
	heap *r = newHeap(sizeof(segment_node), cmp_segment_node);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		update(l, i, &((segment_node){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i]};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i)};
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
	}
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
	}
	}





	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
		p[i] = (index_val){i, a[i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
	}









	}









	}






	}




	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
	}

	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i) {
    scanf("%d", a + i);
    p[i) {
    p[i) = (index_val){i, a[i);
    p[i] = (index_val){i, a[i);
    p[i) {
    scanf("%d", a + i);
    p[i) {
    p[i) = (index_val){i, a[i));