package main;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// Read input from standard input
		int N = sc.nextInt();
		int K = sc.nextInt();
		int R = sc.nextInt();
		int S = sc.nextInt();
		int P = sc.nextInt();
		String T = sc.next();

		// Initialize dictionary to store the count of each character
		HashMap<String, Integer> dict = new HashMap<String, Integer>();
		dict.put("r", 0);
		dict.put("s", 0);
		dict.put("p", 0);

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
			char = T.substring(i, i+1);

			// Check if we have reached the window size
			if (i >= K) {
				// If the current character is a substring of the previous K characters, toggle the state of the character
				if (char.equals(T.substring(i-K, i))) {
					switch (char) {
					case "s":
						// Toggle the state of the character at index i%K
						if (s[i%K]) {
							s[i%K] = false;
							continue;
						} else {
							s[i%K] = true;
						}

					case "r":
						// Toggle the state of the character at index i%K
						if (r[i%K]) {
							r[i%K] = false;
							continue;
						} else {
							r[i%K] = true;

						}

					case "p":
						// Toggle the state of the character at index i%K
						if (p[i%K]) {
							p[i%K] = false;
							continue;
						} else {
							p[i%K] = true;

						}
					}

				// If the current character is not a substring of the previous K characters, update the state of the characters accordingly
				} else {
					switch (char) {
					case "s":
						// Set the state of the character at index i%K to 'on'
						s[i%K] = true;
					case "r":
						// Set the state of the character at index i%K to 'on'
						r[i%K] = true;
					case "p":
						// Set the state of the character at index i%K to 'on'
						p[i%K] = true;
					}

				}
			}

			// Update the dictionary with the count of the current character
			switch (char) {
			case "s":
				dict.put("s", dict.get("s") + 1);
			case "r":
				dict.put("r", dict.get("r") + 1);
			case "p":
				dict.put("p", dict.get("p") + 1);
			}
		}

		// Calculate and print the result
		int res = P*dict.get("r") + S*dict.get("p") + R*dict.get("s");
		System.out.println(res);

	}

}

