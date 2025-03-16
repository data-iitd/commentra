
/*
URL:
https://atcoder.jp/contests/abc174/tasks/abc174_f
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

  // <START-OF-CODE>
  // Constants and global variables
  private static final int MOD = 1000000007;
  private static final int INF = (int) 1e9;
  private static final int INF_BIT = 1 << 30;
  private static final int NIL = -1;

  private static int n, q;
  private static int[] C;
  private static List<Query> Q = new ArrayList<>();

  private static int[] P;
  private static int[] Answers;

  // Query struct represents a query with index, left and right indices
  private static class Query {
    int idx, l, r;

    public Query(int idx, int l, int r) {
      this.idx = idx;
      this.l = l;
      this.r = r;
    }
  }

  // FenwickTree struct represents a Fenwick Tree
  private static class FenwickTree {
    private int[] dat;
    private int n;
    private int minPow2;

    public FenwickTree(int n) {
      this.dat = new int[n + 1];
      this.n = n;

      this.minPow2 = 1;
      while ((this.minPow2 << 1) <= n) {
        this.minPow2 <<= 1;
      }
    }

    public int sum(int i) {
      int s = 0;

      for (; i > 0; i -= i & -i) {
        s += this.dat[i];
      }

      return s;
    }

    public void add(int i, int x) {
      for (; i <= this.n; i += i & -i) {
        this.dat[i] += x;
      }
    }

    public int lowerBound(int w) {
      if (w <= 0) {
        return 0;
      }

      int x = 0;
      for (int k = this.minPow2; k > 0; k /= 2) {
        if (x + k <= this.n && this.dat[x + k] < w) {
          w -= this.dat[x + k];
          x += k;
        }
      }

      return x + 1;
    }
  }

  // Main function where the execution starts
  public static void main(String[] args) throws IOException {
    // Reads the number of elements (n) and the number of queries (q)
    n = readInt();
    q = readInt();
    // Reads the array C
    C = readIntArray(n);

    // Initializes the position array P with -1
    P = new int[n + 1];
    Arrays.fill(P, -1);

    // Reads the queries and stores them in Q
    for (int i = 0; i < q; i++) {
      int l = readInt();
      int r = readInt();
      Query query = new Query(i, l, r);
      Q.add(query);
    }

    // Sorts the queries based on the right index (r)
    Q.sort((a, b) -> Integer.compare(a.r, b.r));
    // Initializes a Fenwick Tree with a size of 500050
    FenwickTree ft = new FenwickTree(500000 + 50);

    // Variable to keep track of the current position in the array C
    int k = 0;
    // Processes each query
    for (Query query : Q) {
      // Updates the Fenwick Tree and position array P until the current right index of the query
      while (k < query.r) {
        if (P[C[k]] != -1) {
          ft.add(P[C[k]] + 1, -1);
        }
        P[C[k]] = k;
        ft.add(k + 1, 1);

        k++;
      }
      // Calculates the answer for the current query using the Fenwick Tree
      Answers[query.idx] = ft.sum(query.r) - ft.sum(query.l - 1);
    }

    // Outputs the answers for each query
    for (int i = 0; i < q; i++) {
      System.out.println(Answers[i]);
    }
  }

  // Public methods for FenwickTree
  // ft := NewFenwickTree(200000 + 5)
  // s := ft.Sum(i) 						// Sum of [1, i] (1-based)
  // ft.Add(i, x) 							// Add x to i (1-based)
  // idx := ft.LowerBound(w) 		// minimum idx such that bit.Sum(idx) >= w

  // Public methods for FenwickTree
  // ft := NewFenwickTree(200000 + 5)
  // s := ft.Sum(i) 						// Sum of [1, i] (1-based)
  // ft.Add(i, x) 							// Add x to i (1-based)
  // idx := ft.LowerBound(w) 		// minimum idx such that bit.Sum(idx) >= w

  // 