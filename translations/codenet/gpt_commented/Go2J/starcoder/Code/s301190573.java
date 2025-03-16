package main;

import java.io.*;
import java.util.*;

public class Main {
  // Define a constant size for the buffered reader
  private static final int size = 1000000;
  
  // Create a buffered reader with the specified size
  private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in), size);
  
  // Function to read the next line from standard input
  private static String NextLine() throws IOException {
    String line, buffer;
    boolean isPrefix;
    do {
      line = reader.readLine();
      buffer = line + " ";
      isPrefix = line.length() >= size;
    } while (isPrefix);
    
    return buffer;
  }
  
  // Function to read two integers from the next line of input
  private static int[] NextInts() throws IOException {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]);
    }
    return a;
  }
  
  // Function to read an array of integers from the next line of input
  private static int[] NextIntArray() throws IOException {
    String[] s = NextLine().split(" ");
    int[] a = new int[s.length];
    for (int i = 0; i < s.length; i++) {
      a[i] = Integer.parseInt(s[i]) - 1;
    }
    return a;
  }
  
  // Declare global variables for union-find structure
  private static int[] par, rank;
  
  public static void main(String[] args) throws IOException {
    // Read the number of elements (n) and number of unions (m)
    int n = NextInts()[0], m = NextInts()[0];
    // Read the array of integers
    int[] p = NextIntArray();
    int x, y;
    
    // Initialize the union-find structure
    initialize(n);
    
    // Process each union operation
    for (int i = 0; i < m; i++) {
      x = NextInts()[0]; // Read the pair of integers for union
      y = NextInts()[0];
      unite(x - 1, y - 1); // Unite the two elements (convert to zero-based index)
    }
    
    // Count the number of elements that are in the same set as their corresponding value in p
    int s = 0;
    for (int i = 0; i < n; i++) {
      if (same(i, p[i])) { // Check if the element is in the same set
        s++; // Increment the count
      }
    }
    
    // Print the result
    System.out.println(s);
  }
  
  // Function to initialize the union-find structure
  private static void initialize(int n) {
    par = new int[n]; // Create parent array
    rank = new int[n]; // Create rank array
    
    // Set each element's parent to itself
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }
  
  // Function to find the root of the element with path compression
  private static int root(int i) {
    if (par[i] == i) {
      return i; // Return the root if it is its own parent
    }
    par[i] = root(par[i]); // Path compression
    return par[i]; // Return the root
  }
  
  // Function to check if two elements are in the same set
  private static boolean same(int i, int j) {
    return root(i) == root(j); // Check if their roots are the same
  }
  
  // Function to unite two elements into the same set
  private static void unite(int i, int j) {
    i = root(i); // Find the root of the first element
    j = root(j); // Find the root of the second element
    
    if (i == j) {
      return; // If they are already in the same set, do nothing
    }
    
    // Union by rank
    if (rank[i] < rank[j]) {
      par[i] = j; // Make j the parent of i
    } else {
      par[j] = i; // Make i the parent of j
      if (rank[i] == rank[j]) {
        rank[i]++; // Increment rank if they were the same
      }
    }
  }
}

