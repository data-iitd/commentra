
#include <stdio.h>

int main() {
    int x, y, a, b;
    scanf("%d %d %d %d", &x, &y, &a, &b);
    int games[1000][2];
    int count = 0;
    for (int i = a; i <= x; i++) {
        if (i <= b) {
            continue;
        }
        for (int j = b; j <= y; j++) {
            if (i > j) {
                games[count][0] = i;
                games[count][1] = j;
                count++;
            }
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d %d\n", games[i][0], games[i][1]);
    }
    return 0;
}
