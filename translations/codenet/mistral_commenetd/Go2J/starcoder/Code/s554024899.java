
package main;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the first two integers from the standard input using the scanner
        int x = sc.nextInt();
        int y = sc.nextInt();

        // Initialize two variables xt and yt to store the indices of the arrays a where x and y are present
        int xt = 0, yt = 0;

        // Define a 3x3 2D array a
        int[][] a = new int[][]{{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};

        // Iterate through each inner loop of the outer loop
        for (int i = 0; i < a.length; i++) {
            // Iterate through each element of the current inner loop
            for (int j = 0; j < a[i].length; j++) {
                // Check if the current element is equal to x, if yes, store its index in xt
                if (x == a[i][j]) {
                    xt = i;
                }
                // Check if the current element is equal to y, if yes, store its index in yt
                if (y == a[i][j]) {
                    yt = i;
                }
            }
        }

        // Check if the indices xt and yt are equal, if yes, print "Yes"
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

