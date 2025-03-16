
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Declare an integer array 'c' of size 3 to store the input values
		int[] c = new int[3];

		// Start an infinite loop to read input values until EOF is reached
		while (true) {
			Scanner sc = new Scanner(System.in);
			c[0] = sc.nextInt();
			c[1] = sc.nextInt();
			c[2] = sc.nextInt();
			sc.close();

			// Declare and initialize a character array 'card' of size 10 with all elements set to zero
			char[] card = new char[10];
			for (int i = 0; i < 10; i++) {
				card[i] = 0;
			}

			// Loop through the array 'c' to mark the corresponding index in 'card' array
			for (int i = 0; i < 3; i++) {
				card[c[i] - 1] = 1;
			}

			// Loop through the array 'card' to check if there are at least 4 distinct numbers in the input
			int count = 0;
			int sum = c[0] + c[1]; // Initialize sum with the sum of the first two input values
			for (int i = 0; i < 10; i++) {
				// If the index in 'card' array is not set to 1 and the sum of input values, index and 1 is less than or equal to 20
				if (card[i] == 0 && sum + i + 1 <= 20) {
					count++; // Increment the count if the condition is true
				}
			}

			// Check if the count is greater than or equal to 4 and print "YES" if true, otherwise print "NO"
			if (count >= 4) {
				System.out.println("YES");
			}
			else {
				System.out.println("NO");
			}
		}
	}
}

