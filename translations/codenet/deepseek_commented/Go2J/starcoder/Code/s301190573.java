package main;

import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) {
    try {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      String line;
      while ((line = br.readLine())!= null) {
        String[] parts = line.split(" ");
        int n = Integer.parseInt(parts[0]);
        int m = Integer.parseInt(parts[1]);
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
          p[i] = Integer.parseInt(br.readLine()) - 1;
        }
        int[] par = new int[n];
        int[] rank = new int[n];
        for (int i = 0; i < n; i++) {
          par[i] = i;
        }
        for (int i = 0; i < m; i++) {
          String[] parts2 = br.readLine().split(" ");
          int x = Integer.parseInt(parts2[0]) - 1;
          int y = Integer.parseInt(parts2[1]) - 1;
          int rootX = root(par,rank,x);
          int rootY = root(par,rank,y);
          if (rootX!= rootY) {
            if (rank[rootX] < rank[rootY]) {
              par[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
              par[rootY] = rootX;
            } else {
              par[rootX] = rootY;
              rank[rootY]++;
            }
          }
        }
        int s = 0;
        for (int i = 0; i < n; i++) {
          if (same(par,rank,i,p[i])) {
            s++;
          }
        }
        System.out.println(s);
      }
    } catch (Exception e) {
      e.printStackTrace();
    }
  }

  public static int root(int[] par, int[] rank, int i) {
    if (par[i] == i) {
      return i;
    }
    par[i] = root(par,rank,par[i]);
    return par[i];
  }

  public static boolean same(int[] par, int[] rank, int i, int j) {
    return root(par,rank,i) == root(par,rank,j);
  }
}
// The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

public static void initialize(int n) {
  par = new int[n];
  rank = new int[n];
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}
// Initializes the union-find data structure with n elements, each in its own set.

public static int root(int[] par, int[] rank, int i) {
  if (par[i] == i) {
    return i;
  }
  par[i] = root(par,rank,par[i]);
  return par[i];
}
// Finds the root of the element i, applying path compression to improve future queries.

public static boolean same(int[] par, int[] rank, int i, int j) {
  return root(par,rank,i) == root(par,rank,j);
}
// Checks if the elements i and j are in the same set.

public static void unite(int[] par, int[] rank, int i, int j) {
  i = root(par,rank,i);
  j = root(par,rank,j);
  if (i == j) {
    return;
  }
  if (rank[i] < rank[j]) {
    par[i] = j;
  } else if (rank[i] > rank[j]) {
    par[j] = i;
    if (rank[i] == rank[j]) {
      rank[i]++;
    }
  } else {
    par[i] = j;
    rank[j]++;
  }
}
// Unites the sets containing elements i and j, attaching the smaller tree under the root of the larger tree.

