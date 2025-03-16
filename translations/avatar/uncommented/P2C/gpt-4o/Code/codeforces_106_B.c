#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int S, R, H, C;
} Item;

int main() {
    int n;
    scanf("%d", &n);
    
    Item *input_array = (Item *)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }
    
    int *outdated = (int *)malloc(n * sizeof(int));
    int outdated_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (input_array[i].S < input_array[j].S && 
                input_array[i].R < input_array[j].R && 
                input_array[i].H < input_array[j].H) {
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

    int minimum_cost = 100000;
    int input_number = 0;

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
            minimum_cost = cost;
            input_number = i + 1;
        }
    }

    printf("%d\n", input_number);

    free(input_array);
    free(outdated);
    return 0;
}

// <END-OF-CODE>
