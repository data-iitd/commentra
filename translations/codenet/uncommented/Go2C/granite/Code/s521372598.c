
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &as[i]);
    }

    int *xs = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        xs[i] = as[i] - i + 1;
    }

    qsort(xs, n, sizeof(int), cmpfunc);

    int b = xs[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(xs[i] - b);
    }
    printf("%d\n", ans);

    free(as);
    free(xs);

    return 0;
}

int cmpfunc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int abs(int n) {
    if (n < 0) {
        return -n;
    }
    return n;
}

// -----------------------------------------

const int inf = 1 << 60;
// const int mod = 1000000007;

int main() {
    int maxBufSize = 100000000;
    setvbuf(stdin, NULL, _IOFBF, maxBufSize);
    setvbuf(stdout, NULL, _IOFBF, maxBufSize);

    int n = 0;
    scanf("%d", &n);

    int *as = (int *)malloc(sizeof(i