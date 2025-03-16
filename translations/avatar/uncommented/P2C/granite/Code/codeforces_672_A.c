
#include <stdio.h>
#include <stdlib.h>

int main() {
    int li[370], ind = 0;
    for (int i = 1; i < 371; i++) {
        int temp[3], p = i, q = i, count = 0;
        while (p!= 0) {
            p /= 10;
            count++;
        }
        if (count == 1) {
            li[ind++] = i;
        }
        if (count == 2) {
            int temp[3];
            while (q!= 0) {
                temp[count - 1] = q % 10;
                q /= 10;
            }
            for (int j = 0; j < count; j++) {
                li[ind++] = temp[j];
            }
        }
        if (count == 3) {
            int temp[3];
            while (q!= 0) {
                temp[count - 1] = q % 10;
                q /= 10;
            }
            for (int j = 0; j < count; j++) {
                li[ind++] = temp[j];
            }
        }
    }
    li[ind - 1] = 0;
    li[ind - 2] = 0;
    int n;
    scanf("%d", &n);
    printf("%d", li[n - 1]);
    return 0;
}
//END-OF-CODE