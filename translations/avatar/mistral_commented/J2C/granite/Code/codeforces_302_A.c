

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, arr[100000], l, r, o = 0, e = 0, i;
    char res[100000];
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) {
            o++;
        } else {
            e++;
        }
    }
    for (i = 0; i < k; i++) {
        scanf("%d %d", &l, &r);
        if ((r - l + 1) % 2 == 1) {
            res[i] = '0';
        } else {
            if ((r - l + 1) / 2 <= o) {
                res[i] = '1';
            } else {
                res[i] = '0';
            }
        }
    }
    for (i = 0; i < k; i++) {
        printf("%c\n", res[i]);
    }
    return 0;
}

