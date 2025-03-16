#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int S, R, H, C;
} Item;

int main() {
    int n;
    scanf("%d", &n);  // Take the number of elements as input

    Item *input_array = (Item *)malloc(n * sizeof(Item));  // Allocate memory for input_array

    // Loop to take inputs and store them in input_array
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }

    int *outdated = (int *)malloc(n * sizeof(int));  // Array to mark outdated items
    int outdated_count = 0;  // Counter for outdated items

    // Nested loop to compare each element in input_array with every other element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input_array[i].S < input_array[j].S &&
                input_array[i].R < input_array[j].R &&
                input_array[i].H < input_array[j].H) {
                // Mark the item as outdated
                int is_outdated = 0;
                for (int k = 0; k < outdated_count; k++) {
                    if (outdated[k] == i) {
                        is_outdated = 1;
                        break;
                    }
                }
                if (!is_outdated) {
                    outdated[outdated_count++] = i;  // Append outdated index
                }
            }
        }
    }

    int minimum_cost = 100000;  // Initialize minimum_cost to a large value
    int input_number = 0;  // Initialize input_number to 0

    // Iterate through input_array to find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        int cost = input_array[i].C;
        int is_outdated = 0;
        for (int k = 0; k < outdated_count; k++) {
            if (outdated[k] == i) {
                is_outdated = 1;
                break;
            }
        }
        if (!is_outdated && cost < minimum_cost) {
            minimum_cost = cost;  // Update minimum_cost
            input_number = i + 1;  // Update input_number
        }
    }

    printf("%d\n", input_number);  // Print the input number of the item with the minimum cost that is not outdated

    // Free allocated memory
    free(input_array);
    free(outdated);

    return 0;
}

// <END-OF-CODE>
