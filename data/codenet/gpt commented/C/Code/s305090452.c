#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

// Define a structure for a binary heap
typedef struct binaryHeap{
  void *array; // Pointer to the array that holds the heap elements
  size_t heap_size; // Current number of elements in the heap
  size_t max_size; // Maximum capacity of the heap
  size_t val_size; // Size of each value in the heap
  int (*cmp) (const void *, const void *); // Comparison function for heap elements
} heap;

// Function to create a new binary heap
heap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  heap *h = (heap *) calloc (1, sizeof (heap)); // Allocate memory for the heap structure
  h->array = malloc (val_size * (1 + 1)); // Allocate memory for the heap array
  h->heap_size = 0; // Initialize heap size to 0
  h->max_size = 1; // Set initial maximum size
  h->val_size = val_size; // Set the value size
  h->cmp = cmpF; // Set the comparison function
  return h; // Return the created heap
}

// Function to get the current size of the heap
int32_t get_heap_size (const heap *h) {
  return h->heap_size; // Return the current size of the heap
}

// Function to check if the heap is empty
int is_empty (const heap *h) {
  return h->heap_size == 0; // Return 1 if the heap is empty, otherwise 0
}

// Function to free the memory allocated for the heap
void free_heap (heap *h) {
  free (h->array); // Free the array holding the heap elements
  free (h); // Free the heap structure itself
}

// Function to initialize the heap
void init_heap (heap *h) {
  h->heap_size = 0; // Set the heap size to 0
}

// Function to swap two elements in the heap
static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
  // Swap elements based on their size (optimized for 64-bit values)
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) a;
    uint64_t *q = (uint64_t *) b;
    val_size /= sizeof (uint64_t);
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
static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
  // Copy elements based on their size (optimized for 64-bit values)
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) src;
    uint64_t *q = (uint64_t *) dst;
    val_size /= sizeof (uint64_t);
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
void push (heap *h, const void *val) {
  // Check if the heap needs to be resized
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1; // Double the max size
    h->array = realloc (h->array, h->val_size * (h->max_size + 1)); // Resize the array
  }
  h->heap_size++; // Increment the heap size
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  size_t k = h->heap_size; // Current index for the new element
  const size_t val_size = h->val_size; // Size of the value
  int (*cmp) (const void *, const void *) = h->cmp; // Get the comparison function
  heap_func_copy(array + k * val_size, val, val_size); // Copy the new value into the heap
  // Maintain the heap property by moving the new element up the heap
  while(k > 1){
    size_t parent = k / 2; // Calculate the parent index
    if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
      return; // If the heap property is satisfied, exit
    }
    heap_func_swap (array + parent * val_size, array + k * val_size, val_size); // Swap with parent
    k = parent; // Move up to the parent
  }
}

// Function to pop the top value from the heap
void pop (heap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  const size_t val_size = h->val_size; // Size of the value
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
  }
  heap_func_copy (array + val_size, array + val_size * h->heap_size, val_size); // Move the last element to the top
  h->heap_size--; // Decrement the heap size
  int (* const cmp) (const void *, const void *) = h->cmp; // Get the comparison function
  const size_t n = h->heap_size; // Current size of the heap
  size_t k = 1; // Start from the root
  // Maintain the heap property by moving the top element down the heap
  while (2 * k + 1 <= n) {
    int c = cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1)); // Compare children
    size_t next = 2 * k + (c <= 0 ? 0 : 1); // Choose the smaller child
    if (cmp (array + val_size * k, array + val_size * next) <= 0) return; // If heap property is satisfied, exit
    heap_func_swap (array + val_size * k, array + val_size * next, val_size); // Swap with the smaller child
    k = next; // Move down to the next level
  }
  // Check if the last child needs to be swapped
  if (2 * k <= n && cmp (array + val_size * k, array + val_size * 2 * k) > 0) {
    heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
  }
}

// Function to get the top value of the heap without removing it
void top (const heap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  const size_t val_size = h->val_size; // Size of the value
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
  }
}

// Define a structure for Union-Find (Disjoint Set Union)
typedef struct UnionFind {
  int32_t *parent; // Array to hold the parent of each element
  int32_t size; // Size of the Union-Find structure
} UnionFind;

// Function to initialize the Union-Find structure
void initUnionFind (UnionFind *u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1; // Set each element's parent to -1 (indicating it is its own root)
  }
}

// Function to create a new Union-Find structure
UnionFind* newUnionFind (const int32_t size) {
  UnionFind *u = (UnionFind *) calloc (1, sizeof (UnionFind)); // Allocate memory for the structure
  u->parent = (int32_t *) calloc (size, sizeof (int32_t)); // Allocate memory for the parent array
  u->size = size; // Set the size
  initUnionFind (u); // Initialize the Union-Find structure
  return u; // Return the created structure
}

