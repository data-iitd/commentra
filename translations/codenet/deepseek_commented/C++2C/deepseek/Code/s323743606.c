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
    int prices[][3] = {
        {380, 380, 380}, {550, 550, 550}, {850, 850, 850}
    };
    int discounts[] = {0.8, 0.85, 0.88};

    int m[MAX_WEIGHT] = {0};

    for (int i = 0; i * items[0].weight < MAX_WEIGHT; i++) {
        for (int j = 0; j * items[1].weight < MAX_WEIGHT; j++) {
            for (int k = 0; k * items[2].weight < MAX_WEIGHT; k++) {
                int weight = i * items[0].weight + j * items[1].weight + k * items[2].weight;
                int price = 0;

                for (int l = 0; l < 3; l++) {
                    int count = (l == 0) ? i : (l == 1) ? j : k;
                    int unit_price = prices[l][count % (l + 2)];
                    price += (count / (l + 2)) * unit_price * discounts[l] + (count % (l + 2)) * unit_price;
                }

                if (weight < MAX_WEIGHT && (m[weight] == 0 || m[weight] > price)) {
                    m[weight] = price;
                }
            }
        }
    }

    int n;
    while (scanf("%d", &n), n) {
        printf("%d\n", m[n]);
    }

    return 0;
}
