#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);
    
    int *num_set = (int *)malloc(n * sizeof(int));
    int num_set_size = 0;
    int two_times_set[30] = {0}; // To track the presence of numbers in the set
    int two_times_set_count = 0;

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int exists = 0;
        for (int j = 0; j < num_set_size; j++) {
            if (num_set[j] == x) {
                exists = 1;
                break;
            }
        }
        if (!exists) {
            num_set[num_set_size++] = x;
        }
    }

    for (int i = 0; i < num_set_size; i++) {
        int value = num_set[i];
        for (int j = 1; j < 30; j++) {
            value /= 2;
            if (value % 2 != 0) {
                if (two_times_set[j] == 0) {
                    two_times_set[j] = 1;
                    two_times_set_count++;
                }
                break;
            }
        }
        if (two_times_set_count != 1) {
            printf("0\n");
            free(num_set);
            return 0;
        }
    }

    long long lcm = num_set[0];
    for (int i = 1; i < num_set_size; i++) {
        lcm = lcm * num_set[i] / gcd(lcm, num_set[i]);
    }

    printf("%lld\n", (num - lcm / 2) / lcm + 1);

    free(num_set);
    return 0;
}
