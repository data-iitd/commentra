#include <stdio.h>

int main() {
    int n, k, i = 1, req = 1;
    scanf("%d %d", &n, &k);

    while (k - req >= 0) {
        if (k - req >= 0) {
            k = k - req;
        } else {
            break;
        }
        i++;
        if (i % n != 0) {
            req = i % n;
        } else {
            req = n;
        }
    }
    printf("%d\n", k);
    return 0;
}
