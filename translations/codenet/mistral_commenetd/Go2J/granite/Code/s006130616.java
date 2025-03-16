
// Package main is the entry point of the program
package main;

import java.util.Scanner;

public class s006130616{
    public static void main(String[] args) {
        // Initialize variables n, m, x for input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();

        // Allocate memory for 2D array a and 1D array p
        int[][] a = new int[n][m];
        int[] p = new int[n];

        // Read input for p and initialize a with empty rows
        for (int i = 0; i < n; i++) {
            // Read input for p[i]
            p[i] = scanner.nextInt();

            // Read input for each element of row i of a
            for (int j = 0; j < m; j++) {
                a[i][j] = scanner.nextInt();
            }
        }

        // Initialize variables ans, tot, and ok
        int ans = 1200001;
        int tot = 0;
        boolean ok = true;

        // Iterate through all possible combinations of bits
        for (int bits = 0; bits < (1 << n); bits++) {
            // Initialize skill array
            int[] skill = new int[m];

            // Calculate total points and update skill array for the current combination of bits
            tot = 0;
            ok = true;
            for (int i = 0; i < n; i++) {
                // Check if the current bit is set
                if ((bits >> i) % 2 == 1) {
                    // Add points from p[i] to total
                    tot += p[i];

                    // Update skill array for each skill
                    for (int j = 0; j < m; j++) {
                        skill[j] += a[i][j];
                    }
                }
            }

            // Check if the current combination of skills is valid
            for (int v : skill) {
                if (v < x) {
                    ok = false;
                    break;
                }
            }

            // If the current combination is valid, update ans if the total points are less than the current answer
            if (ok) {
                if (ans > tot) {
                    ans = tot;
                }
            }
        }

        // Print the answer
        if (ans!= 1200001) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}

// "