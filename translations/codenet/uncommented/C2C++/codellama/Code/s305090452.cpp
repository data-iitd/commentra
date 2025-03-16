#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdint>
#include<cstring>
#include<algorithm>
#include<functional>

using namespace std;

typedef int32_t i32;
typedef int64_t i64;

struct index_val {
  i32 index;
  i32 val;
};

bool cmp_index_val (const index_val &a, const index_val &b) {
  i32 d = a.val - b.val;
  return d == 0 ? 0 : d > 0 ? -1 : 1;
}

struct segment_node {
  i32 index;
  i64 val;
};

void func_segment_node (segment_node *c, const segment_node *a, const segment_node *b) {
  *c = a->val < b->val ? *a : *b;
}

struct edge {
  i32 a, b;
  i64 c;
};

bool cmp_edge (const edge &a, const edge &b) {
  i64 d = a.c - b.c;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n, d;
  scanf ("%" SCNi32 "%" SCNi32, &n, &d);
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  index_val *p = (index_val *) calloc (n, sizeof (index_val));
  for (i32 i = 0; i < n; ++i) {
    scanf ("%" SCNi32, a + i);
    p[i] = (index_val){i, a[i]};
  }
  sort (p, p + n, cmp_index_val);
  const segment_node ini = {n, (i64)(n + 2) * 1000000000 + 1};
  segment_node *l = (segment_node *) calloc (n, sizeof (segment_node));
  segment_node *r = (segment_node *) calloc (n, sizeof (segment_node));
  for (i32 i = 0; i < n; ++i) {
    l[i] = (segment_node){i, a[i] + (i64)(n - 1 - i) * d};
    r[i] = (segment_node){i, a[i] + (i64)i * d};
  }
  for (i32 i = 0; i < n; ++i) {
    l[i].val = min (l[i].val, l[i - 1].val);
    r[i].val = min (r[i].val, r[i + 1].val);
  }
  priority_queue<edge, vector<edge>, greater<edge>> h;
  for (i32 i = 0; i < n; ++i) {
    i32 v = p[i].index;
    if (v > 0) {
      h.push (edge{v, p[i].index, p[i].val + l[v - 1].val - (i64) (n - 1 - v) * d});
    }
    if (v + 1 < n) {
      h.push (edge{v, p[i].index, p[i].val + r[v + 1].val - (i64) v * d});
    }
  }
  i64 sum = 0;
  i32 *u = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    u[i] = -1;
  }
  while (h.size () > 0) {
    edge e = h.top ();
    h.pop ();
    if (u[e.a] == e.b) continue;
    u[e.a] = e.b;
    sum += e.c;
  }
  printf ("%" PRIi64 "\n", sum);
}

int main (void) {
  run ();
  return 0;
}

