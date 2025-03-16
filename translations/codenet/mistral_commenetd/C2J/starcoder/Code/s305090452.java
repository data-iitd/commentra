
import java.util.*;

public class Main {
  public static void main (String[] args) {
    Scanner sc = new Scanner (System.in);
    int n = sc.nextInt ();
    int d = sc.nextInt ();
    int[] a = new int[n];
    index_val[] p = new index_val[n];
    for (int i = 0; i < n; ++i) {
      a[i] = sc.nextInt ();
      p[i] = new index_val();
      p[i].index = i;
      p[i].val = a[i];
    }
    Arrays.sort (p, (a, b) -> a.val - b.val);
    segment_node ini = new segment_node();
    ini.index = n;
    ini.val = (n + 2) * 1000000000 + 1;
    segment_tree l = new segment_tree (ini, n, (a, b) -> a.val < b.val? a : b);
    segment_tree r = new segment_tree (ini, n, (a, b) -> a.val < b.val? a : b);
    for (int i = 0; i < n; ++i) {
      update_tmp (l, i, new segment_node());
      update_tmp (r, i, new segment_node());
      l.array[i].index = i;
      l.array[i].val = a[i] + (n - 1 - i) * d;
      r.array[i].index = i;
      r.array[i].val = a[i] + i * d;
    }
    update_all (l);
    update_all (r);
    heap h = new heap (n, (a, b) -> a.c - b.c);
    for (int i = 0; i < n; ++i) {
      int v = p[i].index;
      if (v > 0) {
        segment_node t = find (l, 0, v);
        h.array[h.heap_size++] = new edge();
        h.array[h.heap_size - 1].a = v;
        h.array[h.heap_size - 1].b = t.index;
        h.array[h.heap_size - 1].c = p[i].val + t.val;
      }
    }
    while (h.heap_size > 1) {
      edge e = pop (h);
      if (same (h, e.a, e.b)) continue;
      unite (h, e.a, e.b);
      if (e.a > 0) {
        segment_node t = find (l, 0, e.a);
        push (h, new edge());
        h.array[h.heap_size - 1].a = e.a;
        h.array[h.heap_size - 1].b = t.index;
        h.array[h.heap_size - 1].c = p[e.a].val + t.val;
      }
      if (e.b > 0) {
        segment_node t = find (r, 0, e.b);
        push (h, new edge());
        h.array[h.heap_size - 1].a = e.b;
        h.array[h.heap_size - 1].b = t.index;
        h.array[h.heap_size - 1].c = p[e.b].val + t.val;
      }
    }
    System.out.println (h.array[0].c);
  }
}

// Define a structure for segment tree

class segment_tree {
  public segment_node[] array;
  public int32_t size;
  public size_t val_size;
  public function<void(void*, const void*, const void*)> func;

