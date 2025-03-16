#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int ara[n];
    int max = 0;
    int freq[100001] = {0};

    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        ara[i] = v;
        freq[v]++;
        if (freq[v] > max) {
            max = freq[v];
        }
    }

    int mm[100001] = {0};
    for (int i = 0; i < n; i++) {
        if (mm[ara[i]] == 0) {
            mm[ara[i]] = 1;
            if (freq[ara[i]] == max) {
                printf("%d\n", ara[i]);
                break;
            }
        }
    }

    return 0;
}
