#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int square = n * n;
    int *odd = (int *)malloc(square * sizeof(int));
    int *even = (int *)malloc(square * sizeof(int));
    int odd_count = 0, even_count = 0;

    // Separating numbers into odd and even arrays
    for (int i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[even_count++] = i;
        } else {
            odd[odd_count++] = i;
        }
    }

    int loop = square / n;
    int div = loop / 2;

    // Nested loops to generate the pattern
    for (int i = 0; i < loop; i++) {
        for (int j = 0; j < div; j++) {
            if (i % 2 == 0) {
                printf("%d %d ", odd[i * div + j], even[even_count - 1 - j]);
            } else {
                printf("%d %d ", even[i * div + j], odd[odd_count - 1 - j]);
            }
        }
        printf("\n");
    }

    free(odd);
    free(even);
    return 0;
}
