#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

class binaryHeap{
  private Object[] array;
  private int heap_size;
  private int max_size;
  private int val_size;
  private int (*cmp) (const void *, const void *);

  public binaryHeap (int val_size, int (*cmpF) (const void *, const void *)) {
    array = new Object[val_size * (1 + 1)];
    heap_size = 0;
    max_size = 1;
    this.val_size = val_size;
    cmp = cmpF;
  }

  public int get_heap_size () {
    return heap_size;
  }

  public boolean is_empty () {
    return heap_size == 0;
  }

  public void free_heap () {
    array = null;
  }

  public void init_heap () {
    heap_size = 0;
  }

  private void heap_func_swap (int a, int b, int val_size) {
    if ((val_size & 7) == 0) {
      long[] p = (long[]) array;
      long[] q = (long[]) array;
      val_size /= 8;
      while (val_size--) {
        long tmp = p[a];
        p[a++] = q[b];
        q[b++] = tmp;
      }
    } else {
      byte[] p = (byte[]) array;
      byte[] q = (byte[]) array;
      while (val_size--) {
        byte tmp = p[a];
        p[a++] = q[b];
        q[b++] = tmp;
      }
    }
  }

  private void heap_func_copy (int dst, int src, int val_size) {
    if ((val_size & 7) == 0) {
      long[] p = (long[]) array;
      long[] q = (long[]) array;
      val_size /= 8;
      while (val_size--) {
        p[dst++] = q[src++];
      }
    } else {
      byte[] p = (byte[]) array;
      byte[] q = (byte[]) array;
      while (val_size--) {
        p[dst++] = q[src++];
      }
    }
  }

  public void push (Object val) {
    if (heap_size == max_size) {
      max_size = 2 * max_size + 1;
      array = Arrays.copyOf (array, val_size * (max_size + 1));
    }
    heap_size++;
    int k = heap_size;
    int val_size = this.val_size;
    int (*cmp) (const void *, const void *) = this.cmp;
    heap_func_copy(array, k * val_size, val, val_size);
    while(k>1){
      int parent = k / 2;
      if (cmp (array + parent * val_size, array + k * val_size) <= 0) {
        return;
      }
      heap_func_swap (array + parent * val_size, array + k * val_size, val_size);
      k = parent;
    }
  }

  public void pop (Object res) {
    int[] array = (int[]) this.array;
    int val_size = this.val_size;
    if (res != null) {
      heap_func_copy (res, array + val_size, val_size);
    }
    heap_func_copy (array + val_size, array + val_size * heap_size, val_size);
    heap_size--;
    int (* const cmp) (const void *, const void *) = this.cmp;
    int n = heap_size;
    int k = 1;
    while (2 * k  + 1 <= n) {
      int next = 2 * k + (cmp (array + val_size * 2 * k, array + val_size * (2 * k + 1)) <= 0 ? 0 : 1);
      if (cmp (array + val_size * k, array + val_size * next) <= 0) return;
      heap_func_swap (array + val_size * k, array + val_size * next, val_size);
      k = next;
    }
    if (2 * k <= n && cmp (array + val_size * k, array + val_size * 2 * k) > 0) {
      heap_func_swap (array + val_size * k, array + val_size * 2 * k, val_size);
    }
  }

  public void top (Object res) {
    int[] array = (int[]) this.array;
    int val_size = this.val_size;
    if (res != null) {
      heap_func_copy (res, array + val_size, val_size);
    }
  }
}

class UnionFind {
  private int[] parent;
  private int size;

  public UnionFind (int size) {
    parent = new int[size];
    this.size = size;
    initUnionFind ();
  }

  public void initUnionFind () {
    for (int i = 0; i < size; ++i){
      parent[i] = -1;
    }
  }

  public int root (int x) {
    int index[] = new int[32];
    int len = 0;
    while (parent[x] >= 0) {
      index[len++] = x;
      x = parent[x];
    }
    while (len > 0) {
      parent[index[--len]] = x;
    }
    return x;
  }

  public boolean same (int x, int y) {
    return root (x) == root (y);
  }

  public int getSize(int x) {
    return - (parent[root (x)]);
  }

  public void unite(int x, int y) {
    x = root (x);
    y = root (y);
    if (x == y) return;
    if (parent[x] > parent[y]) {
      int swap = x;
      x = y;
      y = swap;
    }
    parent[x] += parent[y];
    parent[y] = x;
  }
}

class segment_tree {
  private Object array;
  private int size;
  private int val_size;
  private void (*func) (void *, const void *, const void *);