// Function to free the memory allocated for the Union-Find structure
void freeUnionFind (UnionFind *u) {
  free (u->parent); // Free the parent array
  free (u); // Free the Union-Find structure
}

// Function to find the root of an element with path compression
int32_t root (UnionFind *u, int32_t x) {
  int32_t index[32]; // Array to hold the path for compression
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
int same (UnionFind *u, int32_t x, int32_t y) {
  return root (u, x) == root (u, y); // Return 1 if they have the same root, otherwise 0
}

// Function to get the size of the set containing element x
int32_t getSize(UnionFind *u, int32_t x) {
  return - (u->parent[root (u, x)]); // Return the size of the set
}

// Function to unite two sets containing elements x and y
void unite(UnionFind *u, int32_t x, int32_t y) {
  x = root (u, x); // Find the root of x
  y = root (u, y); // Find the root of y
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
typedef struct segment_tree_void {
  void *array; // Pointer to the array that holds the segment tree nodes
  int32_t size; // Size of the segment tree
  size_t val_size; // Size of each value in the segment tree
  void (*func) (void *, const void *, const void *); // Function to combine two values
} segment_tree;

// Function to copy memory from source to destination
static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
  uint8_t *p = dst; // Pointer to destination
  const uint8_t *q = src; // Pointer to source
  while (size--) {
    *p++ = *q++; // Copy byte by byte
  }
}

// Function to create a new segment tree
segment_tree* new_segment_tree (const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)) {
  int32_t k = 1; // Initialize k to 1
  while (k < n) k *= 2; // Find the next power of 2 greater than n
  segment_tree *s = (segment_tree *) calloc (1, sizeof (segment_tree)); // Allocate memory for the segment tree
  s->array = calloc (2 * k, val_size); // Allocate memory for the segment tree array
  s->size = k; // Set the size of the segment tree
  s->val_size = val_size; // Set the value size
  s->func = func; // Set the function to combine values
  // Initialize the leaves of the segment tree
  for (int32_t i = k; i < 2 * k; ++i) {
    segment_tree_memcpy ((uint8_t *)s->array + i * val_size, ini, val_size);
  }
  uint8_t *a = s->array; // Pointer to the segment tree array
  // Build the segment tree by combining child nodes
  for (int32_t i = k - 1; i > 0; --i) {
    func (a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size);
  }
  return s; // Return the created segment tree
}

// Function to update a value in the segment tree
void update (segment_tree * const s, int32_t k, const void *val) {
  k += s->size; // Move to the leaf position
  uint8_t *p = s->array; // Pointer to the segment tree array
  const size_t size = s->val_size; // Size of the value
  segment_tree_memcpy (p + k * size, val, size); // Update the value at the leaf
  // Update the segment tree upwards
  for (k >>= 1; k > 0; k >>= 1) {
    s->func (p + k * size, p + 2 * k * size, p + (2 * k + 1) * size);
  }
}

// Function to update a value temporarily in the segment tree
void update_tmp (segment_tree * const s, int32_t k, const void *val) {
  k += s->size; // Move to the leaf position
  uint8_t *p = s->array; // Pointer to the segment tree array
  const size_t size = s->val_size; // Size of the value
  segment_tree_memcpy (p + k * size, val, size); // Update the value at the leaf
}

// Function to update all nodes in the segment tree
void update_all (segment_tree * const s) {
  uint8_t * const a = s->array; // Pointer to the segment tree array
  const size_t size = s->val_size; // Size of the value
  // Update the segment tree from the leaves to the root
  for (int32_t i = s->size - 1; i > 0; --i) {
    s->func (a + i * size, a + (2 * i) * size, a + (2 * i + 1) * size);
  }
}

// Function to find the result in a range of the segment tree
void find (const segment_tree *s, int32_t l, int32_t r, void *res) {
  int32_t lindex[32]; // Array to hold left indices
  int32_t rindex[32]; // Array to hold right indices
  int32_t llen = 0; // Length of left indices
  int32_t rlen = 0; // Length of right indices
  // Traverse the segment tree to find the indices
  for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lindex[llen++] = l++; // If l is odd, include it and move to the next
    if (r & 1) rindex[rlen++] = --r; // If r is odd, include the previous and move left
  }
  const uint8_t *p = s->array; // Pointer to the segment tree array
  if (llen == 0) {
    lindex[llen++] = rindex[--rlen]; // If no left indices, take from right
  }
  segment_tree_memcpy (res, p + lindex[0] * s->val_size, s->val_size); // Initialize result with the first left index
  // Combine results from left indices
  for (int32_t i = 1; i < llen; ++i) {
    s->func (res, res, p + lindex[i] * s->val_size);
  }
  // Combine results from right indices
  for (int32_t i = rlen - 1; i >= 0; --i) {
    s->func (res, res, p + rindex[i] * s->val_size);
  }
}

