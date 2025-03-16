

#include <stdio.h>
#include <math.h>

int main() {
    int n, num;
    scanf("%d %d", &n, &num);

    int a[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }

    int two_times_set[30] = {0};
    for (int i = 0; i < num; i++) {
        int count = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            count++;
        }
        two_times_set[count]++;
    }

    int flag = 0;
    for (int i = 0; i < 30; i++) {
        if (two_times_set[i] > 1) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("0\n");
    } else {
        int lcm = a[0];
        for (int i = 1; i < num; i++) {
            lcm = lcm * a[i] / __gcd(lcm, a[i]);
        }

        printf("%d\n", (num - lcm / 2) / lcm + 1);
    }

    return 0;
}
