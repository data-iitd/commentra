#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <memory>

// Define the structure of a binary heap and its operations.
template<typename T>
class BinaryHeap {
public:
    BinaryHeap(size_t val_size, int (*cmpF)(const T*, const T*)) 
        : heap_size(0), max_size(1), val_size(val_size), cmp(cmpF) {
        array = malloc(val_size * (max_size + 1));
    }

    ~BinaryHeap() {
        free(array);
    }

    void push(const T* val) {
        if (heap_size == max_size) {
            max_size = 2 * max_size + 1;
            array = realloc(array, val_size * (max_size + 1));
        }
        heap_size++;
        uint8_t* arr = static_cast<uint8_t*>(array);
        size_t k = heap_size;
        heap_func_copy(arr + k * val_size, val, val_size);
        while (k > 1) {
            size_t parent = k / 2;
            if (cmp(arr + parent * val_size, arr + k * val_size) <= 0) {
                return;
            }
            heap_func_swap(arr + parent * val_size, arr + k * val_size, val_size);
            k = parent;
        }
    }

    void pop(T* res) {
        uint8_t* arr = static_cast<uint8_t*>(array);
        if (res != nullptr) {
            heap_func_copy(res, arr + val_size, val_size);
        }
        heap_func_copy(arr + val_size, arr + val_size * heap_size, val_size);
        heap_size--;
        const size_t n = heap_size;
        size_t k = 1;
        while (2 * k + 1 <= n) {
            int c = cmp(arr + val_size * 2 * k, arr + val_size * (2 * k + 1));
            size_t next = 2 * k + (c <= 0 ? 0 : 1);
            if (cmp(arr + val_size * k, arr + val_size * next) <= 0) return;
            heap_func_swap(arr + val_size * k, arr + val_size * next, val_size);
            k = next;
        }
        if (2 * k <= n && cmp(arr + val_size * k, arr + val_size * 2 * k) > 0) {
            heap_func_swap(arr + val_size * k, arr + val_size * 2 * k, val_size);
        }
    }

    void top(T* res) const {
        uint8_t* arr = static_cast<uint8_t*>(array);
        if (res != nullptr) {
            heap_func_copy(res, arr + val_size, val_size);
        }
    }

    int32_t get_heap_size() const {
        return heap_size;
    }

    bool is_empty() const {
        return heap_size == 0;
    }

private:
    void* array;
    size_t heap_size;
    size_t max_size;
    size_t val_size;
    int (*cmp)(const T*, const T*);

    static void heap_func_swap(void* a, void* b, size_t val_size) {
        uint8_t* p = static_cast<uint8_t*>(a);
        uint8_t* q = static_cast<uint8_t*>(b);
        for (size_t i = 0; i < val_size; ++i) {
            std::swap(p[i], q[i]);
        }
    }

    static void heap_func_copy(void* dst, const void* src, size_t val_size) {
        std::memcpy(dst, src, val_size);
    }
};

// Define the structure of Union-Find and its operations.
class UnionFind {
public:
    UnionFind(int32_t size) : size(size) {
        parent = new int32_t[size];
        initUnionFind();
    }

    ~UnionFind() {
        delete[] parent;
    }

    int32_t root(int32_t x) {
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

    bool same(int32_t x, int32_t y) {
        return root(x) == root(y);
    }

    int32_t getSize(int32_t x) {
        return -parent[root(x)];
    }

    void unite(int32_t x, int32_t y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (parent[x] > parent[y]) {
            std::swap(x, y);
        }
        parent[x] += parent[y];
        parent[y] = x;
    }

private:
    int32_t* parent;
    int32_t size;

    void initUnionFind() {
        std::fill(parent, parent + size, -1);
    }
};

// Define the structure of a segment tree and its operations.
template<typename T>
class SegmentTree {
public:
    SegmentTree(const T* ini, int32_t n, void (*func)(T*, const T*, const T*)) 
        : size(1), func(func) {
        while (size < n) size *= 2;
        array = new T[2 * size];
        std::memcpy(array + size, ini, sizeof(T) * n);
        for (int32_t i = size - 1; i > 0; --i) {
            func(array + i, array + (2 * i), array + (2 * i + 1));
        }
    }

