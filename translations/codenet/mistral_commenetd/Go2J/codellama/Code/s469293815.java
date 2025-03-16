
// Package main provides the entry point for the program.
//
// File:  a.java
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare and initialize three integer variables, A, B, and C, with values read from the standard input.
        Scanner scanner = new Scanner(System.in);
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();

        // Check if the sum of A and B is greater than or equal to C.
        if (A + B >= C) {
            // If the condition is true, print "Yes" to the standard output.
            System.out.println("Yes");
        } else {
            // If the condition is false, print "No" to the standard output.
            System.out.println("No");
        }
    }
}