// Define integer types for convenience
typedef int32_t i32;
typedef int64_t i64;

// Define a structure for index-value pairs
typedef struct index_val {
  i32 index; // Index of the value
  i32 val; // Value
} index_val;

// Comparison function for index-value pairs
int cmp_index_val (const void *a, const void *b) {
  i32 d = ((index_val *)a)->val - ((index_val *)b)->val; // Compare values
  return d == 0 ? 0 : d > 0 ? -1 : 1; // Return comparison result
}

// Define a structure for segment tree nodes
typedef struct segment_node {
  i32 index; // Index of the node
  i64 val; // Value of the node
} segment_node;

// Function to combine two segment nodes
void func_segment_node (void *c, const void *a, const void *b) {
  const segment_node *p = (const segment_node *)a; // First node
  const segment_node *q = (const segment_node *)b; // Second node
  *(segment_node *)c = p->val < q->val ? *p : *q; // Choose the node with the smaller value
}

// Define a structure for edges
typedef struct edge {
  i32 a, b; // Endpoints of the edge
  i64 c; // Cost of the edge
} edge;

// Comparison function for edges
int cmp_edge (const void *a, const void *b) {
  i64 d = ((edge *)a)->c - ((edge *)b)->c; // Compare costs
  return d == 0 ? 0 : d < 0 ? -1 : 1; // Return comparison result
}

// Main function to run the algorithm
void run (void) {
  i32 n, d; // Number of elements and a parameter d
  scanf ("%" SCNi32 "%" SCNi32, &n, &d); // Read n and d
  i32 *a = (i32 *) calloc (n, sizeof (i32)); // Allocate array for values
  index_val *p = (index_val *) calloc (n, sizeof (index_val)); // Allocate array for index-value pairs
  // Read values and initialize index-value pairs
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
    p[i] = (index_val){i, a[i]};
  }
  qsort (p, n, sizeof (index_val), cmp_index_val); // Sort index-value pairs by value
  const segment_node ini = {n, (i64)(n + 2) * 1000000000 + 1}; // Initialize segment node
  segment_tree *l = new_segment_tree (&ini, n, sizeof (segment_node), func_segment_node); // Create left segment tree
  segment_tree *r = new_segment_tree (&ini, n, sizeof (segment_node), func_segment_node); // Create right segment tree
  // Update segment trees with adjusted values
  for (i32 i = 0; i < n; ++i) {
    update_tmp (l, i, &((segment_node){i, a[i] + (i64)(n - 1 - i) * d}));
    update_tmp (r, i, &((segment_node){i, a[i] + (i64)i * d}));
  }
  update_all (l); // Update all nodes in the left segment tree
  update_all (r); // Update all nodes in the right segment tree
  heap *h = new_binary_heap (sizeof (edge), cmp_edge); // Create a new binary heap for edges
  // Process each index-value pair
  for (i32 i = 0; i < n; ++i) {
    i32 v = p[i].index; // Get the original index
    if (v > 0) {
      segment_node t; // Temporary segment node
      find (l, 0, v, &t); // Find the minimum in the left segment tree
      push (h, &((edge){v, t.index, p[i].val + t.val - (i64) (n - 1 - v) * d})); // Push edge to heap
    }
    if (v + 1 < n) {
      segment_node t; // Temporary segment node
      find (r, v + 1, n, &t); // Find the minimum in the right segment tree
      push (h, &((edge){v, t.index, p[i].val + t.val - (i64) v * d})); // Push edge to heap
    }
    update (l, v, &ini); // Update left segment tree
    update (r, v, &ini); // Update right segment tree
  }
  i64 sum = 0; // Initialize sum of costs
  UnionFind *u = newUnionFind (n); // Create a new Union-Find structure
  // Process edges in the heap to find the minimum spanning tree
  while (getSize (u, 0) < n) {
    edge e; // Temporary edge
    pop (h, &e); // Pop the minimum edge from the heap
    if (same (u, e.a, e.b)) continue; // If they are already connected, skip
    unite (u, e.a, e.b); // Union the sets
    sum += e.c; // Add the cost of the edge to the sum
  }
  printf ("%" PRIi64 "\n", sum); // Print the total cost
}

// Main entry point of the program
int main (void) {
  run (); // Execute the run function
  return 0; // Return success
}
