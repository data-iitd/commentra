#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int menu[5][2];
    int e;
    char m[10];

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
        int num_full_10s = (int)ceil((double)menu[i][0] / 10);
        ans += num_full_10s * 10;
    }

    printf("%d\n", menu[0][0] + ans);

    return 0;
}
