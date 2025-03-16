#include<bits/stdc++.h>
using namespace std;

// Define a structure for a binary heap
struct binaryHeap {
  void *array; // Pointer to the array that holds the heap elements
  size_t heap_size; // Current number of elements in the heap
  size_t max_size; // Maximum capacity of the heap
  size_t val_size; // Size of each value in the heap
  int (*cmp) (const void *, const void *); // Comparison function for heap elements
};

// Function to create a new binary heap
binaryHeap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  binaryHeap *h = (binaryHeap *) malloc (sizeof (binaryHeap)); // Allocate memory for the heap structure
  h->array = malloc (val_size * (1 + 1)); // Allocate memory for the heap array
  h->heap_size = 0; // Initialize heap size to 0
  h->max_size = 1; // Set initial maximum size
  h->val_size = val_size; // Set the value size
  h->cmp = cmpF; // Set the comparison function
  return h; // Return the created heap
}

// Function to get the current size of the heap
int get_heap_size (const binaryHeap *h) {
  return h->heap_size; // Return the current size of the heap
}

// Function to check if the heap is empty
bool is_empty (const binaryHeap *h) {
  return h->heap_size == 0; // Return 1 if the heap is empty, otherwise 0
}

// Function to free the memory allocated for the heap
void free_heap (binaryHeap *h) {
  free (h->array); // Free the array holding the heap elements
  free (h); // Free the heap structure itself
}

// Function to initialize the heap
void init_heap (binaryHeap *h) {
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
void push (binaryHeap *h, const void *val) {
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
void pop (binaryHeap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  const size_t val_size = h->val_size; // Size of the value
  if (res!= NULL) {
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
    size_t next = 2 * k + (c <= 0? 0 : 1); // Choose the smaller child
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
void top (const binaryHeap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  const size_t val_size = h->val_size; // Size of the value
  if (res!= NULL) {
    heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
  }
}

// Define a structure for Union-Find (Disjoint Set Union)
struct UnionFind {
  int32_t *parent; // Array to hold the parent of each element
  int32_t size; // Size of the Union-Find structure
};

// Function to initialize the Union-Find structure
void initUnionFind (UnionFind *u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1; // Set each element's parent to -1 (indicating it is its own root)
  }
}

// Function to create a new Union-Find structure
UnionFind* newUnionFind (const int32_t size) {
  UnionFind *u = (UnionFind *) malloc (sizeof (UnionFind)); // Allocate memory for the structure
  u->parent = (int32_t *) malloc (size * sizeof (int32_t)); // Allocate memory for the parent array
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
bool same (UnionFind *u, int32_t x, int32_t y) {
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