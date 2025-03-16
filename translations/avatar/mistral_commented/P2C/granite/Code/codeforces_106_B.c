
#include <stdio.h>

int main() {
    // Define the number of items in the input array
    int n;
    scanf("%d", &n);

    // Initialize an empty list to store the input data
    int input_array[n][4];

    // Read n items from the standard input and store them in the input_array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &input_array[i][j]);
        }
    }

    // Initialize an empty list to store the outdated items
    int outdated[n][4];
    int outdated_count = 0;

    // Check for outdated items in the input array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Check if the current item is older and smaller than the next one
            if (input_array[i][0] < input_array[j][0] &&
                input_array[i][1] < input_array[j][1] &&
                input_array[i][2] < input_array[j][2]) {
                // Append the current item to the outdated list
                for (int k = 0; k < 4; k++) {
                    outdated[outdated_count][k] = input_array[i][k];
                }
                outdated_count++;
            }
        }
    }

    // Convert the outdated list to a set to remove duplicates
    int outdated_set[n][4];
    int outdated_set_count = 0;
    for (int i = 0; i < outdated_count; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < outdated_set_count; j++) {
            if (outdated[i][0] == outdated_set[j][0] &&
                outdated[i][1] == outdated_set[j][1] &&
                outdated[i][2] == outdated_set[j][2] &&
                outdated[i][3] == outdated_set[j][3]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            for (int k = 0; k < 4; k++) {
                outdated_set[outdated_set_count][k] = outdated[i][k];
            }
            outdated_set_count++;
        }
    }

    // Initialize minimum_cost and input_number to large initial values
    int minimum_cost = 100000;
    int input_number = 0;

    // Find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        int cost = input_array[i][3];
        // Check if the current item is not outdated and has a smaller cost than minimum_cost
        int is_outdated = 0;
        for (int j = 0; j < outdated_set_count; j++) {
            if (input_array[i][0] == outdated_set[j][0] &&
                input_array[i][1] == outdated_set[j][1] &&
                input_array[i][2] == outdated_set[j][2] &&
                input_array[i][3] == outdated_set[j][3]) {
                is_outdated = 1;
                break;
            }
        }
        if (!is_outdated && cost < minimum_cost) {
            // Update minimum_cost and input_number
            minimum_cost = cost;
            input_number = i + 1;
        }
    }

    // Print the index of the item with the minimum cost that is not outdated
    printf("%d\n", input_number);

    return 0;
}
