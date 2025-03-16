#include <stdio.h>
#include <stdlib.h>

int main() {
    // Step 1: Setting up input and output streams
    // The code starts by setting up the input and output streams to be as fast as possible.
    // This is achieved by turning off synchronization between the C and C++ standard streams
    // and setting the `cin` object to not buffer its input.

    int m[] = {10, 50, 100, 500};
<<<<<<< HEAD
    // Step 2: Initializing an array to store denominations
=======
    int num[4];
    int money;

    // Step 2: Initializing a vector to store denominations
>>>>>>> 98c87cb78a (data updated)
    // The code initializes an array `m` to store the denominations of the currency,
    // which are 10, 50, 100, and 500.

    int first = 1;
<<<<<<< HEAD
    while (1) {
        int money;
        scanf("%d", &money);
        if (money == 0) break; // Step 3: Reading input and processing each transaction

        // Step 4: Checking if it's the first transaction and outputting a newline if necessary
        if (!first) {
            printf("\n");
        }
        first = 0;

        int sum = 0;
        int num[4] = {0}; // Array to store the number of each denomination
=======
    while (scanf("%d", &money) && money) {
        // Step 3: Reading input and processing each transaction
        // The code enters a loop where it reads an integer `money` from the input.
        // If `money` is zero, the loop terminates. Otherwise, it processes the transaction.

        if (!first)
            printf("\n");

        // Step 4: Checking if it's the first transaction and outputting a newline if necessary
        // The code checks if it's the first transaction. If not, it outputs a newline to separate the transactions.

        first = 0;
        int sum = 0;

>>>>>>> 98c87cb78a (data updated)
        for (int i = 0; i < 4; ++i) {
            scanf("%d", &num[i]);
            sum += num[i] * m[i];
        }

        // Step 5: Calculating the total value of the currency and the change to be given
<<<<<<< HEAD
=======
        // The code initializes `sum` to zero and an array `num` to store the number of each denomination.
        // It then reads the number of each denomination and calculates the total value of the currency.

>>>>>>> 98c87cb78a (data updated)
        int change = sum - money;
        for (int i = 3; i >= 0; --i) {
            if (change / m[i]) {
                num[i] -= change / m[i];
                change %= m[i];
            }
        }

        // Step 6: Calculating the change and updating the number of denominations
<<<<<<< HEAD
=======
        // The code calculates the change by subtracting the input amount from the total value.
        // It then updates the number of each denomination to reflect the change.

>>>>>>> 98c87cb78a (data updated)
        for (int i = 0; i < 4; ++i) {
            if (num[i] > 0) {
                printf("%d %d\n", m[i], num[i]);
            }
        }

        // Step 7: Outputting the denominations and their counts for the change
<<<<<<< HEAD
=======
        // The code outputs the denominations and their counts for the change.
>>>>>>> 98c87cb78a (data updated)
    }

    // Final Comment: The code runs until the input money is zero, processing each transaction
    // to calculate and output the change based on the available denominations.

    return EXIT_SUCCESS;
}

// <END-OF-CODE>
