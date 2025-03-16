
package main;

import java.util.Scanner;

// Define a custom data structure
class data {
	int n, m; // dimensions of the images
	String[] nImg, mImg; // image data as strings

	// Initialize a new data object
	data() {
		// Read dimensions from user input
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		sc.close();
		// Load image data as strings
		nImg = load(n);
		mImg = load(m);
	}

	// Load image data as strings
	String[] load(int cnt) {
		// Allocate memory for image data
		String[] ret = new String[cnt];
		// Read image data from user input
		for (int i = 0; i < cnt; i++) {
			ret[i] = new Scanner(System.in).next();
		}

		// Return loaded image data
		return ret;
	}

	// Check if data already exists in the larger image
	boolean exist() {
		// Iterate through all possible positions in larger image
		for (int i = 0; i <= n-m; i++) {
			for (int j = 0; j <= n-m; j++) {
				// Check if current position matches the smaller image
				if (match(i, j)) {
					// If match is found, return true
					return true;
				}
			}
		}

		// If no match is found, return false
		return false;
	}

	// Check if smaller image matches at current position in larger image
	boolean match(int x, int y) {
		// Iterate through each pixel in smaller image
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				// Check if corresponding pixel in larger image matches
				if (!nImg[x+i].charAt(y+j).equals(mImg[i].charAt(j))) {
					// If mismatch is found, return false
					return false;
				}
			}
		}

		// If all pixels match, return true
		return true;
	}
}

// Main function
public class Main {
	// Main function
	public static void main(String[] args) {
		// Initialize a new data object
		data d = new data();
		// Check if data already exists
		if (d.exist()) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}

