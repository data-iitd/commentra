#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

typedef struct {
    int S, R, H, C;
} Item;

int main() {
    int n;
    Item items[MAX_ITEMS];
    int outdated[MAX_ITEMS];
    int outdated_count = 0;
    int minimum_cost = 100000;
    int input_number = 0;

    // Read the number of items
    scanf("%d", &n);

    // Read each item's attributes (S, R, H, C)
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &items[i].S, &items[i].R, &items[i].H, &items[i].C);
    }

    // Compare each item with every other item to find outdated ones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if item i is outdated compared to item j
            if (items[i].S < items[j].S && items[i].R < items[j].R && items[i].H < items[j].H) {
                // If outdated, add item i to the outdated list
                outdated[outdated_count++] = i;
                break; // No need to check further once outdated is found
            }
        }
    }

    // Loop through the input items to find the one with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        int is_outdated = 0;
        for (int j = 0; j < outdated_count; j++) {
            if (i == outdated[j]) {
                is_outdated = 1;
                break;
            }
        }
        if (!is_outdated && items[i].C < minimum_cost) {
            minimum_cost = items[i].C;
            input_number = i + 1; // Store the index of the current item (1-based index)
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    printf("%d\n", input_number);

    return 0;
}
