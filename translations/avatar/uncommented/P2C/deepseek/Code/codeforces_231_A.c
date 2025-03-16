#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l1[3];
        for (int j = 0; j < 3; j++) {
            scanf("%d", &l1[j]);
        }
        if (l1[0] + l1[1] + l1[2] > 1) {
            c = c + 1;
        }
    }
    printf("%d\n", c);
    return 0;
}
