#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef int32_t i32;
typedef int64_t i64;

#define mod 1000000007

#define new_graph(vertex_num) (graph *)calloc(1, sizeof(graph))
#define new_deque() (deque *)calloc(1, sizeof(deque))
#define get_size(d) ((d)->last + (~(d)->front + 1) & (d)->mask)
#define get_at(d, x) (d)->array[(d)->front + x & (d)->mask]
#define assign_at(d, x, v) (d)->array[(d)->front + x & (d)->mask] = v
#define push_front(d, v) \
  if((((d)->last + 1) & (d)->mask) == (d)->front) { \
    deque_realloc(d); \
  } \
  (d)->front = ((d)->front + (d)->mask) & (d)->mask; \
  (d)->array[(d)->front] = v;

#define cmp_deque_size(a, b) \
  (deque *)*a, (deque *)*b, \
  i32 d = get_size((deque *)*a) - get_size((deque *)*b), \
  d == 0 ? 0 : d > 0 ? -1 : 1;

#define free_deque(d) \
  free((d)->array); \
  free(d);

#define free_graph(g) \
  free((g)->edge); \
  free((g)->start); \
  free(g);

typedef struct directed_edge {
  int32_t vertex;
  int32_t next;
} graph_edge;

typedef struct directedGraph {
  graph_edge *edge;
  int32_t *start;
  int32_t pointer;
  int32_t vertex_num;
  int32_t edge_max_size;
} graph;

typedef struct dp_node {
  i32 one;
  i32 zero;
} node;

typedef struct Deque {
  node *array;
  size_t front;
  size_t last;
  size_t mask;
} deque;

def deque_realloc(d):
  d.array = (node *)realloc(d.array, 2 * (d.mask + 1) * sizeof(node));
  k = 0;
  for (size_t i = d.front; i != d.last; i = (i + 1) & d.mask) {
    d.array[k++] = d.array[i];
  }
  free(d.array);
  d.array = array;
  d.front = 0;
  d.last = k;
  d.mask = 2 * d.mask + 1;

def merge(a, n):
  one = 0;
  zero = 1;
  total = 1;
  for (i32 i = 0; i < n; ++i) {
    one = (one * a[i].zero + zero * a[i].one) % mod;
    zero = zero * a[i].zero % mod;
    total = total * (a[i].zero + a[i].one) % mod;
  }
  return (node) {one, (total + mod - one) % mod};

def mod_pow(r, n):
  t = 1;
  s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;

def run():
  n = int(input());
  p = (i32 *)calloc(n + 1, sizeof(i32));
  depth = (i32 *)calloc(n + 1, sizeof(i32));
  cnt = (i32 *)calloc(n + 1, sizeof(i32));
  cnt[0] = 1;
  g = new_graph(n + 1);
  for (i32 i = 1; i <= n; ++i) {
    p[i] = int(input());
    add_edge(g, p[i], i);
    depth[i] = depth[p[i]] + 1;
    cnt[depth[i]]++;
  }
  dp = (deque **)calloc(n + 1, sizeof(deque *));
  child = (deque **)calloc(n + 1, sizeof(deque *));
  lst = (node *)calloc(n + 1, sizeof(node));
  for (i32 i = n; i >= 0; --i) {
    v = i;
    if (g.start[v] == -1) {
      dp[v] = new_deque();
      push_front(dp[v], (node) {1, 1});
      continue;
    }
    len = 0;
    for (i32 p = g.start[v]; p != -1; p = g.edge[p].next) {
      u = g.edge[p].vertex;
      child[len++] = dp[u];
    }
    if (len > 1) {
      qsort(child, len, sizeof(deque *), cmp_deque_size);
      for (i32 d = 0; d < (i32)get_size(child[1]); ++d) {
        j = 0;
        for (; j < len && d < (i32)get_size(child[j]); ++j) {
          lst[j] = get_at(child[j], d);
        }
        assign_at(child[0], d, merge(lst, j));
      }
      for (i32 j = 1; j < len; ++j) {
        free_deque(child[j]);
      }
    }
    dp[v] = child[0];
    push_front(dp[v], (node) {1, 1});
  }
  ans = 0;
  for (i32 i = 0; i < (i32)get_size(dp[0]); ++i) {
    ans += (i64)mod_pow(2, n + 1 - cnt[i]) * get_at(dp[0], i).one % mod;
  }
  print(ans % mod);

def add_edge(g, from, to):
  if (g.pointer == g.edge_max_size) {
    g.edge_max_size *= 2;
    g.edge = (graph_edge *)realloc(g.edge, sizeof(graph_edge) * g.edge_max_size);
  }
  g.edge[g.pointer] = (graph_edge) {to, g.start[from]};
  g.start[from] = g.pointer++;

def free_graph(g):
  free(g.edge);
  free(g.start);
  free(g);

def free_deque(d):
  free(d.array);
  free(d);

def main():
  run();

