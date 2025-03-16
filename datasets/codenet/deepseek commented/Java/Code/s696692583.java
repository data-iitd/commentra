import static java.util.Arrays.deepToString; // Importing deepToString for debugging purposes

import java.util.Scanner; // Importing Scanner for input handling

public class Main {
	public static void main(String[] args) { // Main method to run the program
		new Main().run(); // Creating an instance of Main and calling its run method
	}
	void tr(Object... os) { // Method to print debug statements
		System.err.println(deepToString(os)); // Printing the array of objects to standard error for debugging
	}

	Scanner sc = new Scanner(System.in); // Initializing a Scanner object to read input from the standard input
	public void run() { // Main logic method
		for (;sc.hasNext();) { // Infinite loop to read input until there is no more input
			int my1 = sc.nextInt(); // Reading the first integer
			int my2 = sc.nextInt(); // Reading the second integer
			int enemy1 = sc.nextInt(); // Reading the third integer
			boolean[] used = new boolean[11]; // Initializing a boolean array to keep track of used positions
			used[my1] = true; // Marking the position of my1 as used
			used[my2] = true; // Marking the position of my2 as used
			used[enemy1] = true; // Marking the position of enemy1 as used
			int all = 0; // Initializing a counter for all unused positions
			int safe = 0; // Initializing a counter for safe positions
			for (int i = 1; i <= 10; i++) if (!used[i]) { // Loop to count all unused positions
				all++; // Incrementing the counter for all unused positions
				if (my1 + my2 + i <= 20) safe++; // Checking if the current position can form a safe combination
			}
			if (safe * 2 >= all) { // Checking if the number of safe positions is sufficient
				System.out.println("YES"); // Printing "YES" if the condition is met
			} else {
				System.out.println("NO"); // Printing "NO" if the condition is not met
			}
		}
	}
	char solve(int[][] a) { // Method to solve a Tic-Tac-Toe-like problem
		char[] s = {'d', 'o', 'x'}; // Array of characters representing the possible outcomes
		for (int side = 1; side <= 2; side++) { // Loop to check for wins for both sides
			for (int i = 0; i < 3; i++) { // Loop to check rows and columns
				if (a[i][0] == side && a[i][1] == side && a[i][2] == side) return s[side]; // Checking rows
				if (a[0][i] == side && a[1][i] == side && a[2][i] == side) return s[side]; // Checking columns
			}
			if (a[0][0] == side && a[1][1] == side && a[2][2] == side) return s[side]; // Checking diagonal (top-left to bottom-right)
			if (a[0][2] == side && a[1][1] == side && a[2][0] == side) return s[side]; // Checking diagonal (top-right to bottom-left)
		}
		return 'd'; // Returning 'd' if no win condition is found
	}
}
