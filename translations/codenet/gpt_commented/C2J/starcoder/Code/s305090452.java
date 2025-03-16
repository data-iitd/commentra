
import java.util.*;
import java.io.*;

// Define a structure for a binary heap
class heap {
  Object[] array; // Pointer to the array that holds the heap elements
  int heap_size; // Current number of elements in the heap
  int max_size; // Maximum capacity of the heap
  int val_size; // Size of each value in the heap
  Comparator<Object> cmp; // Comparison function for heap elements
}

// Function to create a new binary heap
heap new_binary_heap (int val_size, Comparator<Object> cmp) {
  heap h = new heap(); // Allocate memory for the heap structure
  h.array = new Object[val_size * (1 + 1)]; // Allocate memory for the heap array
  h.heap_size = 0; // Initialize heap size to 0
  h.max_size = 1; // Set initial maximum size
  h.val_size = val_size; // Set the value size
  h.cmp = cmp; // Set the comparison function
  return h; // Return the created heap
}

// Function to get the current size of the heap
int get_heap_size (heap h) {
  return h.heap_size; // Return the current size of the heap
}

// Function to check if the heap is empty
boolean is_empty (heap h) {
  return h.heap_size == 0; // Return 1 if the heap is empty, otherwise 0
}

// Function to free the memory allocated for the heap
void free_heap (heap h) {
  h.array = null; // Free the array holding the heap elements
  h = null; // Free the heap structure itself
}

// Function to initialize the heap
void init_heap (heap h) {
  h.heap_size = 0; // Set the heap size to 0
}

// Function to swap two elements in the heap
static void heap_func_swap (Object[] a, Object[] b, int val_size) {
  // Swap elements based on their size (optimized for 64-bit values)
  if ((val_size & 7) == 0) {
    long[] p = (long[]) a;
    long[] q = (long[]) b;
    val_size /= 8;
    while (val_size-- > 0) {
      long tmp = p[0];
      p[0] = q[0];
      q[0] = tmp;
      p++;
      q++;
    }
  } else {
    // Fallback for other sizes
    byte[] p = (byte[]) a;
    byte[] q = (byte[]) b;
    while (val_size-- > 0) {
      byte tmp = p[0];
      p[0] = q[0];
      q[0] = tmp;
      p++;
      q++;
    }
  }
}

// Function to copy values from source to destination
static void heap_func_copy (Object[] dst, Object[] src, int val_size) {
  // Copy elements based on their size (optimized for 64-bit values)
  if ((val_size & 7) == 0) {
    long[] p = (long[]) src;
    long[] q = (long[]) dst;
    val_size /= 8;
    while (val_size-- > 0) {
      q[0] = p[0];
      p++;
      q++;
    }
  } else {
    // Fallback for other sizes
    byte[] p = (byte[]) src;
    byte[] q = (byte[]) dst;
    while (val_size-- > 0) {
      q[0] = p[0];
      p++;
      q++;
    }
  }
}

// Function to push a new value into the heap
void push (heap h, Object val) {
  // Check if the heap needs to be resized
  if (h.heap_size == h.max_size) {
    h.max_size = 2 * h.max_size + 1; // Double the max size
    h.array = Arrays.copyOf (h.array, h.val_size * (h.max_size + 1)); // Resize the array
  }
  h.heap_size++; // Increment the heap size
  Object[] array = h.array; // Cast array to Object[] for generic access
  int k = h.heap_size; // Current index for the new element
  int val_size = h.val_size; // Size of the value
  Comparator<Object> cmp = h.cmp; // Get the comparison function
  heap_func_copy(array, k * val_size, val, val_size); // Copy the new value into the heap
  // Maintain the heap property by moving the new element up the heap
  while(k > 1){
    int parent = k / 2; // Calculate the parent index
    if (cmp.compare (array, parent * val_size, k * val_size) <= 0) {
      return; // If the heap property is satisfied, exit
    }
    heap_func_swap (array, parent * val_size, k * val_size, val_size); // Swap with parent
    k = parent; // Move up to the parent
  }
}

