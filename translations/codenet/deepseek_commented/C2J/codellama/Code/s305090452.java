#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

// Define the structure of a binary heap and its operations.
class binaryHeap {
  private int[] array;
  private int heap_size;
  private int max_size;
  private int val_size;
  private int[] cmp;

  public binaryHeap (int val_size, int[] cmp) {
    this.array = new int[val_size * (1 + 1)];
    this.heap_size = 0;
    this.max_size = 1;
    this.val_size = val_size;
    this.cmp = cmp;
  }

  public int get_heap_size () {
    return this.heap_size;
  }

  public boolean is_empty () {
    return this.heap_size == 0;
  }

  public void free_heap () {
    this.array = null;
    this.cmp = null;
  }

  public void init_heap () {
    this.heap_size = 0;
  }

  public void heap_func_swap (int[] a, int[] b, int val_size) {
    if ((val_size & 7) == 0) {
      long[] p = new long[val_size / 8];
      long[] q = new long[val_size / 8];
      val_size /= 8;
      while (val_size--) {
        long tmp = p[val_size];
        p[val_size] = q[val_size];
        q[val_size] = tmp;
      }
    } else {
      byte[] p = new byte[val_size];
      byte[] q = new byte[val_size];
      while (val_size--) {
        byte tmp = p[val_size];
        p[val_size] = q[val_size];
        q[val_size] = tmp;
      }
    }
  }

  public void heap_func_copy (int[] dst, int[] src, int val_size) {
    if ((val_size & 7) == 0) {
      long[] p = new long[val_size / 8];
      long[] q = new long[val_size / 8];
      val_size /= 8;
      while (val_size--) {
        p[val_size] = q[val_size];
      }
    } else {
      byte[] p = new byte[val_size];
      byte[] q = new byte[val_size];
      while (val_size--) {
        p[val_size] = q[val_size];
      }
    }
  }

  public void push (int[] val) {
    if (this.heap_size == this.max_size) {
      this.max_size = 2 * this.max_size + 1;
      this.array = Arrays.copyOf(this.array, this.val_size * (this.max_size + 1));
    }
    this.heap_size++;
    int[] array = this.array;
    int k = this.heap_size;
    int val_size = this.val_size;
    int[] cmp = this.cmp;
    heap_func_copy(array, val, val_size);
    while(k>1){
      int parent = k / 2;
      if (cmp[parent] <= cmp[k]) {
        return;
      }
      heap_func_swap (array, k, val_size);
      k = parent;
    }
  }

  public void pop (int[] res) {
    int[] array = this.array;
    int val_size = this.val_size;
    if (res != null) {
      heap_func_copy (res, array + val_size, val_size);
    }
    heap_func_copy (array + val_size, array + val_size * this.heap_size, val_size);
    this.heap_size--;
    int[] cmp = this.cmp;
    int n = this.heap_size;
    int k = 1;
    while (2 * k  + 1 <= n) {
      int c = cmp[2 * k] - cmp[2 * k + 1];
      int next = 2 * k + (c <= 0 ? 0 : 1);
      if (cmp[k] <= cmp[next]) return;
      heap_func_swap (array + val_size * k, array + val_size * next, val_size);
      k = next;
    }
    if (2 * k <= n && cmp[k] > cmp[2 * k]) {
      heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
    }
  }

  public void top (int[] res) {
    int[] array = this.array;
    int val_size = this.val_size;
    if (res != null) {
      heap_func_copy (res, array + val_size, val_size);
    }
  }
}

// Define the structure of Union-Find and its operations.
class UnionFind {
  private int[] parent;
  private int size;

  public UnionFind (int size) {
    this.parent = new int[size];
    this.size = size;
  }

  public void initUnionFind () {
    for (int i = 0; i < this.size; ++i){
      this.parent[i] = -1;
    }
  }

