
package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize variables
		int N, K, R, S, P;
		String T;

		// Read input from standard input
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		R = sc.nextInt();
		S = sc.nextInt();
		P = sc.nextInt();
		T = sc.next();

		// Initialize dictionary to store the count of each character
		int[] dict = new int[3];

		// Initialize boolean arrays to represent the state of each character
		String char = "";
		boolean[] s = new boolean[N];
		boolean[] r = new boolean[N];
		boolean[] p = new boolean[N];

		// Initialize all characters to be in the 'on' state
		for (int i = 0; i < N; i++) {
			s[i] = true;
		}

		// Iterate through each character in the input string
		for (int i = 0; i < T.length(); i++) {
			// Assign the current character to a variable
			char = T.substring(i, i + 1);

			// Check if we have reached the window size
			if (i >= K) {
				// If the current character is a substring of the previous K characters, toggle the state of the character
				if (char.equals(T.substring(i - K, i + 1 - K))) {
					switch (char) {
					case "s":
						// Toggle the state of the character at index i%K
						if (s[i % K]) {
							s[i % K] = false;
							continue;
						} else {
							s[i % K] = true;
						}

					case "r":
						// Toggle the state of the character at index i%K
						if (r[i % K]) {
							r[i % K] = false;
							continue;
						} else {
							r[i % K] = true;

						}

					case "p":
						// Toggle the state of the character at index i%K
						if (p[i % K]) {
							p[i % K] = false;
							continue;
						} else {
							p[i % K] = true;

						}
					}

				// If the current character is not a substring of the previous K characters, update the state of the characters accordingly
				} else {
					switch (char) {
					case "s":
						// Set the state of the character at index i%K to 'on'
						s[i % K] = true;
					case "r":
						// Set the state of the character at index i%K to 'on'
						r[i % K] = true;
					case "p":
						// Set the state of the character at index i%K to 'on'
						p[i % K] = true;
					}

				}
			}

			// Update the dictionary with the count of the current character
			switch (char) {
			case "s":
				dict[0] = dict[0] + 1;
			case "r":
				dict[1] = dict[1] + 1;
			case "p":
				dict[2] = dict[2] + 1;
			}
		}

		// Calculate and print the result
		int res = P * dict[1] + S * dict[2] + R * dict[0];
		System.out.println(res);

	}

}

