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

    int num_set[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &num_set[i]);
    }

    int two_times_set[num];
    int two_times_set_size = 0;

    for (int i = 0; i < num; i++) {
        int power_of_two = 0;
        int temp = num_set[i];

        while (temp % 2 == 0) {
            power_of_two++;
            temp /= 2;
        }

        if (power_of_two > 1) {
            printf("0\n");
            return 0;
        }

        int is_new = 1;
        for (int j = 0; j < two_times_set_size; j++) {
            if (two_times_set[j] == power_of_two) {
                is_new = 0;
                break;
            }
        }

        if (is_new) {
            two_times_set[two_times_set_size++] = power_of_two;
        }
    }

    if (two_times_set_size != 1) {
        printf("0\n");
        return 0;
    }

    int lcm = num_set[0];
    for (int i = 1; i < num; i++) {
        lcm = lcm * num_set[i] / gcd(lcm, num_set[i]);
    }

    printf("%d\n", (num - lcm / 2) / lcm + 1);

    return 0;
}
