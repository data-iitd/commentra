#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 5001
<<<<<<< HEAD
=======
#define MAX_MAP_SIZE 5001
>>>>>>> 98c87cb78a (data updated)

typedef struct {
    int weight;
    int price;
<<<<<<< HEAD
} Item;

Item map[MAX_WEIGHT];
=======
} MapEntry;

MapEntry map[MAX_MAP_SIZE];
int mapSize = 0;

void addOrUpdateMap(int weight, int price) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].weight == weight) {
            if (map[i].price > price) {
                map[i].price = price;
            }
            return;
        }
    }
    map[mapSize].weight = weight;
    map[mapSize].price = price;
    mapSize++;
}

int getPrice(int weight) {
    for (int i = 0; i < mapSize; i++) {
        if (map[i].weight == weight) {
            return map[i].price;
        }
    }
    return -1; // Return -1 if weight not found
}
>>>>>>> 98c87cb78a (data updated)

int main() {
    for (int i = 0; i * 200 < MAX_WEIGHT; i++) { // Loop through possible values of i
        for (int j = 0; j * 300 < MAX_WEIGHT; j++) { // Loop through possible values of j
            for (int k = 0; k * 500 < MAX_WEIGHT; k++) { // Loop through possible values of k
                int w = i * 200 + j * 300 + k * 500; // Calculate the weight
                int p = (i / 5) * 5 * 380 * 0.8 + (i % 5) * 380 // Calculate the price for i
                      + (j / 4) * 4 * 550 * 0.85 + (j % 4) * 550 // Calculate the price for j
                      + (k / 3) * 3 * 850 * 0.88 + (k % 3) * 850; // Calculate the price for k
<<<<<<< HEAD
                
                if (map[w].weight == 0) {
                    map[w].weight = w; // Initialize weight
                    map[w].price = p; // Set price
                } else {
                    if (p < map[w].price) {
                        map[w].price = p; // Update the price if it's lower
                    }
                }
            }
        }
    }

    int n;
    while (scanf("%d", &n), n) { // Read input until a zero is entered
        if (map[n].weight != 0) {
            printf("%d\n", map[n].price); // Output the minimum price for the given weight
        } else {
            printf("0\n"); // If no price is found, output 0
        }
    }

=======
                addOrUpdateMap(w, p); // Update the map with the minimum price
            }
        }
    }
    
    int n;
    while (scanf("%d", &n), n) { // Read input until a zero is entered
        int price = getPrice(n);
        if (price != -1) {
            printf("%d\n", price); // Output the minimum price for the given weight
        } else {
            printf("0\n"); // If weight not found, output 0
        }
    }
>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
