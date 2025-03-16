#include <stdio.h> // Including standard input-output header

int main() {
    // Declaring variables to hold the prices and number of items
    long Q, H, S, D, N;

    // Reading the prices of different quantities of the item
    scanf("%ld", &Q); // Price for 4 items
    scanf("%ld", &H); // Price for 2 items
    scanf("%ld", &S); // Price for 1 item
    scanf("%ld", &D); // Price for 1 item when bought in pairs
    scanf("%ld", &N); // Number of items to buy

    // Calculating the minimum price for a single item based on the given prices
    long onePrice = Q * 4 < H * 2 ? (Q * 4 < S ? Q * 4 : S) : (H * 2 < S ? H * 2 : S);

    // Checking if the price of one item is less than or equal to half the price of buying in pairs
    if ((double)onePrice <= (double)D / 2) {
        // If true, calculate the total cost for N items at the price of one item
        printf("%ld\n", N * onePrice);
    } else {
        // If false, calculate the total cost using the pair price and the remaining single item price if N is odd
        printf("%ld\n", (N / 2) * D + (N % 2) * onePrice);
    }

    return 0; // Return 0 to indicate successful completion
}

// <END-OF-CODE>
