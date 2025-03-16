#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int S;
    int R;
    int H;
    int C;
} Item;

int main() {
    // Read the number of items from user input
    int n;
    scanf("%d", &n);

    // Initialize an array to store the input items
    Item *input_array = malloc(n * sizeof(Item));

    // Loop to read each item's attributes (S, R, H, C)
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }

    // Initialize an array to keep track of outdated items
    int *outdated = malloc(n * sizeof(int));
    int outdated_count = 0;

    // Compare each item with every other item to find outdated ones
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if item i is outdated compared to item j
            if (input_array[i].S < input_array[j].S && 
                input_array[i].R < input_array[j].R && 
                input_array[i].H < input_array[j].H) {
                // If outdated, add item i to the outdated list
                int is_outdated = 0;
                for (int k = 0; k < outdated_count; k++) {
                    if (outdated[k] == i) {
                        is_outdated = 1;
                        break;
                    }
                }
                if (!is_outdated) {
                    outdated[outdated_count++] = i;
                }
            }
        }
    }

    // Initialize variables to track the minimum cost and corresponding item index
    int minimum_cost = 100000;
    int input_number = 0;

    // Loop through the input items to find the one with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        int current_item_cost = input_array[i].C;  // Get the cost of the current item
        int is_outdated = 0;
        for (int k = 0; k < outdated_count; k++) {
            if (outdated[k] == i) {
                is_outdated = 1;
                break;
            }
        }
        // Check if the current item is not outdated and has a lower cost than the current minimum
        if (!is_outdated && current_item_cost < minimum_cost) {
            minimum_cost = current_item_cost;  // Update the minimum cost
            input_number = i + 1;  // Store the index of the current item (1-based index)
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    printf("%d\n", input_number);

    // Free allocated memory
    free(input_array);
    free(outdated);

    return 0;
}

// <END-OF-CODE>
