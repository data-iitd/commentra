#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int v[100010];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    int vo[100010] = {0};
    int ve[100010] = {0};
    int vt[100010] = {0};
    for (int i = 0; i < n; i++) {
        vt[v[i]]++;
        if (i % 2 == 0) {
            ve[v[i]]++;
        } else {
            vo[v[i]]++;
        }
    }
    for (int i = 0; i < 100010; i++) {
        for (int j = i + 1; j < 100010; j++) {
            if (vo[i] < vo[j]) {
                int temp = vo[i];
                vo[i] = vo[j];
                vo[j] = temp;
            }
            if (ve[i] < ve[j]) {
                int temp = ve[i];
                ve[i] = ve[j];
                ve[j] = temp;
            }
            if (vt[i] < vt[j]) {
                int temp = vt[i];
                vt[i] = vt[j];
                vt[j] = temp;
            }
        }
    }
    int ans = 0;
    if (vo[0] + ve[0] == vt[0]) {
        ans = n - vo[0] - ve[1] < n - vo[1] - ve[0] ? n - vo[0] - ve[1] : n - vo[1] - ve[0];
    } else {
        ans = n - vo[0] - ve[0];
    }
    printf("%d\n", ans);
    return 0;
}
