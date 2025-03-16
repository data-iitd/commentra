
import java.util.Scanner;

public class s663381244{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		// Step 1: Setting up input and output streams
		// The code starts by setting up the input and output streams to be as fast as possible.
		// This is achieved by creating a `Scanner` object to read input from the console.

		int[] m = {10, 50, 100, 500};

		// Step 2: Initializing an array to store denominations
		// The code initializes an array `m` to store the denominations of the currency,
		// which are 10, 50, 100, and 500.

		boolean first = true;
		while(scanner.hasNextInt()) {
			// Step 3: Reading input and processing each transaction
			// The code enters a loop where it reads an integer `money` from the input.
			// If `money` is zero, the loop terminates. Otherwise, it processes the transaction.

			if(!first)
				System.out.println();

			// Step 4: Checking if it's the first transaction and outputting a newline if necessary
			// The code checks if it's the first transaction. If not, it outputs a newline to separate the transactions.

			first = false;
			int sum = 0;
			int[] num = new int[4];
			for(int i = 0; i < 4; ++i) {
				num[i] = scanner.nextInt();
				sum += num[i] * m[i];
			}

			// Step 5: Calculating the total value of the currency and the change to be given
			// The code initializes `sum` to zero and an array `num` to store the number of each denomination.
			// It then reads the number of each denomination and calculates the total value of the currency.

			int change = sum - scanner.nextInt();
			for(int i = 3; i >= 0; --i) {
				if(change / m[i] > 0) {
					num[i] = num[i] - change / m[i];
					change %= m[i];
				}
			}

			// Step 6: Calculating the change and updating the number of denominations
			// The code calculates the change by subtracting the input amount from the total value.
			// It then updates the number of each denomination to reflect the change.

			for(int i = 0; i < 4; ++i) {
				if(num[i] > 0)
					System.out.println(m[i] + " " + num[i]);
			}

			// Step 7: Outputting the denominations and their counts for the change
			// The code outputs the denominations and their counts for the change.
		}

		// Final Comment: The code runs until the input money is zero, processing each transaction
		// to calculate and output the change based on the available denominations.

		scanner.close();
	}
}

Translate the above Java code to Python and end with comment "