
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char xxs[1000];
    fgets(xxs, 1000, stdin);
    char *xxs_token = strtok(xxs, " ");
    int x = atoi(xxs_token);
    xxs_token = strtok(NULL, " ");
    int t = atoi(xxs_token);
    xxs_token = strtok(NULL, " ");
    int a = atoi(xxs_token);
    xxs_token = strtok(NULL, " ");
    int b = atoi(xxs_token);
    xxs_token = strtok(NULL, " ");
    int da = atoi(xxs_token);
    xxs_token = strtok(NULL, " ");
    int db = atoi(xxs_token);
    if (x == 0) {
        printf("YES\n");
        return 0;
    }
    int a_time = fmin(a / da, t - 1);
    int b_time = fmin(b / db, t - 1);
    for (int i = 0; i <= a_time; i++) {
        for (int j = 0; j <= b_time; j++) {
            if (a - da * i == x || b - db * j == x) {
                printf("YES\n");
                return 0;
            }
            if ((a - da * i) + (b - db * j) == x) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
