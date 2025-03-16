#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include <cstring>
#include <cstdio>

// Define a structure for a binary heap
struct BinaryHeap {
    void *array; // Pointer to the array that holds the heap elements
    size_t heap_size; // Current number of elements in the heap
    size_t max_size; // Maximum capacity of the heap
    size_t val_size; // Size of each value in the heap
    int (*cmp)(const void *, const void *); // Comparison function for heap elements

    BinaryHeap(size_t val_size, int (*cmpF)(const void *, const void *)) 
        : heap_size(0), max_size(1), val_size(val_size), cmp(cmpF) {
        array = malloc(val_size * (max_size + 1)); // Allocate memory for the heap array
    }

    ~BinaryHeap() {
        free(array); // Free the array holding the heap elements
    }

    // Function to push a new value into the heap
    void push(const void *val) {
        // Check if the heap needs to be resized
        if (heap_size == max_size) {
            max_size = 2 * max_size + 1; // Double the max size
            array = realloc(array, val_size * (max_size + 1)); // Resize the array
        }
        heap_size++; // Increment the heap size
        uint8_t *arr = static_cast<uint8_t *>(array); // Cast array to uint8_t pointer for byte-wise access
        size_t k = heap_size; // Current index for the new element
        heap_func_copy(arr + k * val_size, val, val_size); // Copy the new value into the heap
        // Maintain the heap property by moving the new element up the heap
        while (k > 1) {
            size_t parent = k / 2; // Calculate the parent index
            if (cmp(arr + parent * val_size, arr + k * val_size) <= 0) {
                return; // If the heap property is satisfied, exit
            }
            heap_func_swap(arr + parent * val_size, arr + k * val_size, val_size); // Swap with parent
            k = parent; // Move up to the parent
        }
    }

    // Function to pop the top value from the heap
    void pop(void *res) {
        uint8_t *arr = static_cast<uint8_t *>(array); // Cast array to uint8_t pointer for byte-wise access
        if (res != nullptr) {
            heap_func_copy(res, arr + val_size, val_size); // Copy the top value to the result
        }
        heap_func_copy(arr + val_size, arr + val_size * heap_size, val_size); // Move the last element to the top
        heap_size--; // Decrement the heap size
        const size_t n = heap_size; // Current size of the heap
        size_t k = 1; // Start from the root
        // Maintain the heap property by moving the top element down the heap
        while (2 * k + 1 <= n) {
            int c = cmp(arr + val_size * 2 * k, arr + val_size * (2 * k + 1)); // Compare children
            size_t next = 2 * k + (c <= 0 ? 0 : 1); // Choose the smaller child
            if (cmp(arr + val_size * k, arr + val_size * next) <= 0) return; // If heap property is satisfied, exit
            heap_func_swap(arr + val_size * k, arr + val_size * next, val_size); // Swap with the smaller child
            k = next; // Move down to the next level
        }
        // Check if the last child needs to be swapped
        if (2 * k <= n && cmp(arr + val_size * k, arr + val_size * 2 * k) > 0) {
            heap_func_swap(arr + val_size * k, arr + val_size * 2 * k, val_size);
        }
    }

    // Function to get the top value of the heap without removing it
    void top(void *res) const {
        uint8_t *arr = static_cast<uint8_t *>(array); // Cast array to uint8_t pointer for byte-wise access
        if (res != nullptr) {
            heap_func_copy(res, arr + val_size, val_size); // Copy the top value to the result
        }
    }

private:
    // Function to swap two elements in the heap
    static void heap_func_swap(void * restrict a, void * restrict b, size_t val_size) {
        // Swap elements based on their size (optimized for 64-bit values)
        if ((val_size & 7) == 0) {
            uint64_t *p = static_cast<uint64_t *>(a);
            uint64_t *q = static_cast<uint64_t *>(b);
            val_size /= sizeof(uint64_t);
            while (val_size--) {
                uint64_t tmp = *p;
                *p++ = *q;
                *q++ = tmp;
            }
        } else {
            // Fallback for other sizes
            uint8_t *p = static_cast<uint8_t *>(a);
            uint8_t *q = static_cast<uint8_t *>(b);
            while (val_size--) {
                uint8_t tmp = *p;
                *p++ = *q;
                *q++ = tmp;
            }
        }
    }

