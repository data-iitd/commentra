

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef struct binaryHeap{
  void *array;
  size_t heap_size;
  size_t max_size;
  size_t val_size;
  int (*cmp) (const void *, const void *);
} heap;

heap* new_binary_heap (const size_t val_size, int (*cmpF) (const void *, const void *)) {
  heap *h = (heap *) calloc (1, sizeof (heap));
  h->array = malloc (val_size * (1 + 1));
  h->heap_size = 0;
  h->max_size = 1;
  h->val_size = val_size;
  h->cmp = cmpF;
  return h;
}

int32_t get_heap_size (const heap *h) {
  return h->heap_size;
}

int is_empty (const heap *h) {
  return h->heap_size == 0;
}

void free_heap (heap *h) {
  free (h->array);
  free (h);
}

void init_heap (heap *h) {
  h->heap_size = 0;
}

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

void push (heap *h, const void *val) {
  if (h->heap_size == h->max_size) {
    h->max_size = 2 * h->max_size + 1;
    h->array = realloc (h->array, h->val_size * (h->max_size + 1));
  }
  h->heap_size++;
  uint8_t *array = (uint8_t *) h->array;
  size_t k = h->heap_size;
  const size_t val_size = h->val_size;
  int (*cmp) (const void *, const void *) = h->cmp;
  heap_func_copy (array + k * val_size, val, val_size);
  while(k>1){
    size_t parent = k / 2;
    if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
      return;
    }
    heap_func_swap (array + parent * val_size, array + k * val_size, val_size);
    k = parent;
  }
}

void pop (heap *h, void *res) {
  uint8_t *array = (uint8_t *) h->array;
  const size_t val_size = h->val_size;
  if (res!= NULL) {
    heap_func_copy (res, array + val_size, val_size);
  }
  heap_func_copy (array + val_size, array + val_size * h->heap_size, val_size);
  h->heap_size--;
  int (* const cmp) (const void *, const void *) = h->cmp;
  const size_t n = h->heap_size;
  size_t k = 1;
  while (2 * k + 1 <= n) {
    int c = cmp (array + 2 * k * val_size, array + (2 * k + 1) * val_size);
    size_t parent = k / 2;
    if (2 * k + 1 <= n && cmp (array + 2 * k * val_size, array + (2 * k + 1) * val_size) > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t parent = k;
    while (parent > 1) {
      parent >>= 1;
    }
    while (parent > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t parent = k;
    while (parent > 1) {
      parent >>= 1;
    }
    while (parent > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t p = k;
    while (p > 1) {
      p >>= 1;
    }
    while (p > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t p = k;
    while (p > 1) {
      p >>= 1;
    }
    while (p > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t r = k;
    while (r > 1) {
      r >>= 1;
    }
    while (r > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t p = k;
    while (p > 1) {
      p >>= 1;
    }
    while (p > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      l >>= 1;
    }
    while (l > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t p = k;
    while (p > 0) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 0) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size, array + (2 * k + 1) * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t l = k;
    while (l > 1) {
      return;
    }
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    while (p > 1) {
      return;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * val_size);
    size_t p = k;
    }
    heap_func_copy (array + k * v