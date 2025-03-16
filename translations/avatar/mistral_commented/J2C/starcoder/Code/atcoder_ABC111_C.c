
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

int main() {
    int n;
    scanf("%d", &n);
    int *v = (int *) malloc(sizeof(int) * 100010);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int *vo = (int *) malloc(sizeof(int) * 100010);
    int *ve = (int *) malloc(sizeof(int) * 100010);
    int *vt = (int *) malloc(sizeof(int) * 100010);
    for (int i = 0; i < 100010; i++) {
        vo[i] = 0;
        ve[i] = 0;
        vt[i] = 0;
    }
    for (int i = 0; i < n; i += 2) {
        int currentElement = v[i];
        vo[currentElement]++;
    }
    for (int i = 1; i < n; i += 2) {
        int currentElement = v[i];
        ve[currentElement]++;
    }
    for (int i = 0; i < 100010; i++) {
        if (vo[i] + ve[i] == vt[i]) {
            int ans = n - vo[i] - ve[i];
            if (vo[i] > ve[i]) {
                ans = n - vo[i] - ve[i + 1];
            } else {
                ans = n - vo[i + 1] - ve[i];
            }
            printf("%d\n", ans);
            break;
        }
    }
    free(v);
    free(vo);
    free(ve);
    free(vt);
    return 0;
}

