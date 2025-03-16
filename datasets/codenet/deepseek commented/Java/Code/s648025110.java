import java.util.Scanner;  // Importing the Scanner class for input

public class Main {
	public static void main(String args[]) {  // Main method, entry point of the program
		Scanner sc = new Scanner(System.in);  // Creating a Scanner object to read input
		int n;  // Declaring an integer variable to store the number of elements
		n = sc.nextInt();  // Reading the integer input for n
		int[] h = new int[n];  // Initializing an array of size n to store the heights
		for(int i = 0; i < n; i++) {  // Loop to read n integers from input
			h[i] = sc.nextInt();  // Storing the read integer in the array h
		}

		int ans = 0;  // Initializing ans to store the final answer
		int out = 0;  // Initializing out to keep track of the maximum height encountered so far

		for(int i = 0; i < h.length; i++) {  // Loop to iterate through the array h
			if(out < h[i]) {  // Checking if the current height is greater than out
				ans += h[i] - out;  // Adding the difference to ans
				out = h[i];  // Updating out to the current height
			} else {
				out = h[i];  // Updating out to the current height
			}
		}

		System.out.println(ans);  // Printing the final answer
	}
}
