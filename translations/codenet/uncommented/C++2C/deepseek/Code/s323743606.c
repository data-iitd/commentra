#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 5001

typedef struct {
    int weight;
    int price;
} Item;

int main() {
    Item items[] = {
        {200, 0}, {300, 0}, {500, 0}
    };
    int num_items = sizeof(items) / sizeof(items[0]);
    int prices[MAX_WEIGHT] = {0};

    for (int i = 0; i * items[0].weight < MAX_WEIGHT; i++) {
        for (int j = 0; j * items[1].weight < MAX_WEIGHT; j++) {
            for (int k = 0; k * items[2].weight < MAX_WEIGHT; k++) {
                int weight = i * items[0].weight + j * items[1].weight + k * items[2].weight;
                int price = (i / 5) * 5 * 380 * 0.8 + (i % 5) * 380
                          + (j / 4) * 4 * 550 * 0.85 + (j % 4) * 550
                          + (k / 3) * 3 * 850 * 0.88 + (k % 3) * 850;
                if (prices[weight] == 0 || prices[weight] > price) {
                    prices[weight] = price;
                }
            }
        }
    }

    int n;
    while (scanf("%d", &n), n) {
        printf("%d\n", prices[n]);
    }

    return 0;
}
