#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

typedef struct {
    int S, R, H, C;
} Tuple;

int main() {
    int n;
    Tuple input_array[MAX_N];
    Tuple outdated[MAX_N];
    int outdated_count = 0;

    // Read the number of elements
    scanf("%d", &n);

    // Read the tuples and store them in input_array
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }

    // Compare each element in input_array with every other element
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input_array[i].S < input_array[j].S &&
                input_array[i].R < input_array[j].R &&
                input_array[i].H < input_array[j].H) {
                outdated[outdated_count++] = input_array[i];
                break; // No need to check further once an outdated element is found
            }
        }
    }

    // Convert outdated array to a set to remove duplicates
    // This is a simplified approach and assumes no duplicates in the input
    // In a real scenario, a more sophisticated method would be needed

    int minimum_cost = 100000;
    int input_number = 0;

    // Find the item with the minimum cost that is not outdated
    for (int i = 0; i < n; i++) {
        int is_outdated = 0;
        for (int j = 0; j < outdated_count; j++) {
            if (input_array[i].S == outdated[j].S &&
                input_array[i].R == outdated[j].R &&
                input_array[i].H == outdated[j].H) {
                is_outdated = 1;
                break;
            }
        }
        if (!is_outdated && input_array[i].C < minimum_cost) {
            minimum_cost = input_array[i].C;
            input_number = i + 1;
        }
    }

    printf("%d\n", input_number);

    return 0;
}
