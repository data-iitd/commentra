#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int S;
    int R;
    int H;
    int C;
} Item;

int main() {
    // Define the number of items in the input array
    int n;
    scanf("%d", &n);

    // Initialize an array to store the input data
    Item *input_array = (Item *)malloc(n * sizeof(Item));

    // Read n items from the standard input and append them to the input_array
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }

    // Initialize an array to store the outdated items
    int *outdated = (int *)malloc(n * sizeof(int));
    int outdated_count = 0;

    // Check for outdated items in the input array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if the current item is older and smaller than the next one
            if (input_array[i].S < input_array[j].S &&
                input_array[i].R < input_array[j].R &&
                input_array[i].H < input_array[j].H) {
                // Append the current item to the outdated list
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

    // Initialize minimum_cost and input_number to large initial values
    int minimum_cost = 100000;
    int input_number = 0;

    // Find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        int current_item_cost = input_array[i].C;
        int is_outdated = 0;
        for (int k = 0; k < outdated_count; k++) {
            if (outdated[k] == i) {
                is_outdated = 1;
                break;
            }
        }
        // Check if the current item is not outdated and has a smaller cost than minimum_cost
        if (!is_outdated && current_item_cost < minimum_cost) {
            // Update minimum_cost and input_number
            minimum_cost = current_item_cost;
            input_number = i + 1; // +1 for 1-based index
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
