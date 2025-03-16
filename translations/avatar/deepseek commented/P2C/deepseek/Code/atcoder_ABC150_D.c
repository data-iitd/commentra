#include <stdio.h>
#include <stdlib.h>

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
        two_times_set[two_times_count++] = count;
    }

    int unique_count = 0;
    for (int i = 0; i < two_times_count; i++) {
        if (two_times_set[i] != 0) {
            unique_count++;
        }
    }

    if (unique_count != 1) {
        printf("0\n");
        return 0;
    }

    int lcm = num_set[0];
    for (int i = 1; i < n; i++) {
        int a = lcm, b = num_set[i];
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        lcm = (lcm * num_set[i]) / lcm;
    }

    int result = (num - lcm / 2) / lcm + 1;
    printf("%d\n", result);

    return 0;
}
