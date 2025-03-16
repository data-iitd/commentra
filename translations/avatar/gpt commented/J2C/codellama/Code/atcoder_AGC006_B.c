#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declaring variables
    int n, x, max;
    
    // Reading input from the user
    scanf("%d %d", &n, &x);
    
    // Calculating the maximum value based on n
    max = n * 2 - 1;
    
    // Checking if x is equal to 1 or max, if so, print "No" and exit the method
    if (x == 1 || x == max) {
        printf("No\n");
        return 0; // Exit the method early
    }
    
    // If x is valid, print "Yes"
    printf("Yes\n");
    
    // Prepare the line separator for formatting output
    char sep[] = "\n";
    
    // Generate a sequence of numbers based on the input x and n
    char ans[1000];
    int i = 0;
    for (int j = x + n - 1; j < x + n + max - 1; j++) {
        int k = (j % max + 1);
        ans[i++] = k + '0';
        ans[i++] = sep[0];
    }
    ans[i] = '\0';
    
    // Print the generated sequence
    printf("%s", ans);
    
    // End of code
    printf("