// Package main provides
//
// File:  a.java
// Author: ymiyamoto
//
// Created on Sat Dec 29 04:47:30 2018
//
package main;

import java.util.Scanner;

public class a {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();

        // Read three integers from standard input
        // A, B, and C will store these values

        if (A+B >= C) {
            // Check if the sum of A and B is greater than or equal to C
            System.out.println("Yes");
        } else {
            // If the sum is less than C, print "No"
            System.out.println("No");
        }
    }
}

