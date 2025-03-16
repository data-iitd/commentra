#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 5001

typedef struct {
    int weight;
    int price;
<<<<<<< HEAD
} Entry;

Entry map[MAX_WEIGHT];
int map_size = 0;

void add_entry(int weight, int price) {
    for (int i = 0; i < map_size; i++) {
        if (map[i].weight == weight) {
            if (map[i].price > price) {
                map[i].price = price;
            }
            return;
        }
    }
    map[map_size].weight = weight;
    map[map_size].price = price;
    map_size++;
=======
} MapEntry;

MapEntry map[MAX_WEIGHT];
int mapSize = 0;

int findPrice(int weight) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].weight == weight) {
            return map[i].price;
        }
    }
    return -1; // Not found
}

void insertOrUpdate(int weight, int price) {
    int index = findPrice(weight);
    if (index != -1) {
        if (map[index].price > price) {
            map[index].price = price;
        }
    } else {
        map[mapSize].weight = weight;
        map[mapSize].price = price;
        mapSize++;
    }
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    for (int i = 0; i * 200 < MAX_WEIGHT; i++) {
        for (int j = 0; j * 300 < MAX_WEIGHT; j++) {
            for (int k = 0; k * 500 < MAX_WEIGHT; k++) {
                int w = i * 200 + j * 300 + k * 500;
                int p = (i / 5) * 5 * 380 * 0.8 + (i % 5) * 380
                      + (j / 4) * 4 * 550 * 0.85 + (j % 4) * 550
                      + (k / 3) * 3 * 850 * 0.88 + (k % 3) * 850;
<<<<<<< HEAD
                add_entry(w, p);
=======
                insertOrUpdate(w, p);
>>>>>>> 98c87cb78a (data updated)
            }
        }
    }

    int n;
    while (scanf("%d", &n), n) {
<<<<<<< HEAD
        int found = 0;
        for (int i = 0; i < map_size; i++) {
            if (map[i].weight == n) {
                printf("%d\n", map[i].price);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("0\n"); // Assuming 0 if not found, as per original logic
=======
        int price = findPrice(n);
        if (price != -1) {
            printf("%d\n", price);
        } else {
            printf("0\n"); // Assuming 0 for not found
>>>>>>> 98c87cb78a (data updated)
        }
    }

    return 0;
}
<<<<<<< HEAD

// <END-OF-CODE>
=======
>>>>>>> 98c87cb78a (data updated)
