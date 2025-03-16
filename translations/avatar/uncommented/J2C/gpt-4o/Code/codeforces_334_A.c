#include <stdio.h>
#include <stdlib.h>

void debug(int div) {
    fprintf(stderr, "%d\n", div);
}

int main() {
    int n;
    scanf("%d", &n);
    int square = n * n;

    int *odd = (int *)malloc(square * sizeof(int));
    int *even = (int *)malloc(square * sizeof(int));
    int oddCount = 0, evenCount = 0;

    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[evenCount++] = i;
        } else {
            odd[oddCount++] = i;
        }
    }

    int loop = square / n;
    int div = loop / 2;
    debug(div);

    for (int i = 1; i <= loop; i++) {
        for (int j = 0; j < div; j++) {
            if (i % 2 == 1) {
                printf("%d %d ", odd[0], even[evenCount - 1]);
                for (int k = 0; k < oddCount - 1; k++) {
                    odd[k] = odd[k + 1];
                }
                oddCount--;
                evenCount--;
            } else {
                printf("%d %d ", even[0], odd[oddCount - 1]);
                for (int k = 0; k < evenCount - 1; k++) {
                    even[k] = even[k + 1];
                }
                evenCount--;
                oddCount--;
            }
        }
        printf("\n");
    }

    free(odd);
    free(even);
    return 0;
}

// <END-OF-CODE>
