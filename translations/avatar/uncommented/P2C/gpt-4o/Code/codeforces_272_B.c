#include <stdio.h>
#include <stdlib.h>

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y++;
        }
        n /= 2;
    }
    return y;
}

int nPairsWithCommonFX(int* sequence, int size) {
    int* storage = (int*)calloc(size, sizeof(int));
    int* count = (int*)calloc(size, sizeof(int));
    int FXsCount = 0;

    for (int i = 0; i < size; i++) {
        int y = f(sequence[i]);
        int found = 0;

        for (int j = 0; j < FXsCount; j++) {
            if (storage[j] == y) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            storage[FXsCount] = y;
            count[FXsCount] = 1;
            FXsCount++;
        }
    }

    int totalPairs = 0;
    for (int i = 0; i < FXsCount; i++) {
        totalPairs += count[i] * count[i];
    }

    int totalCount = 0;
    for (int i = 0; i < FXsCount; i++) {
        totalCount += count[i];
    }

    free(storage);
    free(count);

    return (totalPairs - totalCount) / 2;
}

int main() {
    int size;
    scanf("%d", &size);
    int* sequence = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        scanf("%d", &sequence[i]);
    }

    int result = nPairsWithCommonFX(sequence, size);
    printf("%d\n", result);

    free(sequence);
    return 0;
}

// <END-OF-CODE>
