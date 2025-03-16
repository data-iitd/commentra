

#include <cstdio>
#include <cstdint>
#include <cstring>
#include <algorithm>

// Define the structure of a binary heap and its operations.
template <typename T>
struct binaryHeap {
  T *array;
  size_t heap_size;
  size_t max_size;
  int (*cmp) (const void *, const void *);

  binaryHeap (size_t val_size, int (*cmpF) (const void *, const void *)) {
    heap_size = 0;
    max_size = 1;
    array = (T *) malloc (val_size * (1 + 1));
    cmp = cmpF;
  }

  // Return the current size of the heap.
  size_t getHeapSize (void) {
    return heap_size;
  }

  // Check if the heap is empty.
  bool isEmpty (void) {
    return heap_size == 0;
  }

  // Free the memory allocated for the heap.
  void freeHeap (void) {
    free (array);
    free (this);
  }

  // Initialize the heap size to zero.
  void initHeap (void) {
    heap_size = 0;
  }

  // Copy one element to another.
  void heapFuncCopy (void * restrict dst, const void * restrict src, size_t val_size) {
    uint8_t *p = (uint8_t *) src;
    uint8_t *q = (uint8_t *) dst;
    while (val_size--) {
      *q++ = *p++;
    }
  }

  // Swap two elements of the heap.
  void heapFuncSwap (void * restrict a, void * restrict b, size_t val_size) {
    uint8_t *p = (uint8_t *) a;
    uint8_t *q = (uint8_t *) b;
    while (val_size--) {
      uint8_t tmp = *p;
      *p++ = *q++;
      *q = tmp;
    }
  }

  // Add a new element to the heap.
  void push (T *val) {
    if (heap_size == max_size) {
      max_size = 2 * max_size + 1;
      array = (T *) realloc (array, max_size * sizeof (T));
    }
    heap_size++;
    uint8_t *p = (uint8_t *) array;
    size_t k = heap_size;
    const size_t val_size = sizeof (T);
    int (* const cmp) (const void *, const void *) = this->cmp;
    heapFuncCopy (p + k * val_size, val, val_size);
    while(k>1){
      size_t parent = k / 2;
      if (cmp (p + parent * val_size, p + k * val_size) <= 0) {
        return;
      }
      heapFuncSwap (p + parent * val_size, p + k * val_size);
      k = parent;
    }
  }

  // Remove the top element from the heap.
  void pop (T *res) {
    uint8_t *p = (uint8_t *) array;
    const size_t val_size = sizeof (T);
    if (res!= NULL) {
      heapFuncCopy (res, p + val_size, val_size);
    }
    heap_size--;
    int (* const cmp) (const void *, const void *) = this->cmp;
    const size_t n = heap_size;
    size_t k = 1;
    while (2 * k + 1 <= n) {
      int c = cmp (p + 2 * k * val_size, p + (2 * k + 1) * val_size);
      size_t parent = k;
      while (2 * parent + 1 <= n) {
        int c = cmp (p + 2 * parent * val_size, p + (2 * parent + 1) * val_size);
        size_t len = 0;
        while (len > 0) {
          size_t index[32];
          size_t len = 0;
          while (len > 0) {
            size_t index[len++] = parent;
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len];
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
          }
          while (len > 0) {
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            size_t index[--len);
            