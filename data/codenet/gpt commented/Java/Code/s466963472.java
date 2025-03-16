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
	
	// Initialize a Scanner object for reading input
	static Scanner sc = new Scanner(System.in);
	// Variable to store the input value for the integral calculation
	static int d;
	
	/**
	 * Reads an integer from the input.
	 * @return true if an integer was read successfully, false otherwise.
	 */
	static boolean read() {
		// Check if the next input is an integer
		if(!sc.hasNextInt()) return false;
		// Store the read integer in variable d
		d = sc.nextInt();
		return true;
	}
	
	/**
	 * Calculates the integral of the function x^2 over the interval [0, 600]
	 * with respect to the given step size d.
	 * @return the result of the integral calculation.
	 */
	static int solve() {
		int ans = 0; // Variable to accumulate the result of the integral
		// Loop through multiples of d until reaching 600
		for(int i = 1; i * d < 600; i++) {
			int x = i * d; // Calculate the current value of x
			int y = x * x; // Calculate x^2
			ans += y * d;  // Accumulate the area of the rectangle (x^2 * d)
		}
		return ans; // Return the final result of the integral
	}
	
	public static void main(String[] args) {
		// Continuously read input and calculate the integral until no more integers are provided
		while(read()) {
			System.out.println(solve()); // Print the result of the integral calculation
		}
	}
}
