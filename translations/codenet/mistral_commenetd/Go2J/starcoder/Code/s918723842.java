// Package main contains the entry point of the program.
package main;

import java.util.Scanner;

// main function is the entry point of the program.
public class euler008 {
    // main is the entry point of the program.
    public static void main(String[] args) {
        // Create a new Scanner to read from the standard input.
        Scanner sc = new Scanner(System.in);
        // Read the height H, width W, and number of obstacles N from the standard input.
        int H = sc.nextInt();
        int W = sc.nextInt();
        int N = sc.nextInt();
        // Calculate the maximum dimension A between H and W.
        int A = Math.max(H, W);
        // Print the result, which is the number of rows or columns needed to place all obstacles without overlapping.
        System.out.println((N + A - 1) / A);
    }
}

// 