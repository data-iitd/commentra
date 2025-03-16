

import java.util.Arrays; // Importing the Arrays class for array-related operations
import java.util.Scanner; // Importing the Scanner class for input/output operations

public class s385901297{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in); // Create a new scanner to read from standard input

		int[] ns = new int[4]; // Create an array of integers with a length of 4
		for (int i = 0; i < 4; i++) { // Read four integers from the input line and store them in the array ns
			ns[i] = scanner.nextInt();
		}

		Arrays.sort(ns); // Sort the array ns in ascending order
		if (Arrays.equals(ns, new int[]{1, 4, 7, 9})) { // Check if the sorted array ns contains the numbers 1, 4, 7, and 9 in that order
			System.out.println("YES"); // Print "YES" if the condition is true
		} else {
			System.out.println("NO"); // Print "NO" if the condition is false
		}
	}
}
