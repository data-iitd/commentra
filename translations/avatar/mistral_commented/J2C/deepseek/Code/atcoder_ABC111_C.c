#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100010

int main() {
    int n;
    int v[MAX_SIZE];
    int vo[MAX_SIZE] = {0};
    int ve[MAX_SIZE] = {0};
    int vt[MAX_SIZE] = {0};
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i += 2) {
        vo[v[i]]++;
    }

    for (i = 1; i < n; i += 2) {
        ve[v[i]]++;
    }

    // Sorting the arrays 'vo', 've', and 'vt' in descending order
    // This part is not implemented in C, as C does not have built-in support for sorting arrays in descending order
    // We will manually find the maximum values after counting the occurrences

    int max_vo = 0, max_ve = 0, max_vt = 0;
    int max_index_vo = 0, max_index_ve = 0, max_index_vt = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        if (vo[i] > max_vo) {
            max_vo = vo[i];
            max_index_vo = i;
        }
        if (ve[i] > max_ve) {
            max_ve = ve[i];
            max_index_ve = i;
        }
        if (vo[i] + ve[i] > vt[i]) {
            vt[i] = vo[i] + ve[i];
        }
    }

    int ans = 0;

    if (max_vo + max_ve == vt[max_index_vt]) {
        ans = n - max_vo - (max_ve == 0 ? 0 : max_ve - 1);
    } else {
        ans = n - max_vo - max_ve;
    }

    printf("%d\n", ans);

    return 0;
}
