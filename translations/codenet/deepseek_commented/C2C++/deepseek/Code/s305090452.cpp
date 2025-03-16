#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cinttypes>

// Define the structure of a binary heap and its operations.
struct BinaryHeap {
    std::vector<void*> array;
    size_t heap_size;
    size_t max_size;
    size_t val_size;
    int (*cmp) (const void *, const void *);
};

// Initialize a new binary heap with a given value size and comparison function.
BinaryHeap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
    BinaryHeap *h = new BinaryHeap;
    h->array.resize(1);
    h->heap_size = 0;
    h->max_size = 1;
    h->val_size = val_size;
    h->cmp = cmpF;
    return h;
}

// Return the current size of the heap.
int32_t get_heap_size (const BinaryHeap *h) {
    return h->heap_size;
}

// Check if the heap is empty.
bool is_empty (const BinaryHeap *h) {
    return h->heap_size == 0;
}

// Free the memory allocated for the heap.
void free_heap (BinaryHeap *h) {
    delete h;
}

// Initialize the heap size to zero.
void init_heap (BinaryHeap *h) {
    h->heap_size = 0;
}

// Swap two elements of the heap.
static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
    std::swap_ranges(static_cast<char*>(a), static_cast<char*>(a) + val_size, static_cast<char*>(b));
}

// Copy one element to another.
static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
    std::memcpy(dst, src, val_size);
}

// Add a new element to the heap.
void push (BinaryHeap *h, const void *val) {
    if (h->heap_size == h->max_size) {
        h->max_size = 2 * h->max_size + 1;
        h->array.resize(h->max_size);
    }
    h->heap_size++;
    size_t k = h->heap_size;
    const size_t val_size = h->val_size;
    int (*cmp) (const void *, const void *) = h->cmp;
    heap_func_copy(h->array[k], val, val_size);
    while(k > 1){
        size_t parent = k / 2;
        if (cmp (h->array[parent], h->array[k]) <= 0) {
            return;
        }
        heap_func_swap (h->array[parent], h->array[k], val_size);
        k = parent;
    }
}

// Remove the top element from the heap.
void pop (BinaryHeap *h, void *res) {
    if (res != nullptr) {
        heap_func_copy (res, h->array[1], h->val_size);
    }
    heap_func_copy (h->array[1], h->array[h->heap_size], h->val_size);
    h->heap_size--;
    int (* const cmp) (const void *, const void *) = h->cmp;
    const size_t n = h->heap_size;
    size_t k = 1;
    while (2 * k  + 1 <= n) {
        int c = cmp (h->array[2 * k], h->array[2 * k + 1]);
        size_t next = 2 * k + (c <= 0 ? 0 : 1);
        if (cmp (h->array[k], h->array[next]) <= 0) return;
        heap_func_swap (h->array[k], h->array[next], h->val_size);
        k = next;
    }
    if (2 * k <= n && cmp (h->array[k], h->array[2 * k]) > 0) {
        heap_func_swap (h->array[k], h->array[2 * k], h->val_size);
    }
}

// Return the top element of the heap without removing it.
void top (const BinaryHeap *h, void *res) {
    if (res != nullptr) {
        heap_func_copy (res, h->array[1], h->val_size);
    }
}

// Define the structure of Union-Find and its operations.
struct UnionFind {
    std::vector<int32_t> parent;
    int32_t size;
};

// Initialize the parent array to -1.
void initUnionFind (UnionFind *u) {
    std::fill(u->parent.begin(), u->parent.end(), -1);
}

// Initialize a new Union-Find structure with a given size.
UnionFind* newUnionFind (const int32_t size) {
    UnionFind *u = new UnionFind;
    u->parent.resize(size);
    u->size = size;
    initUnionFind (u);
    return u;
}

// Free the memory allocated for the Union-Find structure.
void freeUnionFind (UnionFind *u) {
    delete u;
}

// Find the root of a given element.
int32_t root (UnionFind *u, int32_t x) {
    while (u->parent[x] >= 0) {
        x = u->parent[x];
    }
    return x;
}

// Check if two elements are in the same set.
bool same (UnionFind *u, int32_t x, int32_t y) {
    return root (u, x) == root (u, y);
}

// Return the size of the set containing a given element.
int32_t getSize(UnionFind *u, int32_t x) {
    return - (u->parent[root (u, x)]);
}

// Merge two sets.
void unite(UnionFind *u, int32_t x, int32_t y) {
    x = root (u, x);
    y = root (u, y);
    if (x == y) return;
    if (u->parent[x] > u->parent[y]) {
        std::swap(x, y);
    }
    u->parent[x] += u->parent[y];
    u->parent[y] = x;
}

// Define the structure of a segment tree and its operations.
struct SegmentTree {
    std::vector<void*> array;
    int32_t size;
    size_t val_size;
    void (*func) (void *, const void *, const void *);
};

// Copy one memory area to another.
static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
    std::memcpy(dst, src, size);
}

