
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		// Create a BufferedReader to read input from the console
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// Read the number of elements
		int n = Integer.parseInt(br.readLine());

		// Read a line of space-separated strings and split them into an array of strings
		String str[] = br.readLine().split(" ");

		// Initialize an array to count occurrences of each number
		int s[] = new int[100010];

		// Count the occurrences of each number and store in the array `s`
		for (int i = 0; i < n; i++) {
			s[Integer.parseInt(str[i])]++;
		}

		// Process the counts in the array `s`
		for (int i = 0; i < s.length; i++) {
			if (s[i] != 0) {
				// If the count is even, set it to 2
				if (s[i] % 2 == 0) {
					s[i] = 2;
				} else {
					// If the count is odd, set it to 1
					s[i] = 1;
				}
			}
		}

		// Count the number of 1s and 2s in the array `s`
		int one = 0;
		int two = 0;

		for (int i = 0; i < s.length; i++) {
			if (s[i] == 2) {
				two++;
			} else if (s[i] == 1) {
				one++;
			}
		}

		// Adjust the count of ones if the number of twos is odd
		if (two % 2 != 0) {
			one--;
		}

		// Print the sum of the number of twos and the adjusted number of ones
		System.out.println(two + one);
	}

}