
import java.io.*;
import java.util.*;

public class Main {
  // Initialize reader
  static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
  // Initialize size of buffer
  static int size = 1000000;
  // Initialize buffer
  static char[] buffer = new char[size];
  // Initialize index of buffer
  static int index = 0;

  // Function to read a single line from the standard input
  public static String NextLine() throws IOException {
    String str = "";
    boolean isPrefix = true;
    while (isPrefix) {
      isPrefix = false;
      int c = reader.read();
      if (c == -1) {
        return str;
      }
      if (c == '\n') {
        return str;
      }
      if (c == '\r') {
        isPrefix = true;
        if ((reader.read())!= '\n') {
          reader.unread(c);
        }
        return str;
      }
      str += (char) c;
    }
    return str;
  }

  // Function to read two integers from a single line
  public static int[] NextInts() throws IOException {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]);
    }
    return a;
  }

  // Function to read an array of integers from a single line
  public static int[] NextIntArray() throws IOException {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]) - 1;
    }
    return a;
  }

  // Initialize arrays for parent and rank
  static int[] par, rank;

  // Function to initialize arrays
  public static void initialize(int n) {
    par = new int[n];
    rank = new int[n];
    // Set all elements as their own parent initially
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }

  // Main function
  public static void main(String[] args) throws IOException {
    // Read number of nodes and edges
    int n = NextInts()[0];
    int m = NextInts()[0];
    // Read array of edges
    int[] p = NextIntArray();
    // Initialize arrays
    initialize(n);
    // Process each edge by uniting their parents
    for (int i = 0; i < m; i++) {
      int x = NextInts()[0];
      int y = NextInts()[0];
      unite(x - 1, y - 1);
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
  public static int root(int i) {
    // If the node is its own parent, return it
    if (par[i] == i) {
      return i;
    }
    // Recursively find the root of the parent
    par[i] = root(par[i]);
    // Return the new root
    return par[i];
  }

  // Function to check if two nodes have the same parent
  public static boolean same(int i, int j) {
    // Find the root of both nodes
    return root(i) == root(j);
  }

  // Function to unite two nodes
  public static void unite(int i, int j) {
    // Find the roots of both nodes
    i = root(i);
    j = root(j);
    // If they already have the same parent, return
    if (i == j) {
      return;
    }
    // Make the smaller rank node a child of the larger rank node
    if (rank[i] < rank[j]) {
      par[i] = j;
    } else {
      par[j] = i;
      // If they have the same rank, increase the rank of the node with the smaller index
      if (rank[i] == rank[j]) {
        rank[i]++;
      }
    }
  }
}

