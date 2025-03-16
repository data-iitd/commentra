#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 1000

typedef struct {
    int S, R, H, C;
} Item;

int main() {
    int n;
    Item input_array[MAX_ITEMS];
    Item outdated[MAX_ITEMS];
    int outdated_count = 0;
    int minimum_cost = 100000;
    int input_number = 0;

    // Read the number of items
    scanf("%d", &n);

    // Read the items
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }

    // Check for outdated items
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input_array[i].S < input_array[j].S &&
                input_array[i].R < input_array[j].R &&
                input_array[i].H < input_array[j].H) {
                int is_duplicate = 0;
                for (int k = 0; k < outdated_count; k++) {
                    if (input_array[i].S == outdated[k].S &&
                        input_array[i].R == outdated[k].R &&
                        input_array[i].H == outdated[k].H) {
                        is_duplicate = 1;
                        break;
                    }
                }
                if (!is_duplicate) {
                    outdated[outdated_count++] = input_array[i];
                }
            }
        }
    }

    // Find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        Item current_item = input_array[i];
        int cost = current_item.C;
        int is_outdated = 0;

        // Check if the current item is outdated
        for (int j = 0; j < outdated_count; j++) {
            if (current_item.S == outdated[j].S &&
                current_item.R == outdated[j].R &&
                current_item.H == outdated[j].H) {
                is_outdated = 1;
                break;
            }
        }

        // Update minimum_cost and input_number if the current item is not outdated and has a smaller cost
        if (!is_outdated && cost < minimum_cost) {
            minimum_cost = cost;
            input_number = i + 1;
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    printf("%d\n", input_number);

    return 0;
}
