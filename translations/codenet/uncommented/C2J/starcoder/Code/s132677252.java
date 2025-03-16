
import java.util.*;
import java.io.*;

public class Main {
  public static void main (String[] args) {
    Scanner cin = new Scanner (System.in);
    int n = cin.nextInt();
    int[] p = new int[n + 1];
    int[] depth = new int[n + 1];
    int[] cnt = new int[n + 1];
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i) {
      p[i] = cin.nextInt();
      depth[i] = depth[p[i]] + 1;
      cnt[depth[i]]++;
    }
    Deque<node>[] dp = new Deque[n + 1];
    Deque<node>[] child = new Deque[n + 1];
    node[] lst = new node[n + 1];
    for (int i = n; i >= 0; --i) {
      int v = i;
      if (dp[v] == null) {
        dp[v] = new_deque();
        push_front (dp[v], new node(1, 1));
        continue;
      }
      int len = 0;
      for (int p = g.start[v]; p!= -1; p = g.edge[p].next) {
        int u = g.edge[p].vertex;
        child[len++] = dp[u];
      }
      if (len > 1) {
        Arrays.sort (child, new Comparator<Deque<node>>() {
          public int compare (Deque<node> p, Deque<node> q) {
            return get_size (p) - get_size (q);
          }
        });
        for (int d = 0; d < get_size (child[1]); ++d) {
          int j = 0;
          for (; j < len && d < get_size (child[j]); ++j) {
            lst[j] = get_at (child[j], d);
          }
          assign_at (child[0], d, merge (lst, j));
        }
        for (int j = 1; j < len; ++j) {
          free_deque (child[j]);
        }
      }
      dp[v] = child[0];
      push_front (dp[v], new node(1, 1));
    }
    long ans = 0;
    for (int i = 0; i < get_size (dp[0]); ++i) {
      ans += (long) mod_pow (2, n + 1 - cnt[i]) * get_at (dp[0], i).one % mod;
    }
    System.out.println (ans % mod);
  }

  static int mod = 1000000007;

  static int mod_pow (int r, int n) {
    int t = 1;
    int s = r;
    while (n > 0) {
      if ((n & 1)!= 0) t = (t * s) % mod;
      s = (s * s) % mod;
      n >>= 1;
    }
    return t;
  }

  static class node {
    int one;
    int zero;
    node (int one, int zero) {
      this.one = one;
      this.zero = zero;
    }
  }

  static class graph_edge {
    int vertex;
    int next;
    graph_edge (int vertex, int next) {
      this.vertex = vertex;
      this.next = next;
    }
  }

  static class graph {
    graph_edge[] edge;
    int[] start;
    int pointer;
    int vertex_num;
    int edge_max_size;
    graph (int vertex_num) {
      edge = new graph_edge[1];
      start = new int[vertex_num];
      pointer = 0;
      this.vertex_num = vertex_num;
      edge_max_size = 1;
      for (int i = 0; i < vertex_num; ++i) {
        start[i] = -1;
      }
    }
    void add_edge (int from, int to) {
      if (pointer == edge_max_size) {
        edge_max_size *= 2;
        edge = Arrays.copyOf (edge, edge_max_size);
      }
      edge[pointer] = new graph_edge (to, start[from]);
      start[from] = pointer++;
    }
  }

  static graph g = new graph (0);

  static class deque_val {
    int one;
    int zero;
    deque_val (int one, int zero) {
      this.one = one;
      this.zero = zero;
    }
  }

  static class Deque<T> {
    T[] array;
    int front;
    int last;
    int mask;
    Deque () {
      int len = 2;
      array = (T[]) new Object[len];
      front = last = 0;
      mask = len - 1;
    }
    void push_front (T v) {
      if (((last + 1) & mask) == front) {
        deque_realloc ();
      }
      front = (front + mask) & mask;
      array[front] = v;
    }
    T get_at (int x) {
      return array[(front + x) & mask];
    }
    void assign_at (int x, T v) {
      array[(front + x) & mask] = v;
    }
    int get_size () {
      return (last + (~front + 1)) & mask;
    }
    void deque_realloc () {
      T[] array = (T[]) new Object[2 * (mask + 1)];
      int k = 0;
      for (int i = front; i!= last; i = (i + 1) & mask) {
        array[k++] = array[i];
      }
      this.array = array;
      front = 0;
      last = k;
      mask = 2 * mask + 1;
    }
  }

  static Deque<node> new_deque () {
    return new Deque<node>();
  }

  static void free_deque (Deque<node> d) {
  }

  static int get_size (Deque<node> d) {
    return d.get_size();
  }

  static void assign_at (Deque<node> d, int x, node v) {
    d.assign_at (x, v);
  }

  static node get_at (Deque<node> d, int x) {
    return d.get_at (x);
  }

  static void push_front (Deque<node> d, node v) {
    d.push_front (v);
  }

  static int cmp_deque_size (Object a, Object b) {
    Deque<node>[] p = (Deque<node>[]) a;
    Deque<node>[] q = (Deque<node>[]) b;
    int d = get_size (p[0]) - get_size (q[0]);
    return d == 0? 0 : d > 0? -1 : 1;
  }
}

