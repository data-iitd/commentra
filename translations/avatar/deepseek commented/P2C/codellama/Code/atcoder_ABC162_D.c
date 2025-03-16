#include <stdio.h>
#include <string.h>
#include <math.h>

// Defining the function calculate that takes two parameters, n and s
void calculate(int n, char s[]) {
    // Converting the string s into a list of characters
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = s[i];
    }
    
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
    
    // Iterating over possible step sizes from 1 to math.ceil(n / 2) + 1
    for (int step = 1; step <= (int)ceil(n / 2) + 1; step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i < n - 2 * step; i++) {
            // Forming a substring of length 3
            char s[3];
            for (int j = 0; j < 3; j++) {
                s[j] = arr[i + j * step];
            }
            
            // Checking if the substring matches any of the patterns
            if (strcmp(s, "RGB") == 0 || strcmp(s, "RBG") == 0 || strcmp(s, "BGR") == 0 || strcmp(s, "BRG") == 0 || strcmp(s, "GBR") == 0 || strcmp(s, "GRB") == 0) {
                sum = sum + 1;
            }
        }
    }
    
    // Printing the product of the counts of 'R', 'G', and 'B' minus sum
    printf("%d\n", rNum * gNum * bNum - sum);
}

// Calling the function calculate with N and S as arguments
int main() {
    int n;
    char s[100000];
    scanf("%d", &n);
    scanf("%s", s);
    calculate(n, s);
    return 0;
}

