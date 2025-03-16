#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int S, R, H, C;
} Item;

int main() {
    int n;
    scanf("%d", &n);
    Item input_array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &input_array[i].S, &input_array[i].R, &input_array[i].H, &input_array[i].C);
    }
    int input_number = 0;
    int minimum_cost = 100000;
    for (int i = 0; i < n; i++) {
        int is_outdated = 0;
        for (int j = 0; j < n; j++) {
            if (input_array[i].S < input_array[j].S && input_array[i].R < input_array[j].R && input_array[i].H < input_array[j].H) {
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
