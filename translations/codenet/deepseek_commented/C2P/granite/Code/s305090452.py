
import sys

def new_binary_heap(val_size, cmpF):
    heap = {}
    heap['array'] = bytearray(val_size * (1 + 1))
    heap['heap_size'] = 0
    heap['max_size'] = 1
    heap['cmp'] = cmpF
    return heap

def get_heap_size(h):
    return h['heap_size']

def is_empty(h):
    return h['heap_size'] == 0

def free_heap(h):
    del h['array']
    del h

def init_heap(h):
    h['heap_size'] = 0

def heap_func_swap(a, b, val_size):
    if (val_size & 7) == 0:
        for i in range(val_size // 8):
            a[i], b[i] = b[i], a[i]
    else:
        for i in range(val_size):
            a[i], b[i] = b[i], a[i]

def heap_func_copy(dst, src, val_size):
    if (val_size & 7) == 0:
        for i in range(val_size // 8):
            dst[i] = src[i]
    else:
        for i in range(val_size):
            dst[i] = src[i]

def push(h, val):
    if h['heap_size'] == h['max_size']:
        h['max_size'] = 2 * h['max_size'] + 1
        h['array'] = bytearray(h['max_size'] * h['val_size'])
    h['heap_size'] += 1
    array = h['array']
    size = h['max_size']
    val_size = h['val_size']
    cmp = h['cmp']
    k = h['heap_size']
    heap_func_copy(array + k * val_size, val, val_size)
    while k > 1:
        parent = k // 2
        if cmp(array + parent * val_size, array + k * val_size) <= 0:
            break
        heap_func_swap(array + parent * val_size, array + k * val_size, val_size)
        k = parent
    h['heap_size'] = k

def pop(h, res):
    array = h['array']
    val_size = h['val_size']
    if res!= None:
        heap_func_copy(res, array + val_size, val_size)
    heap_func_copy(array + val_size, array + h['heap_size'] * val_size, val_size)
    h['heap_size'] -= 1
    k = 1;
    while 2 * k + 1 <= h['heap_size']:
        int c = cmp(array + 2 * k * val_size, array + (2 * k + 1) * val_size)
        size = h['heap_size']
        val_size = h['val_size']
        heap_func_copy(array + k * val_size, array + (2 * k + 1) * val_size, val_size)
        while k > 1:
            int c = cmp(array + k * val_size, array + ((k - 1) / 2 * val_size)
            size = h['heap_size']
            val_size = h['val_size']
            heap_func_copy(array + k * val_size, array + ((k - 1) / 2 * val_size)
            k = 1;
            while 2 * k + 1 <= size:
                int c = cmp(array + 2 * k * val_size, array + (2 * k + 1) * val_size)
                size = h['heap_size']
                val_size = h['val_size']
                heap_func_copy(array + k * val_size, array + (2 * k + 1) * val_size)
                    size = h['heap_size']
                    val_size = h['val_size']
                    k = 1;
                    while k > 1:
                        int c = cmp(array + k * val_size, array + ((k - 1) / 2 * val_size)
                            size = h['heap_size']
                                val_size = h['val_size']
                                    heap_func_copy(array + k * val_size, array + ((k - 1) / 2 * val_size)
                                        size = h['heap_size']
                                            val_size = h['val_size']
                                                k = 1;
                                                    while k > 1:
                                                        int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                            size = h['heap_size']
                                                                val_size = h['val_size']
                                                                    k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                                                                  int c = cmp(array + k * val_size, array + (2 * k + 1) * val_size)
                                                                                                  size = h['heap_size']
                                                                                                  val_size = h['val_size']
                                                                                                  k = 1;
                                                                                                  while k > 1:
                                                     