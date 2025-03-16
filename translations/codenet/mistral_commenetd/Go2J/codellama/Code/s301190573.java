
import java.io.*;
import java.util.*;

public class Main {
  static class InputReader {
    private final BufferedReader br;
    private StringTokenizer st;

    public InputReader(final InputStream in) {
      br = new BufferedReader(new InputStreamReader(in));
    }

    public String next() {
      while (st == null || !st.hasMoreElements()) {
        try {
          st = new StringTokenizer(br.readLine());
        } catch (final IOException e) {
          e.printStackTrace();
        }
      }
      return st.nextToken();
    }

    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public String nextLine() {
      final String res = null;
      while (res == null || res.isEmpty()) {
        try {
          return br.readLine();
        } catch (final IOException e) {
          e.printStackTrace();
        }
      }
      return res;
    }
  }

  public static void main(final String[] args) {
    final InputReader in = new InputReader(System.in);
    final int n = in.nextInt();
    final int m = in.nextInt();
    final int[] p = new int[n];
    final int[] par = new int[n];
    final int[] rank = new int[n];
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
    for (int i = 0; i < m; i++) {
      final int x = in.nextInt() - 1;
      final int y = in.nextInt() - 1;
      unite(x, y, par, rank);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
      if (same(i, p[i], par)) {
        s++;
      }
    }
    System.out.println(s);
  }

  private static void unite(final int x, final int y, final int[] par, final int[] rank) {
    final int i = root(x, par);
    final int j = root(y, par);
    if (i == j) {
      return;
    }
    if (rank[i] < rank[j]) {
      par[i] = j;
    } else {
      par[j] = i;
      if (rank[i] == rank[j]) {
        rank[i]++;
      }
    }
  }

  private static int root(final int i, final int[] par) {
    if (par[i] == i) {
      return i;
    }
    par[i] = root(par[i], par);
    return par[i];
  }

  private static boolean same(final int i, final int j, final int[] par) {
    return root(i, par) == root(j, par);
  }
}

