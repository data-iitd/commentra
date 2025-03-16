
#include <stdio.h>
#include <stdlib.h>

int main() {
	// Step 1: Setting up input and output streams
	// The code starts by setting up the input and output streams to be as fast as possible.
	// This is achieved by turning off synchronization between the C and C++ standard streams
	// and setting the `cin` object to not buffer its input.

	int m[] = {10, 50, 100, 500};
	int money, num[4];
	bool first = true;
	while(scanf("%d", &money), money) {
		// Step 2: Reading input and processing each transaction
		// The code enters a loop where it reads an integer `money` from the input.
		// If `money` is zero, the loop terminates. Otherwise, it processes the transaction.

		if(!first)
			puts("");

		// Step 3: Checking if it's the first transaction and outputting a newline if necessary
		// The code checks if it's the first transaction. If not, it outputs a newline to separate the transactions.

		first = false;
		int sum = 0;
		for(int i = 0; i < 4; ++i) {
			scanf("%d", &num[i]);
			sum += num[i] * m[i];
		}

		// Step 4: Calculating the total value of the currency and the change to be given
		// The code initializes `sum` to zero and a vector `num` to store the number of each denomination.
		// It then reads the number of each denomination and calculates the total value of the currency.

		int change = sum - money;
		for(int i = 3; i >= 0; --i) {
			if(change / m[i]) {
				num[i] = num[i] - change / m[i];
				change %= m[i];
			}
		}

		// Step 5: Calculating the change and updating the number of denominations
		// The code calculates the change by subtracting the input amount from the total value.
		// It then updates the number of each denomination to reflect the change.

		for(int i = 0; i < 4; ++i)
			if(num[i] > 0)
				printf("%d %d\n", m[i], num[i]);

		// Step 6: Outputting the denominations and their counts for the change
		// The code outputs the denominations and their counts for the change.
	}

	// Final Comment: The code runs until the input money is zero, processing each transaction
	// to calculate and output the change based on the available denominations.

	return 0;
}

Translate the above C code to C++ and end with comment "