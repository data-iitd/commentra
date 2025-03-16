package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// Declare variables n and m to hold the number of problems and the number of hard problems respectively
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		// Calculate the total time required to solve the problems
		// The time for hard problems is 1900 each, and for easy problems is 100 each
		int x = m*1900 + (n-m)*100;
		
		// Calculate the total number of ways to solve the problems
		// This is done by multiplying the total time by 2 raised to the power of m (the number of hard problems)
		System.out.println(x * (int) Math.pow(2, m));
	}
}

