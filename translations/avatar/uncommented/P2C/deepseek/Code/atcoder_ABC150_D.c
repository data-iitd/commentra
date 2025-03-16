#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);
    int num_set[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_set[i]);
    }
    int two_times_set[n];
    int two_times_count = 0;
    for (int i = 0; i < n; i++) {
        int count = 0;
        int temp = num_set[i];
        while (temp % 2 == 0) {
            temp /= 2;
            count++;
        }
        if (count > 0) {
            two_times_set[two_times_count++] = count;
        }
    }
    int all_same = 1;
    for (int i = 1; i < two_times_count; i++) {
        if (two_times_set[i] != two_times_set[0]) {
            all_same = 0;
            break;
        }
    }
    if (!all_same) {
        printf("0\n");
        return 0;
    }
    int num_list[n];
    for (int i = 0; i < n; i++) {
        num_list[i] = num_set[i];
    }
    int lcm = num_list[0];
    for (int i = 1; i < n; i++) {
        lcm = lcm * num_list[i] / gcd(lcm, num_list[i]);
    }
    printf("%d\n", (num - lcm / 2) / lcm + 1);
    return 0;
}
