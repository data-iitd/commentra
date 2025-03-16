
#include <stdio.h>
#include <math.h>

int main() {
    int menu[5][2];
    for (int i = 0; i < 5; i++) {
        char m[10];
        scanf("%s", m);
        int e = m[strlen(m) - 1] - '0';
        if (e == 0) {
            e = 10;
        }
        menu[i][0] = atoi(m);
        menu[i][1] = e;
    }

    qsort(menu, 5, sizeof(menu[0]), cmp);

    int ans = 0;
    for (int i = 1; i < 5; i++) {
        ans += (menu[i][0] + 9) / 10 * 10;
    }
    ans += menu[0][0];

    printf("%d\n", ans);

    return 0;
}

int cmp(const void *a, const void *b) {
    return ((int *)a)[1] - ((int *)b)[1];
}

