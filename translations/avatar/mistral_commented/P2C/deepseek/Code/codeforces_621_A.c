#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lst[i] > lst[j]) {
                int temp = lst[i];
                lst[i] = lst[j];
                lst[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lst[i] < lst[j]) {
                int temp = lst[i];
                lst[i] = lst[j];
                lst[j] = temp;
            }
        }
    }

    int od = 0;
    for (int i = 0; i < n; i++) {
        if (lst[i] & 1) {
            od++;
        }
    }

    int sum = 0;
    int ok = 0;
    for (int i = 0; i < n; i++) {
        if (lst[i] % 2 == 0) {
            sum += lst[i];
        } else {
            if (ok || od > 1) {
                sum += lst[i];
                od--;
                ok = !ok;
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}

