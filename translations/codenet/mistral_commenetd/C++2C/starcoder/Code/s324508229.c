
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int n, ii, a, b; // Declare variables

    // Read the number of test cases
    scanf("%d", &n);

    // Initialize a 10x10 2D array 'cnt' with zeroes
    long long cnt[10][10]={0};

    // Iterate through each number from 1 to n
    for(int i=1;i<=n;i++){
        // Extract the last digit 'b' and the digit before last 'a' from the number 'i'
        b = i % 10;
        a = i;

        // While 'a' has more digits than one, extract the digit before last one
        while(a>=10){
            a /= 10;
        }

        // Increment the count of 'a'th row and 'b'th column in the 'cnt' array
        cnt[a][b]++;
    }

    // Initialize answer variable 'ans' with zero
    long long ans=0;

    // Iterate through each row and column from 1 to 9
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            // Multiply the count of 'i'th row and 'j'th column with the count of 'j'th row and 'i'th column
            // and add it to the answer
            ans += cnt[i][j]*cnt[j][i];
        }
    }

    // Print the final answer
    printf("%lld\n", ans);
}

