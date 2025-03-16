
package com.company;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        // Create a buffered reader for standard input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        // Read the number of elements (n) and number of unions (m)
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        // Read the array of integers
        int[] p = new int[n];
        st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            p[i] = Integer.parseInt(st.nextToken());
        }

        // Initialize the union-find structure
        initialize(n);

        // Process each union operation
        for (int i = 0; i < m; i++) {
            // Read the pair of integers for union
            st = new StringTokenizer(reader.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
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
    public static void initialize(int n) {
        par = new int[n]; // Create parent array
        rank = new int[n]; // Create rank array

        // Set each element's parent to itself
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
    }

    // Function to find the root of the element with path compression
    public static int root(int i) {
        if (par[i] == i) {
            return i; // Return the root if it is its own parent
        }
        par[i] = root(par[i]); // Path compression
        return par[i]; // Return the root
    }

    // Function to check if two elements are in the same set
    public static boolean same(int i, int j) {
        return root(i) == root(j); // Check if their roots are the same
    }

    // Function to unite two elements into the same set
    public static void unite(int i, int j) {
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

    // Declare global variables for union-find structure
    public static int[] par, rank;

    // END-OF-CODE
}