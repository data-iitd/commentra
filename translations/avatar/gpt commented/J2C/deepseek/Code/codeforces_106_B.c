#include <stdio.h>
#include <stdlib.h>

#define MAX_N 500

typedef struct {
    int a, b, c, price;
} Entry;

int main() {
    int n;
    Entry vec[MAX_N];
    int ans = -1;
    int ansprice = 20000;

    // Read the number of entries
    scanf("%d", &n);

    // Read input values into the array
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &vec[i].a, &vec[i].b, &vec[i].c, &vec[i].price);
    }

    // Iterate through each entry to find the best option
    for (int i = 0; i < n; i++) {
        int fl = 1; // Flag to check if the current entry is not dominated

        // Check if the current entry is dominated by any other entry
        for (int j = 0; j < n; j++) {
            if (vec[i].a < vec[j].a && vec[i].b < vec[j].b && vec[i].c < vec[j].c) {
                fl = 0; // Set flag to 0 if dominated
            }
        }

        // If the current entry is not dominated, check its price
        if (fl == 1) {
            if (vec[i].price < ansprice) {
                ansprice = vec[i].price; // Update the best price found
                ans = i + 1; // Update the answer with the current index (1-based)
            }
        }
    }

    // Output the result
    printf("%d\n", ans);

    return 0;
}
