// Package main provides
//
// File:  A.java
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        // Declare three integer variables A, B, and C
        int A, B, C;

        // Create a Scanner object to read input values
        Scanner scanner = new Scanner(System.in);

        // Read input values for A, B, and C from the standard input
        A = scanner.nextInt();
        B = scanner.nextInt();
        C = scanner.nextInt();

        // Check if the sum of A and B is greater than or equal to C
        if (A + B >= C) {
            // If the condition is true, print "Yes"
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No"
            System.out.println("No");
        }

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
