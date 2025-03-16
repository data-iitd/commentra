#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        nums[i]--;
    }

    int no_one = 0;
    if (nums[0]!= 1) {
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
        no_one = 1;
    }

    int is_odd = 0;
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
            is_odd ^= 1;
        }
    }

    if (!is_odd) {
        printf("0\n");
    } else {
        printf("%d\n", 1 << no_one);
    }

    return 0;
}

int twos_in_factorial(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int parity_of_nCr(int n, int i) {
    int f = twos_in_factorial;
    return f(n) - f(n - i) - f(i) > 0;
}

