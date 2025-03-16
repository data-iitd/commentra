#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Creating a Scanner object to read input from the user
    int n, x;
    scanf("%d %d", &n, &x);
    
    // Calling the print method with the inputs x and n
    print(x, n);
    
    return 0;
}

void print(int x, int n) {
    // Calculating the maximum value based on n
    int max = n * 2 - 1;
    
    // Checking if x is equal to 1 or max, if so, print "No" and exit the method
    if (x == 1 || x == max) {
        printf("No");
        return; // Exit the method early
    }
    
    // If x is valid, print "Yes"
    printf("Yes");
    
    // Prepare the line separator for formatting output
    char sep[] = "\n";
    
    // Generate a sequence of numbers based on the input x and n
    char ans[max];
    for (int i = x + n - 1; i < x + n + max - 1; i++) {
        ans[i % max] = (i % max + 1) + sep[0]; // Adjusting the number to fit within the range
    }
    
    // Print the generated sequence
    printf("%s", ans);
}

