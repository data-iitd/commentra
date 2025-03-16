
#include <stdio.h>

int main() {
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int l1[100];
        int sum = 0;
        for (int j = 0; j < 100; j++) {
            scanf("%d", &l1[j]);
            sum += l1[j];
        }
        if (sum > 1) {
            c++;
        }
    }
    printf("%d", c);
    return 0;
}
