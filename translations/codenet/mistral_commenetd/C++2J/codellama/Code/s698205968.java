import java.util.Scanner; // Import the Scanner class for input/output operations

public class Main { // Beginning of the Main class
	public static void main(String[] args) { // Beginning of the main function
		Scanner sc = new Scanner(System.in); // Create a new Scanner object to read input from the user

		while (sc.hasNextInt()) { // Start of the while loop
			// The loop continues as long as the user inputs valid integers (m, f, and r)
			// and at least one of them is not -1

			int m = sc.nextInt(); // Read the first integer from the user input
			int f = sc.nextInt(); // Read the second integer from the user input
			int r = sc.nextInt(); // Read the third integer from the user input

			if (m == -1 || f == -1) { // Check if m or f is -1
				System.out.println("F"); // If so, print "F" and move on to the next input
				continue;
			}

			if (m + f >= 80) { // Check if the sum of m and f is greater than or equal to 80
				System.out.println("A"); // If so, print "A" and move on to the next input
				continue;
			}

			if (m + f >= 65) { // Check if the sum of m and f is greater than or equal to 65
				System.out.println("B"); // If so, print "B" and move on to the next input
				continue;
			}

			if (m + f >= 50 || r >= 50) { // Check if the sum of m and f is greater than or equal to 50
										 // or if r is greater than or equal to 50
				System.out.println("C"); // If so, print "C" and move on to the next input
				continue;
			}

			if (m + f >= 30) { // Check if the sum of m and f is greater than or equal to 30
				System.out.println("D"); // If so, print "D" and move on to the next input
				continue;
			}

			System.out.println("F"); // If none of the above conditions are met, print "F" and move on to the next input
			System.out.println(); // Print a newline character to start the next input on a new line
		}

		sc.close(); // Close the Scanner object
	}
}