// Initialize a new segment tree with an initial array, size, value size, and merge function.
SegmentTree* new_segment_tree (const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)) {
    int32_t k = 1;
    while (k < n) k *= 2;
    SegmentTree *s = new SegmentTree;
    s->array.resize(2 * k);
    s->size = k;
    s->val_size = val_size;
    s->func = func;
    for (int32_t i = k; i < 2 * k; ++i) {
        segment_tree_memcpy (s->array[i], ini, val_size);
    }
    for (int32_t i = k - 1; i > 0; --i) {
        func (s->array[i], s->array[2 * i], s->array[2 * i + 1]);
    }
    return s;
}

// Update a segment tree node.
void update (SegmentTree * const s, int32_t k, const void *val) {
    k += s->size;
    size_t size = s->val_size;
    segment_tree_memcpy (s->array[k], val, size);
    for (k >>= 1; k > 0; k >>= 1) {
        s->func (s->array[k], s->array[2 * k], s->array[2 * k + 1]);
    }
}

// Temporarily update a segment tree node.
void update_tmp (SegmentTree * const s, int32_t k, const void *val) {
    k += s->size;
    size_t size = s->val_size;
    segment_tree_memcpy (s->array[k], val, size);
}

// Update all segment tree nodes.
void update_all (SegmentTree * const s) {
    size_t size = s->val_size;
    for (int32_t i = s->size - 1; i > 0; --i) {
        s->func (s->array[i], s->array[2 * i], s->array[2 * i + 1]);
    }
}

// Find the result of applying the merge function to a range of segment tree nodes.
void find (const SegmentTree *s, int32_t l, int32_t r, void *res) {
    int32_t lindex[32];
    int32_t rindex[32];
    int32_t llen = 0;
    int32_t rlen = 0;
    for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
        if (l & 1) lindex[llen++] = l++;
        if (r & 1) rindex[rlen++] = --r;
    }
    if (llen == 0) {
        lindex[llen++] = rindex[--rlen];
    }
    segment_tree_memcpy (res, s->array[lindex[0]], s->val_size);
    for (int32_t i = 1; i < llen; ++i) {
        s->func (res, res, s->array[lindex[i]]);
    }
    for (int32_t i = rlen - 1; i >= 0; --i) {
        s->func (res, res, s->array[rindex[i]]);
    }
}

// Define the main function to run the program.
typedef int32_t i32;
typedef int64_t i64;

typedef struct index_val {
    i32 index;
    i32 val;
} index_val;

// Compare two index_val structures based on their values.
int cmp_index_val (const void *a, const void *b) {
    i32 d = ((index_val *)a)->val - ((index_val *)b)->val;
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

typedef struct segment_node {
    i32 index;
    i64 val;
} segment_node;

// Merge two segment_node structures based on their values.
void func_segment_node (void *c, const void *a, const void *b) {
    const segment_node *p = (const segment_node *)a;
    const segment_node *q = (const segment_node *)b;
    *(segment_node *)c = p->val < q->val ? *p : *q;
}

typedef struct edge {
    i32 a, b;
    i64 c;
} edge;

// Compare two edge structures based on their costs.
int cmp_edge (const void *a, const void *b) {
    i64 d = ((edge *)a)->c - ((edge *)b)->c;
    return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
    i32 n, d;
    std::cin >> n >> d;
    i32 *a = new i32[n];
    index_val *p = new index_val[n];
    for (i32 i = 0; i < n; ++i) {
        std::cin >> a[i];
        p[i] = {i, a[i]};
    }
    std::sort(p, p + n, [](const index_val &a, const index_val &b) {
        return a.val < b.val;
    });
    const segment_node ini = {n, (i64)(n + 2) * 1000000000 + 1};
    SegmentTree *l = new_segment_tree(&ini, n, sizeof(segment_node), func_segment_node);
    SegmentTree *r = new_segment_tree(&ini, n, sizeof(segment_node), func_segment_node);
    for (i32 i = 0; i < n; ++i) {
        update_tmp(l, i, &((segment_node){i, a[i] + (i64)(n - 1 - i) * d}));
        update_tmp(r, i, &((segment_node){i, a[i] + (i64)i * d}));
    }
    update_all(l);
    update_all(r);
    BinaryHeap *h = new_binary_heap(sizeof(edge), cmp_edge);
    for (i32 i = 0; i < n; ++i) {
        i32 v = p[i].index;
        if (v > 0) {
            segment_node t;
            find(l, 0, v, &t);
            push(h, &((edge){v, t.index, p[i].val + t.val - (i64) (n - 1 - v) * d}));
        }
        if (v + 1 < n) {
            segment_node t;
            find(r, v + 1, n, &t);
            push(h, &((edge){v, t.index, p[i].val + t.val - (i64) v * d}));
        }
        update(l, v, &ini);
        update(r, v, &ini);
    }
    i64 sum = 0;
    UnionFind *u = newUnionFind(n);
    while (getSize(u, 0) < n) {
        edge e;
        pop(h, &e);
        if (same(u, e.a, e.b)) continue;
        unite(u, e.a, e.b);
        sum += e.c;
    }
    std::cout << sum << std::endl;
    delete[] a;
    delete[] p;
    free_heap(h);
    freeUnionFind(u);
    delete l;
    delete r;
}

int main (void) {
    run();
    return 0;
}
