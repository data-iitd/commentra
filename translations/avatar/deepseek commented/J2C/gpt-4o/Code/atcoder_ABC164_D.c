#include <stdio.h>
#include <string.h>

int main() {
    char S[100000]; // Assuming the maximum length of the string is 100000
    scanf("%s", S);
    int N = strlen(S);
    
    // Array to store remainders at each position
    int mod_arr[N];
    // Array to count occurrences of each remainder
    int mod_cnt[2019] = {0};
    // Radix initialized to 1 for the least significant digit
    int radix = 1;
    
    // Process each character in the string from right to left
    for (int i = 0; i < N; i++) {
        int tmp = ((S[N - 1 - i] - '0') * radix) % 2019;
        if (i != 0) tmp = (tmp + mod_arr[i - 1]) % 2019;
        mod_arr[i] = tmp;
        mod_cnt[tmp]++;
        radix = (radix * 10) % 2019;
    }
    
    // Calculate the number of valid pairs using combinatorics
    long long ans = 0; 
    mod_cnt[0]++; // Ensure 0 is counted
    for (int i = 0; i < 2019; i++) {
        ans += (long long)mod_cnt[i] * (mod_cnt[i] - 1) / 2;
    }
    
    // Output the result
    printf("%lld\n", ans);
    
    return 0;
}

// <END-OF-CODE>
