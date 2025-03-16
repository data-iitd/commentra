
import java.util.*; // Import the Scanner class for reading input
import java.lang.*; // Import the Integer class for integer manipulation

class Main {
	public static void main(String args[]) {
		// Initialize a Scanner object to read input from the standard input stream
		Scanner sc = new Scanner(System.in);

		// Read the first integer `t` representing the number of test cases
		int t = sc.nextInt();

		// Create an integer array `count` of size `t+1` to store the count of each integer from 1 to `t`
		int[] count = new int[t + 1];

		// Iterate through the test cases using a for loop
		for (int i = 2; i < t + 1; i++) {
			// Read an integer `n` for the current test case and increment the corresponding count in the `count` array
			count[sc.nextInt()]++;
		}

		// Iterate through the integers from 1 to `t` and print their corresponding counts using another for loop
		for (int i = 1; i < t + 1; i++) {
			// Print the count of the current integer
			System.out.println(count[i]);
		}
	}
}