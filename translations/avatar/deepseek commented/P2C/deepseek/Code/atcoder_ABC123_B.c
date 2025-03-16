#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int menu[5][2];
    char m[10];
    int e;

    for (int i = 0; i < 5; i++) {
        scanf("%s", m);
        e = m[strlen(m) - 1] - '0';
        if (e == 0) {
            e = 10;
        }
        menu[i][0] = atoi(m);
        menu[i][1] = e;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (menu[i][1] > menu[j][1]) {
                int temp0 = menu[i][0];
                int temp1 = menu[i][1];
                menu[i][0] = menu[j][0];
                menu[i][1] = menu[j][1];
                menu[j][0] = temp0;
                menu[j][1] = temp1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < 5; i++) {
        ans += (int)ceil((double)menu[i][0] / 10) * 10;
    }
    printf("%d\n", ans + menu[0][0]);

    return 0;
}
