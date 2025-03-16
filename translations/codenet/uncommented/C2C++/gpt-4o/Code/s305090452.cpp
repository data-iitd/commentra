#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <cstring>

using namespace std;

struct BinaryHeap {
    void *array;
    size_t heap_size;
    size_t max_size;
    size_t val_size;
    int (*cmp)(const void *, const void *);

    BinaryHeap(size_t val_size, int (*cmpF)(const void *, const void *)) {
        this->array = malloc(val_size * (1 + 1));
        this->heap_size = 0;
        this->max_size = 1;
        this->val_size = val_size;
        this->cmp = cmpF;
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

    void push(const void *val) {
        if (heap_size == max_size) {
            max_size = 2 * max_size + 1;
            array = realloc(array, val_size * (max_size + 1));
        }
        heap_size++;
        uint8_t *arr = (uint8_t *)array;
        size_t k = heap_size;
        const size_t val_size = this->val_size;
        int (*cmp)(const void *, const void *) = this->cmp;
        memcpy(arr + k * val_size, val, val_size);
        while (k > 1) {
            size_t parent = k / 2;
            if (cmp(arr + parent * val_size, arr + k * val_size) <= 0) {
                return;
            }
            swap(arr + parent * val_size, arr + k * val_size, val_size);
            k = parent;
        }
    }

    void pop(void *res) {
        uint8_t *arr = (uint8_t *)array;
        const size_t val_size = this->val_size;
        if (res != nullptr) {
            memcpy(res, arr + val_size, val_size);
        }
        memcpy(arr + val_size, arr + val_size * heap_size, val_size);
        heap_size--;
        int (*const cmp)(const void *, const void *) = this->cmp;
        const size_t n = heap_size;
        size_t k = 1;
        while (2 * k + 1 <= n) {
            int c = cmp(arr + val_size * 2 * k, arr + val_size * (2 * k + 1));
            size_t next = 2 * k + (c <= 0 ? 0 : 1);
            if (cmp(arr + val_size * k, arr + val_size * next) <= 0) return;
            swap(arr + val_size * k, arr + val_size * next, val_size);
            k = next;
        }
        if (2 * k <= n && cmp(arr + val_size * k, arr + val_size * 2 * k) > 0) {
            swap(arr + val_size * k, arr + val_size * 2 * k, val_size);
        }
    }

    void top(const void *res) const {
        uint8_t *arr = (uint8_t *)array;
        const size_t val_size = this->val_size;
        if (res != nullptr) {
            memcpy(res, arr + val_size, val_size);
        }
    }

private:
    void swap(void *a, void *b, size_t val_size) {
        uint8_t *p = (uint8_t *)a;
        uint8_t *q = (uint8_t *)b;
        while (val_size--) {
            uint8_t tmp = *p;
            *p++ = *q;
            *q++ = tmp;
        }
    }
};

struct UnionFind {
    vector<int32_t> parent;
    int32_t size;

    UnionFind(int32_t size) : size(size) {
        parent.resize(size, -1);
    }

    int32_t root(int32_t x) {
        vector<int32_t> index(32);
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
};

struct SegmentTree {
    void *array;
    int32_t size;
    size_t val_size;
    void (*func)(void *, const void *, const void *);

    SegmentTree(const void *ini, int32_t n, size_t val_size, void (*func)(void *, const void *, const void *)) {
        int32_t k = 1;
        while (k < n) k *= 2;
        this->array = calloc(2 * k, val_size);
        this->size = k;
        this->val_size = val_size;
        this->func = func;
        for (int32_t i = k; i < 2 * k; ++i) {
            memcpy((uint8_t *)this->array + i * val_size, ini, val_size);
        }
        uint8_t *a = (uint8_t *)this->array;
        for (int32_t i = k - 1; i > 0; --i) {
            func(a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size);
        }
    }

    ~SegmentTree() {
        free(array);
    }

    void update(int32_t k, const void *val) {
        k += size;
        uint8_t *p = (uint8_t *)array;
        const size_t size = val_size;
        memcpy(p + k * size, val, size);
        for (k >>= 1; k > 0; k >>= 1) {
            func(p + k * size, p + 2 * k * size, p + (2 * k + 1) * size);
        }
    }

    void find(int32_t l, int32_t r, void *res) const {
        int32_t lindex[32];
        int32_t rindex[32];
        int32_t llen = 0;
        int32_t rlen = 0;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lindex[llen++] = l++;
            if (r & 1) rindex[rlen++] = --r;
        }
        const uint8_t *p = (const uint8_t *)array;
        if (llen == 0) {
            lindex[llen++] = rindex[--rlen];
        }
        memcpy(res, p + lindex[0] * val_size, val_size);
        for (int32_t i = 1; i < llen; ++i) {
            func(res, res, p + lindex[i] * val_size);
        }
        for (int32_t i = rlen - 1; i >= 0; --i) {
            func(res, res, p + rindex[i] * val_size);
        }
    }
};

struct IndexVal {
    int32_t index;
    int32_t val;
};

int cmp_index_val(const void *a, const void *b) {
    int32_t d = ((IndexVal *)a)->val - ((IndexVal *)b)->val;
    return d == 0 ? 0 : d > 0 ? -1 : 1;
}

struct SegmentNode {
    int32_t index;
    int64_t val;
};

void func_segment_node(void *c, const void *a, const void *b) {
    const SegmentNode *p = (const SegmentNode *)a;
    const SegmentNode *q = (const SegmentNode *)b;
    *(SegmentNode *)c = p->val < q->val ? *p : *q;
}

struct Edge {
    int32_t a, b;
    int64_t c;
};

int cmp_edge(const void *a, const void *b) {
    int64_t d = ((Edge *)a)->c - ((Edge *)b)->c;
    return d == 0 ? 0 : d < 0 ? -1 : 1;
}

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
    SegmentTree l(&ini, n, sizeof(SegmentNode), func_segment_node);
    SegmentTree r(&ini, n, sizeof(SegmentNode), func_segment_node);
    for (int32_t i = 0; i < n; ++i) {
        SegmentNode node = {i, a[i] + (int64_t)(n - 1 - i) * d};
        l.update(i, &node);
        node = {i, a[i] + (int64_t)i * d};
        r.update(i, &node);
    }
    Edge edge;
    BinaryHeap h(sizeof(Edge), cmp_edge);
    for (int32_t i = 0; i < n; ++i) {
        int32_t v = p[i].index;
        if (v > 0) {
            SegmentNode t;
            l.find(0, v, &t);
            edge = {v, t.index, p[i].val + t.val - (int64_t)(n - 1 - v) * d};
            h.push(&edge);
        }
        if (v + 1 < n) {
            SegmentNode t;
            r.find(v + 1, n, &t);
            edge = {v, t.index, p[i].val + t.val - (int64_t)v * d};
            h.push(&edge);
        }
        l.update(v, &ini);
        r.update(v, &ini);
    }
    int64_t sum = 0;
    UnionFind u(n);
    while (u.getSize(0) < n) {
        h.pop(&edge);
        if (u.same(edge.a, edge.b)) continue;
        u.unite(edge.a, edge.b);
        sum += edge.c;
    }
    cout << sum << endl;
}

int main() {
    run();
    return 0;
}

// <END-OF-CODE>
