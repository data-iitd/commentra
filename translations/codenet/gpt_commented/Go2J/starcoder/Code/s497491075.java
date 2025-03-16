package main;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        // Initialize a new scanner to read input
        Scanner sc = new Scanner(System.in);

        // Read the first line of input and parse N (number of lines) and D (distance threshold)
        int[] a = sc.nextLine().split(" ");
        int N = Integer.parseInt(a[0]);
        int D = Integer.parseInt(a[1]);

        // Read the next N lines of input, each containing a pair of integers
        int[][] lines = new int[N][2];
        for (int i = 0; i < N; i++) {
            String[] b = sc.nextLine().split(" ");
            lines[i][0] = Integer.parseInt(b[0]);
            lines[i][1] = Integer.parseInt(b[1]);
        }

        // Initialize a counter for the number of points within the distance D
        int count = 0;
        // Iterate over each line of input
        for (int[] line : lines) {
            // Calculate the Euclidean distance from the origin (0, 0)
            double d = Math.sqrt(line[0] * line[0] + line[1] * line[1]);
            // Check if the distance is less than or equal to D
            if (D >= d) {
                count++; // Increment the count if within distance
            }
        }
        // Output the total count of points within distance D
        System.out.println(count);
    }
}