  public int root (int x) {
    int[] index = new int[32];
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

  public boolean same (int x, int y) {
    return root (x) == root (y);
  }

  public int getSize(int x) {
    return - (this.parent[root (x)]);
  }

  public void unite(int x, int y) {
    x = root (x);
    y = root (y);
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

// Define the structure of a segment tree and its operations.
class segment_tree {
  private int[] array;
  private int size;
  private int val_size;
  private int[] func;

  public segment_tree (int[] ini, int n, int val_size, int[] func) {
    int k = 1;
    while (k < n) k *= 2;
    this.array = new int[2 * k];
    this.size = k;
    this.val_size = val_size;
    this.func = func;
    for (int i = k; i < 2 * k; ++i) {
      array[i] = ini[i];
    }
    int[] a = this.array;
    for (int i = k - 1; i > 0; --i) {
      func[i] = func[2 * i] + func[2 * i + 1];
    }
  }

  public void update (int k, int val) {
    k += this.size;
    int[] p = this.array;
    int size = this.val_size;
    array[k] = val;
    for (k >>= 1; k > 0; k >>= 1) {
      func[k] = func[2 * k] + func[2 * k + 1];
    }
  }

  public void update_tmp (int k, int val) {
    k += this.size;
    int[] p = this.array;
    int size = this.val_size;
    array[k] = val;
  }

  public void update_all () {
    int[] a = this.array;
    int size = this.val_size;
    for (int i = this.size - 1; i > 0; --i) {
      func[i] = func[2 * i] + func[2 * i + 1];
    }
  }

  public void find (int l, int r, int[] res) {
    int[] lindex = new int[32];
    int[] rindex = new int[32];
    int llen = 0;
    int rlen = 0;
    for (l += this.size, r += this.size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lindex[llen++] = l++;
      if (r & 1) rindex[rlen++] = --r;
    }
    int[] p = this.array;
    if (llen == 0) {
      lindex[llen++] = rindex[--rlen];
    }
    res[0] = p[lindex[0]];
    for (int i = 1; i < llen; ++i) {
      res[0] += p[lindex[i]];
    }
    for (int i = rlen - 1; i >= 0; --i) {
      res[0] += p[rindex[i]];
    }
  }
}

// Define the main function to run the program.
class Main {
  public static void run () {
    int n, d;
    scanf ("%d%d", &n, &d);
    int[] a = new int[n];
    index_val[] p = new index_val[n];
    for (int i = 0; i < n; ++i) {
      scanf ("%d", a + i);
      p[i] = new index_val(i, a[i]);
    }
    qsort (p, n, sizeof (index_val), cmp_index_val);
    int[] ini = new int[n];
    for (int i = 0; i < n; ++i) {
      ini[i] = p[i].index;
    }
    segment_tree l = new segment_tree (ini, n, sizeof (segment_node), func_segment_node);
    segment_tree r = new segment_tree (ini, n, sizeof (segment_node), func_segment_node);
    for (int i = 0; i < n; ++i) {
      l.update_tmp (i, p[i].val + (n - 1 - i) * d);
      r.update_tmp (i, p[i].val + i * d);
    }
    l.update_all ();
    r.update_all ();
    heap h = new binaryHeap (sizeof (edge), cmp_edge);
    for (int i = 0; i < n; ++i) {
      int v = p[i].index;
      if (v > 0) {
        segment_node t;
        l.find (0, v, t);
        h.push (new edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d));
      }
      if (v + 1 < n) {
        segment_node t;
        r.find (v + 1, n, t);
        h.push (new edge(v, t.index, p[i].val + t.val - v * d));
      }
      l.update (v, ini);
      r.update (v, ini);
    }
    long sum = 0;
    UnionFind u = new UnionFind (n);
    while (u.getSize (0) < n) {
      edge e;
      h.pop (e);
      if (u.same (e.a, e.b)) continue;
      u.unite (e.a, e.b);
      sum += e.c;
    }
    printf ("%ld\n", sum);
  }

  public static void main (String[] args) {
    run ();
  }
}

