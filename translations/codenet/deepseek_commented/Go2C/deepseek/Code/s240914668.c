#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nextInt() {
    int i;
    scanf("%d", &i);
    return i;
}

int* nextInts(int n) {
    int* slice = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &slice[i]);
    }
    return slice;
}

void puts(int a) {
    printf("%d\n", a);
}

void flush() {
    fflush(stdout);
}

int main() {
    int n = nextInt();
    int* a = nextInts(n);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i + 1;
        while (r + 1 < n && (a[r] - a[l]) * (a[r + 1] - a[r]) >= 0) {
            r++;
        }
        ans++;
        i = r;
    }
    puts(ans);
    flush();

    free(a);
    return 0;
}
