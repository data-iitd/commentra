#include <stdio.h>
#include <stdlib.h>

// Struct to represent a shop with its price and stock.
typedef struct {
    int a; // price
    int b; // stock
} shop;

// Comparator function for sorting shops by price.
int compare(const void *x, const void *y) {
    shop *shop1 = (shop *)x;
    shop *shop2 = (shop *)y;
    return shop1->a - shop2->a;
}

// Function to read an integer from input.
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

<<<<<<< HEAD
// Function to find the minimum of two integers.
=======
// Function to return the minimum of two integers.
>>>>>>> 98c87cb78a (data updated)
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Main function to execute the program logic.
int main() {
    // Read the number of shops and the amount of items to buy.
    int N = getInt();
    int M = getInt();

    // Create an array of shops and read each shop's price and stock.
    shop *s = (shop *)malloc(N * sizeof(shop));
    for (int i = 0; i < N; i++) {
        s[i].a = getInt();
        s[i].b = getInt();
    }

    // Sort the shops by price.
    qsort(s, N, sizeof(shop), compare);

    // Calculate the total cost of buying the required number of items.
    int total = 0;
    for (int i = 0; i < N; i++) {
        // Determine the number of items to buy from the current shop.
        int n = min(s[i].b, M);
        // Update the total cost and the remaining items to buy.
        total += n * s[i].a;
        M -= n;
        // Break if all items are bought.
        if (M == 0) {
            break;
        }
    }

    // Print the total cost.
    printf("%d\n", total);

    // Free allocated memory.
    free(s);
    return 0;
}

// <END-OF-CODE>
