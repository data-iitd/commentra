#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n, num;
    scanf("%d %d", &n, &num);

    int num_set[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &num_set[i]);
    }

    int two_times_set[n];
    for (int i = 0; i < n; i++) {
        int count = 0;
        while (num_set[i] % 2 == 0) {
            num_set[i] /= 2;
            count++;
        }
        two_times_set[i] = count;
    }

    int unique_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (two_times_set[i] == two_times_set[j]) {
                unique_count++;
            }
        }
    }

    if (unique_count != 1) {
        printf("0");
        return 0;
    }

    int lcm = num_set[0];
    for (int i = 1; i < n; i++) {
        lcm = lcm * num_set[i] / gcd(lcm, num_set[i]);
    }

    printf("%d", (num - lcm / 2) / lcm + 1);

    return 0;
}

