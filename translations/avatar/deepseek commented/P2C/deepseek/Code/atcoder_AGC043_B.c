#include <stdio.h>
#include <stdlib.h>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in the factorial of n
    int count = 0;
    while (n > 0) {
        count += n / 2;
        n /= 2;
    }
    return count;
}

int parity_of_nCr(int n, int i) {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    int fn = twos_in_factorial(n);
    int fi = twos_in_factorial(i);
    int fn_i = twos_in_factorial(n - i);
    return fn - fi - fn_i > 0;
}

int main() {
    // Read an integer n and a list of integers from the input
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        nums[i]--;
    }
    
    // If the list does not contain the number 1, halve each number in the list and set no_one to True
    int no_one = 0;
    int found_one = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            found_one = 1;
        }
    }
    if (!found_one) {
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
        no_one = 1;
    }
    
    // Initialize is_odd to False
    int is_odd = 0;
    
    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && nums[i] % 2 == 1) {
            is_odd ^= 1;
        }
    }
    
    // If is_odd is False, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if (!is_odd) {
        printf("0\n");
    } else {
        printf("%d\n", 1 << no_one);
    }
    
    return 0;
}
