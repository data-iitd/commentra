

import java.util.*;

public class s305090452{
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int d = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    int[][] p = new int[n][2];
    for (int i = 0; i < n; i++) {
      p[i][0] = i;
      p[i][1] = a[i];
    }
    Arrays.sort(p, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        return Integer.compare(o1[1], o2[1]);
      }
    });
    class SegmentNode {
      int index;
      long val;
      public SegmentNode(int index, long val) {
        this.index = index;
        this.val = val;
      }
    }
    SegmentNode ini = new SegmentNode(n, (long)(n + 2) * 1000000000 + 1);
    SegmentTree l = new SegmentTree(n, ini, new Comparator<SegmentNode>() {
      @Override
      public int compare(SegmentNode o1, SegmentNode o2) {
        return Long.compare(o1.val, o2.val);
      }
    });
    SegmentTree r = new SegmentTree(n, ini, new Comparator<SegmentNode>() {
      @Override
      public int compare(SegmentNode o1, SegmentNode o2) {
        return Long.compare(o1.val, o2.val);
      }
    });
    for (int i = 0; i < n; i++) {
      l.update(i, new SegmentNode(i, a[i] + (long)(n - 1 - i) * d));
      r.update(i, new SegmentNode(i, a[i] + (long)i * d));
    }
    PriorityQueue<int[]> q = new PriorityQueue<int[]>(new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        return Long.compare(o1[2], o2[2]);
      }
    });
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        SegmentNode t = l.query(0, i);
        q.add(new int[]{i, t.index, p[i][1] + t.val - (long)(n - 1 - i) * d});
      }
      if (i + 1 < n) {
        SegmentNode t = r.query(i + 1, n);
        q.add(new int[]{i, t.index, p[i][1] + t.val - (long)i * d});
      }
      l.update(p[i][0], ini);
      r.update(p[i][0], ini);
    }
    long sum = 0;
    UnionFind u = new UnionFind(n);
    while (u.size > 1) {
      int[] e = q.poll();
      if (u.same(e[0], e[1])) continue;
      u.unite(e[0], e[1]);
      sum += e[2];
    }
    System.out.println(sum);
  }
}

class SegmentTree {
  int n;
  SegmentNode[] tree;
  Comparator<SegmentNode> cmp;
  public SegmentTree(int n, SegmentNode ini, Comparator<SegmentNode> cmp) {
    this.n = n;
    tree = new SegmentNode[4 * n];
    this.cmp = cmp;
    build(1, 0, n - 1, ini);
  }
  void build(int v, int tl, int tr, SegmentNode ini) {
    if (tl == tr) {
      tree[v] = ini;
    } else {
      int tm = (tl + tr) / 2;
      build(2 * v, tl, tm, ini);
      build(2 * v + 1, tm + 1, tr, ini);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1]) <= 0? tree[2 * v] : tree[2 * v + 1];
    }
  }
  void update(int v, SegmentNode val) {
    update(1, 0, n - 1, val);
  }
  void update(int v, int tl, int tr, SegmentNode val) {
    if (tl == tr) {
      tree[v] = val;
    } else {
      int tm = (tl + tr) / 2;
      update(2 * v, tl, tm, val);
      update(2 * v + 1, tm + 1, tr, val);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1]) <= 0? tree[2 * v] : tree[2 * v + 1];
    }
  }
  SegmentNode query(int v, int tl, int tr) {
    if (tl == tr) {
      return tree[v];
    } else {
      int tm = (tl + tr) / 2;
      SegmentNode left = query(2 * v, tl, tm);
      SegmentNode right = query(2 * v + 1, tm + 1, tr);
      return cmp.compare(left, right) <= 0? left : right;
    }
  }
  void update(int v, int tl, int tr, SegmentNode val) {
    if (tl == tr) {
      tree[v] = val;
    } else {
      int tm = (tl + tr) / 2;
      update(2 * v, tl, tm, val);
      update(2 * v + 1, tm + 1, tr, val);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1]) <= 0? tree[2 * v] : tree[2 * v + 1];
    }
  }
  SegmentNode query(int v, int tl, int tr) {
    if (tl == tr) {
      return tree[v];
    } else {
      int tm = (tl + tr) / 2;
      SegmentNode left = query(2 * v, tl, tm);
      SegmentNode right = query(2 * v + 1, tm + 1, tr);
      return cmp.compare(left, right) <= 0? left : right;
    }
  }
  void swap(int v, int tl, int tr) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      swap(2 * v, tl, tm);
      swap(2 * v + 1, tm + 1, tr);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1];
    }
  }
  void push(int v, int tl, int tr) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      push(2 * v, tl, tm);
      push(2 * v + 1, tm + 1, tr);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1];
    }
  }
  void pop(int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      pop(2 * v, tl, tm);
      pop(2 * v + 1, tm + 1, tr);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1);
    }
  }
  void free (int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      free (2 * v, tl, tm);
      tree[v] = cmp.compare(tree[2 * v + 1, tm + 1, tr);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1);
    }
  }
  }
  void swap(int v, int tl, int tr) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      swap(2 * v, tl, tm);
      swap(2 * v + 1, tm + 1, tr);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1);
    }
  }
  }
  void free (int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      free (2 * v, tl, tm);
      tree[v] = cmp.compare(tree[2 * v], tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1);
    }
  }
  }
  }
  void push(int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      push(2 * v, tl, tm);
      tree[v] = cmp.compare(tree[2 * v + 1) <= 0? tree[2 * v] : tree[2 * v + 1);
    }
  }
  }
  }
  void free (int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      free (2 * v + 1);
      free (2 * v) <= 0? tree[2 * v] : tree[2 * v + 1);
    }
  }
  }
  }
  }
  }
  void free (int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      free (2 * v + 1);
      free (2 * v) <= 0? tree[2 * v) : tree[2 * v + 1);
    }
  }
  }
  }
  }
  }
  }
  }
  void swap(int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      swap(2 * v, tl, tm);
      swap(2 * v + 1);
      swap(2 * v) <= 0? swap(2 * v) {
      return;
    }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  void free (int v) {
    if (tl == tr) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      free (2 * v) {
      return;
    } else {
      int tm = (tl + tr) / 2;
      free (2 * v + 1);
      free (2 * v) <= 0? tree[2 * v) : tree[2 * v + 1);
      free (2 * v) <= 0? tree[2 * v) : tree[2 * v + 1);
      free (2 * v) <= 0? tree[2 * v) {
      return;
    }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
}

}
}

}

}
}

}

}

}

}
}
}
}
}
}
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
}
}
}
}
}
}
}
}
}
}
}
}
}
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
  }
 