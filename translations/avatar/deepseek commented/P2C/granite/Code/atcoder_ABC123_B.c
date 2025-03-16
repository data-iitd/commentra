

#include <stdio.h>
#include <math.h>

int main() {
    int menu[5][2];
    int i, ans = 0;
    char m[10];
    for (i = 0; i < 5; i++) {
        scanf("%s", m);
        menu[i][0] = atoi(m);
        menu[i][1] = m[strlen(m) - 1] - '0';
        if (menu[i][1] == 0) {
            menu[i][1] = 10;
        }
    }
    for (i = 1; i < 5; i++) {
        ans += ceil(menu[i][0] / 10.0) * 10;
    }
    ans += menu[0][0];
    printf("%d\n", ans);
    return 0;
}
// END-OF-CODE