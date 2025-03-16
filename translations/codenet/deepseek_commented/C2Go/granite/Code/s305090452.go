
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
	cmp       func(a, b []byte) int
}

func newHeap(val_size int, cmp func(a, b []byte) int) *heap {
	h := &heap{
		array:     make([]byte, val_size*(1+1)),
		heap_size: 0,
		max_size:  1,
		cmp:       cmp,
	}
	return h
}

func (h *heap) getHeapSize() int {
	return h.heap_size
}

func (h *heap) isEmpty() bool {
	return h.heap_size == 0
}

func (h *heap) freeHeap() {
	h.array = nil
	h = nil
}

func (h *heap) initHeap() {
	h.heap_size = 0
}

func (h *heap) cmpFunc(a, b []byte) int {
	return h.cmp(a, b)
}

func (h *heap) push(val []byte) {
	if h.heap_size == h.max_size {
		h.max_size = 2 * h.max_size + 1
		h.array = append(h.array, make([]byte, h.max_size*len(val))...)
	}
	h.heap_size++
	array := h.array
	val_size := len(val)
	cmp := h.cmpFunc
	n := h.heap_size
	k := n
	for k > 1 {
		parent := k / 2
		if cmp(array[parent*val_size:(parent+1)*val_size], array[(k-1)*val_size:k*val_size]) <= 0 {
			break
		}
		copy(array[k*val_size:(k+1)*val_size], array[(k-1)*val_size:k*val_size])
		k = parent
	}
}

func (h *heap) pop(res []byte) {
	array := h.array
	val_size := len(res)
	if res!= nil {
		copy(res, array+val_size:val_size*2])
	}
	h.heap_size--
	int cmp(a, b []byte) int {
		return h.cmp(a, b)
	}
	int k = 1;
	while (2*k+1 <= h.heap_size) {
		int c = cmp(array+val_size*2*k, array+val_size*(2*k+1)) {
			int next = 2*k+1;
			if (2*k <= h.heap_size && cmp(array+val_size*k, array+val_size*next) > 0) {
				copy(array+val_size*k, array+val_size*next)
				k = next;
			}
		}
	}
	if (2*k <= h.heap_size && cmp(array+val_size*k, array+val_size*(2*k+1)) {
			copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*(2*k+1), array+val_size*k) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*(2*k+1), array+val_size*k) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
				copy(array+val_size*k, array+val_size*(2*k+1)) {
    return 0;
}
}


}









};



}


}


}



}




}


}


}


}


}

}

}

}

}
}

}
}
}
}

}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}

}
}
}

}

}
}

}

}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}