#include <stdio.h>
#include <stdlib.h>

void get_nums(int num, int t, int *result) {
    // This function distributes the value t among num parts.
    // It calculates the base number for each part by dividing t by num.
    // It adds 1 to the base number for the first t % num parts.
    int base = t / num;
    int extra = t % num;
    
    for (int i = 0; i < num; i++) {
        result[i] = base + (i < extra ? 1 : 0);
    }
}

int main() {
    int n, k, l, r, sa, sk;
    
    // Read input values for n, k, l, r, sa, and sk
    scanf("%d %d %d %d %d %d", &n, &k, &l, &r, &sa, &sk);
    
    int *ans = (int *)malloc(n * sizeof(int));
    
    // Use the get_nums function to calculate the distribution of sk and sa - sk
    get_nums(k, sk, ans);
    get_nums(n - k, sa - sk, ans + k);
    
    // Print the result as a space-separated string of numbers
    for (int i = 0; i < n; i++) {
        printf("%d", ans[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    
    printf("\n");
    
    free(ans);
    return 0;
}

// <END-OF-CODE>
