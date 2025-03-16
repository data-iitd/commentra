
####
# Code #
####

#include <stdio.h>
#include <stdlib.h>

// Define the modulus value
#define MOD 100000007

// Function to read an integer
int I(){
    int x;
    scanf("%d", &x);
    return x;
}

// Function to read a list of integers
int III(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    return x * 1000 + y * 100 + z * 10 + I();
}

// Function to read a list of lists (2D array)
int Line(int N){
    int i, j, k;
    int read_all[N][3];
    for (i = 0; i < N; i++)
        for (j = 0; j < 3; j++)
            read_all[i][j] = I();
    int ans[3];
    for (i = 0; i < 3; i++)
        ans[i] = 0;
    for (i = 0; i < N; i++)
        for (j = 0; j < 3; j++)
            ans[j] += read_all[i][j];
    return ans[0] * 1000 + ans[1] * 100 + ans[2] * 10 + I();
}

// Main function
int main(){
    // Input the string S and its length n
    char S[100001];
    scanf("%s", S);
    int n = strlen(S);

    // Base case: if the length of the string is 1
    if (n == 1){
        // Check if the string is '5' or '?' and print 1 if true, else print 0
        if (S[0] == '5' || S[0] == '?')
            printf("1\n");
        else
            printf("0\n");
        return 0;
    }

    // Initialize a 2D array dp of size (n, 13) with all elements initialized to 0
    int dp[n][13];
    int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < 13; j++)
            dp[i][j] = 0;

    // Iterate through each index i from 0 to n-1
    for (i = 0; i < n; i++){
        // If i is the first index, process it differently
        if (i == 0){
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i]!= '?')
                dp[i][S[i] - '0'] = 1;
            // If the character at index i is '?', update all elements in the dp array accordingly
            else
                for (j = 0; j < 10; j++)
                    dp[i][j] = 1;
        }
        // If i is not the first index, process it differently
        else{
            // If the character at index i is not '?', update the dp array accordingly
            if (S[i]!= '?')
                for (k = 0; k < 13; k++)
                    dp[i][(k * 10 + S[i] - '0') % 13] += dp[i - 1][k];
            // If the character at index i is '?', update all elements in the dp array accordingly
            else
                for (j = 0; j < 10; j++)
                    for (k = 0; k < 13; k++)
                        dp[i][(k * 10 + j) % 13] += dp[i - 1][k];
            // Update all elements in the dp array with the current value modulo MOD
            for (k = 0; k < 13; k++)
                dp[i][k] %= MOD;
        }
    }

    // Print the final answer, which is dp[n-1][5]
    printf("%d\n", dp[n - 1][5]);

    return 0;
}
