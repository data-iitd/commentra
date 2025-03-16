#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, value, pos = 0, flag = 0;
    int result;

    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        a[i] = value;
    }

    if (a[0] > 15) {
        result = 15;
    } else {
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] > 15) {
                pos = i - 1;
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            result = a[pos] + 15;
        } else {
            result = a[n - 1] + 15;
        }
    }

    if (result > 90) result = 90;

    printf("%d\n", result);

    return 0;
}
