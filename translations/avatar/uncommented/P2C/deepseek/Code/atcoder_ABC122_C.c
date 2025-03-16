#include <stdio.h>
#include <stdlib.h>

int count(int total, char *s, int i) {
    if (s[i-1] == 'A' && s[i] == 'C') {
        return total + 1;
    }
    return total;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    char *s = (char *)malloc(n + 1);
    scanf("%s", s);

    int *cumsum = (int *)malloc((n + 1) * sizeof(int));
    cumsum[0] = 0;
    for (int i = 1; i < n; i++) {
        cumsum[i] = count(cumsum[i-1], s, i);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", cumsum[r-1] - cumsum[l-1]);
    }

    free(s);
    free(cumsum);
    return 0;
}
