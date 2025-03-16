#include <stdio.h>
#include <stdlib.h>

int main() {
    int li[370];
    int ind = 0;
    for (int i = 1; i <= 370; i++) {
        int temp[3];
        int p = i, q = i, count = 0;
        while (p != 0) {
            p /= 10;
            count++;
        }
        if (count == 1) {
            li[ind++] = i;
        }
        if (count == 2) {
            int temp_index = 0;
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[temp_index++] = x;
            }
            for (int j = temp_index - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
        if (count == 3) {
            int temp_index = 0;
            while (q != 0) {
                int x = q % 10;
                q /= 10;
                temp[temp_index++] = x;
            }
            for (int j = temp_index - 1; j >= 0; j--) {
                li[ind++] = temp[j];
            }
        }
    }
    li[ind - 1] = 0;
    li[ind - 2] = 0;
    int n;
    scanf("%d", &n);
    printf("%d\n", li[n - 1]);
    return 0;
}
