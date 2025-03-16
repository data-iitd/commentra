// Package main is the entry point of the program
package main;

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner next = new Scanner(System.in); // Initialize a new scanner for reading input
		String N = next.next(); // Read input N as a string
		int n = 0;
		for (int i = 0; i < N.length(); i++) {
			n += N.charAt(i) - '0'; // Convert each digit to an integer and add to the sum
		}
		int m = next.nextInt(); // Read input m as an integer
		if (m % n == 0) {
			System.out.println("Yes"); // Print "Yes" if m is divisible by n
		} else {
			System.out.println("No"); // Print "No" if m is not divisible by n
		}
	}
}

