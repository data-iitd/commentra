
// Package declaration and importing necessary packages
package com.company;

import java.util.*;

// s219662687 class declaration and initialization of constants
public class s219662687{
    public static final int INF = (int)Math.pow(10, 11); // Large constant value for initializing arrays

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Reading input values from standard input
        int A = sc.nextInt();
        int B = sc.nextInt();
        int Q = sc.nextInt();

        // Initializing arrays s and t with size A+2 and B+2 respectively
        // The first and last elements are initialized with -INF and INF respectively
        int[] s = new int[A+2];
        int[] t = new int[B+2];
        Arrays.fill(s, -INF);
        Arrays.fill(t, INF);

        // Reading A elements of array s from standard input
        for (int i = 1; i <= A; i++) {
            s[i] = sc.nextInt();
        }

        // Reading B elements of array t from standard input
        for (int i = 1; i <= B; i++) {
            t[i] = sc.nextInt();
        }

        // Processing each query
        for (int i = 0; i < Q; i++) {
            // Reading query value x from standard input
            int x = sc.nextInt();

            // Finding the indices b and d of array s and t respectively
            // where s[b] and t[d] are the smallest elements greater than x
            int b = Arrays.binarySearch(s, x);
            int d = Arrays.binarySearch(t, x);

            // Computing the minimum distance between x and any pair of elements S and T
            // from arrays s and t respectively
            int res = INF;
            for (int S : new int[]{s[b-1], s[b]}) {
                for (int T : new int[]{t[d-1], t[d]}) {
                    // Computing the absolute difference between S and x, and T and S
                    int d1 = Math.abs(S - x);
                    int d2 = Math.abs(T - S);

                    // Updating the minimum distance if the current pair has a smaller distance
                    res = Math.min(res, Math.min(d1, d2));
                }
            }

            // Printing the minimum distance for the current query
            System.out.println(res);
        }
    }
}

// Input reading helper functions
// (No need to translate as it is already provided in the given code snippet)

// Helper functions for array manipulation and arithmetic operations
// (No need to translate as it is already provided in the given code snippet)

// End of code marker
// 