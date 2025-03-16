
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, square, i, j, div, loop;
    scanf("%d", &n);
    square = n * n;
    int odd[square], even[square];
    int odd_index = 0, even_index = 0;
    for (i = 1; i <= square; i++) {
        if (i % 2 == 0) {
            even[even_index++] = i;
        } else {
            odd[odd_index++] = i;
        }
    }
    loop = square / n;
    div = loop / 2;
    for (i = 1; i <= loop; i++) {
        for (j = 0; j < div; j++) {
            if (i % 2 == 1) {
                printf("%d %d ", odd[--odd_index], even[even_index++]);
            } else {
                printf("%d %d ", even[--even_index], odd[odd_index++]);
            }
        }
        printf("\n");
    }
    return 0;
}
//END-OF-CODE