
import static java.util.Arrays.deepToString; // Import and initialize the deepToString() method statically

import java.util.Scanner; // Import the Scanner class

public class Main {
	public static void main(String[] args) { // Main method to start the program
		new Main().run(); // Create an instance of Main and call its run() method
	}

	void tr(Object... os) { // A utility method to print an object array with deepToString()
		System.err.println(deepToString(os)); // Print the deepToString() representation of the object array
	}

	Scanner sc = new Scanner(System.in); // Initialize the Scanner object to read input from the console

	public void run() { // The main logic of the program
		for (; sc.hasNext();) { // Continuously read input until there is no more input
			int my1 = sc.nextInt(); // Read the first integer from the input
			int my2 = sc.nextInt(); // Read the second integer from the input
			int enemy1 = sc.nextInt(); // Read the third integer from the input

			boolean[] used = new boolean[11]; // Initialize a boolean array of size 11 to keep track of used numbers
			used[my1] = true; // Set the boolean value of my1 to true
			used[my2] = true; // Set the boolean value of my2 to true
			used[enemy1] = true; // Set the boolean value of enemy1 to true

			int all = 0; // Initialize a counter for the total number of unused numbers
			int safe = 0; // Initialize a counter for the number of safe pairs

			for (int i = 1; i <= 10; i++) { // Iterate through all numbers from 1 to 10
				if (!used[i]) { // If the number is not used
					all++; // Increment the all counter
					if (my1 + my2 + i <= 20) { // If the sum of my1, my2, and the current number is less than or equal to 20
						safe++; // Increment the safe counter
					}
				}
			}

			if (safe * 2 >= all) { // If the number of safe pairs is greater than or equal to half of the total number of unused numbers
				System.out.println("YES"); // Print "YES" to the console
			} else {
				System.out.println("NO"); // Print "NO" to the console
			}
		}
	}

	char solve(int[][] a) { // A method to determine the side of the winning player based on the given 3x3 board
		char[] s = {'d', 'o', 'x'}; // Initialize an array of side characters

		for (int side = 1; side <= 2; side++) { // Iterate through both sides (1 for 'x' and 2 for 'o')
			for (int i = 0; i < 3; i++) { // Iterate through each row
				if (a[i][0] == side && a[i][1] == side && a[i][2] == side) { // If all three elements in a row are the same side
					return s[side]; // Return the side character
				}
				if (a[0][i] == side && a[1][i] == side && a[2][i] == side) { // If all three elements in a column are the same side
					return s[side]; // Return the side character
				}
			}
			if (a[0][0] == side && a[1][1] == side && a[2][2] == side) { // If all three diagonal elements are the same side
				return s[side]; // Return the side character
			}
			if (a[0][2] == side && a[1][1] == side && a[2][0] == side) { // If the opposite diagonal elements are the same side
				return s[side]; // Return the side character
			}
		}
		return 'd'; // If no winning side is found, return the default character 'd'
	}
}