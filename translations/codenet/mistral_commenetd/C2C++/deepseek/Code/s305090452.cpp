#include <iostream>
#include <vector>
#include <cstdint>
#include <cstring>

// Include necessary header files

class BinaryHeap {
public:
    BinaryHeap(size_t val_size, int (*cmpF) (const void *, const void *));
    ~BinaryHeap();
    void push(const void *val);
    void pop(void *res);
    void top(void *res) const;
    int getSize() const;
    bool isEmpty() const;

private:
    void* array;
    size_t heap_size;
    size_t max_size;
    size_t val_size;
    int (*cmp) (const void *, const void *);

    static void heapFuncSwap(void * restrict a, void * restrict b, size_t val_size);
    static void heapFuncCopy(void * restrict dst, const void * restrict src, size_t val_size);
};

BinaryHeap::BinaryHeap(size_t val_size, int (*cmpF) (const void *, const void *))
    : array(malloc(val_size * (1 + 1))), heap_size(0), max_size(1), val_size(val_size), cmp(cmpF) {
    // Allocate memory for heap array
}

BinaryHeap::~BinaryHeap() {
    free(array);
}

void BinaryHeap::push(const void *val) {
    if (heap_size == max_size) {
        max_size = 2 * max_size + 1;
        array = realloc(array, val_size * (max_size + 1));
    }
    heap_size++;
    uint8_t *array = static_cast<uint8_t*>(this->array);
    size_t k = heap_size;
    const size_t val_size = this->val_size;
    int (*cmp) (const void *, const void *) = this->cmp;
    heapFuncCopy(array + k * val_size, val, val_size);
    while (k > 1) {
        size_t parent = k / 2;
        if (cmp(array + parent * val_size, array + k * val_size) <= 0) {
            return;
        }
        heapFuncSwap(array + parent * val_size, array + k * val_size, val_size);
        k = parent;
    }
}

void BinaryHeap::pop(void *res) {
    uint8_t *array = static_cast<uint8_t*>(this->array);
    const size_t val_size = this->val_size;
    if (res != NULL) {
        heapFuncCopy(res, array + val_size, val_size);
    }
    heapFuncCopy(array + val_size, array + val_size * heap_size, val_size);
    heap_size--;
    int (* const cmp) (const void *, const void *) = this->cmp;
    const size_t n = heap_size;
    size_t k = 1;
    while (2 * k + 1 <= n) {
        int c = cmp(array + val_size * 2 * k, array + val_size * (2 * k + 1));
        size_t next = 2 * k + (c <= 0 ? 0 : 1);
        if (cmp(array + val_size * k, array + val_size * next) <= 0) return;
        heapFuncSwap(array + val_size * k, array + val_size * next, val_size);
        k = next;
    }
    if (2 * k <= n && cmp(array + val_size * k, array + val_size * 2 * k) > 0) {
        heapFuncSwap(array + val_size * k, array + val_size * 2 * k, val_size);
    }
}

void BinaryHeap::top(void *res) const {
    uint8_t *array = static_cast<uint8_t*>(this->array);
    const size_t val_size = this->val_size;
    if (res != NULL) {
        heapFuncCopy(res, array + val_size, val_size);
    }
}

int BinaryHeap::getSize() const {
    return heap_size;
}

bool BinaryHeap::isEmpty() const {
    return heap_size == 0;
}

void BinaryHeap::heapFuncSwap(void * restrict a, void * restrict b, size_t val_size) {
    if ((val_size & 7) == 0) {
        uint64_t *p = static_cast<uint64_t*>(a);
        uint64_t *q = static_cast<uint64_t*>(b);
        val_size /= sizeof(uint64_t);
        while (val_size--) {
            uint64_t tmp = *p;
            *p++ = *q;
            *q++ = tmp;
        }
    } else {
        uint8_t *p = static_cast<uint8_t*>(a);
        uint8_t *q = static_cast<uint8_t*>(b);
        while (val_size--) {
            uint8_t tmp = *p;
            *p++ = *q;
            *q++ = tmp;
        }
    }
}

void BinaryHeap::heapFuncCopy(void * restrict dst, const void * restrict src, size_t val_size) {
    if ((val_size & 7) == 0) {
        uint64_t *p = static_cast<uint64_t*>(const_cast<void*>(src));
        uint64_t *q = static_cast<uint64_t*>(dst);
        val_size /= sizeof(uint64_t);
        while (val_size--) {
            *q++ = *p++;
        }
    } else {
        uint8_t *p = static_cast<uint8_t*>(const_cast<void*>(src));
        uint8_t *q = static_cast<uint8_t*>(dst);
        while (val_size--) {
            *q++ = *p++;
        }
    }
}

// Define a structure for Union-Find data structure

class UnionFind {
public:
    UnionFind(int32_t size);
    ~UnionFind();
    void init();
    int32_t root(int32_t x);
    bool same(int32_t x, int32_t y);
    int32_t getSize(int32_t x);
    void unite(int32_t x, int32_t y);

private:
    int32_t* parent;
    int32_t size;
};

UnionFind::UnionFind(int32_t size) : parent(new int32_t[size]), size(size) {
    init();
}

UnionFind::~UnionFind() {
    delete[] parent;
}

void UnionFind::init() {
    for (int32_t i = 0; i < size; ++i) {
        parent[i] = -1;
    }
}

