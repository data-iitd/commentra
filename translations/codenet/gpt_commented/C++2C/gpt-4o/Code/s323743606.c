#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
#define MAX_WEIGHT 5001

// Structure to represent a key-value pair in the map
=======
#define MAX_WEIGHT 5000

// Structure to represent a key-value pair for the map
>>>>>>> 98c87cb78a (data updated)
typedef struct {
    int weight;
    int price;
} Pair;

// Function to compare two pairs for qsort
int compare(const void *a, const void *b) {
    return ((Pair *)a)->weight - ((Pair *)b)->weight;
}

int main() {
    // Declare an array to store the minimum price for each weight
<<<<<<< HEAD
    Pair m[MAX_WEIGHT];
    int count = 0;

    // Iterate over possible quantities of items weighing 200 units
    for (int i = 0; i * 200 < MAX_WEIGHT; i++) {
        // Iterate over possible quantities of items weighing 300 units
        for (int j = 0; j * 300 < MAX_WEIGHT; j++) {
            // Iterate over possible quantities of items weighing 500 units
            for (int k = 0; k * 500 < MAX_WEIGHT; k++) {
=======
    Pair m[MAX_WEIGHT + 1];
    for (int i = 0; i <= MAX_WEIGHT; i++) {
        m[i].weight = i;
        m[i].price = -1; // Initialize prices to -1 (indicating no price set)
    }

    // Iterate over possible quantities of items weighing 200 units
    for (int i = 0; i * 200 < MAX_WEIGHT + 1; i++) {
        // Iterate over possible quantities of items weighing 300 units
        for (int j = 0; j * 300 < MAX_WEIGHT + 1; j++) {
            // Iterate over possible quantities of items weighing 500 units
            for (int k = 0; k * 500 < MAX_WEIGHT + 1; k++) {
>>>>>>> 98c87cb78a (data updated)
                // Calculate the total weight based on the quantities of items
                int w = i * 200 + j * 300 + k * 500;

                // Calculate the price based on the quantities of items
<<<<<<< HEAD
                int p = (i / 5) * 5 * 380 * 0.8 + (i % 5) * 380
                      + (j / 4) * 4 * 550 * 0.85 + (j % 4) * 550
                      + (k / 3) * 3 * 850 * 0.88 + (k % 3) * 850;

                // Update the array with the minimum price for the calculated weight
                int found = 0;
                for (int l = 0; l < count; l++) {
                    if (m[l].weight == w) {
                        found = 1;
                        if (m[l].price > p) {
                            m[l].price = p; // If weight already exists, take the minimum price
                        }
                        break;
                    }
                }
                if (!found && w < MAX_WEIGHT) {
                    m[count].weight = w;
                    m[count].price = p; // If weight does not exist, set the price
                    count++;
=======
                int p = (i / 5 * 5 * 380 * 0.8) + (i % 5 * 380) +
                        (j / 4 * 4 * 550 * 0.85) + (j % 4 * 550) +
                        (k / 3 * 3 * 850 * 0.88) + (k % 3 * 850);

                // Update the array with the minimum price for the calculated weight
                if (m[w].price == -1) {
                    m[w].price = p; // If weight does not exist, set the price
                } else {
                    m[w].price = (m[w].price < p) ? m[w].price : p; // Take the minimum price
>>>>>>> 98c87cb78a (data updated)
                }
            }
        }
    }

<<<<<<< HEAD
    // Sort the array based on weights
    qsort(m, count, sizeof(Pair), compare);

    // Read input weights and output the corresponding minimum prices
    int n;
    while (scanf("%d", &n), n) {
        // Binary search for the weight
        int left = 0, right = count - 1;
        int price = -1; // Default price if not found
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (m[mid].weight == n) {
                price = m[mid].price;
                break;
            } else if (m[mid].weight < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        printf("%d\n", price); // Output the minimum price for the given weight
=======
    // Read input weights and output the corresponding minimum prices
    int n;
    while (scanf("%d", &n), n) {
        printf("%d\n", m[n].price); // Output the minimum price for the given weight
>>>>>>> 98c87cb78a (data updated)
    }

    return 0;
}

// <END-OF-CODE>
