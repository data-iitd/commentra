#include <stdio.h>
#include <math.h>

int main() {
    int menu[5][2];
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &menu[i][0]);
        menu[i][1] = menu[i][0] % 10;
        if (menu[i][1] == 0) {
            menu[i][1] = 10;
        }
    }
    for (int i = 1; i < 5; i++) {
        int num_full_10s = ceil(menu[i][0] / 10.0);
        ans += num_full_10s * 10;
    }
    printf("%d\n", menu[0][0] + ans);
    return 0;
}