  public segment_tree (segment_node ini, int32_t n, function<void(void*, const void*, const void*)> func) {
    int32_t k = 1;
    while (k < n) k *= 2;
    array = new segment_node[2 * k];
    size = k;
    val_size = sizeof (segment_node);
    this.func = func;
    for (int32_t i = k; i < 2 * k; ++i) {
      segment_tree_memcpy (array[i], ini, val_size);
    }
    segment_node[] a = array;
    for (int32_t i = k - 1; i > 0; --i) {
      func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }

  public void update (int32_t k, segment_node val) {
    k += size;
    segment_tree_memcpy (array[k], val, val_size);
    for (k >>= 1; k > 0; k >>= 1) {
      func (array[k], array[2 * k], array[2 * k + 1]);
    }
  }

  public void update_tmp (int32_t k, segment_node val) {
    k += size;
    segment_tree_memcpy (array[k], val, val_size);
  }

  public void update_all () {
    segment_node[] a = array;
    for (int32_t i = size - 1; i > 0; --i) {
      func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }
}

// Define a structure for segment node

class segment_node {
  public int32_t index;
  public int64_t val;
}

// Define a structure for index_val

class index_val {
  public int32_t index;
  public int32_t val;
}

// Define a structure for edge

class edge {
  public int32_t a, b;
  public int64_t c;
}

// Define a structure for binary heap

class heap {
  public edge[] array;
  public int32_t heap_size;
  public int32_t max_size;
  public size_t val_size;
  public function<int(const void*, const void*)> cmp;

  public heap (int32_t val_size, function<int(const void*, const void*)> cmp) {
    array = new edge[1];
    heap_size = 0;
    max_size = 1;
    this.val_size = val_size;
    this.cmp = cmp;
  }

  public static void segment_tree_memcpy (void* dst, const void* src, size_t size) {
    uint8_t* p = (uint8_t*) dst;
    const uint8_t* q = (uint8_t*) src;
    while (size--) {
      *p++ = *q++;
    }
  }

  public static segment_node find (segment_tree s, int32_t l, int32_t r) {
    int32_t lindex[32];
    int32_t rindex[32];
    int32_t llen = 0;
    int32_t rlen = 0;
    for (l += s.size, r += s.size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lindex[llen++] = l++;
      if (r & 1) rindex[rlen++] = --r;
    }
    segment_node res = new segment_node();
    if (llen == 0) {
      lindex[llen++] = rindex[--rlen];
    }
    segment_tree_memcpy (res, s.array[lindex[0]], s.val_size);
    for (int32_t i = 1; i < llen; ++i) {
      s.func (res, res, s.array[lindex[i]]);
    }
    for (int32_t i = rlen - 1; i >= 0; --i) {
      s.func (res, res, s.array[rindex[i]]);
    }
    return res;
  }

  public static void push (heap h, edge e) {
    if (h.heap_size == h.max_size) {
      h.max_size = 2 * h.max_size + 1;
      h.array = Arrays.copyOf (h.array, h.max_size);
    }
    h.heap_size++;
    h.array[h.heap_size] = e;
    int32_t k = h.heap_size;
    while (k > 1) {
      int32_t parent = k / 2;
      if (h.cmp (h.array[parent], h.array[k]) <= 0) {
        return;
      }
      edge tmp = h.array[parent];
      h.array[parent] = h.array[k];
      h.array[k] = tmp;
      k = parent;
    }
  }

  public static edge pop (heap h) {
    edge res = h.array[1];
    h.array[1] = h.array[h.heap_size--];
    int32_t k = 1;
    while (2 * k + 1 <= h.heap_size) {
      int32_t c = h.cmp (h.array[2 * k], h.array[2 * k + 1]);
      int32_t next = 2 * k + (c <= 0? 0 : 1);
      if (h.cmp (h.array[k], h.array[next]) <= 0) {
        return res;
      }
      edge tmp = h.array[k];
      h.array[k] = h.array[next];
      h.array[next] = tmp;
      k = next;
    }
    if (2 * k <= h.heap_size && h.cmp (h.array[k], h.array[2 * k]) > 0) {
      edge tmp = h.array[k];
      h.array[k] = h.array[2 * k];
      h.array[2 * k] = tmp;
    }
    return res;
  }

  public static void top (heap h, edge res) {
    res = h.array[1];
  }

  public static void init_heap (heap h) {
    h.heap_size = 0;
  }

  public static int get_heap_size (heap h) {
    return h.heap_size;
  }

  public static boolean is_empty (heap h) {
    return h.heap_size == 0;
  }

  public static void free_heap (heap h) {
    h.array = null;
    h.heap_size = 0;
    h.max_size = 0;
    h.val_size = 0;
    h.cmp = null;
  }

  public static void initUnionFind (UnionFind u) {
    for (int32_t i = 0; i < u.size; ++i) {
      u.parent[i] = -1;
    }
  }

  public static UnionFind newUnionFind (int32_t size) {
    UnionFind u = new UnionFind();
    u.parent = new int32_t[size];
    u.size = size;
    initUnionFind (u);
    return u;
  }

  public static void freeUnionFind (UnionFind u) {
    u.parent = null;
    u.size = 0;
  }

  public static int32_t root (UnionFind u, int32_t x) {
    int32_t index[32];
    int32_t len = 0;
    while (u.parent[x] >= 0) {
      index[len++] = x;
      x = u.parent[x];
    }
    while (len > 0) {
      u.parent[index[--len]] = x;
    }
    return x;
  }

  public static boolean same (UnionFind u, int32_t x, int32_t y) {
    return root (u, x) == root (u, y);
  }

  public static int32_t getSize (UnionFind u, int32_t x) {
    return -u.parent[root (u, x)];
  }

  public static void unite (UnionFind u, int32_t x, int32_t y) {
    x = root (u, x);
    y = root (u, y);
    if (x == y) return;
    if (u.parent[x] > u.parent[y]) {
      int32_t swap = x;
      x = y;
      y = swap;
    }
    u.parent[x] += u.parent[y];
    u.parent[y] = x;
  }
}

// Define a structure for Union-Find data structure

class UnionFind {
  public int32_t[] parent;
  public int32_t size;

  public void initUnionFind (UnionFind u) {
    for (int32_t i = 0; i < u.size; ++i) {
      u.parent[i] = -1;
    }
  }

  public UnionFind newUnionFind (int32_t size) {
    UnionFind u = new UnionFind();
    u.parent = new int32_t[size];
    u.size = size;
    initUnionFind (u);
    return u;
  }

  public void freeUnionFind (UnionFind u) {
    u.parent = null;
    u.size = 0;
  }

  public int32_t root (UnionFind u, int32_t x) {
    int32_t index[32];
    int32_t len = 0;
    while (u.parent[x] >= 0) {
      index[len++] = x;
      x = u.parent[x];
    }
    while (len > 0) {
      u.parent[index[--len]] = x;
    }
    return x;
  }

  public boolean same (UnionFind u, int32_t x, int32_t y) {
    return root (u, x) == root (u, y);
  }

  public int32_t getSize (UnionFind u, int32_t x) {
    return -u.parent[root (u, x)];
  }

  public void unite (UnionFind u, int32_t x, int32_t y) {
    x = root (u, x);
    y = root (u, y);
    if (x == y) return;
    if (u.parent[x] > u.parent[y]) {
      int32_t swap = x;
      x = y;
      y = swap;
    }
    u.parent[x] += u.parent[y];
    u.parent[y] = x;
  }
}

// Define a structure for segment tree

class segment_tree {
  public segment_node[] array;
  public int32_t size;
  public size_t val_size;
  public function<void(void*, const void*, const void*)> func;

  public segment_tree (segment_node ini, int32_t n, function<void(void*, const void*, const void*)> func) {
    int32_t k = 1;
    while (k < n) k *= 2;
    array = new segment_node[2 * k];
    size = k;
    val_size = sizeof (segment_node);
    this.func = func;
    for (int32_t i = k; i < 2 * k; ++i) {
      segment_tree_memcpy (array[i], ini, val_size);
    }
    segment_node[] a = array;
    for (int32_t i = k - 1; i > 0; --i) {
      func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }

  public void update (int32_t k, segment_node val) {
    k += size;
    segment_tree_memcpy (array[k], val, val_size);
    for (k >>= 1; k > 0; k >>= 1) {
      func (array[k], array[2 * k], array[2 * k + 1]);
    }
  }

  public void update_tmp (int32_t k, segment_node val) {
    k += size;
    segment_tree_memcpy (array[k], val, val_size);
  }

  public void update_all () {
    segment_node[] a = array;
    for (int32_