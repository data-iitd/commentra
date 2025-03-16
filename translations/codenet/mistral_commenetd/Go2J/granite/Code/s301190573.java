

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s301190573{
  static int size = 1000000;
  static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), size);

  // Function to read a single line from the standard input
  static String NextLine() {
    String line = "";
    try {
      line = reader.readLine();
    } catch (Exception e) {
      e.printStackTrace();
    }
    return line;
  }

  // Function to read two integers from a single line
  static int[] NextInts() {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]);
    }
    return a;
  }

  // Function to read an array of integers from a single line
  static int[] NextIntArray() {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]) - 1; // Decrease each index by 1 for some reason
    }
    return a;
  }

  // Initialize arrays for parent and rank
  static int[] par, rank;

  // Function to initialize arrays
  static void initialize(int n) {
    par = new int[n];
    rank = new int[n];
    // Set all elements as their own parent initially
    Arrays.fill(par, 0, n, -1);
  }

  // s301190573 function
  public static void main(String[] args) {
    // Read number of nodes and edges
    int[] n_m = NextInts();
    int n = n_m[0], m = n_m[1];
    // Read array of edges
    int[] p = NextIntArray();
    // Initialize arrays
    initialize(n);
    // Process each edge by uniting their parents
    for (int i = 0; i < m; i++) {
      int[] x_y = NextInts();
      unite(x_y[0] - 1, x_y[1] - 1);
    }
    // Count the number of disconnected components
    int s = 0;
    for (int i = 0; i < n; i++) {
      if (same(i, p[i])) {
        s++;
      }
    }
    // Print the result
    System.out.println(s);
  }

  // Function to find the root of a node
  static int root(int i) {
    // If the node is its own parent, return it
    if (par[i] < 0) {
      return i;
    }
    // Recursively find the root of the parent
    par[i] = root(par[i]);
    // Return the new root
    return par[i];
  }

  // Function to check if two nodes have the same parent
  static boolean same(int i, int j) {
    // Find the root of both nodes
    return root(i) == root(j);
  }

  // Function to unite two nodes
  static void unite(int i, int j) {
    // Find the roots of both nodes
    i = root(i);
    j = root(j);
    // If they already have the same parent, return
    if (i == j) {
      return;
    }
    // Make the smaller rank node a child of the larger rank node
    if (rank[i] > rank[j]) {
      par[j] += par[i]; // Add the size of the first node to the second node
      par[i] = j; // Set the parent of the first node to the second node
    } else {
      par[i] += par[j]; // Add the size of the second node to the first node
      par[j] = i; // Set the parent of the second node to the first node
      if (rank[i] == rank[j]) {
        rank[i]++; // Increase the rank of the first node if both nodes have the same rank
      }
    }
  }
}

