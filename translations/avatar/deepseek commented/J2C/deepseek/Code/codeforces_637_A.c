#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int ara[n];
    int map[100001] = {0};
    int max = 0;

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        ara[i] = v;
        map[v]++;
        if (map[v] > max) {
            max = map[v];
        }
    }

    int mm[100001] = {0};
    for (int i = 0; i < n; i++) {
        mm[ara[i]]++;
        if (mm[ara[i]] == max) {
            printf("%d\n", ara[i]);
            break;
        }
    }

    return 0;
}
