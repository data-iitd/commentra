#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <cinttypes>

// Define a structure for a binary heap
struct BinaryHeap {
    void *array; // Pointer to the array that holds the heap elements
    std::size_t heap_size; // Current number of elements in the heap
    std::size_t max_size; // Maximum capacity of the heap
    std::size_t val_size; // Size of each value in the heap
    int (*cmp) (const void *, const void *); // Comparison function for heap elements
};

// Function to create a new binary heap
BinaryHeap* new_binary_heap(const std::size_t val_size, int (*cmpF) (const void *, const void *)) {
    BinaryHeap *h = new BinaryHeap; // Allocate memory for the heap structure
    h->array = malloc(val_size * (1 + 1)); // Allocate memory for the heap array
    h->heap_size = 0; // Initialize heap size to 0
    h->max_size = 1; // Set initial maximum size
    h->val_size = val_size; // Set the value size
    h->cmp = cmpF; // Set the comparison function
    return h; // Return the created heap
}

// Function to get the current size of the heap
int32_t get_heap_size(const BinaryHeap *h) {
    return h->heap_size; // Return the current size of the heap
}

// Function to check if the heap is empty
bool is_empty(const BinaryHeap *h) {
    return h->heap_size == 0; // Return true if the heap is empty, otherwise false
}

// Function to free the memory allocated for the heap
void free_heap(BinaryHeap *h) {
    free(h->array); // Free the array holding the heap elements
    delete h; // Free the heap structure itself
}

// Function to initialize the heap
void init_heap(BinaryHeap *h) {
    h->heap_size = 0; // Set the heap size to 0
}

// Function to swap two elements in the heap
static void heap_func_swap(void * restrict a, void * restrict b, std::size_t val_size) {
    // Swap elements based on their size (optimized for 64-bit values)
    if ((val_size & 7) == 0) {
        uint64_t *p = (uint64_t *) a;
        uint64_t *q = (uint64_t *) b;
        val_size /= sizeof(uint64_t);
        while (val_size--) {
            uint64_t tmp = *p;
            *p++ = *q;
            *q++ = tmp;
        }
    } else {
        // Fallback for other sizes
        uint8_t *p = (uint8_t *) a;
        uint8_t *q = (uint8_t *) b;
        while (val_size--) {
            uint8_t tmp = *p;
            *p++ = *q;
            *q++ = tmp;
        }
    }
}

// Function to copy values from source to destination
static void heap_func_copy(void * restrict dst, const void * restrict src, std::size_t val_size) {
    // Copy elements based on their size (optimized for 64-bit values)
    if ((val_size & 7) == 0) {
        uint64_t *p = (uint64_t *) src;
        uint64_t *q = (uint64_t *) dst;
        val_size /= sizeof(uint64_t);
        while (val_size--) {
            *q++ = *p++;
        }
    } else {
        // Fallback for other sizes
        uint8_t *p = (uint8_t *) src;
        uint8_t *q = (uint8_t *) dst;
        while (val_size--) {
            *q++ = *p++;
        }
    }
}

// Function to push a new value into the heap
void push(BinaryHeap *h, const void *val) {
    // Check if the heap needs to be resized
    if (h->heap_size == h->max_size) {
        h->max_size = 2 * h->max_size + 1; // Double the max size
        h->array = realloc(h->array, h->val_size * (h->max_size + 1)); // Resize the array
    }
    h->heap_size++; // Increment the heap size
    uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
    std::size_t k = h->heap_size; // Current index for the new element
    const std::size_t val_size = h->val_size; // Size of the value
    int (*cmp) (const void *, const void *) = h->cmp; // Get the comparison function
    heap_func_copy(array + k * val_size, val, val_size); // Copy the new value into the heap
    // Maintain the heap property by moving the new element up the heap
    while (k > 1) {
        size_t parent = k / 2; // Calculate the parent index
        if (cmp(array + parent * val_size, array + k * val_size) <= 0) {
            return; // If the heap property is satisfied, exit
        }
        heap_func_swap(array + parent * val_size, array + k * val_size, val_size); // Swap with parent
        k = parent; // Move up to the parent
    }
}

