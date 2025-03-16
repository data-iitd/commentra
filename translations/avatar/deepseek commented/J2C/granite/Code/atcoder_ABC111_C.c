

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    int v[100010];
    int vo[100010] = {0};
    int ve[100010] = {0};
    int vt[100010] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        vt[v[i]]++;
        if (i % 2 == 0) {
            ve[v[i]]++;
        } else {
            vo[v[i]]++;
        }
    }
    qsort(vo, 100010, sizeof(int), cmpfunc);
    qsort(ve, 100010, sizeof(int), cmpfunc);
    qsort(vt, 100010, sizeof(int), cmpfunc);
    int ans = 0;
    if (vo[0] + ve[0] == vt[0]) {
        ans = n - vo[0] - ve[1] < n - vo[1] - ve[0]? n - vo[0] - ve[1] : n - vo[1] - ve[0];
    } else {
        ans = n - vo[0] - ve[0];
    }
    printf("%d\n", ans);
    return 0;
}

int cmpfunc(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