  public segment_tree (Object ini, int n, int val_size, void (*func) (void *, const void *, const void *)) {
    int k = 1;
    while (k < n) k *= 2;
    this.array = new Object[2 * k];
    this.size = k;
    this.val_size = val_size;
    this.func = func;
    for (int i = k; i < 2 * k; ++i) {
      array[i] = ini;
    }
    Object[] a = (Object[]) this.array;
    for (int i = k - 1; i > 0; --i) {
      func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }

  public void update (int k, Object val) {
    k += size;
    Object[] p = (Object[]) this.array;
    int size = this.val_size;
    for (int i = 0; i < size; ++i) {
      p[k * size + i] = val;
    }
    for (k >>= 1; k > 0; k >>= 1) {
      func (p[k * size], p[2 * k * size], p[2 * k + 1 * size]);
    }
  }

  public void update_tmp (int k, Object val) {
    k += size;
    Object[] p = (Object[]) this.array;
    int size = this.val_size;
    for (int i = 0; i < size; ++i) {
      p[k * size + i] = val;
    }
  }

  public void update_all () {
    Object[] a = (Object[]) this.array;
    int size = this.val_size;
    for (int i = size - 1; i > 0; --i) {
      func (a[i], a[2 * i], a[2 * i + 1]);
    }
  }

  public void find (int l, int r, Object res) {
    int lindex[] = new int[32];
    int rindex[] = new int[32];
    int llen = 0;
    int rlen = 0;
    for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
      if (l & 1) lindex[llen++] = l++;
      if (r & 1) rindex[rlen++] = --r;
    }
    Object[] p = (Object[]) this.array;
    if (llen == 0) {
      lindex[llen++] = rindex[--rlen];
    }
    for (int i = 0; i < size; ++i) {
      res[i] = p[lindex[0] * size + i];
    }
    for (int i = 1; i < llen; ++i) {
      func (res, res, p[lindex[i] * size]);
    }
    for (int i = rlen - 1; i >= 0; --i) {
      func (res, res, p[rindex[i] * size]);
    }
  }
}

class segment_node {
  public int index;
  public long val;

  public segment_node (int index, long val) {
    this.index = index;
    this.val = val;
  }
}

class edge {
  public int a, b;
  public long c;

  public edge (int a, int b, long c) {
    this.a = a;
    this.b = b;
    this.c = c;
  }
}

public class Main {
  public static void run () {
    int n, d;
    Scanner sc = new Scanner (System.in);
    n = sc.nextInt ();
    d = sc.nextInt ();
    int[] a = new int[n];
    index_val[] p = new index_val[n];
    for (int i = 0; i < n; ++i) {
      a[i] = sc.nextInt ();
      p[i] = new index_val (i, a[i]);
    }
    Arrays.sort (p, new Comparator<index_val> () {
      public int compare (index_val a, index_val b) {
        int d = a.val - b.val;
        return d == 0 ? 0 : d > 0 ? -1 : 1;
      }
    });
    segment_node ini = new segment_node (n, (long)(n + 2) * 1000000000 + 1);
    segment_tree l = new segment_tree (ini, n, new segment_node (), new segment_node ());
    segment_tree r = new segment_tree (ini, n, new segment_node (), new segment_node ());
    for (int i = 0; i < n; ++i) {
      update_tmp (l, i, new segment_node (i, a[i] + (long)(n - 1 - i) * d));
      update_tmp (r, i, new segment_node (i, a[i] + (long)i * d));
    }
    update_all (l);
    update_all (r);
    binaryHeap h = new binaryHeap (new edge (), new edge ());
    for (int i = 0; i < n; ++i) {
      int v = p[i].index;
      if (v > 0) {
        segment_node t;
        find (l, 0, v, t);
        push (h, new edge (v, t.index, p[i].val + t.val - (long) (n - 1 - v) * d));
      }
      if (v + 1 < n) {
        segment_node t;
        find (r, v + 1, n, t);
        push (h, new edge (v, t.index, p[i].val + t.val - (long) v * d));
      }
      update (l, v, ini);
      update (r, v, ini);
    }
    long sum = 0;
    UnionFind u = new UnionFind (n);
    while (getSize (u, 0) < n) {
      edge e;
      pop (h, e);
      if (same (u, e.a, e.b)) continue;
      unite (u, e.a, e.b);
      sum += e.c;
    }
    System.out.println (sum);
  }

  public static void main (String[] args) {
    run ();
  }
}

