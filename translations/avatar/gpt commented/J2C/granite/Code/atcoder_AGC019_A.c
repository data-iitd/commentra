
#include <stdio.h> // Importing the standard input/output library

int main() {
    // Reading the prices of different quantities of the item
    long Q, H, S, D, N; // Declaring variables to store the prices and the number of items to buy
    scanf("%ld %ld %ld %ld %ld", &Q, &H, &S, &D, &N);
    
    // Calculating the minimum price for a single item based on the given prices
    long onePrice = (Q * 4 < H * 2)? ((Q * 4 < S)? Q * 4 : S) : ((H * 2 < S)? H * 2 : S);
    
    // Checking if the price of one item is less than or equal to half the price of buying in pairs
    if ((double) onePrice <= (double) D / 2) {
        // If true, calculate the total cost for N items at the price of one item
        printf("%ld\n", N * onePrice);
    } else {
        // If false, calculate the total cost using the pair price and the remaining single item price if N is odd
        printf("%ld\n", (N / 2) * D + (N % 2) * onePrice);
    }
    
    return 0; // Returning 0 to indicate successful execution of the program
}
