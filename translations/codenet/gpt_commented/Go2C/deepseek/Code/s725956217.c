#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold shop information
typedef struct {
    int a, b;
} Shop;

// Define a type for the array of shops
typedef Shop Shops[100000];

// Function to compare two shops for sorting by price
int compare(const void *p1, const void *p2) {
    Shop *s1 = (Shop *)p1;
    Shop *s2 = (Shop *)p2;
    return s1->a - s2->a;
}

// Main function
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Allocate memory for the shops
    Shops s;

    // Read the price and quantity for each shop
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i].a, &s[i].b);
    }

    // Sort the shops by price
    qsort(s, N, sizeof(Shop), compare);

    int total = 0; // Initialize total cost
    // Calculate the total cost based on available quantities and prices
    for (int i = 0; i < N; i++) {
        int n = (s[i].b < M) ? s[i].b : M; // Determine how much can be bought from this shop
        total += n * s[i].a; // Add to total cost
        M -= n; // Decrease the remaining quantity needed
        if (M == 0) {
            break; // Stop if the required quantity is met
        }
    }

    // Output the total cost
    printf("%d\n", total);

    return 0;
}

