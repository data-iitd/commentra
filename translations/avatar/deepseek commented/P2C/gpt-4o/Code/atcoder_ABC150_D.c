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

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);

    int *num_set = (int *)malloc(n * sizeof(int));
    int two_times_set[30] = {0}; // To store the counts of divisions by 2
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &num_set[i]);
    }

    for (int i = 0; i < n; i++) {
        int temp = num_set[i];
        int j;
        for (j = 1; j < 30; j++) {
            temp /= 2;
            if (temp % 2 != 0) {
                if (count == 0) {
                    two_times_set[count++] = j; // Store the first count
                } else if (two_times_set[0] != j) {
                    printf("0\n");
                    free(num_set);
                    return 0; // More than one unique count
                }
                break;
            }
        }
    }

    // If we reach here, all counts are the same
    int lcm_value = num_set[0];
    for (int i = 1; i < n; i++) {
        lcm_value = lcm(lcm_value, num_set[i]);
    }

    // Calculate the number of integers in the range from 1 to num that are divisible by the LCM
    printf("%d\n", (num - lcm_value / 2) / lcm_value + 1);

    free(num_set);
    return 0;
}
