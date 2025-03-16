#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the number of possible ways to color a string
void calculate(int n, char *s) {
    // Converting the string s into a list of characters
    char *arr = (char *) malloc(n * sizeof(char));
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
    
    // Iterating over possible step sizes from 1 to n / 2 + 1
    for (int step = 1; step <= n / 2 + 1; step++) {
        // Iterating over possible starting indices for the substring
        for (int i = 0; i < n - 2 * step; i++) {
            // Forming a substring of length 3
            char *s = (char *) malloc(3 * sizeof(char));
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

// Driver code
int main() {
    int n;
    scanf("%d", &n);
    char *s = (char *) malloc(n * sizeof(char));
    scanf("%s", s);
    calculate(n, s);
    return 0;
}

