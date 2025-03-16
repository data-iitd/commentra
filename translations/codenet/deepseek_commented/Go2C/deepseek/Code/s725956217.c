#include <stdio.h>
#include <stdlib.h>

// Struct to represent a shop with its price and stock.
typedef struct {
    int a, b;
} shop;

// Function to compare two shops by price.
int compare(const void *p1, const void *p2) {
    shop *s1 = (shop *)p1;
    shop *s2 = (shop *)p2;
    return s1->a - s2->a;
}

// Main function to execute the program logic.
int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Create an array of shops and read each shop's price and stock.
    shop s[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &s[i].a, &s[i].b);
    }

    // Sort the shops by price.
    qsort(s, N, sizeof(shop), compare);

    // Calculate the total cost of buying the required number of items.
    int total = 0;
    for (int i = 0; i < N; i++) {
        // Determine the number of items to buy from the current shop.
        int n = (s[i].b < M) ? s[i].b : M;
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

    return 0;
}
