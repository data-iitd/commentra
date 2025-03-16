#include <stdio.h>
#include <stdlib.h>

// Structure to represent a shop with capacity and demand
typedef struct {
    int a; // capacity
    int b; // demand
} shop;

// Function to compare two shops based on their capacity
int compare(const void *x, const void *y) {
    shop *shop1 = (shop *)x;
    shop *shop2 = (shop *)y;
    return shop1->a - shop2->a;
}

// Function to read an integer from standard input
int getInt() {
    int i;
    scanf("%d", &i);
    return i;
}

// Function to print output to the console
void out(int x) {
    printf("%d\n", x);
}

// Main function is the entry point of the program
int main() {
    // Read the number of shops N and the number of customers M from the standard input
    int N = getInt();
    int M = getInt();

    // Allocate memory for an array of shops
    shop *s = (shop *)malloc(N * sizeof(shop));

    // For each shop, read its capacity and demand
    for (int i = 0; i < N; i++) {
        s[i].a = getInt();
        s[i].b = getInt();
    }

    // Sort the array of shops based on their capacity
    qsort(s, N, sizeof(shop), compare);

    // Initialize a variable to store the total capacity used by the shops
    int total = 0;

    // For each shop in the sorted array
    for (int i = 0; i < N; i++) {
        // Calculate the minimum capacity that can be served by the shop without exceeding the maximum demand
        int n = (s[i].b < M) ? s[i].b : M;
        // Add the capacity of the shop multiplied by the number of customers it can serve to the total capacity
        total += n * s[i].a;
        // Decrease the maximum demand by the number of customers served by the shop
        M -= n;
        // If the maximum demand becomes zero, break the loop
        if (M == 0) {
            break;
        }
    }

    // Print the total capacity used by the shops
    out(total);

    // Free the allocated memory
    free(s);

    return 0;
}

// <END-OF-CODE>
