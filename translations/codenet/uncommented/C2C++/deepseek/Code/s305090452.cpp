#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cinttypes>

struct BinaryHeap {
    std::vector<void*> array;
    size_t heap_size;
    size_t max_size;
    size_t val_size;
    int (*cmp) (const void *, const void *);
};

BinaryHeap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
    BinaryHeap *h = new BinaryHeap;
    h->array.resize(1);
    h->heap_size = 0;
    h->max_size = 1;
    h->val_size = val_size;
    h->cmp = cmpF;
    return h;
}

int32_t get_heap_size (const BinaryHeap *h) {
    return h->heap_size;
}

bool is_empty (const BinaryHeap *h) {
    return h->heap_size == 0;
}

void free_heap (BinaryHeap *h) {
    delete[] h->array[0];
    delete h;
}

void init_heap (BinaryHeap *h) {
    h->heap_size = 0;
}

static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
    std::swap_ranges(static_cast<uint8_t*>(a), static_cast<uint8_t*>(a) + val_size, static_cast<uint8_t*>(b));
}

static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
    std::memcpy(dst, src, val_size);
}

void push (BinaryHeap *h, const void *val) {
    if (h->heap_size == h->max_size) {
        h->max_size = 2 * h->max_size + 1;
        h->array.resize(h->max_size + 1);
        for (size_t i = h->heap_size + 1; i < h->array.size(); ++i) {
            h->array[i] = malloc(h->val_size);
        }
    }
    h->heap_size++;
    uint8_t *array = static_cast<uint8_t*>(h->array[h->heap_size]);
    size_t val_size = h->val_size;
    int (*cmp) (const void *, const void *) = h->cmp;
    heap_func_copy(array, val, val_size);
    size_t k = h->heap_size;
    while(k > 1) {
        size_t parent = k / 2;
        if (cmp(h->array[parent], h->array[k]) <= 0) {
            return;
        }
        heap_func_swap(h->array[parent], h->array[k], val_size);
        k = parent;
    }
}

void pop (BinaryHeap *h, void *res) {
    uint8_t *array = static_cast<uint8_t*>(h->array[1]);
    size_t val_size = h->val_size;
    if (res != NULL) {
        heap_func_copy(res, array, val_size);
    }
    heap_func_copy(array, h->array[h->heap_size], val_size);
    h->heap_size--;
    int (* const cmp) (const void *, const void *) = h->cmp;
    size_t n = h->heap_size;
    size_t k = 1;
    while (2 * k + 1 <= n) {
        int c = cmp(h->array[2 * k], h->array[2 * k + 1]);
        size_t next = 2 * k + (c <= 0 ? 0 : 1);
        if (cmp(h->array[k], h->array[next]) <= 0) return;
        heap_func_swap(h->array[k], h->array[next], val_size);
        k = next;
    }
    if (2 * k <= n && cmp(h->array[k], h->array[2 * k]) > 0) {
        heap_func_swap(h->array[k], h->array[2 * k], val_size);
    }
}

void top (const BinaryHeap *h, void *res) {
    uint8_t *array = static_cast<uint8_t*>(h->array[1]);
    size_t val_size = h->val_size;
    if (res != NULL) {
        heap_func_copy(res, array, val_size);
    }
}

struct UnionFind {
    std::vector<int32_t> parent;
    int32_t size;
};

void initUnionFind (UnionFind &u) {
    for (int32_t i = 0; i < u.size; ++i){
        u.parent[i] = -1;
    }
}

UnionFind* newUnionFind (const int32_t size) {
    UnionFind *u = new UnionFind;
    u->parent.resize(size);
    u->size = size;
    initUnionFind (*u);
    return u;
}

void freeUnionFind (UnionFind *u) {
    delete[] u->parent;
    delete u;
}

int32_t root (UnionFind *u, int32_t x) {
    std::vector<int32_t> index;
    while (u->parent[x] >= 0) {
        index.push_back(x);
        x = u->parent[x];
    }
    for (int32_t i : index) {
        u->parent[i] = x;
    }
    return x;
}

bool same (UnionFind *u, int32_t x, int32_t y) {
    return root (u, x) == root (u, y);
}

int32_t getSize(UnionFind *u, int32_t x) {
    return - (u->parent[root (u, x)]);
}

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

struct SegmentTree {
    std::vector<void*> array;
    int32_t size;
    size_t val_size;
    void (*func) (void *, const void *, const void *);
};

static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
    std::memcpy(dst, src, size);
}

