#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, num;
    scanf("%d %d", &n, &num);
    int num_set[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_set[i]);
    }
    int two_times_set[30] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            if (num_set[i] % 2!= 0) {
                two_times_set[j]++;
                num_set[i] /= 2;
                break;
            }
            num_set[i] /= 2;
        }
    }
    int count = 0;
    for (int i = 0; i < 30; i++) {
        if (two_times_set[i] == 1) {
            count++;
        }
    }
    if (count > 1) {
        printf("0\n");
    } else {
        int lcm = num_set[0];
        for (int i = 1; i < n; i++) {
            lcm = lcm * num_set[i] / __gcd(lcm, num_set[i]);
        }
        printf("%d\n", (num - lcm / 2) / lcm + 1);
    }
    return 0;
}