// Function to pop the top value from the heap
void pop (heap h, Object res) {
  Object[] array = h.array; // Cast array to Object[] for generic access
  int val_size = h.val_size; // Size of the value
  if (res!= null) {
    heap_func_copy (res, array, val_size); // Copy the top value to the result
  }
  heap_func_copy (array, val_size, array, val_size * h.heap_size); // Move the last element to the top
  h.heap_size--; // Decrement the heap size
  Comparator<Object> cmp = h.cmp; // Get the comparison function
  int n = h.heap_size; // Current size of the heap
  int k = 1; // Start from the root
  // Maintain the heap property by moving the top element down the heap
  while (2 * k + 1 <= n) {
    int c = cmp.compare (array, val_size * 2 * k, val_size * (2 * k + 1)); // Compare children
    int next = 2 * k + (c <= 0? 0 : 1); // Choose the smaller child
    if (cmp.compare (array, val_size * k, val_size * next) <= 0) return; // If heap property is satisfied, exit
    heap_func_swap (array, val_size * k, val_size * next, val_size); // Swap with the smaller child
    k = next; // Move down to the next level
  }
  // Check if the last child needs to be swapped
  if (2 * k <= n && cmp.compare (array, val_size * k, val_size * 2 * k) > 0) {
    heap_func_swap (array, val_size * k, val_size * 2 * k, val_size);
  }
}

// Function to get the top value of the heap without removing it
void top (heap h, Object res) {
  Object[] array = h.array; // Cast array to Object[] for generic access
  int val_size = h.val_size; // Size of the value
  if (res!= null) {
    heap_func_copy (res, array, val_size); // Copy the top value to the result
  }
}

// Define a structure for Union-Find (Disjoint Set Union)
class UnionFind {
  int[] parent; // Array to hold the parent of each element
  int size; // Size of the Union-Find structure
}

// Function to initialize the Union-Find structure
void initUnionFind (UnionFind u) {
  for (int i = 0; i < u.size; ++i){
    u.parent[i] = -1; // Set each element's parent to -1 (indicating it is its own root)
  }
}

// Function to create a new Union-Find structure
UnionFind newUnionFind (int size) {
  UnionFind u = new UnionFind(); // Allocate memory for the structure
  u.parent = new int[size]; // Allocate memory for the parent array
  u.size = size; // Set the size
  initUnionFind (u); // Initialize the Union-Find structure
  return u; // Return the created structure
}

// Function to free the memory allocated for the Union-Find structure
void freeUnionFind (UnionFind u) {
  u.parent = null; // Free the parent array
  u = null; // Free the Union-Find structure
}

// Function to find the root of an element with path compression
int root (UnionFind u, int x) {
  int index[] = new int[32]; // Array to hold the path for compression
  int len = 0; // Length of the path
  while (u.parent[x] >= 0) {
    index[len++] = x; // Store the current index
    x = u.parent[x]; // Move to the parent
  }
  // Path compression: make all nodes point directly to the root
  while (len > 0) {
    u.parent[index[--len]] = x;
  }
  return x; // Return the root
}

// Function to check if two elements are in the same set
boolean same (UnionFind u, int x, int y) {
  return root (u, x) == root (u, y); // Return 1 if they have the same root, otherwise 0
}

// Function to get the size of the set containing element x
int getSize(UnionFind u, int x) {
  return - (u.parent[root (u, x)]); // Return the size of the set
}

// Function to unite two sets containing elements x and y
void unite(UnionFind u, int x, int y) {
  x = root (u, x); // Find the root of x
  y = root (u, y); // Find the root of y
  if (x == y) return; // If they are already in the same set, do nothing
  // Union by size: attach the smaller tree under the larger tree
  if (u.parent[x] > u.parent[y]) {
    int swap = x; // Swap x and y if necessary
    x = y;
    y = swap;
  }
  u.parent[x] += u.parent[y]; // Update the size of the new root
  u.parent[y] = x; // Make x the parent of y
}

// Define a structure for a segment tree
class segment_tree {
  Object[] array; // Pointer to the array that holds the segment tree nodes
  int size; // Size of the segment tree
  int val_size; // Size of each value in the segment tree
  BiConsumer<Object, Object, Object> func; // Function to combine two values
}

// Function to copy memory from source to destination
static void segment_tree_memcpy (Object[] dst, Object[] src, int size) {
  byte[] p = (byte[]) dst; // Pointer to destination
  byte[] q = (byte[]) src; // Pointer to source
  while (size-- > 0) {
    p[0] = q[0]; // Copy byte by byte
    p++;
    q++;
  }
}

// Function to create a