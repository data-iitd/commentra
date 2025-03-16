
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
    Arrays.sort (p, new Comparator<index_val> () {
      @Override
      public int compare (index_val a, index_val b) {
        return a.val - b.val;
      }
    });
    segment_node ini = new segment_node();
    ini.index = n;
    ini.val = (n + 2) * 1000000000 + 1;
    segment_tree l = new segment_tree (ini, n, segment_node.class, func_segment_node);
    segment_tree r = new segment_tree (ini, n, segment_node.class, func_segment_node);
    for (int i = 0; i < n; ++i) {
      update_tmp (l, i, new segment_node(i, a[i] + (n - 1 - i) * d));
      update_tmp (r, i, new segment_node(i, a[i] + i * d));
    }
    update_all (l);
    update_all (r);
    heap h = new heap (edge.class, cmp_edge);
    for (int i = 0; i < n; ++i) {
      int v = p[i].index;
      if (v > 0) {
        segment_node t = find (l, 0, v);
        push (h, new edge(v, t.index, p[i].val + t.val - (n - 1 - v) * d));
      }
      if (v + 1 < n) {
        segment_node t = find (r, v + 1, n);
        push (h, new edge(v, t.index, p[i].val + t.val - v * d));
      }
      update (l, v, ini);
      update (r, v, ini);
    }
    long sum = 0;
    UnionFind u = newUnionFind (n);
    while (getSize (u, 0) < n) {
      edge e = pop (h);
      if (same (u, e.a, e.b)) continue;
      unite (u, e.a, e.b);
      sum += e.c;
    }
    System.out.println (sum);
  }
}

class segment_tree {
  public segment_node[] array;
  public int size;
  public int val_size;
  public void (*func) (void *, const void *, const void *);
  public segment_tree (segment_node ini, int n, Class c, void (*f) (void *, const void *, const void *)) {
    int k = 1;
    while (k < n) k *= 2;
    array = new segment_node[2 * k];
    size = k;
    val_size = c.getFields ().length;
    func = f;
    for (int i = k; i < 2 * k; ++i) {
      segment_node tmp = new segment_node();
      for (int j = 0; j < val_size; ++j) {
        tmp.getClass ().getField ("f" + j).set (tmp, ini.getClass ().getField ("f" + j).get (ini));
      }
      array[i] = tmp;
    }
    for (int i = k - 1; i > 0; --i) {
      func (array[i], array[2 * i], array[2 * i + 1]);
    }
  }
}

class segment_node {
  public int index;
  public long val;
}

class index_val {
  public int index;
  public int val;
}

class edge {
  public int a, b;
  public long c;
}

class UnionFind {
  public int[] parent;
  public int size;
  public UnionFind (int n) {
    parent = new int[n];
    size = n;
    for (int i = 0; i < n; ++i) {
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
  public int getSize (int x) {
    return - parent[root (x)];
  }
  public void unite (int x, int y) {
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

class heap {
  public Object[] array;
  public int heap_size;
  public int max_size;
  public int val_size;
  public int (*cmp) (const void *, const void *);
  public heap (Class c, int (*f) (const void *, const void *)) {
    array = new Object[1];
    heap_size = 0;
    max_size = 1;
    val_size = c.getFields ().length;
    cmp = f;
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
  public static void heap_func_swap (Object[] a, Object[] b, int val_size) {
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
  public static void heap_func_copy (Object[] dst, Object[] src, int val_size) {
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
      byte[] p = (byte[]) src;
      byte[] q = (byte[]) dst;
      while (val_size-- > 0) {
        q[0] = p[0];
        p++;
        q++;
      }
    }
  }
  public void push (Object val) {
    if (heap_size == max_size) {
      max_size = 2 * max_size + 1;
      array = Arrays.copyOf (array, max_size);
    }
    heap_size++;
    Object[] array = this.array;
    int k = heap_size;
    int val_size = this.val_size;
    int (*cmp) (const void *, const void *) = this.cmp;
    heap_func_copy(array, val, val_size);
    while(k>1){
      int parent = k / 2;
      if (cmp (array[parent], array[k]) <= 0) {
        return;
      }
      heap_func_swap (array, parent, k);
      k = parent;
    }
  }
  public void pop (Object res) {
    Object[] array = this.array;
    int val_size = this.val_size;
    if (res!= null) {
      heap_func_copy (res, array, val_size);
    }
    heap_func_copy (array, array, val_size);
    heap_size--;
    int (* const cmp) (const void *, const void *) = this.cmp;
    int n = heap_size;
    int k = 1;
    while (2 * k  + 1 <= n) {
      int c = cmp (array[2 * k], array[2 * k + 1]);
      int next = 2 * k + (c <= 0? 0 : 1);
      if (cmp (array[k], array[next]) <= 0) return;
      heap_func_swap (array, k, next);
      k = next;
    }
    if (2 * k <= n && cmp (array[k], array[2 * k]) > 0) {
      heap_func_swap (array, k, 2 * k);
    }
  }
  public void top (Object res) {
    Object[] array = this.array;
    int val_size = this.val_size;
    if (res!= null) {
      heap_func_copy (res, array, val_size);
    }
  }
}

