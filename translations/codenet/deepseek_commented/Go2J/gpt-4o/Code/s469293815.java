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
        Scanner scanner = new Scanner(System.in);
        
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int C = scanner.nextInt();
        
        // Read three integers from standard input
        // A, B, and C will store these values

        if (A + B >= C) {
            // Check if the sum of A and B is greater than or equal to C
            System.out.println("Yes");
        } else {
            // If the sum is less than C, print "No"
            System.out.println("No");
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