SegmentTree* new_segment_tree (const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)) {
    int32_t k = 1;
    while (k < n) k *= 2;
    SegmentTree *s = new SegmentTree;
    s->array.resize(2 * k);
    s->size = k;
    s->val_size = val_size;
    s->func = func;
    for (int32_t i = k; i < 2 * k; ++i) {
        segment_tree_memcpy (s->array[i], (uint8_t*)ini + (i - k) * val_size, val_size);
    }
    for (int32_t i = k - 1; i > 0; --i) {
        func (s->array[i], s->array[2 * i], s->array[2 * i + 1]);
    }
    return s;
}

void update (SegmentTree * const s, int32_t k, const void *val) {
    k += s->size;
    size_t size = s->val_size;
    segment_tree_memcpy (s->array[k], val, size);
    for (k >>= 1; k > 0; k >>= 1) {
        s->func (s->array[k], s->array[2 * k], s->array[2 * k + 1]);
    }
}

void update_tmp (SegmentTree * const s, int32_t k, const void *val) {
    k += s->size;
    size_t size = s->val_size;
    segment_tree_memcpy (s->array[k], val, size);
}

void update_all (SegmentTree * const s) {
    size_t size = s->val_size;
    for (int32_t i = s->size - 1; i > 0; --i) {
        s->func (s->array[i], s->array[2 * i], s->array[2 * i + 1]);
    }
}

void find (const SegmentTree *s, int32_t l, int32_t r, void *res) {
    std::vector<int32_t> lindex, rindex;
    for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
        if (l & 1) lindex.push_back(l++);
        if (r & 1) rindex.push_back(--r);
    }
    if (lindex.empty()) {
        lindex.push_back(rindex.back());
    }
    segment_tree_memcpy(res, s->array[lindex[0]], size);
    for (size_t i = 1; i < lindex.size(); ++i) {
        s->func(res, res, s->array[lindex[i]]);
    }
    for (int32_t i = rindex.size() - 1; i >= 0; --i) {
        s->func(res, res, s->array[rindex[i]]);
    }
}

typedef int32_t i32;
typedef int64_t i64;

struct IndexVal {
    i32 index;
    i32 val;
};

int cmp_index_val (const void *a, const void *b) {
    i32 d = ((IndexVal *)a)->val - ((IndexVal *)b)->val;
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

struct SegmentNode {
    i32 index;
    i64 val;
};

void func_segment_node (void *c, const void *a, const void *b) {
    const SegmentNode *p = (const SegmentNode *)a;
    const SegmentNode *q = (const SegmentNode *)b;
    *(SegmentNode *)c = p->val < q->val ? *p : *q;
}

struct Edge {
    i32 a, b;
    i64 c;
};

int cmp_edge (const void *a, const void *b) {
    i64 d = ((Edge *)a)->c - ((Edge *)b)->c;
    return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
    i32 n, d;
    std::cin >> n >> d;
    std::vector<i32> a(n);
    std::vector<IndexVal> p(n);
    for (i32 i = 0; i < n; ++i) {
        std::cin >> a[i];
        p[i] = {i, a[i]};
    }
    std::sort(p.begin(), p.end(), cmp_index_val);
    const SegmentNode ini = {n, (i64)(n + 2) * 1000000000 + 1};
    SegmentTree *l = new_segment_tree(&ini, n, sizeof(SegmentNode), func_segment_node);
    SegmentTree *r = new_segment_tree(&ini, n, sizeof(SegmentNode), func_segment_node);
    for (i32 i = 0; i < n; ++i) {
        update_tmp(l, i, &((SegmentNode){i, a[i] + (i64)(n - 1 - i) * d}));
        update_tmp(r, i, &((SegmentNode){i, a[i] + (i64)i * d}));
    }
    update_all(l);
    update_all(r);
    BinaryHeap *h = new_binary_heap(sizeof(Edge), cmp_edge);
    for (i32 i = 0; i < n; ++i) {
        i32 v = p[i].index;
        if (v > 0) {
            SegmentNode t;
            find(l, 0, v, &t);
            push(h, &((Edge){v, t.index, p[i].val + t.val - (i64) (n - 1 - v) * d}));
        }
        if (v + 1 < n) {
            SegmentNode t;
            find(r, v + 1, n, &t);
            push(h, &((Edge){v, t.index, p[i].val + t.val - (i64) v * d}));
        }
        update(l, v, &ini);
        update(r, v, &ini);
    }
    i64 sum = 0;
    UnionFind *u = newUnionFind(n);
    while (getSize(u, 0) < n) {
        Edge e;
        pop(h, &e);
        if (same(u, e.a, e.b)) continue;
        unite(u, e.a, e.b);
        sum += e.c;
    }
    std::cout << sum << std::endl;
}

int main (void) {
    run();
    return 0;
}
