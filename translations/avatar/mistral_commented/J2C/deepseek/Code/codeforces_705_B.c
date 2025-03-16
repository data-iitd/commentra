#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    int arr[t];

    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) {
            static int prevWinner = 0;
            if (prevWinner == 0) {
                prevWinner = 2;
            }

            if ((arr[i] - 1) % 2 == 0) {
                printf("%d\n", prevWinner == 0 ? 2 : 1);
                prevWinner = (prevWinner == 0 ? 2 : 1);
            }
        }
    }

    return 0;
}
