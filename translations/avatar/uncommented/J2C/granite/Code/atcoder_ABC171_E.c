
#include <stdio.h>

int main() {
    int n, a[100000], r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        r ^= a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i!= 0) printf(" ");
        printf("%d", r ^ a[i]);
    }
    return 0;
}
// END-OF-CODE