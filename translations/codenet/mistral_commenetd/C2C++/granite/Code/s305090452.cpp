

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

// Include necessary header files

typedef struct binaryHeap{
  void *array;
  size_t heap_size;
  size_t max_size;
  size_t val_size;
  int (*cmp) (const void *, const void *);
} heap;

// Define a structure for binary heap

heap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  heap *h = (heap *) calloc (1, sizeof (heap));
  // Allocate memory for heap structure

  h->array = malloc (val_size * (1 + 1));
  // Allocate memory for heap array

  h->heap_size = 0;
  h->max_size = 1;
  h->val_size = val_size;
  h->cmp = cmpF;
  // Initialize heap properties

  return h;
}

// Function to create a new binary heap

int32_t get_heap_size (const heap *h) {
  // Function to get the current size of the heap

  return h->heap_size;
}

int is_empty (const heap *h) {
  // Function to check if the heap is empty

  return h->heap_size == 0;
}

void free_heap (heap *h) {
  free (h->array);
  free (h);
  // Function to free the memory allocated for the heap
}

void init_heap (heap *h) {
  h->heap_size = 0;
  // Function to initialize an empty heap
}

// Implementation of various heap functions

static void heap_func_swap (void * restrict a, void * restrict b, size_t val_size) {
  // Helper function to swap two elements in the heap

  if ((val_size & 7) == 0) {
    uint64_t *p = (uint64_t *) a;
    uint64_t *q = (uint64_t *) b;
    val_size /= sizeof (uint64_t);
    while (val_size--) {
      uint64_t tmp = *p;
      *p++ = *q++;
      *q++ = tmp;
    }
  } else {
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (val_size--) {
      uint8_t tmp = *p;
      *p++ = *q++;
      *q++ = tmp;
    }
  }
}

static void heap_func_copy (void * restrict dst, const void * restrict src, size_t val_size) {
  // Helper function to copy elements from one location to another

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

// Helper functions for heap manipulation

void push (heap *h, const void *val) {
  // Function to add a new element to the heap

  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1;
    h->array = realloc (h->array, h->val_size * (h->max_size + 1));
  }
  h->heap_size++;
  uint8_t *array = (uint8_t *) h->array;
  size_t k = h->heap_size;
  const size_t val_size = h->val_size;
  int (* const cmp) (const void *, const void *) = h->cmp;
  heap_func_copy (array + k * val_size, val, val_size);
  while(k>1){
    size_t parent = k / 2;
    if (cmp (array + k * val_size, array + parent * val_size) <= 0) {
      return;
    }
    heap_func_swap (array + parent * val_size, array + k * val_size);
    k = parent;
  }
}

void pop (heap *h, void *res) {
  // Function to remove and return the root element from the heap

  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res!= NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
  if (h->heap_size > 1) {
    size_t parent = h->heap_size;
    const size_t val_size = h->val_size;
    int (* const cmp) (const void *, const void *) = h->cmp;
    const size_t n = h->heap_size;
    size_t k = 1;
    while (k < n) k *= 2;
    }
    heap_func_copy (array + k * val_size, array + (k - 1) * val_size);
    }
    if (k > 1) {
      return;
    }
    if (res!= NULL) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    }
    if (h->heap_size > 1) {
      return;
    }
    if (h->heap_size > 1) {
      return;
    }
  