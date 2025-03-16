
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int a, b, c, k;
    scanf("%d %d %d %d", &a, &b, &c, &k);

    int patterns[4][k];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < k; j++) {
            patterns[i][j] = i;
        }
    }

    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int l = 0; l < 4; l++) {
                for (int m = 0; m < 4; m++) {
                    int r = a, g = b, bl = c;
                    for (int n = 0; n < k; n++) {
                        if (patterns[i][n] == 0) {
                            continue;
                        } else if (patterns[i][n] == 1) {
                            r *= 2;
                        } else if (patterns[i][n] == 2) {
                            g *= 2;
                        } else if (patterns[i][n] == 3) {
                            bl *= 2;
                        }
                    }
                    if (g > r && bl > g) {
                        count++;
                        break;
                    }
                }
            }
        }
    }

    if (count > 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
