#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int count;
} Counter;

int compare(const void *a, const void *b) {
    return ((Counter *)a)->key - ((Counter *)b)->key;
}

int main() {
    int n;
    scanf("%d", &n);

    Counter *counter = malloc(n * sizeof(Counter));
    int unique_count = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        // Check if the number is already in the counter
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (counter[j].key == num) {
                counter[j].count++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the counter
        if (!found) {
            counter[unique_count].key = num;
            counter[unique_count].count = 1;
            unique_count++;
        }
    }

    long long c = 0;

    for (int i = 0; i < unique_count; i++) {
        int key = counter[i].key;
        if (key == 0) {
            c += (long long)counter[i].count * (counter[i].count - 1);
        } else {
            for (int j = 0; j < unique_count; j++) {
                if (counter[j].key == -key) {
                    c += (long long)counter[i].count * counter[j].count;
                    break;
                }
            }
        }
    }

    printf("%lld\n", c / 2);

    free(counter);
    return 0;
}

// <END-OF-CODE>
