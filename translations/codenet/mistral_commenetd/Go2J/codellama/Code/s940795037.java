
// Package main is the entry point of the program
package main

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // Creating a new scanner instance
        Scanner sc = new Scanner(System.in);

        // Reading the first integer from the standard input
        int n = sc.nextInt();
        // Initializing the answer variable
        double ans = 0.0;

        // Iterating through the given number of integers
        for (int i = 0; i < n; i++) {
            // Reading the next integer from the standard input
            double tmp = 1 / sc.nextInt();
            // Adding the reciprocal of the current integer to the answer
            ans += tmp;
        }

        // Printing the final answer
        System.out.println(1 / ans);

    }

}

