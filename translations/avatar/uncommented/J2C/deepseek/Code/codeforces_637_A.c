#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int ara[n];
    int max = 0;
    int map[100001] = {0};
    int mm[100001] = {0};

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        ara[i] = v;
        map[v]++;
    }

    for (int i = 0; i < 100001; i++) {
        if (map[i] > max) {
            max = map[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (mm[ara[i]] == 0) {
            mm[ara[i]] = 1;
            if (mm[ara[i]] == max) {
                printf("%d\n", ara[i]);
                break;
            }
        } else {
            mm[ara[i]]++;
            if (mm[ara[i]] == max) {
                printf("%d\n", ara[i]);
                break;
            }
        }
    }

    return 0;
}