    // Function to copy values from source to destination
    static void heap_func_copy(void * restrict dst, const void * restrict src, size_t val_size) {
        // Copy elements based on their size (optimized for 64-bit values)
        if ((val_size & 7) == 0) {
            uint64_t *p = static_cast<uint64_t *>(src);
            uint64_t *q = static_cast<uint64_t *>(dst);
            val_size /= sizeof(uint64_t);
            while (val_size--) {
                *q++ = *p++;
            }
        } else {
            // Fallback for other sizes
            uint8_t *p = static_cast<uint8_t *>(src);
            uint8_t *q = static_cast<uint8_t *>(dst);
            while (val_size--) {
                *q++ = *p++;
            }
        }
    }
};

// Define a structure for Union-Find (Disjoint Set Union)
struct UnionFind {
    std::vector<int32_t> parent; // Array to hold the parent of each element

    UnionFind(int32_t size) : parent(size, -1) {} // Initialize with -1

    // Function to find the root of an element with path compression
    int32_t root(int32_t x) {
        std::vector<int32_t> index(32); // Array to hold the path for compression
        int32_t len = 0; // Length of the path
        while (parent[x] >= 0) {
            index[len++] = x; // Store the current index
            x = parent[x]; // Move to the parent
        }
        // Path compression: make all nodes point directly to the root
        while (len > 0) {
            parent[index[--len]] = x;
        }
        return x; // Return the root
    }

    // Function to check if two elements are in the same set
    bool same(int32_t x, int32_t y) {
        return root(x) == root(y); // Return true if they have the same root, otherwise false
    }

    // Function to unite two sets containing elements x and y
    void unite(int32_t x, int32_t y) {
        x = root(x); // Find the root of x
        y = root(y); // Find the root of y
        if (x == y) return; // If they are already in the same set, do nothing
        // Union by size: attach the smaller tree under the larger tree
        if (parent[x] > parent[y]) {
            std::swap(x, y);
        }
        parent[x] += parent[y]; // Update the size of the new root
        parent[y] = x; // Make x the parent of y
    }

    // Function to get the size of the set containing element x
    int32_t getSize(int32_t x) {
        return -parent[root(x)]; // Return the size of the set
    }
};

// Define a structure for a segment tree
struct SegmentTree {
    void *array; // Pointer to the array that holds the segment tree nodes
    int32_t size; // Size of the segment tree
    size_t val_size; // Size of each value in the segment tree
    void (*func)(void *, const void *, const void *); // Function to combine two values

    SegmentTree(const void *ini, int32_t n, size_t val_size, void (*func)(void *, const void *, const void *)) 
        : val_size(val_size), func(func) {
        int32_t k = 1; // Initialize k to 1
        while (k < n) k *= 2; // Find the next power of 2 greater than n
        array = calloc(2 * k, val_size); // Allocate memory for the segment tree array
        size = k; // Set the size of the segment tree
        // Initialize the leaves of the segment tree
        for (int32_t i = k; i < 2 * k; ++i) {
            memcpy(static_cast<uint8_t *>(array) + i * val_size, ini, val_size);
        }
        uint8_t *a = static_cast<uint8_t *>(array); // Pointer to the segment tree array
        // Build the segment tree by combining child nodes
        for (int32_t i = k - 1; i > 0; --i) {
            func(a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size);
        }
    }

    ~SegmentTree() {
        free(array); // Free the segment tree array
    }

    // Function to update a value in the segment tree
    void update(int32_t k, const void *val) {
        k += size; // Move to the leaf position
        uint8_t *p = static_cast<uint8_t *>(array); // Pointer to the segment tree array
        memcpy(p + k * val_size, val, val_size); // Update the value at the leaf
        // Update the segment tree upwards
        for (k >>= 1; k > 0; k >>= 1) {
            func(p + k * val_size, p + 2 * k * val_size, p + (2 * k + 1) * val_size);
        }
    }

