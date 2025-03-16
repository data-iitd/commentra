
import java.io.*;
import java.util.*;

// The main package declaration.
// This package uses BufferedReader and InputStreamReader for efficient I/O operations.

public class s301190573{
  // Global variables for the union-find data structure.
  private static int[] par;
  private static int[] rank;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String[] input = br.readLine().split(" ");
    int n = Integer.parseInt(input[0]);
    int m = Integer.parseInt(input[1]);
    int[] p = new int[n];
    input = br.readLine().split(" ");
    for (int i = 0; i < n; i++) {
      p[i] = Integer.parseInt(input[i]) - 1;
    }
    initialize(n);
    for (int i = 0; i < m; i++) {
      input = br.readLine().split(" ");
      int x = Integer.parseInt(input[0]) - 1;
      int y = Integer.parseInt(input[1]) - 1;
      unite(x, y);
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (same(i, p[i])) {
        count++;
      }
    }
    System.out.println(count);
  }

  private static void initialize(int n) {
    par = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }

  private static int root(int i) {
    if (par[i] == i) {
      return i;
    }
    par[i] = root(par[i]);
    return par[i];
  }

  private static boolean same(int i, int j) {
    return root(i) == root(j);
  }

  private static void unite(int i, int j) {
    int x = root(i);
    int y = root(j);
    if (x == y) {
      return;
    }
    if (rank[x] < rank[y]) {
      par[x] = y;
    } else {
      par[y] = x;
      if (rank[x] == rank[y]) {
        rank[x]++;
      }
    }
  }
}
// The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

