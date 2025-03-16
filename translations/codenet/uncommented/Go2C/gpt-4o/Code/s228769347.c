#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    FILE *wfp = stdout;

    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (argc > 2) {
            wfp = fopen(argv[2], "w");
        }
    }

    int n;
    fscanf(fp, "%d", &n);
    int *ll = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &ll[i]);
    }

    qsort(ll, n, sizeof(int), compare);

    long long ans = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int l = j + 1;
            int r = n;
            while (l < r) {
                int m = (l + r) / 2;
                if (ll[m] < ll[i] + ll[j]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            ans += l - (j + 1);
        }
    }

    fprintf(wfp, "%lld\n", ans);

    free(ll);
    if (fp != stdin) fclose(fp);
    if (wfp != stdout) fclose(wfp);

    return 0;
}

// <END-OF-CODE>
