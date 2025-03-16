

import sys
import array
import heapq

def new_binary_heap(val_size, cmpF):
    h = {}
    h['array'] = array.array('L', [0] * (val_size * (1 + 1)))
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
    h['array'] = None
    h = None

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
        h['array'] = array.array('L', h['array'] + [0] * (h['val_size'] * (h['max_size'] + 1)))
    h['heap_size'] += 1
    array = h['array']
    size = h['heap_size']
    cmp = h['cmp']
    k = size
    while k > 1:
        parent = k // 2
        if cmp(array[parent * h['val_size']:(parent + 1) * h['val_size']], array[(k - 1) * h['val_size']:k * h['val_size']]) <= 0:
            break
        heap_func_swap(array, (k - 1) * h['val_size'], k * h['val_size'], h['val_size'])
        k = parent
    return

def pop(h, res):
    array = h['array']
    val_size = h['val_size']
    if res!= None:
        heap_func_copy(res, array, val_size)
    heap_func_copy(array, array + val_size * h['heap_size'], val_size)
    h['heap_size'] -= 1
    cmp = h['cmp']
    size = h['heap_size']
    k = 1
    while 2 * k + 1 <= size:
        c = cmp(array + 2 * k * val_size, array + (2 * k + 1) * val_size)
        next = 2 * k + (c <= 0) * 0
        if cmp(array + k * val_size, array + next * val_size) <= 0:
            break
        heap_func_swap(array + k * val_size, array + next * val_size, val_size)
        k = next
    if 2 * k <= size and cmp(array + k * val_size, array + 2 * k * val_size) > 0:
        heap_func_swap(array + k * val_size, array + 2 * k * val_size, val_size)
    return

def top(h, res):
    array = h['array']
    val_size = h['val_size']
    if res!= None:
        heap_func_copy(res, array, val_size)
    return

def newUnionFind(size):
    u = {}
    u['parent'] = [-1] * size
    u['size'] = size
    return u

def initUnionFind(u):
    for i in range(u['size']):
        u['parent'][i] = -1
    return

def freeUnionFind(u):
    u['parent'] = None
    u['size'] = 0
    free(u)

def root(u, x):
    path = []
    while u['parent'][x] >= 0:
        path.append(x)
        x = u['parent'][x]
    for i in range(len(path)):
        u['parent'][path[i]] = -1
    return path[-1]

def same(u, x, y):
    return root(u, x) == root(u, y)

def unite(u, x, y):
    x = root(u, x)
    y = root(u, y)
    if x == y:
        return
    if u['parent'][x] > u['parent'][y]:
        u['parent'][x] = y;
    return

def getSize(u, x):
    return - (u['parent'][root(u, x)];

def new_segment_tree(const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)):
    int32_t k = 1;
    while (k < n):
        k *= 2;
    segment_tree *s = (segment_tree *) calloc (1, sizeof (segment_tree));
    s['array'] = (void *) calloc (2 * k, val_size);
    s['size'] = k;
    s['val_size'] = val_size;
    s['func'] = func;
    for (int32_t i = k; i < 2 * k; ++i) {
        s['parent'][i] = -1;
    }
    uint8_t *p = (uint8_t *) s['array'];
    const size_t size = s['val_size'];
    for (int32_t i = k; i < 2 * k; ++i) {
        s['parent'][i] = -1;
    }
    return s;
}

void update(segment_tree * const s, int32_t k, const void *val):
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + k * size, val, size);
    return;
}

void update_tmp(segment_tree * const s, int32_t k, const void *val):
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + k * size, val, size);
    return;
}

void update_all(segment_tree * const s):
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    for (int32_t i = s->size - 1; ++i) {
        s['parent'][i] = -1;
    }
    return;
}

void find(const segment_tree * const s, int32_t l, int32_t r, void *res):
    int32_t lindex[32];
    int32_t rindex[32];
    int32_t llen = 0;
    int32_t rlen = 0;
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + l * size, llen = 0;
    llen = 0;
    lindex[llen] = 0;
    rlen = 0;
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + l * size, llen = 0;
    rlen = 0;
    for (int32_t i = s->size - 1; ++i) {
        s['parent'][i] = -1;
    }
    return;
}

void update_tmp(segment_tree * const s, int32_t k, const void *val):
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + k * size, klen = 0;
    rlen = 0;
    for (int32_t i = k; ++i) {
        s['parent'][i] = -1;
    }
    return;
}

void update_all(segment_tree * const s):
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + k * size, klen = 0;
    rlen = 0;
    for (int32_t i = s->size - 1; ++i) {
        s['parent'][i] = -1;
    }
    return;
}

void find(const segment_tree * const s, int32_t l, int32_t r, void *res):
    uint8_t *p = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + l * size, llen = 0;
    rlen = 0;
    for (int32_t i = s->size - 1;
    rlen = 0;
    for (int32_t i = s->size;
    segment_tree_memcpy (p + k * size, klen = 0;
    rlen = 0;
    for (int32_t i = s->size - 1;
    rlen = 0;
    for (int32_t i = s->size - 1;
    rlen = 0;
    for (int32_t i = s->size;
    segment_tree_memcpy (p + k * size, klen = 0;
    rlen = 0;
    for (int32_t i = s->size - 1;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->array;
    const size_t size = s->val_size;
    segment_tree_memcpy (p + i * size, i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->array;
    const size_t size = s->val_size;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size;
    rlen = 0;
    for (int32_t i = s->array;
    const size_t size = s->val_size);
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array);
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    const size_t size = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->size);
    rlen = 0;
    for (int32_t i = s->array;
    const size_t size = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array);
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array);
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array);
    rlen = 0);
    for (int32_t i = s->array);
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0);
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0);
    for (int32_t i = s->val_size);
    rlen = 0);
    for (int32_t i = s->array);
    rlen = 0);
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->val_size);
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0);
    for (int32_t i = s->array;
    rlen = 0;
    return;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array);
    rlen = 0);
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t i = s->array;
    rlen = 0;
    for (int32_t) {
    return