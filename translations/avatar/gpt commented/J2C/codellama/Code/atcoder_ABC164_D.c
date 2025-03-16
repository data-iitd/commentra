#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

int main() { 
    // Create a Scanner object to read input from the user
    char S[1000000]; 
    int N; 
    int mod_arr[1000000]; 
    int mod_cnt[2019]; 
    int radix = 1; 
    int i; 
    int tmp; 
    long ans = 0L; 
    
    // Read the input string S
    scanf("%s", S); 
    
    // Get the length of the string S
    N = strlen(S); 
    
    // Initialize an array to store the modulo results
    for (i = 0; i < N; i++) { 
        // Calculate the current digit's contribution to the modulo 2019
        tmp = ((int) S[N - 1 - i] - (int) '0') * radix % 2019; 
        
        // If not the first character, add the previous modulo result
        if (i != 0) 
            tmp = (tmp + mod_arr[i - 1]) % 2019; 
        
        // Store the current modulo result
        mod_arr[i] = tmp; 
        
        // Increment the count of this modulo result
        mod_cnt[tmp]++; 
        
        // Update the radix for the next digit (base 10)
        radix = radix * 10 % 2019; 
    } 
    
    // Initialize the answer variable to count pairs
    ans = 0L; 
    
    // Increment the count for modulo 0 to account for pairs starting from the beginning
    mod_cnt[0]++; 
    
    // Calculate the number of pairs of indices with the same modulo value
    for (i = 0; i < 2019; i++) { 
        ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2; 
    } 
    
    // Print the final answer
    printf("%ld\n", ans); 
    
    return 0; 
} 
