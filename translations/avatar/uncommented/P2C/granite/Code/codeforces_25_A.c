
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int list[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
        list[i] %= 2;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += list[i];
    }
    if (sum == 1) {
        for (int i = 0; i < n; i++) {
            if (list[i] == 1) {
                printf("%d\n", i + 1);
                break;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }
    return 0;
}
