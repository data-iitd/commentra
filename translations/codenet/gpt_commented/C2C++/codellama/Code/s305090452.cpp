#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdint>
#include<cstring>
#include<algorithm>
#include<functional>

// Define a structure for a binary heap
struct binaryHeap{
  void *array; // Pointer to the array that holds the heap elements
  size_t heap_size; // Current number of elements in the heap
  size_t max_size; // Maximum capacity of the heap
  size_t val_size; // Size of each value in the heap
  std::function<int(const void *, const void *)> cmp; // Comparison function for heap elements
};

// Function to create a new binary heap
binaryHeap* new_binary_heap (const size_t val_size, std::function<int(const void *, const void *)> cmpF) {
  binaryHeap *h = (binaryHeap *) calloc (1, sizeof (binaryHeap)); // Allocate memory for the heap structure
  h->array = malloc (val_size * (1 + 1)); // Allocate memory for the heap array
  h->heap_size = 0; // Initialize heap size to 0
  h->max_size = 1; // Set initial maximum size
  h->val_size = val_size; // Set the value size
  h->cmp = cmpF; // Set the comparison function
  return h; // Return the created heap
}

// Function to get the current size of the heap
int32_t get_heap_size (const binaryHeap *h) {
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
template<typename T>
void heap_func_swap (T * restrict a, T * restrict b) {
  // Swap elements based on their size (optimized for 64-bit values)
  if ((sizeof(T) & 7) == 0) {
    uint64_t *p = (uint64_t *) a;
    uint64_t *q = (uint64_t *) b;
    size_t val_size = sizeof(T) / sizeof(uint64_t);
    while (val_size--) {
      uint64_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  } else {
    // Fallback for other sizes
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (sizeof(T)--) {
      uint8_t tmp = *p;
      *p++ = *q;
      *q++ = tmp;
    }
  }
}

// Function to copy values from source to destination
template<typename T>
void heap_func_copy (T * restrict dst, const T * restrict src) {
  // Copy elements based on their size (optimized for 64-bit values)
  if ((sizeof(T) & 7) == 0) {
    uint64_t *p = (uint64_t *) src;
    uint64_t *q = (uint64_t *) dst;
    size_t val_size = sizeof(T) / sizeof(uint64_t);
    while (val_size--) {
      *q++ = *p++;
    }
  } else {
    // Fallback for other sizes
    uint8_t *p = (uint8_t *) src;
    uint8_t *q = (uint8_t *) dst;
    while (sizeof(T)--) {
      *q++ = *p++;
    }
  }
}

// Function to push a new value into the heap
template<typename T>
void push (binaryHeap *h, const T *val) {
  // Check if the heap needs to be resized
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1; // Double the max size
    h->array = realloc (h->array, h->val_size * (h->max_size + 1)); // Resize the array
  }
  h->heap_size++; // Increment the heap size
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  size_t k = h->heap_size; // Current index for the new element
  const size_t val_size = h->val_size; // Size of the value
  std::function<int(const void *, const void *)> cmp = h->cmp; // Get the comparison function
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
template<typename T>
void pop (binaryHeap *h, T *res) {
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  const size_t val_size = h->val_size; // Size of the value
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
  }
  heap_func_copy (array + val_size, array + val_size * h->heap_size, val_size); // Move the last element to the top
  h->heap_size--; // Decrement the heap size
  std::function<int(const void *, const void *)> cmp = h->cmp; // Get the comparison function
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
template<typename T>
void top (const binaryHeap *h, T *res) {
  uint8_t *array = (uint8_t *) h->array; // Cast array to uint8_t pointer for byte-wise access
  const size_t val_size = h->val_size; // Size of the value
  if (res != NULL) {
    heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
  }
}

// Define a structure for