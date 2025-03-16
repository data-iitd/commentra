#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    // TreeMap-like structure using a dynamically allocated array of pairs
    typedef struct {
        int key;
        int value;
    } Pair;

    int capacity = 10;
    Pair* map = (Pair*)malloc(capacity * sizeof(Pair));
    int size = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // Find the position to insert or update the pair
        int pos = -1;
        for (int j = 0; j < size; j++) {
            if (map[j].key == num) {
                pos = j;
                break;
            } else if (map[j].key > num) {
                pos = j;
                break;
            }
        }

        // If no position found, insert at the end
        if (pos == -1) {
            if (size == capacity) {
                capacity *= 2;
                map = (Pair*)realloc(map, capacity * sizeof(Pair));
            }
            map[size].key = num;
            map[size].value = 1;
            size++;
        } else {
            // If the key exists, increment the value
            map[pos].value++;
        }
    }

    // Sum up all the counts
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans += map[i].value;
    }

    // Print the final answer
    printf("%d\n", ans);

    // Free the allocated memory
    free(map);

    return 0;
}
