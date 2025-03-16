
import java.util.Scanner; // Importing Scanner class for reading input from the console

public class Main {
	public static void main(String args[]) {
		// Creating a Scanner object to read input from the console
		Scanner sc = new Scanner(System.in);

		String S; // Declaring a String variable 'S' to store the input string
		long MOD = 1000000007; // Declaring a constant 'MOD' with value 1000000007

		// Initializing a 2D long array 'dp' of size (S.length() + 1) x 13
		long dp[][] = new long[S.length() + 1][13];
		dp[0][0] = 1; // Initializing the first element of the dp array with value 1

		// Reading the input string 'S' from the console
		S = sc.next();

		// Iterating through each character in the input string 'S'
		for(int i = 0; i < S.length(); i++) {
			// Checking if the current character is a '?'
			if(S.substring(i , i + 1).equals("?")) {
				// Iterating through each digit from 0 to 9 and each state from 0 to 12
				for(int j = 0; j < 10; j++) {
					for(int k = 0; k < 13; k++) {
						// Updating the dp array for the current state and next character '?'
						dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
						dp[i + 1][(k * 10 + j) % 13] %= MOD;
					}
				}
			} else { // Else, the current character is not a '?'
				// Iterating through each state from 0 to 12
				for(int k = 0; k < 13; k++) {
					// Extracting the digit from the current character and updating the dp array
					int x = Integer.parseInt(S.substring(i, i + 1));
					dp[i + 1][(k * 10 + x) % 13] += dp[i][k];
					dp[i + 1][(k * 10 + x) % 13] %= MOD;
				}
			}
		}

		// Printing the result, which is the value of dp[S.length()][5]
		System.out.println(dp[S.length()][5]);
	}
}

