#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to calculate the result
void calculate(int n, char s[]) {
    // Initializing counts for 'R', 'G', and 'B'
    int rNum = 0, gNum = 0, bNum = 0;
    
    // Counting the occurrences of 'R', 'G', and 'B'
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') rNum++;
        else if (s[i] == 'G') gNum++;
        else if (s[i] == 'B') bNum++;
    }
    
    // Initializing sum to 0
    int sum = 0;
    
    // Iterating over possible step sizes from 1 to ceil(n / 2) + 1
    for (int step = 1; step <= (int)ceil((double)n / 2) + 1; step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i <= n - 2 * step; i++) {
            // Forming a substring of length 3
            char s[4];
            s[0] = s[1] = s[2] = '\0';
            s[0] = s[i];
            s[1] = s[i + step];
            s[2] = s[i + step * 2];
            
            // Checking if the substring matches any of the patterns
            if ((s[0] == 'R' && s[1] == 'G' && s[2] == 'B') ||
                (s[0] == 'R' && s[1] == 'B' && s[2] == 'G') ||
                (s[0] == 'G' && s[1] == 'R' && s[2] == 'B') ||
                (s[0] == 'G' && s[1] == 'B' && s[2] == 'R') ||
                (s[0] == 'B' && s[1] == 'R' && s[2] == 'G') ||
                (s[0] == 'B' && s[1] == 'G' && s[2] == 'R')) {
                sum++;
            }
        }
    }
    
    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    printf("%d\n", rNum * gNum * bNum - sum);
}

// Main function to take input and call calculate
int main() {
    int N;
    char S[100001];
    
    // Taking input for N and S
    scanf("%d", &N);
    scanf("%s", S);
    
    // Calling the function calculate with N and S as arguments
    calculate(N, S);
    
    return 0;
}
