

import sys

def new_binary_heap(val_size, cmpF):
    h = {}
    h['array'] = [0] * (val_size * (1 + 1))
    h['heap_size'] = 0
    h['max_size'] = 1
    h['val_size'] = val_size
    h['cmp'] = cmpF
    return h

def get_heap_size(h):
    return h['heap_size']

def is_empty(h):
    return h['heap_size'] == 0

def free_heap(h):
    del h['array']
    del h
    return

def init_heap(h):
    h['heap_size'] = 0
    return

def heap_func_swap(a, b, val_size):
    if (val_size & 7) == 0:
        for i in range(val_size // 8):
            a[i], b[i] = b[i], a[i]
    else:
        for i in range(val_size):
            a[i], b[i] = b[i], a[i]
    return

def heap_func_copy(dst, src, val_size):
    if (val_size & 7) == 0:
        for i in range(val_size // 8):
            dst[i] = src[i]
    else:
        for i in range(val_size):
            dst[i] = src[i]
    return

def push(h, val):
    if h['heap_size'] == h['max_size']:
        h['max_size'] = 2 * h['max_size'] + 1
        h['array'] = h['array'] + [0] * (h['val_size'] * (h['max_size'] + 1))
    h['heap_size'] += 1
    array = h['array']
    k = h['heap_size']
    val_size = h['val_size']
    cmp = h['cmp']
    while k > 1:
        parent = k // 2
        if cmp(array[parent * val_size:(parent + 1) * val_size], array[(k - 1) * val_size:k * val_size]) <= 0:
            break
        heap_func_swap(array[parent * val_size:(parent + 1) * val_size], array[(k - 1) * val_size:k * val_size], val_size)
        k = parent
    return

def pop(h, res):
    array = h['array']
    val_size = h['val_size']
    if res!= None:
        heap_func_copy(res, array + val_size, val_size)
    heap_func_copy(array + val_size, array + val_size * h['heap_size'], val_size)
    h['heap_size'] -= 1
    k = 1
    while 2 * k + 1 <= h['heap_size']:
        c = h['cmp'](array + val_size * 2 * k, array + val_size * (2 * k + 1))
        size = h['heap_size']
        next = 2 * k + (c <= 0) * 0 + (c > 0) * 1
        if 2 * k <= size and h['cmp'](array + val_size * k, array + val_size * next) > 0:
            heap_func_swap(array + val_size * k, array + val_size * next, val_size)
            k = next
    if 2 * k <= size and h['cmp'](array + val_size * k, array + val_size * 2 * k) > 0:
        heap_func_swap(array + val_size * k, array + val_size * 2 * k, val_size)
    return

def top(h, res):
    array = h['array']
    val_size = h['val_size']
    if res!= None:
        heap_func_copy(res, array + val_size, val_size)
    return

def new_union_find(size):
    u = {}
    u['parent'] = [0] * size
    u['size'] = size
    init_union_find(u)
    return u

def free_union_find(u):
    free(u['parent'])
    free(u)
    return

def initUnionFind(u):
    for i in range(u['size']):
        u['parent'][i] = -1
    return

def root(u, x):
    int32_t index[32];
    int32_t len = 0;
    while (u['parent'][x] >= 0:
        index[len++] = x;
        x = u['parent'][x];
    while (x > 0) {
        x = u['parent'][x];
    }
    while (len > 0) {
        int32_t swap = index[--len];
        index[len++] = swap;
        x = u['parent'][swap];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]]);
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]], u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]];
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1]));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]), u['parent'][index[1));
        x = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent')[index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent')[index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent)[index[0]);
    }
    while (len > 0) {
        int32_t c = u['cmp'](u['parent')[index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent')[index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent][index[0]);
    }
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    }
    while (len > 0) {
        int32_t c = u['parent][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent'][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent][index[0]);
    }
    while (len > 0) {
        int32_t c = u['parent)[index[0]);
    }
    while (len > 0) {
        int32_t c = u['paren