// Function to pop the top value from the heap
void pop(BinaryHeap *h, void *res) {
    uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
    const std::size_t val_size = h->val_size; // Size of the value
    if (res != NULL) {
        heap_func_copy(res, array + val_size, val_size); // Copy the top value to the result
    }
    heap_func_copy(array + val_size, array + val_size * h->heap_size, val_size); // Move the last element to the top
    h->heap_size--; // Decrement the heap size
    int (* const cmp) (const void *, const void *) = h->cmp; // Get the comparison function
    const std::size_t n = h->heap_size; // Current size of the heap
    size_t k = 1; // Start from the root
    // Maintain the heap property by moving the top element down the heap
    while (2 * k + 1 <= n) {
        int c = cmp(array + val_size * 2 * k, array + val_size * (2 * k + 1)); // Compare children
        size_t next = 2 * k + (c <= 0 ? 0 : 1); // Choose the smaller child
        if (cmp(array + val_size * k, array + val_size * next) <= 0) return; // If heap property is satisfied, exit
        heap_func_swap(array + val_size * k, array + val_size * next, val_size); // Swap with the smaller child
        k = next; // Move down to the next level
    }
    // Check if the last child needs to be swapped
    if (2 * k <= n && cmp(array + val_size * k, array + val_size * 2 * k) > 0) {
        heap_func_swap(array + val_size * k, array + val_size * 2 * k, val_size);
    }
}

// Function to get the top value of the heap without removing it
void top(const BinaryHeap *h, void *res) {
    uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
    const std::size_t val_size = h->val_size; // Size of the value
    if (res != NULL) {
        heap_func_copy(res, array + val_size, val_size); // Copy the top value to the result
    }
}

// Define a structure for Union-Find (Disjoint Set Union)
struct UnionFind {
    std::vector<int32_t> parent; // Array to hold the parent of each element
    int32_t size; // Size of the Union-Find structure
};

// Function to initialize the Union-Find structure
void initUnionFind(UnionFind &u) {
    for (int32_t i = 0; i < u.size; ++i) {
        u.parent[i] = -1; // Set each element's parent to -1 (indicating it is its own root)
    }
}

// Function to create a new Union-Find structure
UnionFind* newUnionFind(const int32_t size) {
    UnionFind *u = new UnionFind; // Allocate memory for the structure
    u->parent.resize(size); // Allocate memory for the parent array
    u->size = size; // Set the size
    initUnionFind(*u); // Initialize the Union-Find structure
    return u; // Return the created structure
}

// Function to free the memory allocated for the Union-Find structure
void freeUnionFind(UnionFind *u) {
    delete u; // Free the Union-Find structure
}

// Function to find the root of an element with path compression
int32_t root(UnionFind *u, int32_t x) {
    std::vector<int32_t> index(32); // Array to hold the path for compression
    int32_t len = 0; // Length of the path
    while (u->parent[x] >= 0) {
        index[len++] = x; // Store the current index
        x = u->parent[x]; // Move to the parent
    }
    // Path compression: make all nodes point directly to the root
    while (len > 0) {
        u->parent[index[--len]] = x;
    }
    return x; // Return the root
}

// Function to check if two elements are in the same set
bool same(UnionFind *u, int32_t x, int32_t y) {
    return root(u, x) == root(u, y); // Return true if they have the same root, otherwise false
}

// Function to get the size of the set containing element x
int32_t getSize(UnionFind *u, int32_t x) {
    return -u->parent[root(u, x)]; // Return the size of the set
}

// Function to unite two sets containing elements x and y
void unite(UnionFind *u, int32_t x, int32_t y) {
    x = root(u, x); // Find the root of x
    y = root(u, y); // Find the root of y
    if (x == y) return; // If they are already in the same set, do nothing
    // Union by size: attach the smaller tree under the larger tree
    if (u->parent[x] > u->parent[y]) {
        int32_t swap = x; // Swap x and y if necessary
        x = y;
        y = swap;
    }
    u->parent[x] += u->parent[y]; // Update the size of the new root
    u->parent[y] = x; // Make x the parent of y
}

