/**
 * 
 * AOJ No. 0014 Integral
 * 
 * @author 		yuichirw <y.iky917@gmail.com>
 * @accepted	2010-11-09
 * @see			http://rose.u-aizu.ac.jp/onlinejudge/ProblemSet/description.jsp?id=0014&lang=jp
 */

import java.util.*;
public class Main {
	
	// Scanner object to read input from the standard system input
	static Scanner sc = new Scanner(System.in);
	
	// Variable to store the input value
	static int d;
	
	// Method to read an integer input. Returns false if no input is available.
	static boolean read() {
		if(!sc.hasNextInt()) return false;
		d = sc.nextInt();
		return true;
	}
	
	// Method to solve the problem by calculating the sum of squares of multiples of d up to 600
	static int solve() {
		int ans,n;
		// Original commented-out code for reference
		/*
		ans = 0; n = 600 / d;
		for(int x = d; x < 600; x += d) {
			ans += d * ((x * x));
		}
		return ans;
		*/
		
		// New implementation using a loop to calculate the sum of squares of multiples of d
		ans = 0;
		for(int i = 1; i * d < 600; i++) {
			int x = i * d;
			int y = x * x;
			ans += y * d;
		}
		return ans;
	}
	
	// Main method to repeatedly read input, solve the problem, and print the result
	public static void main(String[] args) {
		while(read()) {
			System.out.println(solve());
		}
	}

}
