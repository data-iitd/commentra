#include <stdio.h>
#include <stdlib.h>

int absint(int a) {
    return (a < 0) ? -a : a;
}

int main(int argc, char *argv[]) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
    }

    int n;
    fscanf(fp, "%d", &n);

    int *aa = (int *)malloc((n + 2) * sizeof(int));
    if (aa == NULL) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

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

    free(aa);
    if (fp != stdin) {
        fclose(fp);
    }

    return 0;
}

// <END-OF-CODE>
