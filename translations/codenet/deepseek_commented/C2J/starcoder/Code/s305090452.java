
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
      p[i] = new index_val (i, a[i]);
    }
    Arrays.sort (p, (a, b) -> a.val - b.val);
    segment_node ini = new segment_node (n, (long)(n + 2) * 1000000000 + 1);
    segment_tree l = new segment_tree (ini, n, segment_node::func);
    segment_tree r = new segment_tree (ini, n, segment_node::func);
    for (int i = 0; i < n; ++i) {
      l.update_tmp (i, new segment_node (i, a[i] + (long)(n - 1 - i) * d));
      r.update_tmp (i, new segment_node (i, a[i] + (long)i * d));
    }
    l.update_all ();
    r.update_all ();
    heap h = new heap (edge::cmp);
    for (int i = 0; i < n; ++i) {
      int v = p[i].index;
      if (v > 0) {
        segment_node t = l.find (0, v);
        h.push (new edge (v, t.index, p[i].val + t.val - (long)(n - 1 - v) * d));
      }
      if (v + 1 < n) {
        segment_node t = r.find (v + 1, n);
        h.push (new edge (v, t.index, p[i].val + t.val - (long)v * d));
      }
      l.update (v, ini);
      r.update (v, ini);
    }
    long sum = 0;
    UnionFind u = new UnionFind (n);
    while (u.getSize (0) < n) {
      edge e = h.pop ();
      if (u.same (e.a, e.b)) continue;
      u.unite (e.a, e.b);
      sum += e.c;
    }
    System.out.println (sum);
  }
}

class index_val {
  int index;
  int val;
  index_val (int index, int val) {
    this.index = index;
    this.val = val;
  }
}

class segment_node {
  int index;
  long val;
  segment_node (int index, long val) {
    this.index = index;
    this.val = val;
  }
  static void func (segment_node c, segment_node a, segment_node b) {
    c.val = a.val < b.val? a.val : b.val;
  }
}

class edge {
  int a, b;
  long c;
  edge (int a, int b, long c) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
  static int cmp (edge a, edge b) {
    long d = a.c - b.c;
    return d == 0? 0 : d < 0? -1 : 1;
  }
}

