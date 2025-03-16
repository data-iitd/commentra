#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    long cnt[21] = {0}; // Array size is 21 to accommodate indices from 0 to 20
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        // Increment the count for the input integer adjusted by +10 to handle negative values
        cnt[num + 10]++;
    }
    
    long res = 0;
    
    // Calculate the number of pairs (i, 20 - i) where i ranges from 0 to 9
    for (int i = 0; i < 10; i++) {
        // Multiply the counts of i and (20 - i) and add to the result
        res += cnt[i] * cnt[20 - i];
    }
    
    // Add the number of pairs of the integer 10 (i.e., combinations of 10 taken 2 at a time)
    res += (cnt[10] * (cnt[10] - 1)) / 2;
    
    // Output the final result
    printf("%ld\n", res);
    
    return 0;
}
