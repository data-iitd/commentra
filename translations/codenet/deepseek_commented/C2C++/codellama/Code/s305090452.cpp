#include<cstdio>
#include<cstdlib>
#include<cstdint>
#include<cinttypes>

// Define the structure of a binary heap and its operations.
struct binaryHeap{
  void *array;
  size_t heap_size;
  size_t max_size;
  size_t val_size;
  int (*cmp) (const void *, const void *);
};

// Initialize a new binary heap with a given value size and comparison function.
binaryHeap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  binaryHeap *h = (binaryHeap *) calloc (1, sizeof (binaryHeap));
  h->array = malloc (val_size * (1 + 1));
  h->heap_size = 0;
  h->max_size = 1;
  h->val_size = val_size;
  h->cmp = cmpF;
  return h;
}

// Return the current size of the heap.
int32_t get_heap_size (const binaryHeap *h) {
  return h->heap_size;
}

// Check if the heap is empty.
int is_empty (const binaryHeap *h) {
  return h->heap_size == 0;
}

// Free the memory allocated for the heap.
void free_heap (binaryHeap *h) {
  free (h->array);
  free (h);
}

// Initialize the heap size to zero.
void init_heap (binaryHeap *h) {
  h->heap_size = 0;
}

// Swap two elements of the heap.
static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
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
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (val_size--) {
      uint8_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  }
}

// Copy one element to another.
static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) src;
    uint64_t *q = (uint64_t *) dst;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      *q++ = *p++;
    }
  } else {
    uint8_t *p = (uint8_t *) src;
    uint8_t *q = (uint8_t *) dst;
    while (val_size--) {
      *q++ = *p++;
    }
  }
}

// Add a new element to the heap.
void push (binaryHeap *h, const void *val) {
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1;
    h->array = realloc (h->array, h->val_size * (h->max_size + 1));
  }
  h->heap_size++;
  uint8_t *array = (uint8_t *) h->array;
  size_t k = h->heap_size;
  const size_t val_size = h->val_size;
  int (*cmp) (const void *, const void *) = h->cmp;
  heap_func_copy(array + k * val_size, val, val_size);
  while(k>1){
    size_t parent = k / 2;
    if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
      return;
    }
    heap_func_swap (array + parent * val_size, array + k * val_size, val_size);
    k = parent;
  }
}

// Remove the top element from the heap.
void pop (binaryHeap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
  heap_func_copy (array + val_size, array + val_size * h->heap_size, val_size);
  h->heap_size--;
  int (* const cmp) (const void *, const void *) = h->cmp;
  const size_t n = h->heap_size;
  size_t k = 1;
  while (2 * k  + 1 <= n) {
    int c = cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1));
    size_t next = 2 * k + (c <= 0 ? 0 : 1);
    if (cmp (array + val_size * k, array + val_size * next) <= 0) return;
    heap_func_swap (array + val_size * k, array + val_size * next, val_size);
    k = next;
  }
  if (2 * k <= n && cmp (array + val_size * k, array + val_size * 2 * k) > 0) {
    heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
  }
}

// Return the top element of the heap without removing it.
void top (const binaryHeap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
}

// Define the structure of Union-Find and its operations.
struct UnionFind {
  int32_t *parent;
  int32_t size;
};

// Initialize the parent array to -1.
void initUnionFind (UnionFind *u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1;
  }
}

// Initialize a new Union-Find structure with a given size.
UnionFind* newUnionFind (const int32_t size) {
  UnionFind *u = (UnionFind *) calloc (1, sizeof (UnionFind));
  u->parent = (int32_t *) calloc (size, sizeof (int32_t));
  u->size = size;
  initUnionFind (u);
  return u;
}

// Free the memory allocated for the Union-Find structure.
void freeUnionFind (UnionFind *u) {
  free (u->parent);
  free (u);
}

// Find the root of a given element.
int32_t root (UnionFind *u, int32_t x) {
  int32_t index[32];
  int32_t len = 0;
  while (u->parent[x] >= 0) {
    index[len++] = x;
    x = u->parent[x];
  }
  while (len > 0) {
    u->parent[index[--len]] = x;
  }
  return x;
}

// Check if two elements are in the same set.
int same (UnionFind *u, int32_t x, int32_t y) {
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
    int32_t swap = x;
    x = y;
    y = swap;
  }
  u->parent[x] += u->parent[y];
  u->parent[y] = x;
}

// Define the structure of a segment tree and its operations.
struct segment_tree_void {
  void *array;
  int32_t size;
  size_t val_size;
  void (*func) (void *, const void *, const void *);
};

// Copy one memory area to another.
static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
  uint8_t *p = dst;
  const uint8_t *q = src;
  while (size--) {
    *p++ = *q++;
  }
}

// Initialize a new segment tree with an initial array, size, value size, and merge function.
segment_tree_void* new_segment_tree (const void *ini, const int32_t n, const size_t val_size, void (*func) (void *, const void *, const void *)) {
  int32_t k = 1;
  while (k < n) k *= 2;
  segment_tree_void *s = (segment_tree_void *) calloc (1, sizeof (segment_tree_void));
  s->array = calloc (2 * k, val_size);
  s->size = k;
  s->val_size = val_size;
  s->func = func;
  for (int32_t i = k; i < 2 * k; ++i) {
    segment_tree_memcpy ((uint8_t *)s->array + i * val_size, ini, val_size);
  }
  uint8_t *a = s->array;
  for (int32_t i = k - 1; i > 0; --i) {
    func (a + i * val_size, a + (2 * i) * val_size, a + (2 * i + 1) * val_size);
  }
  return s;
}

// Update a segment tree node.
void update (segment_tree_void * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t *p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
  for (k >>= 1; k > 0; k >>= 1) {
    s->func (p + k * size, p + 2 * k * size, p + (2 * k + 1) * size);
  }
}

// Temporarily update a segment tree node.
void update_tmp (segment_tree_void * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t *p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
}

// Update all segment tree nodes.
void update_all (segment_tree_void * const s) {
  uint8_t * const a = s->array;
  const size_t size = s->val_size;
  for (int32_t i = s->size - 1; i > 0; --i) {
    s->func (a + i * size, a + (2 * i) * size, a + (2 * i + 1) * size);
  }
}

// Find the result of applying the merge function to a range of segment tree nodes.
void find (const segment_tree_void *s, int32_t l, int32_t r, void *res) {
  int32_t lindex[32];
  int32_t rindex[32];
  int32_t llen = 0;
  int32_t rlen = 0;
  for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
    if (l & 1) lindex[llen++] = l++;
    if (r & 1) rindex[rlen++] = --r;
  }
  const uint8_t *p = s->array;
  if (llen == 0) {
    lindex[llen++] = rindex[--rlen];
  }
  segment_tree_memcpy (res, p + lindex[0] * s->val_size, s->val_size);
  for (int32_t i = 1; i < llen; ++i) {
    s->func (res, res, p + lindex[i] * s->val_size);
  }
  for (int32_t i = rlen - 1; i >= 0; --i) {
    s->func (res, res, p + rindex[i] * s->val_size);
 