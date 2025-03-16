#include <stdio.h>
#include <limits.h>

int main() {
    int a, max, min;
    scanf("%d", &a);
    int ar[a];

    for (int i = 0; i < a; i++) {
        scanf("%d", &ar[i]);
    }

    for (int i = 0; i < a; i++) {
        max = (ar[i] - ar[0] > ar[a - 1] - ar[i]) ? ar[i] - ar[0] : ar[a - 1] - ar[i];
        if (i == 0) {
            min = ar[i + 1] - ar[i];
        } else if (i == a - 1) {
            min = ar[i] - ar[i - 1];
        } else {
            min = (ar[i] - ar[i - 1] < ar[i + 1] - ar[i]) ? ar[i] - ar[i - 1] : ar[i + 1] - ar[i];
        }
        printf("%d %d\n", min, max);
    }

    return 0;
}