int32_t UnionFind::root(int32_t x) {
    int32_t index[32];
    int32_t len = 0;
    while (parent[x] >= 0) {
        index[len++] = x;
        x = parent[x];
    }
    while (len > 0) {
        parent[index[--len]] = x;
    }
    return x;
}

bool UnionFind::same(int32_t x, int32_t y) {
    return root(x) == root(y);
}

int32_t UnionFind::getSize(int32_t x) {
    return -parent[root(x)];
}

void UnionFind::unite(int32_t x, int32_t y) {
    x = root(x);
    y = root(y);
    if (x == y) return;
    if (parent[x] > parent[y]) {
        int32_t swap = x;
        x = y;
        y = swap;
    }
    parent[x] += parent[y];
    parent[y] = x;
}

// Define a structure for segment tree

template<typename T, typename Func>
class SegmentTree {
public:
    SegmentTree(const T* ini, int32_t n, size_t val_size, Func func);
    ~SegmentTree();
    void update(int32_t k, const T* val);
    void updateAll();
    void find(int32_t l, int32_t r, T* res) const;

private:
    T* array;
    int32_t size;
    size_t val_size;
    Func func;

    static inline void segmentTreeMemcpy(void* dst, const void* src, size_t size);
};

template<typename T, typename Func>
SegmentTree<T, Func>::SegmentTree(const T* ini, int32_t n, size_t val_size, Func func)
    : val_size(val_size), func(func) {
    int32_t k = 1;
    while (k < n) k *= 2;
    array = new T[2 * k];
    size = k;
    std::memcpy(array + k, ini, n * val_size);
    for (int32_t i = k; i < 2 * k; ++i) {
        segmentTreeMemcpy(array + i, array + i, val_size);
    }
    for (int32_t i = k - 1; i > 0; --i) {
        func(array + i, array + 2 * i, array + 2 * i + 1);
    }
}

template<typename T, typename Func>
SegmentTree<T, Func>::~SegmentTree() {
    delete[] array;
}

template<typename T, typename Func>
void SegmentTree<T, Func>::update(int32_t k, const T* val) {
    k += size;
    T* p = array;
    const size_t size = this->val_size;
    segmentTreeMemcpy(p + k, val, size);
    for (k >>= 1; k > 0; k >>= 1) {
        func(p + k, p + 2 * k, p + 2 * k + 1);
    }
}

template<typename T, typename Func>
void SegmentTree<T, Func>::updateAll() {
    T* const a = array;
    const size_t size = this->val_size;
    for (int32_t i = size - 1; i > 0; --i) {
        func(a + i, a + 2 * i, a + 2 * i + 1);
    }
}

template<typename T, typename Func>
void SegmentTree<T, Func>::find(int32_t l, int32_t r, T* res) const {
    int32_t lindex[32];
    int32_t rindex[32];
    int32_t llen = 0;
    int32_t rlen = 0;
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
        if (l & 1) lindex[llen++] = l++;
        if (r & 1) rindex[rlen++] = --r;
    }
    const uint8_t* p = reinterpret_cast<const uint8_t*>(array);
    if (llen == 0) {
        lindex[llen++] = rindex[--rlen];
    }
    segmentTreeMemcpy(res, p + lindex[0] * val_size, val_size);
    for (int32_t i = 1; i < llen; ++i) {
        func(res, res, p + lindex[i] * val_size);
    }
    for (int32_t i = rlen - 1; i >= 0; --i) {
        func(res, res, p + rindex[i] * val_size);
    }
}

template<typename T, typename Func>
inline void SegmentTree<T, Func>::segmentTreeMemcpy(void* dst, const void* src, size_t size) {
    uint8_t* p = static_cast<uint8_t*>(dst);
    const uint8_t* q = static_cast<const uint8_t*>(src);
    while (size--) {
        *p++ = *q++;
    }
}

// Define a structure for index_val

struct IndexVal {
    int32_t index;
    int32_t val;
};

int cmpIndexVal(const void* a, const void* b) {
    int32_t d = ((IndexVal*)a)->val - ((IndexVal*)b)->val;
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

// Define a structure for segment_node

struct SegmentNode {
    int32_t index;
    int64_t val;
};

void funcSegmentNode(void* c, const void* a, const void* b) {
    const SegmentNode* p = (const SegmentNode*)a;
    const SegmentNode* q = (const SegmentNode*)b;
    *(SegmentNode*)c = p->val < q->val ? *p : *q;
}

// Define a structure for edge

struct Edge {
    int32_t a, b;
    int64_t c;
};

int cmpEdge(const void* a, const void* b) {
    int64_t d = ((Edge*)a)->c - ((Edge*)b)->c;
    return d == 0 ? 0 : d < 0 ? -1 : 1;
}

// Implementation of various helper functions

void run() {
    int32_t n, d;
    std::cin >> n >> d;
    int32_t* a = new int32_t[n];
    IndexVal* p = new IndexVal[n];
    for (int32_t i = 0; i < n; ++i) {
        std::cin >> a[i];
        p[i] = {i, a[i]};
    }
    qsort(p, n, sizeof(IndexVal), cmpIndexVal);
    const SegmentNode ini = {n, (int64_t)(n + 2) * 1000000000 + 1};
    SegmentTree<SegmentNode, void(*)(void*, const void*, const void*)> l(