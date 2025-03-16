
#include <stdio.h>
#include <stdlib.h>

int absint(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

int main() {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
    }

    int n;
    fscanf(fp, "%d", &n);

    int *aa = (int *)malloc(sizeof(int) * (n + 2));
    int sum = 0;
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &aa[i + 1]);
        sum += absint(aa[i + 1] - aa[i]);
    }
    sum += absint(aa[n + 1] - aa[n]);

    for (int i = 1; i < n + 1; i++) {
        int ans = sum - absint(aa[i + 1] - aa[i]) - absint(aa[i] - aa[i - 1]) + absint(aa[i + 1] - aa[i - 1]);
        printf("%d\n", ans);
    }

    fclose(fp);
    free(aa);
    return 0;
}

