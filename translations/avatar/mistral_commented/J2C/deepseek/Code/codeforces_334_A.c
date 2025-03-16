#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int square = n * n;

    int *odd = (int *)malloc(square * sizeof(int));
    int *even = (int *)malloc(square * sizeof(int));

    int odd_index = 0, even_index = 0;

    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[even_index++] = i;
        } else {
            odd[odd_index++] = i;
        }
    }

    int loop = square / n;
    int div = loop / 2;

    for (int i = 1; i <= loop; i++) {
        for (int j = 0; j < div; j++) {
            if (i % 2 == 1) {
                printf("%d %d ", odd[j], even[even_index - 1 - j]);
            } else {
                printf("%d %d ", even[j], odd[odd_index - 1 - j]);
            }
        }
        printf("\n");
    }

    free(odd);
    free(even);

    return 0;
}
