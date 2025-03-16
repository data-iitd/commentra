#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Disable synchronization with C I/O for faster input/output
    cin.tie(0);
    ios::sync_with_stdio(false);

    # Initialize a vector to hold the denominations of money
    m = [10, 50, 100, 500]

    first = True # Flag to handle formatting of output
    # Read money input until EOF or invalid input
    for money in iter(int, 0):
        # Print a newline before the output of subsequent transactions
        if not first:
            print()

        first = False # Set the flag to false after the first input
        sum = 0 # Initialize sum to calculate total value of coins
        num = [0, 0, 0, 0] # Vector to hold the number of each denomination

        # Read the number of coins for each denomination and calculate the total sum
        for i in range(4):
            num[i] = int(input()) # Input the number of coins for the current denomination
            sum += num[i] * m[i] # Update the total sum

        # Calculate the change to be returned
        change = sum - money

        # Calculate how many coins of each denomination to return as change
        for i in range(3, -1, -1):
            if change // m[i]: # Check if the current denomination can be used for change
                num[i] = num[i] - change // m[i] # Reduce the number of coins of this denomination
                change %= m[i] # Update the remaining change to be returned

        # Output the remaining coins of each denomination that are greater than zero
        for i in range(4):
            if num[i] > 0: # Only print denominations that still have coins left
                print(m[i], num[i]) # Print denomination and count

    return EXIT_SUCCESS # Return success status
}

