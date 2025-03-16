#include <stdio.h>

int twos_in_factorial(int n) {
    return n - __builtin_popcount(n);
}

int parity_of_nCr(int n, int i) {
    int f_n = twos_in_factorial(n);
    int f_n_i = twos_in_factorial(n - i);
    int f_i = twos_in_factorial(i);
    return (f_n - f_n_i - f_i) > 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int nums[100]; // Assuming a maximum size of 100 for the input array
    for (int j = 0; j < n; j++) {
        scanf("%d", &nums[j]);
        nums[j]--; // Decrementing each input by 1
    }

    int no_one = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] == 0) {
            no_one = 1; // Set no_one to true if 1 is not in nums
            break;
        }
    }

    if (no_one == 0) {
        for (int j = 0; j < n; j++) {
            nums[j] /= 2; // Divide each number by 2
        }
    }

    int is_odd = 0;
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1; // Toggle is_odd
        }
    }

    if (is_odd == 0) {
        printf("0\n");
    } else {
        printf("%d\n", 1 << no_one); // Print 1 or 2 based on no_one
    }

    return 0;
}

// <END-OF-CODE>
