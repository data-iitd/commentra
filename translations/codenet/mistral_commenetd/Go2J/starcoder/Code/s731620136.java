
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // Create a new Scanner

		int N = sc.nextInt(); // Read the first integer from input

		//... (empty block for N == 0 case)

		if (N < 4) { // Check if N is less than 4
			System.out.println(0); // Print 0 if N is less than 4
			return; // Return
		}

		//... (variable initialization block)

		int nr = 0; // Declare and initialize variables for red, blue, and green balls
		int nb = 0;
		int ng = 0;

		for (int i = 0; i < N; i++) { // Iterate through each index i from 0 to N-1
			if (S.charAt(i) == 'R') { // If the character at index i is 'R'
				nr++; // Increment the nr counter
			}

			if (S.charAt(i) == 'B') { // If the character at index i is 'B'
				nb++; // Increment the nb counter
			}

			if (S.charAt(i) == 'G') { // If the character at index i is 'G'
				ng++; // Increment the ng counter
			}
		}

		int same = 0; // Initialize a counter for the number of same-colored groups of three balls

		//... (outer loop block)

		for (int a = 1; a < N; a++) { // Iterate through each index a from 1 to N-1
			int i = 0; // Initialize index i to 0
			int j = a; // Initialize index j to a
			int k = 2 * a; // Initialize index k to a multiplied by 2

			//... (inner loop block)

			while (k < N) { // Iterate through each index k from a*2 to N-1
				//... (check condition block)

				if (S.charAt(i)!= S.charAt(j) && S.charAt(i)!= S.charAt(k) && S.charAt(j)!= S.charAt(k)) { // Check if the balls at indices i, j, and k have different colors
					same++; // If so, increment the same counter
				}

				//... (update indices block)

				i++; // Increment index i
				j++; // Increment index j
				k++; // Increment index k
			}
		}

		int tot = nr * nb * ng; // Calculate the total number of balls

		//... (comment out or remove the following lines as they are not used in the final solution)

		// int tot = 0; // Initialize a variable for the total number of balls
		// int sum = 0; // Initialize a variable for the number of distinct triples
		// int sum2 = 0; // Initialize a variable for the number of distinct triples with the same middle index

		//... (calculate the final result)

		System.out.println(tot - same); // Print the result, which is the total number of balls minus the number of same-colored groups of three balls
	}
}

