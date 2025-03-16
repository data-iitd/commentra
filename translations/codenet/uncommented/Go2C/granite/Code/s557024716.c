
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);

    int patterns[4][k];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < k; j++) {
            patterns[i][j] = 0;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {
            patterns[j][i] = 1;
        }
    }

    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < k; j++) {
            if (patterns[i][j] == 1) {
                count++;
            }
        }
    }

    int result = 0;
    for (int i = 0; i < count; i++) {
        int r = a, g = b, bl = c;
        for (int j = 0; j < k; j++) {
            if (patterns[0][j] == 1) {
                r *= 2;
            }
            if (patterns[1][j] == 1) {
                g *= 2;
            }
            if (patterns[2][j] == 1) {
                bl *= 2;
            }
        }
        if (g > r && bl > g) {
            result = 1;
            break;
        }
    }

    if (result == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
// END-OF-CODE