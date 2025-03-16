
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// Define a structure for a binary heap
class binaryHeap {
  void *array; // Pointer to the array that holds the heap elements
  int heap_size; // Current number of elements in the heap
  int max_size; // Maximum capacity of the heap
  int val_size; // Size of each value in the heap
  int (*cmp) (const void *, const void *); // Comparison function for heap elements

  // Function to create a new binary heap
  public binaryHeap (int val_size, int (*cmpF) (const void *, const void *)) {
    array = malloc (val_size * (1 + 1)); // Allocate memory for the heap array
    heap_size = 0; // Initialize heap size to 0
    max_size = 1; // Set initial maximum size
    this.val_size = val_size; // Set the value size
    cmp = cmpF; // Set the comparison function
  }

  // Function to get the current size of the heap
  public int get_heap_size () {
    return heap_size; // Return the current size of the heap
  }

  // Function to check if the heap is empty
  public boolean is_empty () {
    return heap_size == 0; // Return 1 if the heap is empty, otherwise 0
  }

  // Function to free the memory allocated for the heap
  public void free_heap () {
    free (array); // Free the array holding the heap elements
  }

  // Function to initialize the heap
  public void init_heap () {
    heap_size = 0; // Set the heap size to 0
  }

  // Function to swap two elements in the heap
  private void heap_func_swap (void * restrict a, void * restrict b, int val_size) {
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
  private void heap_func_copy (void * restrict dst, const void * restrict src, int val_size) {
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
  public void push (const void *val) {
    // Check if the heap needs to be resized
    if (heap_size == max_size) {
      max_size = 2 * max_size + 1; // Double the max size
      array = realloc (array, val_size * (max_size + 1)); // Resize the array
    }
    heap_size++; // Increment the heap size
    byte[] array = (byte[]) this.array; // Cast array to byte array for byte-wise access
    int k = heap_size; // Current index for the new element
    int val_size = this.val_size; // Size of the value
    int (*cmp) (const void *, const void *) = this.cmp; // Get the comparison function
    heap_func_copy(array, val, val_size); // Copy the new value into the heap
    // Maintain the heap property by moving the new element up the heap
    while(k > 1){
      int parent = k / 2; // Calculate the parent index
      if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
        return; // If the heap property is satisfied, exit
      }
      heap_func_swap (array + parent * val_size, array + k * val_size, val_size); // Swap with parent
      k = parent; // Move up to the parent
    }
  }

  // Function to pop the top value from the heap
  public void pop (void *res) {
    byte[] array = (byte[]) this.array; // Cast array to byte array for byte-wise access
    int val_size = this.val_size; // Size of the value
    if (res != null) {
      heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
    }
    heap_func_copy (array + val_size, array + val_size * heap_size, val_size); // Move the last element to the top
    heap_size--; // Decrement the heap size
    int (* const cmp) (const void *, const void *) = this.cmp; // Get the comparison function
    int n = heap_size; // Current size of the heap
    int k = 1; // Start from the root
    // Maintain the heap property by moving the top element down the heap
    while (2 * k + 1 <= n) {
      int c = cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1)); // Compare children
      int next = 2 * k + (c <= 0 ? 0 : 1); // Choose the smaller child
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
  public void top (void *res) {
    byte[] array = (byte[]) this.array; // Cast array to byte array for byte-wise access
    int val_size = this.val_size; // Size of the value
    if (res != null) {
      heap_func_copy (res, array + val_size, val_size); // Copy the top value to the result
    }
  }
}

// Define a structure for Union-Find (Disjoint Set Union)
class UnionFind {
  int[] parent; // Array to hold the parent of each element
  int size; // Size of the Union-Find structure

  // Function to initialize the Union-Find structure
  public void initUnionFind () {
    for (int i = 0; i < size; ++i){
      parent[i] = -1; // Set each element's parent to -1 (indicating it is its own root)
    }
  }

  // Function to create a new Union-Find structure
  public UnionFind (int size) {
    parent = new int[size]; // Allocate memory for the parent array
    this.size = size; // Set the size
    initUnionFind (); // Initialize the Union-Find structure
  }

  // Function to free the memory allocated for the Union-Find structure
  public void freeUnionFind () {
    parent = null; // Free the parent array
  }

  // Function to find the root of an element with path compression
  public int root (int x) {
    int index[] = new int[3