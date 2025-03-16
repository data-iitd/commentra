/**
 * 
 * AOJ No. 0014 Integral
 * 
 * @author 		yuichirw <y.iky917@gmail.com>
 * @accepted	2010-11-09
 * @see			http://rose.u-aizu.ac.jp/onlinejudge/ProblemSet/description.jsp?id=0014&lang=jp
 */

import java.util.*; // Importing the Scanner class from the java.util package

public class Main { // Defining the Main class
	
	static Scanner sc; // Declaring a static Scanner object named sc
	static int d; // Declaring a static integer variable named d

	static boolean read() { // Defining a static boolean method named read
		if(!sc.hasNextInt()) { // Checking if the Scanner has next integer
			return false; // Returning false if not
		}
		d = sc.nextInt(); // Reading an integer value and assigning it to d
		return true; // Returning true if successful
	}

	static int solve() { // Defining a static integer method named solve
		int ans, n; // Declaring two local integer variables ans and n

		ans = 0; // Initializing ans to 0
		n = 600 / d; // Calculating the number of times d fits into 600

		/*
		ans = 0; n = 600 / d;
		for(int x = d; x < 600; x += d) { // This loop calculates the sum of squares of multiples of d up to 600
			ans += d * ((x * x)); // Adding the product of d and the square of x to ans
		}
		return ans;
		*/

		// Instead of the above loop, we can calculate the sum of squares of multiples of d up to the square root of 600 using the following method:
		for(int i = 1; i * d < 600; i++) { // Starting the loop from i = 1 and continuing until i * d < 600
			int x = i * d; // Assigning the value of i * d to x
			int y = x * x; // Calculating the square of x and assigning it to y
			ans += y * d; // Adding the product of d, the square of x, and d to ans
		}

		return ans; // Returning the final value of ans
	}

	public static void main(String[] args) { // Defining the main method
		while(read()) { // Starting an infinite loop that continues until read() returns false
			System.out.println(solve()); // Printing the result of solve()
		}
	}

}
