#include <stdio.h>
#include <stdlib.h>

int nextInt() {
    int num;
    scanf("%d", &num);
    return num;
}

int* nextInts(int n) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = nextInt();
    }
    return arr;
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
    
    printf("%d\n", ans);
    free(a);
    return 0;
}

// <END-OF-CODE>
