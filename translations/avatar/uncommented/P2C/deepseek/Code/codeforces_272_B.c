#include <stdio.h>
#include <stdlib.h>

int f(int n) {
    int y = 1;
    while (n != 1) {
        if (n % 2) {
            y += 1;
        }
        n /= 2;
    }
    return y;
}

int nPairsWithCommonFX(int* sequence, int size) {
    int* storage[size];
    int* FXs = (int*)malloc(size * sizeof(int));
    int FXsSize = 0;

    for (int i = 0; i < size; i++) {
        int y = f(sequence[i]);
        int found = 0;
        for (int j = 0; j < FXsSize; j++) {
            if (FXs[j] == y) {
                storage[j][0] += 1;
                found = 1;
                break;
            }
        }
        if (!found) {
            storage[FXsSize] = (int*)malloc(1 * sizeof(int));
            storage[FXsSize][0] = 1;
            FXs[FXsSize] = y;
            FXsSize += 1;
        }
    }

    int sum = 0;
    for (int i = 0; i < FXsSize; i++) {
        sum += storage[i][0] * storage[i][0];
    }
    sum = sum - FXsSize;
    sum /= 2;

    for (int i = 0; i < FXsSize; i++) {
        free(storage[i]);
    }
    free(FXs);

    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    int* sequence = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    int result = nPairsWithCommonFX(sequence, n);
    printf("%d\n", result);

    free(sequence);
    return 0;
}