    ~SegmentTree() {
        delete[] array;
    }

    void update(int32_t k, const T* val) {
        k += size;
        std::memcpy(array + k, val, sizeof(T));
        for (k >>= 1; k > 0; k >>= 1) {
            func(array + k, array + (2 * k), array + (2 * k + 1));
        }
    }

    void find(int32_t l, int32_t r, T* res) const {
        int32_t lindex[32];
        int32_t rindex[32];
        int32_t llen = 0;
        int32_t rlen = 0;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lindex[llen++] = l++;
            if (r & 1) rindex[rlen++] = --r;
        }
        if (llen == 0) {
            lindex[llen++] = rindex[--rlen];
        }
        std::memcpy(res, array + lindex[0], sizeof(T));
        for (int32_t i = 1; i < llen; ++i) {
            func(res, res, array + lindex[i]);
        }
        for (int32_t i = rlen - 1; i >= 0; --i) {
            func(res, res, array + rindex[i]);
        }
    }

private:
    T* array;
    int32_t size;
    void (*func)(T*, const T*, const T*);
};

// Define the main function to run the program.
typedef int32_t i32;
typedef int64_t i64;

struct IndexVal {
    i32 index;
    i32 val;
};

int cmp_index_val(const IndexVal* a, const IndexVal* b) {
    i32 d = a->val - b->val;
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

struct SegmentNode {
    i32 index;
    i64 val;
};

void func_segment_node(SegmentNode* c, const SegmentNode* a, const SegmentNode* b) {
    *c = a->val < b->val ? *a : *b;
}

struct Edge {
    i32 a, b;
    i64 c;
};

int cmp_edge(const Edge* a, const Edge* b) {
    i64 d = a->c - b->c;
    return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run() {
    i32 n, d;
    std::cin >> n >> d;
    std::vector<i32> a(n);
    std::vector<IndexVal> p(n);
    for (i32 i = 0; i < n; ++i) {
        std::cin >> a[i];
        p[i] = {i, a[i]};
    }
    std::sort(p.begin(), p.end(), [](const IndexVal& a, const IndexVal& b) {
        return cmp_index_val(&a, &b) < 0;
    });
    SegmentNode ini = {n, (i64)(n + 2) * 1000000000 + 1};
    SegmentTree<SegmentNode> l(&ini, n, func_segment_node);
    SegmentTree<SegmentNode> r(&ini, n, func_segment_node);
    for (i32 i = 0; i < n; ++i) {
        l.update(i, &(SegmentNode){i, a[i] + (i64)(n - 1 - i) * d});
        r.update(i, &(SegmentNode){i, a[i] + (i64)i * d});
    }
    BinaryHeap<Edge> h(sizeof(Edge), cmp_edge);
    for (i32 i = 0; i < n; ++i) {
        i32 v = p[i].index;
        if (v > 0) {
            SegmentNode t;
            l.find(0, v, &t);
            h.push(&(Edge){v, t.index, p[i].val + t.val - (i64)(n - 1 - v) * d});
        }
        if (v + 1 < n) {
            SegmentNode t;
            r.find(v + 1, n, &t);
            h.push(&(Edge){v, t.index, p[i].val + t.val - (i64)v * d});
        }
        l.update(v, &ini);
        r.update(v, &ini);
    }
    i64 sum = 0;
    UnionFind u(n);
    while (u.getSize(0) < n) {
        Edge e;
        h.pop(&e);
        if (u.same(e.a, e.b)) continue;
        u.unite(e.a, e.b);
        sum += e.c;
    }
    std::cout << sum << std::endl;
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
