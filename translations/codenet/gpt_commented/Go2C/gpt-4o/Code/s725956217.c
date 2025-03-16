#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int price;
    int quantity;
} Shop;

// Comparator function for qsort to sort shops by price
int compare(const void *a, const void *b) {
    return ((Shop *)a)->price - ((Shop *)b)->price;
}

// Function to read an integer from input
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// Function to find the minimum of two integers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Main function
int main() {
    int N = getInt(); // Read the number of shops
    int M = getInt(); // Read the total quantity needed
    Shop *shops = malloc(N * sizeof(Shop)); // Allocate memory for shops

    // Read the price and quantity for each shop
    for (int i = 0; i < N; i++) {
<<<<<<< HEAD
        shops[i].price = getInt(); // Read price
        shops[i].quantity = getInt(); // Read quantity
=======
        shops[i].price = getInt();
        shops[i].quantity = getInt();
>>>>>>> 98c87cb78a (data updated)
    }

    // Sort the shops by price
    qsort(shops, N, sizeof(Shop), compare);

<<<<<<< HEAD
    int total = 0; // Initialize total cost
    // Calculate the total cost based on available quantities and prices
    for (int i = 0; i < N; i++) {
        int n = min(shops[i].quantity, M); // Determine how much can be bought from this shop
        total += n * shops[i].price; // Add to total cost
        M -= n; // Decrease the remaining quantity needed
=======
    int totalCost = 0; // Initialize total cost

    // Calculate the total cost based on available quantities and prices
    for (int i = 0; i < N; i++) {
        int quantityToBuy = min(shops[i].quantity, M); // Determine how much can be bought from this shop
        totalCost += quantityToBuy * shops[i].price; // Add to total cost
        M -= quantityToBuy; // Decrease the remaining quantity needed
>>>>>>> 98c87cb78a (data updated)
        if (M == 0) {
            break; // Stop if the required quantity is met
        }
    }

<<<<<<< HEAD
    printf("%d\n", total); // Output the total cost
    free(shops); // Free allocated memory
    return 0; // Return success
=======
    printf("%d\n", totalCost); // Output the total cost

    free(shops); // Free allocated memory
    return 0;
>>>>>>> 98c87cb78a (data updated)
}

// <END-OF-CODE>
