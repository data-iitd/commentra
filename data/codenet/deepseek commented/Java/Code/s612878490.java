
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

import static java.lang.Integer.parseInt;

/**
 * Point Card
 */
public class Main {

	public static void main(String[] args) throws IOException {
		// Create a BufferedReader to read input from the standard input stream
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		String[] words;

		// Read the first line of input, which contains two integers separated by a space
		line = br.readLine();

		// Parse the two integers from the input line
		int N, M;
		N = parseInt(line.substring(0, line.indexOf(' ')));
		M = parseInt(line.substring(line.indexOf(' ') + 1));

		// Initialize an array to store the shortage of points for each item
		int[] shortage = new int[M];

		// Read each item's required points and calculate the shortage
		for (int i = 0; i < M; i++) {
			line = br.readLine();
			int A = parseInt(line.substring(0, line.indexOf(' ')));
			shortage[i] = N > A ? N - A : 0;
		}

		// Sort the array of shortages in ascending order
		Arrays.sort(shortage);

		// Initialize a variable to store the total shortage that needs to be filled
		int ans = 0;

		// Sum up all but the last element of the sorted shortages array
		for (int i = 0; i < M - 1; i++) {
			ans += shortage[i];
		}

		// Print the total shortage that needs to be filled
		System.out.println(ans);

	}
}

