#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in the factorial of n
    return n - __builtin_popcount(n);
}

int parity_of_nCr(int n, int i) {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    return twos_in_factorial(n) - twos_in_factorial(n - i) - twos_in_factorial(i) > 0;
}

int main() {
    // Read an integer n and a list of integers from the input
    int n;
    scanf("%d", &n);
    int nums[n];
    char *line = malloc(1000000);
    fgets(line, 1000000, stdin);
    char *token = strtok(line, " ");
    for (int i = 0; i < n; i++) {
        nums[i] = atoi(token) - 1;
        token = strtok(NULL, " ");
    }
    
    // If the list does not contain the number 1, halve each number in the list and set no_one to True
    int no_one = 0;
    if (1 != nums[0]) {
        for (int i = 0; i < n; i++) {
            nums[i] /= 2;
        }
        no_one = 1;
    }
    
    // Initialize is_odd to False
    int is_odd = 0;
    
    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for (int i = 0; i < n; i++) {
        if (!parity_of_nCr(n - 1, i) && nums[i] & 1) {
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