// Define a structure for a segment tree
struct SegmentTree {
    std::vector<void*> array; // Vector to hold the segment tree nodes
    int32_t size; // Size of the segment tree
    std::size_t val_size; // Size of each value in the segment tree
    void (*func) (void *, const void *, const void *); // Function to combine two values
};

// Function to copy memory from source to destination
static inline void segment_tree_memcpy(void *dst, const void *src, std::size_t size) {
    uint8_t *p = static_cast<uint8_t*>(dst); // Pointer to destination
    const uint8_t *q = static_cast<const uint8_t*>(src); // Pointer to source
    while (size--) {
        *p++ = *q++; // Copy byte by byte
    }
}

// Function to create a new segment tree
SegmentTree* new_segment_tree(const void *ini, const int32_t n, const std::size_t val_size, void (*func) (void *, const void *, const void *)) {
    int32_t k = 1; // Initialize k to 1
    while (k < n) k *= 2; // Find the next power of 2 greater than n
    SegmentTree *s = new SegmentTree; // Allocate memory for the segment tree
    s->array.resize(2 * k, nullptr); // Allocate memory for the segment tree array
    s->size = k; // Set the size of the segment tree
    s->val_size = val_size; // Set the value size
    s->func = func; // Set the function to combine values
    // Initialize the leaves of the segment tree
    for (int32_t i = k; i < 2 * k; ++i) {
        segment_tree_memcpy(s->array[i], ini, val_size);
    }
    // Build the segment tree by combining child nodes
    for (int32_t i = k - 1; i > 0; --i) {
        func(s->array[i], s->array[2 * i], s->array[2 * i + 1]);
    }
    return s; // Return the created segment tree
}

// Function to update a value in the segment tree
void update(SegmentTree * const s, int32_t k, const void *val) {
    k += s->size; // Move to the leaf position
    void *p = s->array[k]; // Pointer to the segment tree array
    const std::size_t size = s->val_size; // Size of the value
    segment_tree_memcpy(p, val, size); // Update the value at the leaf
    // Update the segment tree upwards
    for (k >>= 1; k > 0; k >>= 1) {
        s->func(s->array[k], s->array[2 * k], s->array[2 * k + 1]);
    }
}

// Function to update a value temporarily in the segment tree
void update_tmp(SegmentTree * const s, int32_t k, const void *val) {
    k += s->size; // Move to the leaf position
    void *p = s->array[k]; // Pointer to the segment tree array
    const std::size_t size = s->val_size; // Size of the value
    segment_tree_memcpy(p, val, size); // Update the value at the leaf
}

// Function to update all nodes in the segment tree
void update_all(SegmentTree * const s) {
    const std::size_t size = s->val_size; // Size of the value
    // Update the segment tree from the leaves to the root
    for (int32_t i = s->size - 1; i > 0; --i) {
        s->func(s->array[i], s->array[2 * i], s->array[2 * i + 1]);
    }
}

// Function to find the result in a range of the segment tree
void find(const SegmentTree *s, int32_t l, int32_t r, void *res) {
    std::vector<int32_t> lindex(32); // Array to hold left indices
    std::vector<int32_t> rindex(32); // Array to hold right indices
    int32_t llen = 0; // Length of left indices
    int32_t rlen = 0; // Length of right indices
    // Traverse the segment tree to find the indices
    for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
        if (l & 1) lindex[llen++] = l++; // If l is odd, include it and move to the next
        if (r & 1) rindex[rlen++] = --r; // If r is odd, include the previous and move left
    }
    const std::size_t size = s->val_size; // Size of the value
    if (llen == 0) {
        lindex[llen++] = rindex[--rlen]; // If no left indices, take from right
    }
    segment_tree_memcpy(res, s->array[lindex[0]], size); // Initialize result with the first left index
    // Combine results from left indices
    for (int32_t i = 1; i < llen; ++i) {
        s->func(res, res, s->array[lindex[i]]);
    }
    // Combine results from right indices
    for (int32_t i = rlen - 1; i >= 0; --i) {
        s->func(res, res, s->array[rindex[i]]);
    }
}

// Define integer types for convenience
typedef int32_t i32;
typedef int64_t i64;

// Define a structure for index-value pairs
struct IndexVal {
    i32 index; // Index of the value
    i32 val; // Value
};

