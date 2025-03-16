#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int l[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    int l2[n];
    for (int i = 0; i < n; i++) {
        if (l[i] % m == 0) {
            l2[i] = l[i] / m;
        } else {
            l2[i] = l[i] / m + 1;
        }
    }

    int mx = l2[0];
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (l2[i] > mx) {
            mx = l2[i];
            ind = i;
        }
    }

    printf("%d\n", ind + 1);

    return 0;
}
