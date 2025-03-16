#include <bits/stdc++.h>
using namespace std;

int main() {
    // Read the input string S
    string S;
    cin >> S;
    
    // Get the length of the string S
    int N = S.length();
    
    // Initialize an array to store the modulo results
    int mod_arr[N];
    
    // Initialize a count array for modulo values from 0 to 2018
    int mod_cnt[2019];
    
    // Variable to keep track of the current radix (base 10 power)
    int radix = 1;
    
    // Loop through each character in the string S from the end to the beginning
    for (int i = 0; i < N; i++) {
        // Calculate the current digit's contribution to the modulo 2019
        int tmp = (int(S[N - 1 - i]) - (int) '0') * radix % 2019;
        
        // If not the first character, add the previous modulo result
        if (i!= 0)
            tmp = (tmp + mod_arr[i - 1]) % 2019;
        
        // Store the current modulo result
        mod_arr[i] = tmp;
        
        // Increment the count of this modulo result
        mod_cnt[tmp]++;
        
        // Update the radix for the next digit (base 10)
        radix = radix * 10 % 2019;
    }
    
    // Initialize the answer variable to count pairs
    long long ans = 0;
    
    // Increment the count for modulo 0 to account for pairs starting from the beginning
    mod_cnt[0]++;
    
    // Calculate the number of pairs of indices with the same modulo value
    for (int i = 0; i < 2019; i++) {
        ans += mod_cnt[i] * (mod_cnt[i] - 1) / 2;
    }
    
    // Print the final answer
    cout << ans << endl;
}