// Comparison function for index-value pairs
int cmp_index_val(const void *a, const void *b) {
    i32 d = ((IndexVal *)a)->val - ((IndexVal *)b)->val; // Compare values
    return d == 0 ? 0 : d > 0 ? -1 : 1; // Return comparison result
}

// Define a structure for segment tree nodes
struct SegmentNode {
    i32 index; // Index of the node
    i64 val; // Value of the node
};

// Function to combine two segment nodes
void func_segment_node(void *c, const void *a, const void *b) {
    const SegmentNode *p = (const SegmentNode *)a; // First node
    const SegmentNode *q = (const SegmentNode *)b; // Second node
    *(SegmentNode *)c = p->val < q->val ? *p : *q; // Choose the node with the smaller value
}

// Define a structure for edges
struct Edge {
    i32 a, b; // Endpoints of the edge
    i64 c; // Cost of the edge
};

// Comparison function for edges
int cmp_edge(const void *a, const void *b) {
    i64 d = ((Edge *)a)->c - ((Edge *)b)->c; // Compare costs
    return d == 0 ? 0 : d < 0 ? -1 : 1; // Return comparison result
}

// Main function to run the algorithm
void run() {
    i32 n, d; // Number of elements and a parameter d
    std::cin >> n >> d; // Read n and d
    std::vector<i32> a(n); // Allocate array for values
    std::vector<IndexVal> p(n); // Allocate array for index-value pairs
    // Read values and initialize index-value pairs
    for (i32 i = 0; i < n; ++i) {
        std::cin >> a[i];
        p[i] = {i, a[i]};
    }
    std::qsort(p.data(), n, sizeof(IndexVal), cmp_index_val); // Sort index-value pairs by value
    const SegmentNode ini = {n, (i64)(n + 2) * 1000000000 + 1}; // Initialize segment node
    SegmentTree *l = new_segment_tree(&ini, n, sizeof(SegmentNode), func_segment_node); // Create left segment tree
    SegmentTree *r = new_segment_tree(&ini, n, sizeof(SegmentNode), func_segment_node); // Create right segment tree
    // Update segment trees with adjusted values
    for (i32 i = 0; i < n; ++i) {
        update_tmp(l, i, &((SegmentNode){i, a[i] + (i64)(n - 1 - i) * d}));
        update_tmp(r, i, &((SegmentNode){i, a[i] + (i64)i * d}));
    }
    update_all(l); // Update all nodes in the left segment tree
    update_all(r); // Update all nodes in the right segment tree
    BinaryHeap *h = new_binary_heap(sizeof(Edge), cmp_edge); // Create a new binary heap for edges
    // Process each index-value pair
    for (i32 i = 0; i < n; ++i) {
        i32 v = p[i].index; // Get the original index
        if (v > 0) {
            SegmentNode t; // Temporary segment node
            find(l, 0, v, &t); // Find the minimum in the left segment tree
            push(h, &((Edge){v, t.index, p[i].val + t.val - (i64) (n - 1 - v) * d})); // Push edge to heap
        }
        if (v + 1 < n) {
            SegmentNode t; // Temporary segment node
            find(r, v + 1, n, &t); // Find the minimum in the right segment tree
            push(h, &((Edge){v, t.index, p[i].val + t.val - (i64) v * d})); // Push edge to heap
        }
        update(l, v, &ini); // Update left segment tree
        update(r, v, &ini); // Update right segment tree
    }
    i64 sum = 0; // Initialize sum of costs
    UnionFind *u = newUnionFind(n); // Create a new Union-Find structure
    // Process edges in the heap to find the minimum spanning tree
    while (getSize(u, 0) < n) {
        Edge e; // Temporary edge
        pop(h, &e); // Pop the minimum edge from the heap
        if (same(u, e.a, e.b)) continue; // If they are already connected, skip
        unite(u, e.a, e.b); // Union the sets
        sum += e.c; // Add the cost of the edge to the sum
    }
    std::cout << sum << std::endl; // Print the total cost
}

// Main entry point of the program
int main() {
    run(); // Execute the run function
    return 0; // Return success
}
