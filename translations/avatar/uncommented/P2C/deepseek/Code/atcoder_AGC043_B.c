#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twos_in_factorial(int n) {
    char buffer[50];
    sprintf(buffer, "%b", n);
    int count = 0;
    for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] == '1') {
            count++;
        }
    }
    return n - count;
}

int parity_of_nCr(int n, int i) {
    int f_n = twos_in_factorial(n);
    int f_n_i = twos_in_factorial(n - i);
    int f_i = twos_in_factorial(i);
    return f_n - f_n_i - f_i > 0;
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        nums[i]--;
    }
    int no_one = 0;
    if (nums[0] != 1) {
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
        no_one = 1;
    }
    int is_odd = 0;
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && nums[i] % 2 == 1) {
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
