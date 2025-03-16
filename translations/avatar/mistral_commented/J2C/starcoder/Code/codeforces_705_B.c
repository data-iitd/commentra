
#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int arr[100000];
        int prevWinner = 0;
        for (int i = 0; i < 100000; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] == 1) {
                if (prevWinner == 0) {
                    prevWinner = 2;
                }
                if ((i - 1) % 2 == 0) {
                    printf("%d\n", prevWinner == 0? 2 : 1);
                    prevWinner = (prevWinner == 0? 2 : 1);
                }
            }
        }
    }
    return 0;
}