class segment_tree {
  segment_node[] array;
  int size;
  int val_size;
  void (*func) (segment_node, segment_node, segment_node);
  segment_tree (segment_node ini, int size, void (*func) (segment_node, segment_node, segment_node)) {
    int k = 1;
    while (k < size) k *= 2;
    this.array = new segment_node[2 * k];
    this.size = k;
    this.val_size = ini.val;
    this.func = func;
    for (int i = k; i < 2 * k; ++i) {
      this.array[i] = ini;
    }
    segment_node[] a = this.array;
    for (int i = k - 1; i > 0; --i) {
      this.func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }
  void update (int k, segment_node val) {
    k += this.size;
    this.array[k] = val;
    for (k >>= 1; k > 0; k >>= 1) {
      this.func (this.array[k], this.array[2 * k], this.array[2 * k + 1]);
    }
  }
  void update_tmp (int k, segment_node val) {
    k += this.size;
    this.array[k] = val;
  }
  void update_all () {
    segment_node[] a = this.array;
    for (int i = this.size - 1; i > 0; --i) {
      this.func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }
  segment_node find (int l, int r) {
    int lindex[] = new int[32];
    int rindex[] = new int[32];
    int llen = 0;
    int rlen = 0;
    for (l += this.size, r += this.size; l < r; l >>= 1, r >>= 1) {
      if ((l & 1)!= 0) lindex[llen++] = l++;
      if ((r & 1)!= 0) rindex[rlen++] = --r;
    }
    if (llen == 0) {
      lindex[llen++] = rindex[--rlen];
    }
    segment_node res = this.array[lindex[0]];
    for (int i = 1; i < llen; ++i) {
      this.func (res, res, this.array[lindex[i]]);
    }
    for (int i = rlen - 1; i >= 0; --i) {
      this.func (res, res, this.array[rindex[i]]);
    }
    return res;
  }
}

class UnionFind {
  int[] parent;
  int size;
  UnionFind (int size) {
    this.parent = new int[size];
    this.size = size;
    for (int i = 0; i < size; ++i) {
      this.parent[i] = -1;
    }
  }
  void initUnionFind () {
    for (int i = 0; i < this.size; ++i) {
      this.parent[i] = -1;
    }
  }
  int root (int x) {
    int index[] = new int[32];
    int len = 0;
    while (this.parent[x] >= 0) {
      index[len++] = x;
      x = this.parent[x];
    }
    while (len > 0) {
      this.parent[index[--len]] = x;
    }
    return x;
  }
  boolean same (int x, int y) {
    return this.root (x) == this.root (y);
  }
  int getSize (int x) {
    return - this.parent[this.root (x)];
  }
  void unite (int x, int y) {
    x = this.root (x);
    y = this.root (y);
    if (x == y) return;
    if (this.parent[x] > this.parent[y]) {
      int swap = x;
      x = y;
      y = swap;
    }
    this.parent[x] += this.parent[y];
    this.parent[y] = x;
  }
}

class heap {
  edge[] array;
  int heap_size;
  int max_size;
  int val_size;
  int (*cmp) (edge, edge);
  heap (int (*cmp) (edge, edge)) {
    this.array = new edge[1];
    this.heap_size = 0;
    this.max_size = 1;
    this.val_size = edge.class.getDeclaredFields ().length;
    this.cmp = cmp;
  }
  int get_heap_size () {
    return this.heap_size;
  }
  boolean is_empty () {
    return this.heap_size == 0;
  }
  void free_heap () {
    this.array = null;
  }
  void init_heap () {
    this.heap_size = 0;
  }
  static void swap (Object a, Object b, int val_size) {
    try {
      for (int i = 0; i < val_size; ++i) {
        Object tmp = a.getClass ().getField ("f" + i).get (a);
        a.getClass ().getField ("f" + i).set (a, b.getClass ().getField ("f" + i).get (b));
        b.getClass ().getField ("f" + i).set (b, tmp);
      }
    } catch (Exception e) {
      e.printStackTrace ();
    }
  }
  static void copy (Object dst, Object src, int val_size) {
    try {
      for (int i = 0; i < val_size; ++i) {
        dst.getClass ().getField ("f" + i).set (dst, src.getClass ().getField ("f" + i).get (src));
      }
    } catch (Exception e) {
      e.printStackTrace ();
    }
  }
  void push (edge val) {
    if (this.heap_size == this.max_size) {
      this.max_size = 2 * this.max_size + 1;
      this.array = Arrays.copyOf (this.array, this.max_size);
    }
    this.heap_size++;
    Object[] array = this.array;
    int k = this.heap_size;
    int val_size = this.val_size;
    int (*cmp) (edge, edge) = this.cmp;
    copy (array[k], val, val_size);
    while (k > 1) {
      int parent = k / 2;
      if (cmp (array[parent], array[k]) <= 0) {
        return;
      }
      swap (array[parent], array[k], val_size);
      k = parent;
    }
  }
  void pop (edge res) {
    Object[] array = this.array;
    int val_size = this.val_size;
    if (res!= null) {
      copy (res, array[val_size], val_size);
    }
    copy (array[val_size], array[val_size * this.heap_size], val_size);
    this.heap_size--;
    int (* const cmp) (edge, edge) = this.cmp;
    int n = this.heap_size;
    int k = 1;
    while (2 * k  + 1 <= n) {
      int c = cmp (array[val_size * 2 * k], array[val_size * (2 * k + 1)]);
      int next = 2 * k + (c <= 0? 0 : 1);
      if (cmp (array[val_size * k], array[val_size * next]) <= 0) return;
      swap (array[val_size * k], array[val_size * next], val_size);
      k = next;
    }
    if (2 * k <= n && cmp (array[val_size * k], array[val_size * 2 * k]) > 0) {
      swap (array[val_size * k], array[val_size * 2 * k], val_size);
    }
  }
  void top (edge res) {
    Object[] array = this.array;
    int val_size = this.val_size;
    if (res!= null) {
      copy (res, array[val_size], val_size);
    }
  }
}

