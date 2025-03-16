
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
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // Initialize BufferedReader to read input from the console

		String line; // Initialize a String variable to store each line of input

		line = br.readLine(); // Read the first line of input containing N and M

		int N, M; // Initialize two integer variables to store the values of N and M
		N = parseInt(line.substring(0, line.indexOf(' '))); // Parse the first part of the line to get N
		M = parseInt(line.substring(line.indexOf(' ') + 1)); // Parse the second part of the line to get M

		int[] shortage = new int[M]; // Initialize an integer array of size M to store the shortages

		for (int i = 0; i < M; i++) { // Iterate through each line of input to calculate the shortages
			line = br.readLine();
			int A = parseInt(line.substring(0, line.indexOf(' '))); // Parse the first part of the line to get A
			shortage[i] = N > A ? N - A : 0; // Calculate the shortage and store it in the array
		}

		Arrays.sort(shortage); // Sort the shortages in ascending order

		int ans = 0; // Initialize an integer variable to store the answer

		for (int i = 0; i < M - 1; i++) { // Iterate through the first M-1 shortages to calculate the answer
			ans += shortage[i];
		}

		System.out.println(ans); // Print the answer to the console

	}
}

