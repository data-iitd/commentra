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

int main() {
    int nPairsWithCommonFX(int *sequence, int length);
    int length;
    scanf("%d", &length); // Read input length (not used in C)
    int sequence[length];
    for (int i = 0; i < length; i++) {
        scanf("%d", &sequence[i]);
    }
    int result = nPairsWithCommonFX(sequence, length);
    printf("%d\n", result);
    return 0;
}

int nPairsWithCommonFX(int *sequence, int length) {
    int storage[length];
    int FXs[length];
    int storageSize = 0;
    int FXsSize = 0;

    for (int i = 0; i < length; i++) {
        int y = f(sequence[i]);
        int isUnique = 1;
        for (int j = 0; j < storageSize; j++) {
            if (storage[j] == y) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            storage[storageSize++] = y;
            FXs[FXsSize++] = y;
        } else {
            for (int j = 0; j < storageSize; j++) {
                if (storage[j] == y) {
                    storage[j] = sequence[i];
                    break;
                }
            }
        }
    }

    int totalPairs = 0;
    for (int i = 0; i < FXsSize; i++) {
        for (int j = i + 1; j < FXsSize; j++) {
            if (FXs[i] == FXs[j]) {
                totalPairs += 1;
            }
        }
    }

    return totalPairs;
}
