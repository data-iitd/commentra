#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int l1[1000];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &l1[j]);
            sum += l1[j];
        }
        if (sum > 1) {
            c++;
        }
    }
    printf("%d\n", c);

    return 0;
}
