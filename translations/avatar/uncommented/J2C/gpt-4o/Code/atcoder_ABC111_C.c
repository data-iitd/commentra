#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100010

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int v[MAX_SIZE] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int vo[MAX_SIZE] = {0};
    int ve[MAX_SIZE] = {0};
    int vt[MAX_SIZE] = {0};

    for (int i = 0; i < n; i++) {
        vt[v[i]]++;
        if (i % 2 == 0) {
            ve[v[i]]++;
        } else {
            vo[v[i]]++;
        }
    }

    qsort(vo, MAX_SIZE, sizeof(int), compare);
    qsort(ve, MAX_SIZE, sizeof(int), compare);
    qsort(vt, MAX_SIZE, sizeof(int), compare);

    int ans = 0;
    if (vo[0] + ve[0] == vt[0]) {
        ans = (n - vo[0] - ve[1] < n - vo[1] - ve[0]) ? (n - vo[0] - ve[1]) : (n - vo[1] - ve[0]);
    } else {
        ans = n - vo[0] - ve[0];
    }

    printf("%d\n", ans);
    return 0;
}
