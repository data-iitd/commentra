
package main;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
  static int size = 1000000;
  static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in),size);
  static String NextLine() {
    String line = "";
    String buffer = "";
    boolean isPrefix = true;
    while (isPrefix) {
      try {
        line = reader.readLine();
        buffer += line;
      } catch (Exception e) {
        e.printStackTrace();
      }
      isPrefix = line.endsWith("\n");
    }
    return buffer;
  }
  static int[] NextInts() {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]);
    }
    return a;
  }
  static int[] NextIntArray() {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]) - 1;
    }
    return a;
  }
  static int[] par, rank;
  public static void main(String[] args) {
    int[] nm = NextInts();
    int n = nm[0], m = nm[1];
    int[] p = NextIntArray();
    initialize(n);
    for (int i = 0; i < m; i++) {
      int[] xy = NextInts();
      unite(xy[0] - 1, xy[1] - 1);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
      if (same(i, p[i])) {
        s++;
      }
    }
    System.out.println(s);
  }
  public static void initialize(int n) {
    par = new int[n];
    rank = new int[n];
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  public static int root(int i) {
    if (par[i] == i) {
      return i;
    }
    par[i] = root(par[i]);
    return par[i];
  }
  public static boolean same(int i, int j) {
    return root(i) == root(j);
  }
  public static void unite(int i, int j) {
    i = root(i);
    j = root(j);
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
}

