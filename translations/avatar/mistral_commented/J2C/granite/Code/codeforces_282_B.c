
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, x, y, s1 = 0, s2 = 0, i, j = 0, flag = 0, dif = 0;
    char ch[100000];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);

        int temp1 = s1 + x;
        int temp2 = s2 + y;

        if (abs(temp1 - temp2) <= 500) {
            s1 += x;
            ch[j++] = 'A';
            continue;
        }

        if (abs(temp1 - s2) <= 500) {
            s2 += y;
            ch[j++] = 'G';
            continue;
        }

        flag = 1;
        break;
    }

    if (flag == 1)
        printf("-1\n");
    else {
        for (i = 0; i < j; i++)
            printf("%c", ch[i]);
        printf("\n");
    }

    return 0;
}
