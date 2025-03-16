#include <stdio.h>

int twos_in_factorial(int n) {
    // Calculate the number of factors of 2 in the factorial of n
    return n - __builtin_popcount(n);
}

int parity_of_nCr(int n, int i) {
    // Determine the parity (odd or even) of the binomial coefficient nCr
    int f = twos_in_factorial(n);
    return f - twos_in_factorial(n - i) - twos_in_factorial(i) > 0;
}

int main() {
    // Read an integer n and a list of integers from the input
    int n;
    scanf("%d", &n);
    
    int nums[100]; // Assuming a maximum size of 100 for the input list
    int count = 0;
    
    // Read the list of integers
    while (scanf("%d", &nums[count]) != EOF) {
        nums[count]--; // Decrement each number by 1
        count++;
    }
    
    // If the list does not contain the number 1, halve each number in the list and set no_one to True
    int no_one = 0;
    int contains_one = 0;
    for (int j = 0; j < count; j++) {
        if (nums[j] == 0) {
            contains_one = 1; // Check if 1 is in the list (0 after decrement)
            break;
        }
    }
    
    if (!contains_one) {
        for (int j = 0; j < count; j++) {
            nums[j] /= 2; // Halve each number
        }
        no_one = 1; // Set no_one to True
    }
    
    // Initialize is_odd to 0 (False)
    int is_odd = 0;
    
    // Iterate over the list nums, checking the parity of nCr for each element and the corresponding index
    for (int i = 0; i < count; i++) {
        if (!parity_of_nCr(n - 1, i) && (nums[i] & 1)) {
            is_odd ^= 1; // Toggle is_odd
        }
    }
    
    // If is_odd is 0, print 0; otherwise, print 1 << no_one (which is equivalent to 2 ** no_one)
    if (!is_odd) {
        printf("0\n");
    } else {
        printf("%d\n", 1 << no_one);
    }
    
    return 0;
}

// <END-OF-CODE>
