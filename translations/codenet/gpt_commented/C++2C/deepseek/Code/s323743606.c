#include <stdio.h>
#include <stdlib.h>

// Define a structure for the map entries
typedef struct {
    int weight;
    int price;
} MapEntry;

// Function to compare two MapEntry elements for qsort
int compare(const void *a, const void *b) {
    return ((MapEntry *)a)->weight - ((MapEntry *)b)->weight;
}

int main() {
    // Declare an array to store the map entries
    MapEntry entries[5001];
    int entryCount = 0;

    // Iterate over possible quantities of items weighing 200 units
    for (int i = 0; i * 200 < 5001; i++) {
        // Iterate over possible quantities of items weighing 300 units
        for (int j = 0; j * 300 < 5001; j++) {
            // Iterate over possible quantities of items weighing 500 units
            for (int k = 0; k * 500 < 5001; k++) {
                // Calculate the total weight based on the quantities of items
                int w = i * 200 + j * 300 + k * 500;

                // Calculate the price based on the quantities of items
                int p = i / 5 * 5 * 380 * 0.8 + i % 5 * 380
                      + j / 4 * 4 * 550 * 0.85 + j % 4 * 550
                      + k / 3 * 3 * 850 * 0.88 + k % 3 * 850;

                // Store the weight and price in the entries array
                entries[entryCount].weight = w;
                entries[entryCount].price = p;
                entryCount++;
            }
        }
    }

    // Sort the entries array based on weight
    qsort(entries, entryCount, sizeof(MapEntry), compare);

    // Read input weights and output the corresponding minimum prices
    int n;
    while (scanf("%d", &n) != EOF && n) {
        // Perform binary search to find the minimum price for the given weight
        int left = 0, right = entryCount - 1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (entries[mid].weight == n) {
                result = entries[mid].price;
                break;
            } else if (entries[mid].weight < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        printf("%d\n", result); // Output the minimum price for the given weight
    }

    return 0;
}