    // Function to find the result in a range of the segment tree
    void find(int32_t l, int32_t r, void *res) const {
        int32_t lindex[32]; // Array to hold left indices
        int32_t rindex[32]; // Array to hold right indices
        int32_t llen = 0; // Length of left indices
        int32_t rlen = 0; // Length of right indices
        // Traverse the segment tree to find the indices
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lindex[llen++] = l++; // If l is odd, include it and move to the next
            if (r & 1) rindex[rlen++] = --r; // If r is odd, include the previous and move left
        }
        const uint8_t *p = static_cast<const uint8_t *>(array); // Pointer to the segment tree array
        if (llen == 0) {
            lindex[llen++] = rindex[--rlen]; // If no left indices, take from right
        }
        memcpy(res, p + lindex[0] * val_size, val_size); // Initialize result with the first left index
        // Combine results from left indices
        for (int32_t i = 1; i < llen; ++i) {
            func(res, res, p + lindex[i] * val_size);
        }
        // Combine results from right indices
        for (int32_t i = rlen - 1; i >= 0; --i) {
            func(res, res, p + rindex[i] * val_size);
        }
    }
};

// Define integer types for convenience
using i32 = int32_t;
using i64 = int64_t;

// Define a structure for index-value pairs
struct IndexVal {
    i32 index; // Index of the value
    i32 val; // Value
};

// Comparison function for index-value pairs
int cmp_index_val(const void *a, const void *b) {
    i32 d = static_cast<const IndexVal *>(a)->val - static_cast<const IndexVal *>(b)->val; // Compare values
    return d == 0 ? 0 : d > 0 ? -1 : 1; // Return comparison result
}

// Define a structure for segment tree nodes
struct SegmentNode {
    i32 index; // Index of the node
    i64 val; // Value of the node
};

// Function to combine two segment nodes
void func_segment_node(void *c, const void *a, const void *b) {
    const SegmentNode *p = static_cast<const SegmentNode *>(a); // First node
    const SegmentNode *q = static_cast<const SegmentNode *>(b); // Second node
    *(SegmentNode *)c = p->val < q->val ? *p : *q; // Choose the node with the smaller value
}

// Define a structure for edges
struct Edge {
    i32 a, b; // Endpoints of the edge
    i64 c; // Cost of the edge
};

// Comparison function for edges
int cmp_edge(const void *a, const void *b) {
    i64 d = static_cast<const Edge *>(a)->c - static_cast<const Edge *>(b)->c; // Compare costs
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
    std::sort(p.begin(), p.end(), cmp_index_val); // Sort index-value pairs by value
    const SegmentNode ini = {n, (i64)(n + 2) * 1000000000 + 1}; // Initialize segment node
    SegmentTree l(&ini, n, sizeof(SegmentNode), func_segment_node); // Create left segment tree
    SegmentTree r(&ini, n, sizeof(SegmentNode), func_segment_node); // Create right segment tree
    // Update segment trees with adjusted values
    for (i32 i = 0; i < n; ++i) {
        l.update(i, &SegmentNode{i, a[i] + (i64)(n - 1 - i) * d});
        r.update(i, &SegmentNode{i, a[i] + (i64)i * d});
    }
    BinaryHeap h(sizeof(Edge), cmp_edge); // Create a new binary heap for edges
    // Process each index-value pair
    for (i32 i = 0; i < n; ++i) {
        i32 v = p[i].index; // Get the original index
        if (v > 0) {
            SegmentNode t; // Temporary segment node
            l.find(0, v, &t); // Find the minimum in the left segment tree
            h.push(&Edge{v, t.index, p[i].val + t.val - (i64)(n - 1 - v) * d}); // Push edge to heap
        }
        if (v + 1 < n) {
            SegmentNode t; // Temporary segment node
            r.find(v + 1, n, &t); // Find the minimum in the right segment tree
            h.push(&Edge{v, t.index, p[i].val + t.val - (i64)v * d}); // Push edge to heap
        }
        l.update(v, &ini); // Update left segment tree
        r.update(v, &ini); // Update right segment tree
    }
    i64 sum = 0; // Initialize sum of costs
    UnionFind u(n); // Create a new Union-Find structure
    // Process edges in the heap to find the minimum spanning tree
    while (u.getSize(0) < n) {
        Edge e; // Temporary edge
        h.pop(&e); // Pop the minimum edge from the heap
        if (u.same(e.a, e.b)) continue; // If they are already connected, skip
        u.unite(e.a, e.b); // Union the sets
        sum += e.c; // Add the cost of the edge to the sum
    }
    std::cout << sum << std::endl; // Print the total cost
}

// Main entry point of the program
int main() {
    run(); // Execute the run function
    return 0; // Return success
}

// <END-OF-CODE>
