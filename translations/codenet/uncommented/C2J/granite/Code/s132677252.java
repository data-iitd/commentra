
import java.util.*;
import java.io.*;

class s132677252 {
  static int mod = 1000000007;

  static int mod_pow (int r, int n) {
    int t = 1;
    int s = r;
    while (n > 0) {
      if (n % 2 == 1) t = (int) ((long) t * s % mod);
      s = (int) ((long) s * s % mod);
      n /= 2;
    }
    return t;
  }

  static class Node {
    int one;
    int zero;

    Node (int one, int zero) {
      this.one = one;
      this.zero = zero;
    }

    Node merge (Node that) {
      long one = (long) this.one * that.zero + (long) this.zero * that.one;
      long zero = (long) this.zero * that.zero;
      long total = this.zero + this.one + that.zero + that.one;
      return new Node ((int) (one % mod), (int) (zero % mod));
    }
  }

  static class Deque {
    Node[] array;
    int front;
    int last;
    int mask;

    Deque (int len) {
      array = new Node[len];
      front = last = 0;
      mask = len - 1;
    }

    int size () {
      return (last + (~front + 1)) & mask;
    }

    void realloc () {
      Node[] array = new Node[2 * (mask + 1)];
      int k = 0;
      for (int i = front; i!= last; i = (i + 1) & mask) {
        array[k++] = this.array[i];
      }
      this.array = array;
      front = 0;
      last = k;
      mask = 2 * mask + 1;
    }

    Node get (int x) {
      return array[(front + x) & mask];
    }

    void set (int x, Node v) {
      array[(front + x) & mask] = v;
    }

    void push_front (Node v) {
      if (((last + 1) & mask) == front) {
        realloc ();
      }
      front = (front + mask) & mask;
      array[front] = v;
    }
  }

  public static void main (String[] args) throws IOException {
    BufferedReader br = new BufferedReader (new InputStreamReader (System.in));
    int n = Integer.parseInt (br.readLine ());
    int[] p = new int[n + 1];
    int[] depth = new int[n + 1];
    int[] cnt = new int[n + 1];
    cnt[0] = 1;
    Map<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>> ();
    for (int i = 1; i <= n; ++i) {
      p[i] = Integer.parseInt (br.readLine ());
      if (!graph.containsKey (p[i])) {
        graph.put (p[i], new ArrayList<Integer> ());
      }
      graph.get (p[i]).add (i);
      depth[i] = depth[p[i]] + 1;
      cnt[depth[i]]++;
    }
    Deque[] dp = new Deque[n + 1];
    Deque[] child = new Deque[n + 1];
    Node[] lst = new Node[n + 1];
    for (int i = n; i >= 0; --i) {
      int v = i;
      if (!graph.containsKey (v)) {
        dp[v] = new Deque (1);
        dp[v].push_front (new Node (1, 1));
        continue;
      }
      int len = 0;
      for (int u : graph.get (v)) {
        child[len++] = dp[u];
      }
      if (len > 1) {
        Arrays.sort (child, 0, len, new Comparator<Deque> () {
          public int compare (Deque d1, Deque d2) {
            return d1.size () - d2.size ();
          }
        });
        for (int d = 0; d < child[1].size (); ++d) {
          int j = 0;
          for (; j < len && d < child[j].size (); ++j) {
            lst[j] = child[j].get (d);
          }
          child[0].set (d, Node.merge (lst, j));
        }
        for (int j = 1; j < len; ++j) {
          child[j] = null;
        }
      }
      dp[v] = child[0];
      dp[v].push_front (new Node (1, 1));
    }
    long ans = 0;
    for (int i = 0; i < dp[0].size (); ++i) {
      ans += (long) mod_pow (2, n + 1 - cnt[i]) * dp[0].get (i).one % mod;
    }
    System.out.println (ans % mod);
  }
}

