import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int[] p = new int[n];
    for (int i=0;i<n;i++) {
      p[i] = sc.nextInt();
    }
    initialize(n);
    for (int i=0;i<m;i++) {
      int x = sc.nextInt();
      int y = sc.nextInt();
      unite(x-1,y-1);
    }
    int s = 0;
    for (int i=0;i<n;i++) {
      if (same(i,p[i]-1)) { s++; }
    }
    System.out.println(s);
  }
  static int[] par,rank;
  static void initialize(int n) {
    par = new int[n];
    rank = new int[n];
    for (int i=0;i<n;i++) {
      par[i] = i;
    }
  }
  static int root(int i) {
    if (par[i] == i) { return i; }
    par[i] = root(par[i]);
    return par[i];
  }
  static boolean same(int i,int j) {
    return root(i) == root(j);
  }
  static void unite(int i,int j) {
    i = root(i);
    j = root(j);
    if (i == j) { return; }
    if (rank[i] < rank[j]) {
      par[i] = j;
    } else {
      par[j] = i;
      if (rank[i] == rank[j]) { rank[i]++; }
    }
  }
}
