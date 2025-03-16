import java.util.*;

public class Main {

	/*
	 * This class contains the main method and solves the problem 122C
	 * 
	 */
	public static void main(String[] args) {
		// Initialize scanner to read input from standard input
		Scanner sc = new Scanner(System.in);

		// Read the number of strings and queries from the input
		int N = sc.nextInt(), Q = sc.nextInt();

		// Read the string s from the input
		String s = sc.next();

		// Initialize an integer array pre of size N+1 to store the prefix sums
		int pre[] = new int[N+1];

		// Iterate through the string s from index 1 to N-1
		for(int i = 1; i<N; i++) {
			// If the current character is 'A' and the next character is 'C'
			if(s.charAt(i-1) == 'A' && s.charAt(i) =='C') {
				// Set the corresponding element in the pre array to 1
				pre[i] = 1;
			}
		}

		// Calculate the prefix sums of the pre array
		for(int i = 1; i<N; i++) {
			pre[i] += pre[i-1];
		}

		// Process the queries
		while(Q-- > 0) {
			// Read the left and right indices of the query from the input
			int l = sc.nextInt(), r = sc.nextInt();

			// Decrement the right index by 1 because the indices are 1-based
			r--;

			// Print the difference between the prefix sum at index r and the prefix sum at index l-1
			System.out.println(pre[r] - pre[l-1]);
		}
	}
}
