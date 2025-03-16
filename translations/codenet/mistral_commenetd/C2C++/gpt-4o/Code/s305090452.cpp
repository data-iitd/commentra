#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

// Define a structure for binary heap
template<typename T>
class BinaryHeap {
public:
    BinaryHeap(size_t val_size, function<int(const T&, const T&)> cmpF) 
        : heap_size(0), max_size(1), val_size(val_size), cmp(cmpF) {
        array = malloc(val_size * (max_size + 1));
    }

    ~BinaryHeap() {
        free(array);
    }

    int32_t get_heap_size() const {
        return heap_size;
    }

    bool is_empty() const {
        return heap_size == 0;
    }

    void push(const T& val) {
        if (heap_size == max_size) {
            max_size = 2 * max_size + 1;
            array = realloc(array, val_size * (max_size + 1));
        }
        heap_size++;
        uint8_t* arr = static_cast<uint8_t*>(array);
        size_t k = heap_size;
        memcpy(arr + k * val_size, &val, val_size);
        while (k > 1) {
            size_t parent = k / 2;
            if (cmp(*(T*)(arr + parent * val_size), *(T*)(arr + k * val_size)) <= 0) {
                return;
            }
            swap(arr + parent * val_size, arr + k * val_size);
            k = parent;
        }
    }

    void pop(T& res) {
        uint8_t* arr = static_cast<uint8_t*>(array);
        if (!is_empty()) {
            memcpy(&res, arr + val_size, val_size);
            memcpy(arr + val_size, arr + val_size * heap_size, val_size);
            heap_size--;
            int n = heap_size;
            size_t k = 1;
            while (2 * k + 1 <= n) {
                int c = cmp(*(T*)(arr + val_size * 2 * k), *(T*)(arr + val_size * (2 * k + 1)));
                size_t next = 2 * k + (c <= 0 ? 0 : 1);
                if (cmp(*(T*)(arr + val_size * k), *(T*)(arr + val_size * next)) <= 0) return;
                swap(arr + val_size * k, arr + val_size * next);
                k = next;
            }
            if (2 * k <= n && cmp(*(T*)(arr + val_size * k), *(T*)(arr + val_size * 2 * k)) > 0) {
                swap(arr + val_size * k, arr + val_size * 2 * k);
            }
        }
    }

    void top(T& res) const {
        uint8_t* arr = static_cast<uint8_t*>(array);
        if (!is_empty()) {
            memcpy(&res, arr + val_size, val_size);
        }
    }

private:
    void* array;
    size_t heap_size;
    size_t max_size;
    size_t val_size;
    function<int(const T&, const T&)> cmp;

    void swap(void* a, void* b) {
        uint8_t* p = static_cast<uint8_t*>(a);
        uint8_t* q = static_cast<uint8_t*>(b);
        for (size_t i = 0; i < val_size; ++i) {
            std::swap(p[i], q[i]);
        }
    }
};

// Define a structure for Union-Find data structure
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
            swap(x, y);
        }
        parent[x] += parent[y];
        parent[y] = x;
    }

private:
    int32_t* parent;
    int32_t size;

    void initUnionFind() {
        for (int32_t i = 0; i < size; ++i) {
            parent[i] = -1;
        }
    }
};

// Define a structure for segment tree
template<typename T>
class SegmentTree {
public:
    SegmentTree(const T& ini, int32_t n, function<void(T&, const T&, const T&)> func) 
        : size(1), func(func) {
        while (size < n) size *= 2;
        array = new T[2 * size];
        for (int32_t i = size; i < 2 * size; ++i) {
            array[i] = ini;
        }
        for (int32_t i = size - 1; i > 0; --i) {
            func(array[i], array[2 * i], array[2 * i + 1]);
        }
    }

    ~SegmentTree() {
        delete[] array;
    }

    void update(int32_t k, const T& val) {
        k += size;
        array[k] = val;
        for (k >>= 1; k > 0; k >>= 1) {
            func(array[k], array[2 * k], array[2 * k + 1]);
        }
    }

    void find(int32_t l, int32_t r, T& res) const {
        int32_t lindex[32], rindex[32];
        int32_t llen = 0, rlen = 0;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lindex[llen++] = l++;
            if (r & 1) rindex[rlen++] = --r;
        }
        if (llen == 0) {
            lindex[llen++] = rindex[--rlen];
        }
        res = array[lindex[0]];
        for (int32_t i = 1; i < llen; ++i) {
            func(res, res, array[lindex[i]]);
        }
        for (int32_t i = rlen - 1; i >= 0; --i) {
            func(res, res, array[rindex[i]]);
        }
    }

private:
    T* array;
    int32_t size;
    function<void(T&, const T&, const T&)> func;
};

// Define structures for various data types
struct IndexVal {
    int32_t index;
    int32_t val;
};

bool cmp_index_val(const IndexVal& a, const IndexVal& b) {
    return a.val > b.val;
}

struct SegmentNode {
    int32_t index;
    int64_t val;
};

void func_segment_node(SegmentNode& c, const SegmentNode& a, const SegmentNode& b) {
    c = a.val < b.val ? a : b;
}

struct Edge {
    int32_t a, b;
    int64_t c;
};

bool cmp_edge(const Edge& a, const Edge& b) {
    return a.c < b.c;
}

// Main function to run the algorithm
void run() {
    int32_t n, d;
    cin >> n >> d;
    vector<int32_t> a(n);
    vector<IndexVal> p(n);
    for (int32_t i = 0; i < n; ++i) {
        cin >> a[i];
        p[i] = {i, a[i]};
    }
    sort(p.begin(), p.end(), cmp_index_val);
    SegmentNode ini = {n, (int64_t)(n + 2) * 1000000000 + 1};
    SegmentTree<SegmentNode> l(ini, n, func_segment_node);
    SegmentTree<SegmentNode> r(ini, n, func_segment_node);
    for (int32_t i = 0; i < n; ++i) {
        l.update(i, {i, a[i] + (int64_t)(n - 1 - i) * d});
        r.update(i, {i, a[i] + (int64_t)i * d});
    }
    Edge edge;
    BinaryHeap<Edge> h(sizeof(Edge), cmp_edge);
    for (int32_t i = 0; i < n; ++i) {
        int32_t v = p[i].index;
        if (v > 0) {
            SegmentNode t;
            l.find(0, v, t);
            edge = {v, t.index, p[i].val + t.val};
            h.push(edge);
        }
    }
}

// Entry point
int main() {
    run();
    return 0;
}

// <END-OF-CODE>
