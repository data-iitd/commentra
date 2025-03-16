#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    int *ara = (int *) malloc(sizeof(int) * n);
    int max = 0;
    int *mm = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &ara[i]);
        if (mm[ara[i]] == 0) {
            mm[ara[i]] = 1;
            if (mm[ara[i]] > max) {
                max = mm[ara[i]];
            }
        } else {
            mm[ara[i]]++;
            if (mm[ara[i]] > max) {
                max = mm[ara[i]];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (mm[ara[i]] == max) {
            printf("%d\n", ara[i]);
            break;
        }
    }
    return 0;
}

