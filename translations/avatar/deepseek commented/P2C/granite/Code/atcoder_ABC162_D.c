
#include <stdio.h>
#include <math.h>
#include <string.h>

// Function to calculate the product of the counts of 'R', 'G', and 'B' minus sum
void calculate(int n, char* s) {
    // Converting the string s into a list of characters
    char arr[n];
    strcpy(arr, s);
    
    // Calculating the counts of 'R', 'G', and 'B'
    int rNum = 0, gNum = 0, bNum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'R') {
            rNum++;
        } else if (arr[i] == 'G') {
            gNum++;
        } else if (arr[i] == 'B') {
            bNum++;
        }
    }
    
    // Initializing sum to 0
    int sum = 0;
    
    // Iterating over possible step sizes from 1 to ceil(n / 2) + 1
    for (int step = 1; step <= ceil(n / 2.0); step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i < n - 2 * step; i++) {
            // Forming a substring of length 3
            char s[3];
            s[0] = arr[i];
            s[1] = arr[i + step];
            s[2] = arr[i + step * 2];
            
            // Checking if the substring matches any of the patterns
            if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0) {
                sum++;
            }
        }
    }
    
    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    printf("%d\n", rNum * gNum * bNum - sum);
}

// Main function
int main() {
    int n;
    char s[1000];
    
    // Taking input for N and S
    scanf("%d", &n);
    scanf("%s", s);
    
    // Calling the function calculate with N and S as arguments
    calculate(n, s);
    
    return 0;
}

