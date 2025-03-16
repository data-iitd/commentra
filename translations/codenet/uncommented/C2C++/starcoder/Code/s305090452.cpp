#include<bits/stdc++.h>
using namespace std;

typedef long long i64;

struct UnionFind {
  int32_t *parent;
  int32_t size;
};

void initUnionFind (UnionFind *u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1;
  }
}

UnionFind* newUnionFind (const int32_t size) {
  UnionFind *u = (UnionFind *) calloc (1, sizeof (UnionFind));
  u->parent = (int32_t *) calloc (size, sizeof (int32_t));
  u->size = size;
  initUnionFind (u);
  return u;
}

void freeUnionFind (UnionFind *u) {
  free (u->parent);
  free (u);
}

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

int same (UnionFind *u, int32_t x, int32_t y) {
  return root (u, x) == root (u, y);
}

int32_t getSize(UnionFind *u, int32_t x) {
  return - (u->parent[root (u, x)]);
}

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

struct segment_tree_void {
  void *array;
  int32_t size;
  size_t val_size;
  void (*func) (void *, const void *, const void *);
};

static inline void segment_tree_memcpy (void *dst, const void *src, size_t size) {
  uint8_t *p = dst;
  const uint8_t *q = src;
  while (size--) {
    *p++ = *q++;
  }
}

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

void update (segment_tree_void * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t *p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
  for (k >>= 1; k > 0; k >>= 1) {
    s->func (p + k * size, p + 2 * k * size, p + (2 * k + 1) * size);
  }
}

void update_tmp (segment_tree_void * const s, int32_t k, const void *val) {
  k += s->size;
  uint8_t *p = s->array;
  const size_t size = s->val_size;
  segment_tree_memcpy (p + k * size, val, size);
}

void update_all (segment_tree_void * const s) {
  uint8_t * const a = s->array;
  const size_t size = s->val_size;
  for (int32_t i = s->size - 1; i > 0; --i) {
    s->func (a + i * size, a + (2 * i) * size, a + (2 * i + 1) * size);
  }
}

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
  }
}

struct edge {
  int32_t a, b;
  i64 c;
};

int cmp_edge (const void *a, const void *b) {
  i64 d = ((edge *)a)->c - ((edge *)b)->c;
  return d == 0? 0 : d < 0? -1 : 1;
}

struct index_val {
  int32_t index;
  int32_t val;
};

int cmp_index_val (const void *a, const void *b) {
  int32_t d = ((index_val *)a)->val - ((index_val *)b)->val;
  return d == 0? 0 : d > 0? -1 : 1;
}

struct segment_node {
  int32_t index;
  i64 val;
};

void func_segment_node (void *c, const void *a, const void *b) {
  const segment_node *p = (const segment_node *)a;
  const segment_node *q = (const segment_node *)b;
  *(segment_node *)c = p->val < q->val? *p : *q;
}

void run (void) {
  int32_t n, d;
  scanf ("%" SCNd32 " %" SCNd32, &n, &d);
  int32_t *a = (int32_t *) calloc (n, sizeof (int32_t));
  index_val *p = (index_val *) calloc (n, sizeof (index_val));
  for (int32_t i = 0; i < n; ++i) {
    scanf ("%" SCNd32, a + i);
    p[i] = (index_val){i, a[i]};
  }
  qsort (p, n, sizeof (index_val), cmp_index_val);
  const segment_node ini = {n, (i64)(n + 2) * 1000000000 + 1};
  segment_tree_void *l = new_segment_tree (&ini, n, sizeof (segment_node), func_segment_node);
  segment_tree_void *r = new_segment_tree (&ini, n, sizeof (segment_node), func_segment_node);
  for (int32_t i = 0; i < n; ++i) {
    update_tmp (l, i, &((segment_node){i, a[i] + (i64)(n - 1 - i) * d}));
    update_tmp (r, i, &((segment_node){i, a[i] + (i64)i * d}));
  }
  update_all (l);
  update_all (r);
  heap *h = new_binary_heap (sizeof (edge), cmp_edge);
  for (int32_t i = 0; i < n; ++i) {
    int32_t v = p[i].index;
    if (v > 0) {
      segment_node t;
      find (l, 0, v, &t);
      push (h, &((edge){v, t.index, p[i].val + t.val - (i64) (n - 1 - v) * d}));
    }
    if (v + 1 < n) {
      segment_node t;
      find (r, v + 1, n, &t);
      push (h, &((edge){v, t.index, p[i].val + t.val - (i64) v * d}));
    }
    update (l, v, &ini);
    update (r, v, &ini);
  }
  i64 sum = 0;
  UnionFind *u = newUnionFind (n);
  while (getSize (u, 0) < n) {
    edge e;
    pop (h, &e);
    if (same (u, e.a, e.b)) continue;
    unite (u, e.a, e.b);
    sum += e.c;
  }
  printf ("%" PRIi64 "\n", sum);
}

int main (void) {
  run ();
  return 0;
}

