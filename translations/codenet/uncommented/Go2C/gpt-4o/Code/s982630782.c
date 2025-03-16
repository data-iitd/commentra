#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} Pair;

int compare(const void *a, const void *b) {
    return ((Pair *)b)->key - ((Pair *)a)->key; // Sort in descending order
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    int *keys = malloc(N * sizeof(int));
    int *values = malloc(N * sizeof(int));
    int uniqueCount = 0;

    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (keys[j] == num) {
                values[j]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            keys[uniqueCount] = num;
            values[uniqueCount] = 1;
            uniqueCount++;
        }
    }

    for (int i = 0; i < M; i++) {
        int B, C;
        scanf("%d %d", &B, &C);
        int found = 0;
        for (int j = 0; j < uniqueCount; j++) {
            if (keys[j] == C) {
                values[j] += B;
                found = 1;
                break;
            }
        }
        if (!found) {
            keys[uniqueCount] = C;
            values[uniqueCount] = B;
            uniqueCount++;
        }
    }

    Pair *pairs = malloc(uniqueCount * sizeof(Pair));
    for (int i = 0; i < uniqueCount; i++) {
        pairs[i].key = keys[i];
        pairs[i].value = values[i];
    }

    qsort(pairs, uniqueCount, sizeof(Pair), compare);

    int rest = N;
    int sum = 0;
    for (int i = 0; i < uniqueCount; i++) {
        int num = pairs[i].value;
        if (num >= rest) {
            sum += rest * pairs[i].key;
            break;
        }
        sum += num * pairs[i].key;
        rest -= num;
    }

    printf("%d\n", sum);

    free(keys);
    free(values);
    free(pairs);
    
    return 0;
}

// <END-OF-CODE>
