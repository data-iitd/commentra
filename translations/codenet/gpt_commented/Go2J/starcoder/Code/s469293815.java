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
		// Declare three integer variables A, B, and C
		int A, B, C;
		
		// Read input values for A, B, and C from the standard input
		Scanner sc = new Scanner(System.in);
		A = sc.nextInt();
		B = sc.nextInt();
		C = sc.nextInt();

		// Check if the sum of A and B is greater than or equal to C
		if (A+B >= C) {
			// If the condition is true, print "Yes"
			System.out.println("Yes");
		} else {
			// If the condition is false, print "No"
			System.out.println("No");
		}
	}
}

